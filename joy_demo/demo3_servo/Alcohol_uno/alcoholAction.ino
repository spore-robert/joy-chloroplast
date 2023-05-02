void testServo(Servo svo)
{
  
  alcholAction(svo,-1,-1,-1,-1);
  
}

void checkParams(int &nowTheta,int &newTheta,int &delayTime,int &repeat )
{
  if( nowTheta  < 90)
    nowTheta = 90;
  if( newTheta >120 || newTheta <0)
    newTheta = 120;
  if( delayTime < 0 )
    delayTime = 250;  
  if( repeat < 0)
    repeat = 3;
      
  
}

long ultrasonicSensor()
{
    long duration,distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);     
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1; 
    Serial.print("distance = ");
    Serial.println(distance);
    return distance;
  
  
}

int irSensor()
{
  int irState = digitalRead(irPin);
  Serial.print("irState=");
  Serial.println(irState);

  
  return irState;
}

void alcholAction(Servo svo , int nowTheta,int newTheta,int delayTime,int repeat)
{
  
  checkParams(nowTheta, newTheta, delayTime, repeat); 
  Serial.print("nowTheta, newTheta, delayTime, repeat:");
  Serial.print(nowTheta);
  Serial.print(",");
  Serial.print(newTheta);
  Serial.print(",");
  Serial.print(delayTime);
  Serial.print(",");
  Serial.println(repeat);
  for(int i  =0 ; i < repeat ; i++){
    svo.write(120);
    delay(delayTime);
    svo.write(90);
    delay(delayTime);
  }    
  
}
