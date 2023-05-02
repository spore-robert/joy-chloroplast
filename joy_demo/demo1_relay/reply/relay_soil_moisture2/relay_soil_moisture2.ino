#include "SoftwareSerial.h"
#include <ArduinoJson.h>//step 1
#define PIN_TX 11
#define PIN_RX 12
 
#define LOCAL_TEST

StaticJsonDocument<200> doc;//step 2


SoftwareSerial swSerial(PIN_RX , PIN_TX);//12 11

#define PIN_AO 0
int relayPin = 7;
int ledPin =  13;

int ledPin8 = 8;
int ledPin9 = 9;
int ledPin10 = 10;


int buttonPin2 = 2; 
int buttonState2 = 0;

int soilValue=0; 
bool bAuto = false;
int delayTime = 1000;

void setup() {
  Serial.begin(9600); 
  swSerial.begin(9600);
  pinMode(PIN_AO, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin8,OUTPUT);
  pinMode(ledPin9,OUTPUT);
  pinMode(ledPin10,OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(relayPin, OUTPUT);


}


void loop() {

  #ifdef LOCAL_TEST
   //{"auto":"on"} 
     hwSerialRead();
  #endif
  swSerialRead();
  soilValue = analogRead(PIN_AO);
  delay(100);

  buttonState2 = digitalRead(buttonPin2);
  if(buttonState2==1){
        digitalWrite(relayPin,HIGH);

        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,LOW);
        delay(1500);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(relayPin,LOW);
  
  }

  if(bAuto == true){
    
    

    Serial.print("AO="); 
    Serial.println(soilValue);
    


   
      
      if(soilValue>600)
      {
        digitalWrite(relayPin,HIGH);
        digitalWrite(ledPin,HIGH);
        delay(delayTime);    
        digitalWrite(relayPin,LOW);
        digitalWrite(ledPin,LOW);
      }
      else
      {
        digitalWrite(relayPin,LOW);
        digitalWrite(ledPin,LOW);
        
      }
      delay(100);
  }
}
