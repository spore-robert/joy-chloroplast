#define PIN_AO 2
int relayPin = 7;
int ledPin =  11;

int buttonPin2 = 2; 
int buttonState2 = 0;
int buttonPin3 = 3; 
int buttonState3 = 0;
int button3Count =0;
int enableMotor=0;
int soilValue=0; 
void setup() {
  Serial.begin(9600); 
  pinMode(PIN_AO, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);  
  pinMode(relayPin, OUTPUT);
}


void loop() {
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  soilValue = analogRead(PIN_AO);

  Serial.print("AO="); 
  Serial.println(soilValue);
  if(buttonState3){
    button3Count = button3Count +1;
    button3Count = button3Count%2;
    if(button3Count ==1)
      enableMotor =1;
    else
      enableMotor =0;  
  }
  if(enableMotor == true){
    if(buttonState2){
      digitalWrite(relayPin,HIGH);
      digitalWrite(ledPin,HIGH);
      delay(1000);
    }
    else if(soilValue>900)
    {
      digitalWrite(relayPin,HIGH);
      digitalWrite(ledPin,HIGH);
      delay(1000);    
    }
    else if(soilValue>500)
    {
      digitalWrite(relayPin,HIGH);
      digitalWrite(ledPin,HIGH);
      delay(200);    
    }  
    else
    {
      digitalWrite(relayPin,LOW);
      digitalWrite(ledPin,LOW);
      
    }
  }
    delay(100);
}
