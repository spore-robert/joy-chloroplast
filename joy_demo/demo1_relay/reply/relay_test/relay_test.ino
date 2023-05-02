int relayPin = 7;
int ledPin =  11;
int buttonPin2 = 2; 
int buttonState2 = 0; 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(relayPin, OUTPUT);
}


void loop() {
  buttonState2 = digitalRead(buttonPin2);
  if(buttonState2){
    digitalWrite(relayPin,HIGH);
    digitalWrite(ledPin,HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(relayPin,LOW);
    digitalWrite(ledPin,LOW);
    
  }
    delay(100);
}
