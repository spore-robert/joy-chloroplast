#include <ESP8266WiFi.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <Servo.h>
#define SPORE_MASTER
//////////////////////
// WiFi Definitions //
//////////////////////
//????
/*

*/
#ifdef SPORE_MASTER
const char* ssid = "spore";
const char* password = "033128882";
IPAddress server(192, 168, 1, 11); // ip of your ROS server
#else
const char* ssid = "spore-ros";
const char* password = "62148320";
IPAddress server(192, 168, 0, 101); // ip of your ROS server
#endif
IPAddress ip_address;
int status = WL_IDLE_STATUS;

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


int i;

int ledpin13 = 13;

int inPin5 = 5;
int outPin4 = 4;



void chatterCallback(const std_msgs::String& msg) {
  Serial.print("chatterCallback:");
  Serial.println(msg.data);
  digitalWrite(outPin4,HIGH);
  for(int i = 0 ;i <5 ; i++)
  {
     int m = i%2; 
     digitalWrite(ledpin13,m);
    delay(200);
  }
  digitalWrite(outPin4,LOW);
  
}
std_msgs::String str_msg;
ros::Subscriber<std_msgs::String> sub("joyTalk", &chatterCallback);
ros::Publisher chatPub("chatter", &str_msg);
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
  Serial.begin(115200);
  setupWiFi();
  delay(2000);
  pinMode(ledpin13,OUTPUT);
  pinMode(inPin5, INPUT);
  pinMode(outPin4, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(chatPub);
  digitalWrite(outPin4,LOW);
}

void loop() {
  if(digitalRead(inPin5))
  {
    Serial.println("pub msg:Detected");
    str_msg.data = "Detected";
    chatPub.publish( &str_msg );
    nh.spinOnce();
    delay(10000);
  }
  else
  {
    //Serial.println("inPin5 is LOW");
    nh.spinOnce();
  }
     
  delay(50);
}
