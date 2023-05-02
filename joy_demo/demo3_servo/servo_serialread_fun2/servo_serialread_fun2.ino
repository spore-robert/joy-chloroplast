#include <Servo.h>  
#define PIN_SERVO 6  
Servo myservo;  
int irPin = 7;
int trigPin = 9;
int echoPin = 8;
int outPin12 = 12;
int inPin11 = 11;
long duration, cm, inches;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(PIN_SERVO); 
  Serial.begin(9600);
  pinMode(irPin,INPUT);

  myservo.write(90);
  pinMode(trigPin, OUTPUT);        
  pinMode(echoPin, INPUT);
  pinMode(outPin12, OUTPUT);        
  pinMode(inPin11, INPUT);

  digitalWrite(outPin12 , LOW);
  
   
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);     
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1; 
  Serial.print("cm = ");
  Serial.println(cm);
  String s;
  while(Serial.available())
  {
    char c = Serial.read();
    if(c!="\n")
    {
      s=s+c;
    } 
    delay(5); 

    
  }
  if(s!="")
  {
    Serial.println(s);
    myservo.write(s.toInt());
  }
  
  int bState = digitalRead(irPin);
  int bROSinput = digitalRead(inPin11);
  Serial.print("ir=");
  Serial.println(bState);
  if(bState==LOW || cm <50)
  {
    digitalWrite(outPin12 , HIGH);
    for(int i  =0 ; i < 3 ; i++){
      myservo.write(120);
      delay(250);
      myservo.write(90);
      delay(250);
    }
    digitalWrite(outPin12 , LOW);
  
  }
  else if(bROSinput)
  {
    for(int i  =0 ; i < 3 ; i++){
      myservo.write(120);
      delay(250);
      myservo.write(90);
      delay(250);
    }
    Serial.println("ros publish");
    
  }
  else
  {
    //digitalWrite(outPin12 , LOW);
  }

  
  
 
  
}
