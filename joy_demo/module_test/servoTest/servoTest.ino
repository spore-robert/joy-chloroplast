#include <Servo.h>
#define PIN_SERVO 6

Servo myservo;  

void serialRead()
{
  
  String s;
  while(Serial.available())
  {
    char c = Serial.read();
    if(c!='\n')
    {
      s=s+c;
    } 
    delay(5); 

    
  }
  if(s!="")
  {
    Serial.println(s);
    if(s[0] == 'f')
    {
      
      for(int i  =0 ; i < 3 ; i++){
      myservo.write(130);
      delay(250);
      myservo.write(93);
      delay(250);
    }
    }
    else
    {
      myservo.write(s.toInt());
    }
  }  
  
}
void setup() {
  // put your setup code here, to run once:
  myservo.attach(PIN_SERVO);
  Serial.begin(9600);
  Serial.println("setup");
  Serial.print("servo :");
  Serial.println(myservo.read());
 // myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  serialRead();
  delay(50);

}
