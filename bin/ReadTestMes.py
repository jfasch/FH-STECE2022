import json
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import paho.mqtt.client as mqtt

# Setze das Backend auf TkAgg
matplotlib.use("TkAgg")

# MQTT-Konfiguration
MQTT_BROKER = "172.30.60.112" #--> IP Thomas "localhost"
MQTT_PORT = 1883
MQTT_TOPIC = "DistanceData"

# Globale Variable für die Distanz
current_distance = 0

# Callback-Funktion für eingehende Nachrichten
def on_message(client, userdata, message):
    global current_distance
    try:
        payload = message.payload.decode("utf-8")
        data = json.loads(payload)
        current_distance = data["Data"]["Distance"]
    except (json.JSONDecodeError, KeyError) as e:
        print(f"Fehler beim Verarbeiten der Nachricht: {e}")

# MQTT-Client konfigurieren
client = mqtt.Client(protocol=mqtt.MQTTv311)
client.on_message = on_message
client.connect(MQTT_BROKER, MQTT_PORT)
client.subscribe(MQTT_TOPIC)
client.loop_start()

# Matplotlib-Setup
fig, ax = plt.subplots()
bar = ax.barh(["Distance"], [0], color="blue")
ax.set_xlim(0, 1000)  # Initiale Achsenskala

# Animationsfunktion
def update(frame):
    global current_distance
    bar[0].set_width(current_distance)
    ax.set_xlim(0, max(current_distance * 1.1, 1000))

# Animation starten
ani = FuncAnimation(fig, update, interval=500, cache_frame_data=False)
anim = ani  # Animation nicht vorzeitig löschen
plt.xlabel("Distance")
plt.title("Dynamischer Balken basierend auf MQTT-Daten")
plt.show()

# MQTT-Client stoppen
client.loop_stop()
client.disconnect()
