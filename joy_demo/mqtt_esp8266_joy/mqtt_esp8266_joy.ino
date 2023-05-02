
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <SoftwareSerial.h>
#define RX_PIN 5
#define TX_PIN 4
SoftwareSerial mySerial(RX_PIN, TX_PIN);

//Joy modify start,????
#define joy_home
#ifdef joy_home
const char* ssid = "";
const char* password = "";//home ap password
const char* mqtt_server = "172.10.2.1";//mac in home ip
#else
const char* ssid = "spore_24G";
const char* password = "033128882";
const char* mqtt_server = "192.168.1.32";

#endif



WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;
int ledPin = BUILTIN_LED;

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
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
void ledBlink()
{
  for(int i = 0 ; i < 3 ; i++)
  {
    digitalWrite(ledPin,HIGH);
    delay(50);
    digitalWrite(ledPin,LOW);
    delay(50);

  }
}
void callback(char* topic, byte* payload, unsigned int length) {
  ledBlink();
  String recv_payload="";//joy
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    recv_payload = recv_payload +(char)payload[i];
  }
  mySerial.println(recv_payload);


  Serial.println();
  


  /*
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   
  
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  
  }
  */

}

void reconnect() {
 
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      
      client.publish("outTopic", "hello world");//????
      
      client.subscribe("node_red/cmd");//????
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      
      delay(5000);
    }
  }
}
void swSerialWrite()
{
  String s="";
  while (Serial.available()) {
      char data = Serial.read();
      if(data != '\r' || data != '\n')
      {
        s.concat(data);
        delay(5);
      }
  }
  if(s != "")
  {

    mySerial.println(s);
  }

}


void swSerialRead()
{
  String s="";
  while (mySerial.available()) {
      char data = mySerial.read();
      if(data != '\r' || data != '\n')
      {
        s.concat(data);
        delay(5);
      }
  }
  if(s != "")
  {

    Serial.println(s);
    int str_len = s.length(); 
    s.toCharArray(msg, str_len);
    client.publish("esp8266/respond", msg);//????
  }

}
void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

   
   mySerial.begin(9600);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  swSerialRead();
  delay(50);
  /*
  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);//????
  }
  */
}
