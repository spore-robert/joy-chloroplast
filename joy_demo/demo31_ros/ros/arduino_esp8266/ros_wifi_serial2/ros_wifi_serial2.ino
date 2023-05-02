#include <ros.h>
#include <std_msgs/String.h>
#include "Arduino.h"
#include <SPI.h>

#include <Servo.h>
#include <ESP8266WiFi.h>
IPAddress server(192, 168, 1, 11);
WiFiClient client;

class WiFiHardware {

  public:
  WiFiHardware() {};

  void init() {
    // do your initialization here. this probably includes TCP server/client setup
    client.connect(server, 11411);
  }

  // read a byte from the serial port. -1 = failure
  int read() {
    // implement this method so that it reads a byte from the TCP connection and returns it
    //  you may return -1 is there is an error; for example if the TCP connection is not open
    return client.read();         //will return -1 when it will works
  }

  // write data to the connection to ROS
  void write(uint8_t* data, int length) {
    // implement this so that it takes the arguments and writes or prints them to the TCP connection
    for(int i=0; i<length; i++)
      client.write(data[i]);
  }

  // returns milliseconds since start of program
  unsigned long time() {
     return millis(); // easy; did this one for you
  }
};

Servo s;
int i;

void chatterCallback(const std_msgs::String& msg) {
//  i = atoi(msg.data);
    Serial.println(msg.data);
//  s.write(i);
}

char ssid[] = "spore";
char password[] = "033128882";
ros::Subscriber<std_msgs::String> sub("chatter", &chatterCallback);
ros::NodeHandle_<WiFiHardware> nh;
void setupWiFi()
{
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial.print("Could not connect to"); Serial.println(ssid);
    while(1) delay(500);
  }
  Serial.print("Ready! Use ");
  Serial.print(WiFi.localIP());
  Serial.println(" to access client");
}

void setup() {
Serial.begin(9600);
  delay(100);

  setupWiFi();
  //delay(2000);
  
  
  s.attach(9);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  delay(500);
}
