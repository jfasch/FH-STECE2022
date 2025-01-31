import json
import time
import random
from datetime import datetime
import paho.mqtt.client as mqtt

# MQTT- Configuration
BROKER_ADDRESS = "localhost" #-->IP Thomas "172.30.60.112"  "localhost" (for connection on local PC)
BROKER_PORT = 1883           # Standard-MQTT-Port
TOPIC = "DistanceData"       #This is a Topic which we defined. @ECE23 If this topic is addepted you also need to change it the corresponding reading file

# MQTT-Client init and connection
def on_connect(client, userdata, flags, rc):
    """! Callback-Funktion für die MQTT-Verbindung.
    
        @brief This function is called to make a mqtt connection
        
        @param client mqtt client
        @param rc Feedbackcode of the connection (0 == success).
    """
    if rc == 0:
        print("Verbindung zum MQTT-Broker erfolgreich.")
    else:
        print(f"Verbindung fehlgeschlagen. Fehlercode: {rc}")

client = mqtt.Client()
client.on_connect = on_connect

try:
    client.connect(BROKER_ADDRESS, BROKER_PORT, 60)
    client.loop_start()
except Exception as e:
    print(f"Fehler beim Verbinden mit dem MQTT-Broker: {e}")
    exit(1)

while True:
    # Creation of a timestemp (on the C++ Raspicode this is created with the toolcase/base/millis- function)
    timestamp = datetime.now().strftime("%Y.%d.%m.%S.%f")[:-3]

    # Creation of dumy Data (on Raspi use : sensor.read_sensor() of the  toolcase/base/vl53l1x.h )
    distance = round(random.uniform(0.0, 1000.0), 1)

    # Creating the JSON Structur
    data_packet = {
        "Data": {
            "Timestamp": timestamp,
            "Distance": distance
        }
    }

    # Converting the JSON Structure into a JSON Datapackage
    json_data = json.dumps(data_packet)

    #Publishing the JSON data on the mqtt topic
    try:
        client.publish(TOPIC, json_data)
        print(f"Veröffentlicht: {json_data}")
    except Exception as e:
        print(f"Fehler beim Veröffentlichen: {e}")

    # Delay so that the mqtt is not spamed :)
    time.sleep(1)
