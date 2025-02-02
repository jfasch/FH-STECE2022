"""! Reads the JSON string provided via MQTT.
    @file ReadTestMes.py
    @brief Visualization of the measured distance from MQTT messages.
    @package docstring
    
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
    """! Documentation for reading the Data.
        @brief Handles incoming MQTT messages.
    
        This function reads in the sent Data in ASCII.
        It then converts back the raw ASCII Data into the JSON Dataformat.
        Extracts at this stage of the Softwaredevelopment only the sent Distance.
        
        @param client The MQTT client instance.
        @param message The received MQTT message containing the JSON payload.

        @return current_distance GlobalVariable which stores the measured distance

        @exception json.JSONDecodeError Raised if the received payload is not valid JSON.
        @exception KeyError Raised if the expected key ('Data' or 'Distance') is missing.
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
    """! Documentation for visualization of the Data.

        @brief Updates the visualization with the latest distance measurement.    
        
        This function adaptes the length of the bar with each measured value.
        At this point of softwaredevelopment the scale of the barchart is set to 2300mm. This could be adapted.
        Because of the maximum scale length the current distance is trimmed to a max value of 2300mm.
        @code
        ax.set_xlim(0, max(current_distance, 2300))
        @endcode
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
