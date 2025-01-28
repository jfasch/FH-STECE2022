import json
import time
import random
from datetime import datetime
import paho.mqtt.client as mqtt

# MQTT-Konfiguration
BROKER_ADDRESS = "172.30.60.112" #-->IP Thomas "localhost"  # Adresse des MQTT-Brokers
BROKER_PORT = 1883  # Standard-MQTT-Port
TOPIC = "DistanceData"

# MQTT-Client initialisieren
def on_connect(client, userdata, flags, rc):
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
    # Erzeuge Zeitstempel im Format yyyy.dd.mm.ss.mm
    timestamp = datetime.now().strftime("%Y.%d.%m.%S.%f")[:-3]

    # Erzeuge einen zufälligen Distanzwert
    distance = round(random.uniform(0.0, 1000.0), 1)

    # Erstelle das JSON-Datenpaket
    data_packet = {
        "Data": {
            "Timestamp": timestamp,
            "Distance": distance
        }
    }

    # Konvertiere das Datenpaket in eine JSON-Zeichenkette
    json_data = json.dumps(data_packet)

    # Veröffentliche die Nachricht im MQTT-Topic
    try:
        client.publish(TOPIC, json_data)
        print(f"Veröffentlicht: {json_data}")
    except Exception as e:
        print(f"Fehler beim Veröffentlichen: {e}")

    # Warte eine Sekunde
    time.sleep(1)
