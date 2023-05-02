void ledAlert(int state)
{
  //0,init
  //1.play music
  //2.pause
  //3.volumn
  //4.next
  //5.loop
  //6. receive esp8266 msg
  int cmdMap[6][3]={{3,3,50},
                    {2,3,100},
                    {5,1,50},
                    {3,2,50},
                    {1,3,100},
                    {1,1,50}};
  int blinkCount = cmdMap[state][0];
  int blinkNum = cmdMap[state][1];
  int blinkTime = cmdMap[state][2];

  for(int j = 0 ; j < 3 ;j++){
      digitalWrite(ledPin[j],LOW);
  }
  delay(50);
  for(int i = 0 ; i < blinkCount ; i++)
  {
      for(int j = 0 ; j < blinkNum ;j++){
        digitalWrite(ledPin[j],LOW);
      }
      delay(blinkTime);
      for(int j = 0 ; j < blinkNum ;j++){
        digitalWrite(ledPin[j],HIGH);
      }
      delay(blinkTime);
   
  }

}