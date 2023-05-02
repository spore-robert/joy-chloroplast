#include <Servo.h>  
#include "SoftwareSerial.h"
#include <ArduinoJson.h>//step 1
#include <DHT.h>
#define PIN_TX 10
#define PIN_RX 11
#define PIN_SERVO 6  
#define LOCAL_TEST

StaticJsonDocument<200> doc;//step 2

Servo svo;  
SoftwareSerial swSerial(PIN_RX , PIN_TX);//12 11
int irPin = 7;
int trigPin = 9;
int echoPin = 8;
int ledPin = 13;
#define DHTPIN 2          // 定義DHT11數據輸出引腳為2
#define DHTTYPE DHT11     // 定義使用DHT11型號
DHT dht(DHTPIN, DHTTYPE); // 初始化DHT11


long duration, cm, inches;
bool bAuto = true;

void setup() {

  pinMode(ledPin, OUTPUT);  
  svo.attach(PIN_SERVO); 
  Serial.begin(9600);
  swSerial.begin(9600);
  pinMode(irPin,INPUT);
  pinMode(trigPin, OUTPUT);        
  pinMode(echoPin, INPUT);

  //testServo(svo);
  dht.begin();            // 初始化DHT11
   
}



void loop() {

  #ifdef LOCAL_TEST
   //{"uTest":123} 
     hwSerialRead();
  #endif
  swSerialRead();

  if(bAuto)
  {
    
    cm = ultrasonicSensor();
      
    int bState = irSensor();
    //int bROSinput = digitalRead(inPin11);
    
    if(bState==LOW || cm <50)
    {
      for(int i  =0 ; i < 3 ; i++){
        svo.write(120);
        delay(25);
        svo.write(90);
        delay(25);
      }    
    
    }
    
  }
  /*
  float humidity = dht.readHumidity();   // 讀取濕度值
  float temperature = dht.readTemperature(); // 讀取溫度值

  Serial.print("Humidity: ");   // 顯示濕度值
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: "); // 顯示溫度值
  Serial.print(temperature);
  Serial.println("°C");
*/

  delay(50);

  


  
}
