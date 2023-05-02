void handleNodeRed(String payload){
  deserializeJson( doc, payload);//step 3
  
  
  Serial.print("doc[uTest]");
  String uTest = doc["uTest"];
  Serial.println(uTest);
  if(uTest != "null")
  {
   
  }
  else 
  {
      /*
    {
      action:{
        "relay":"on",
        "delay":200      
      }
      ,
      "auto":"on",
      "getSoilValue":"on"
      "{"waterInject":1500}"
      
  
    }
    */
    String jAuto = doc["auto"];
    String getSoilValue = doc["getSoilValue"];
    if(jAuto =="on")
    {
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        bAuto = true;
    }
    else if(jAuto == "off")
    {
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(relayPin,LOW);
        digitalWrite(ledPin,LOW);
        bAuto = false;
    }
    String jRelay = doc["action"]["relay"];
    String jDelay = doc["action"]["delay"];
    if(jRelay =="on")
    {
        digitalWrite(relayPin,HIGH);
        digitalWrite(ledPin,HIGH);

    }
    else if(jRelay =="off")
    {
      digitalWrite(relayPin,LOW);
      digitalWrite(ledPin,LOW);
    }
    if(jDelay !="null")
    {
      delayTime = jDelay.toInt();
    }
    
    //soilValue
    if(getSoilValue == "on")
    {


      swSerial.println(soilValue);
    }
     int  injectTime = doc["waterInject"];
     if(injectTime != 0){
        digitalWrite(relayPin,HIGH);

        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,LOW);
        delay(injectTime);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(relayPin,LOW);
  
  }
   
  }
}
