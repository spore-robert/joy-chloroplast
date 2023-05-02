
#include "Arduino.h"
#include <ArduinoJson.h>//step 1
#include "SoftwareSerial.h"                    // 採用SoftwareSerial程式庫
#include "DFRobotDFPlayerMini.h"        // 採用DFRobotDFPlayerMini程式庫
#define LOCAL_TEST
#define PIN_TX 11
#define PIN_RX 12
bool bAuto = true;
SoftwareSerial mySoftwareSerial(2, 3);
StaticJsonDocument<200> doc;//step 2
 
//SoftwareSerial swSerial(PIN_RX , PIN_TX);//11 10

DFRobotDFPlayerMini myDFPlayer;         //宣告MP3 Player
void printDetail(uint8_t type, int value);  //印出詳情
int io1Pin =8;
int io2Pin =9;
int io3Pin =10;
int ledPin[3]={8,9,10};
int btnPin=5;
int irPin =12;
uint8_t iVolume = 20;
int playState = 0;

void setup() {
    for(int i = 0 ; i < 3 ; i++)
    {
        pinMode(ledPin[i],OUTPUT);
        digitalWrite(ledPin[i],HIGH);
    }
    pinMode(btnPin,INPUT);
    pinMode(irPin,INPUT);

    Serial.begin(9600);                 // 定義Serial傳輸速率9600bps
    delay(100);
    
      

   
    mySoftwareSerial.begin(9600);  // 定義mySoftwareSerial傳輸速率9600bps, DFPlayerMini的通訊速率為9600bps.

    //Serial.println(F("DFRobot DFPlayer Mini Demo"));   // 印出DFRobot DFPlayer Mini Demo字串到Serial通訊埠
    //Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));    // 以下用法依此類通, 不再贅述喔
    delay(2000);
    while (!myDFPlayer.begin(mySoftwareSerial))                 // 如果DFPlayer Mini回應不正確.
    {  //Use softwareSerial to communicate with mp3.   // 印出下面3行字串
      //  Serial.println(F("Unable to begin:"));                      // 然後程式卡死.
      //  Serial.println(F("1.Please recheck the connection!"));
      //  Serial.println(F("2.Please insert the SD card!"));
        ledAlert(0);
        
        delay(1000);                                   
    } 
    playState =1;
    //Serial.println(F("DFPlayer Mini online."));  // 如果DFPlayer Mini回應正確.印出"DFPlayer Mini online."
    //swSerial.println("hello");
    myDFPlayer.volume(iVolume);
    myDFPlayer.play(1);  // 播放第1首音樂
    playState =2;
    
    delay(3000);
    myDFPlayer.pause(); 
    delay(3000);
    myDFPlayer.start(); 
    
    
    
   
   
  
   
   
   //Serial.println("setup");
}

void loop() {

   //{"uTest":123} 
    hwSerialRead();
    int btnState = digitalRead(btnPin);
    int irState = digitalRead(irPin);
    int Resistance =analogRead(A0);
    int newVolume = map(Resistance, 0, 1024, 10, 25);
    if(newVolume != iVolume)
    {
      iVolume =newVolume;
      myDFPlayer.volume(iVolume);
    }
    
    if(btnState == 1)
    {
      if(playState ==1){
        myDFPlayer.play(1);
        playState =2;
      }
      else if(playState ==2){
         myDFPlayer.pause();
         playState =3;
      }
      else if(playState ==3){
        myDFPlayer.start();
        playState =2;
      }

      delay(100);

    }

    if (irState == 0){


    }

    else if(irState == 1){
     if(playState ==1){
        myDFPlayer.play(1);
        playState =2;
      }
    }
    
    Serial.print("btnPin,irState ,newVolume: ");
    Serial.print(btnState);
    Serial.print(" , ");
    Serial.println(irState);
    Serial.print(" , ");
    Serial.println(newVolume);
    delay(500);
//  swSerialRead();
  delay(100);
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }

}

void printDetail(uint8_t type, int value){
  playState = 0;
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
  
}
