"""@package docstring
Documentation for Reading JSON Messages.
 
This File is used for the visualization of the meassured distance.
At first it connects to the existing MQTT broker and subscribes the topic 'DistanceData'.
Then it extracts the Data which are published to this topic and saves it on the Variable 'current_distance'.
In the next step the variable is visualized with the help of the library matplotlib.
"""

import json
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import paho.mqtt.client as mqtt

matplotlib.use("TkAgg")

MQTT_BROKER = "172.27.1.34" #"localhost" for trying it out on one pc
MQTT_PORT = 1883
MQTT_TOPIC = "DistanceData"

current_distance = 0

def on_message(client, userdata, message):
    """Documentation for reading the Data.
 
    This function reads in the sent Data in ASCII.
    It then converts back the raw ASCII Data into the JSON Dataformat.
    Extracts at this stage of the Softwaredevelopment only the sent Distance.
    
    +some Errorhandeling is happening.

    Intern Parameters:
    Payload: ASCII Decoded raw Data
    Data: JSON Datastruct created out of the payload.
    current_distance: Distance data extracted from the data.
    """
    global current_distance
    try:
        payload = message.payload.decode("utf-8")
        data = json.loads(payload)
        current_distance = data["Data"]["Distance"]
    except (json.JSONDecodeError, KeyError) as e:
        print(f"An Error has appeard: Error number: {e}")

# MQTT-configuration
client = mqtt.Client(protocol=mqtt.MQTTv311) 
client.on_message = on_message
client.connect(MQTT_BROKER, MQTT_PORT)
client.subscribe(MQTT_TOPIC)
client.loop_start()

# Matplotlib-Setup
fig, ax = plt.subplots()
bar = ax.barh(["Distance"], [0], color="blue")
ax.set_xlim(0, 2300)

def update(frame):
    """Documentation for visualization of the Data.
 
    This function adaptes the length of the bar with each measured value.
    At this point of softwaredevelopment the scale of the barchart is set to 2300mm. This could be adapted.
    Because of the maximum scale length the current distance is trimmed to a max value of 2300mm.
    Possible solution: Adaption of the scale ax.set_xlim(0, 2300) -> ax.set_xlim(0, max(current_distance, 2300)).
    And usage of this inside the function which updates the Bar's length.
    """
    global current_distance
    if current_distance >= 2300:
        print(f"Measured Distance exceeds the scale! Measured Value: {current_distance}")
        current_distance = 2300
    bar[0].set_width(current_distance)

#Animation
ani = FuncAnimation(fig, update, interval=500, cache_frame_data=False)
anim = ani
plt.xlabel("Distance")
plt.title("Measured Distance")
plt.show()
 #Disconnection
client.loop_stop()
client.disconnect()
