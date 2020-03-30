#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include "keys.h"

// Update these with values suitable for your network.

const char *mqtt_server = "192.168.1.183";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
String lastState = "";

void setup_wifi()
{

    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(WIFI_NAME);
    WiFi.hostname("Smart_TV");

    WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros());

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");

    payload[length] = '\0';
    String state = String((char *)payload);

    Serial.print(state);
    Serial.println();

    if (state == "ON" && lastState != "ON")
    {
        digitalWrite(2, LOW);
        delay(500);
        digitalWrite(2, HIGH);
        client.publish("home-assistant/theater/tv", "ON");
        lastState = "ON";
    }
    if (state == "OFF" && lastState != "OFF")
    {
        digitalWrite(2, LOW);
        delay(500);
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
        delay(500);
        digitalWrite(2, HIGH);
        client.publish("home-assistant/theater/tv", "OFF");
        lastState = "OFF";
    }
    
}

void reconnect()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Create a random client ID
        String clientId = "ESP8266Client-";
        clientId += String(random(0xffff), HEX);
        // Attempt to connect
        if (client.connect(clientId.c_str()))
        {
            Serial.println("connected");
            // Once connected, publish an announcement...
            client.publish("home-assistant/theater/tv/available", "online");
            // ... and resubscribe
            client.subscribe("home-assistant/theater/tv/set");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void setup()
{
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

void loop()
{

    if (!client.connected())
    {
        reconnect();
    }
    client.loop();

    unsigned long now = millis();
    if (now - lastMsg > 60000)
    {
        lastMsg = now;
        client.publish("home-assistant/theater/tv/available", "online");
    }
}