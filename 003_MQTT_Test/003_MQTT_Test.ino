#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "SuchiHome";
const char* password = "Suchi1027!";
const char* mqtt_server = "broker.hivemq.com";
const int greenLED= 27;
const int redLED= 12;
const int yellowLED= 14;

#define mqtt_port 1883
#define MQTT_USER ""
#define MQTT_PASSWORD ""

String MQTT_SERIAL_PUBLISH_CH = "/myIoT/led/";
String MQTT_SERIAL_RECEIVER_CH = "/myIoT/led/";
String LEDs[3] = { "red/", "green/", "yellow/" };
WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup_wifi() {
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    randomSeed(micros());
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "treelife-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(),MQTT_USER,MQTT_PASSWORD)) {
      Serial.println("connected");
      //Once connected, publish an announcement...
      for(int i =0; i<3; i++){
        String Temp = MQTT_SERIAL_PUBLISH_CH +LEDs[i];
        const char * Title = Temp.c_str();
        client.publish(Title, "{status: off}");
        client.subscribe(Title);  
      }
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte *payload, unsigned int length) {
    //print recevied messages on the serial console
    Serial.println("-------new message from broker-----");
    Serial.print("channel:");
    Serial.println(topic);
    Serial.print("data:");  
    Serial.write(payload, length);
    Serial.println();
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, payload);
    // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  
  const String ledStatus = doc["status"];
  Serial.print("Status :");
  Serial.print(ledStatus);
  String Topic = (String) topic;
  if(Topic.equals("/myIoT/led/red/") ){
    if(ledStatus.equals("on")) { digitalWrite(redLED, HIGH); } else {digitalWrite(redLED, LOW); }
  }
  if(Topic == "/myIoT/led/green/"){
    if(ledStatus == "on") {digitalWrite(greenLED, HIGH); }else {digitalWrite(greenLED, LOW); }
  }
  if(Topic == "/myIoT/led/yellow/"){
    if(ledStatus == "on") {digitalWrite(yellowLED, HIGH); }else {digitalWrite(yellowLED, LOW);} 
  } 
  
}


void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(500);// Set time out for   
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  reconnect();
}

void loop() {
   client.loop();
 }
