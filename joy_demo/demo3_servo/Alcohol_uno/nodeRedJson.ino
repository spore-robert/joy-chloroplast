void handleNodeRed(String payload){
  deserializeJson( doc, payload);//step 3
  
  
  Serial.print("doc[uTest]");
  String uTest = doc["uTest"];
  Serial.println(uTest);
  if(uTest != "null")
  {
    /*
    //nowTheta,int newTheta,int delayTime,int repeat
    String nowTheta = doc["uTest"]["nowTheta"];
    String newTheta = doc["uTest"]["newTheta"];
    String delayTime = doc["uTest"]["delayTime"];
    String repeat = doc["uTest"]["repeat"];
    testServo(svo ,nowTheta.toInt(),newTheta.toInt(),delayTime.toInt(),repeat.toInt());
    */
    testServo(svo);
  }
  else 
  {

    /*
    {
      "servo1":90
      "led":"on",
      '"motor":30,
      "ledRepeat":
        {
          "delay":500,
          "count":3
        }
        "servoSmooth":
        {
          "theta":90,
          "delay":25,
          "count":5
        }
        "auto":"on"
  
    }
  
    */
    String servo1 = doc["servo1"];
    String led = doc["led"];//step 4
    String sDelay = doc["ledRepeat"]["delay"];
    String count = doc["ledRepeat"]["count"];
  
    
    String svoTheta = doc["servoSmooth"]["theta"];
    String svoDelay = doc["servoSmooth"]["delay"];
    String svoCount = doc["servoSmooth"]["count"];
    String uTest = doc["uTest"];
    String strAuto = doc["auto"];
    
    
    
    int iDelay = sDelay.toInt ();
    int iCount = count.toInt ();
    int iTheta = servo1.toInt();
    int iSvoTheta = svoTheta.toInt();
    int iSvoDelay = svoDelay.toInt();
    
    String getTempValue = doc["getTempValue"];
    if(strAuto != "null")//{"auto":"false"}
    {
      if(strAuto == "on")
        bAuto = true;
      else if(strAuto == "off")
        bAuto = false;
    }
    //get temperature    
    if(getTempValue == "on")
    {
      float humidity = dht.readHumidity();   // 讀取濕度值
      float temperature = dht.readTemperature(); // 讀取溫度值
      char buffer1[10], buffer2[10]; 
      dtostrf(humidity, 5, 2, buffer1);
      dtostrf(temperature, 5, 2, buffer2);
      String strHumidity = buffer1;  
      String strTemperature= buffer1;  
      String data = strHumidity+","+strTemperature;
      swSerial.println(data);

      

    }
  
    if(servo1 != "null"){
      svo.write(iTheta);
    }
  
    if(led=="on"){
    digitalWrite(ledPin, HIGH);  
    }
    else if (led=="off"){
      digitalWrite(ledPin, LOW); 
    }
    
    String sLedRepeat = doc["ledRepeat"];
    if(sLedRepeat != "null"){

      for(int i =0 ; i<iCount ; i++){

      
        digitalWrite(ledPin, LOW); 
        delay(iDelay);
        digitalWrite(ledPin, HIGH);
        delay(iDelay);
        
        }  
    }  
  
  //servo control 
    String seoAction = doc["servoSmooth"] ;
    if(seoAction!= "null")
    {
      //alcholAction(Servo svo , int nowTheta,int newTheta,int delayTime,int repeat)
        
      
        Serial.print("delayTime,repeat:");
        Serial.print(svoDelay.toInt());
        Serial.print(",");
        Serial.println(svoCount.toInt());
        
        alcholAction(svo,-1,-1,svoDelay.toInt(),svoCount.toInt());

    }
  }
}
