int replyPin5 = 5;
int btnPin2 = 3;
int btnPin2_state = 0;
int ledPin_g = 8;
int ledPin_r = 9;
int ledPin_y = 10;
void setup() {

  pinMode(replyPin5,OUTPUT);
  pinMode(btnPin2, INPUT);
  
  pinMode(ledPin_g,OUTPUT);
  pinMode(ledPin_r,OUTPUT);
  pinMode(ledPin_y,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 btnPin2_state = digitalRead(btnPin2);
 Serial.print("btnPin2_state = ");
 Serial.println(btnPin2_state);
 if(btnPin2_state == true)
 { 
 digitalWrite(replyPin5, HIGH);
 digitalWrite(ledPin_g, HIGH);
 delay(3000);
 
 }
 else
 {
 
   digitalWrite(replyPin5, LOW);
   digitalWrite(ledPin_g, LOW);
 }
 delay(100);
}
