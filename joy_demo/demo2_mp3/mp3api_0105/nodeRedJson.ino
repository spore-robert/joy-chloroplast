
     /*
    {
      action:{
        "relay":"on",
        "delay":200      
      }
      ,
      "auto":"on",
      "volume":20,
      "action":"play",//pause,next,preview,resume
      "loop":"on"
      

      
      // /
      
  
    }
    */
void actionHandle(String action)
{
   if(action == "play")
    {
        ledAlert(1);
        myDFPlayer.play(1);
        playState =2;
    }
    else if(action == "pause")
    {
        ledAlert(2);
        myDFPlayer.pause();
        playState =3;
    }
    else if(action == "next")
    {
        ledAlert(3);
        myDFPlayer.next();
        playState =2;

    }
    else if(action == "previous")
    {
        ledAlert(3);
        myDFPlayer.previous();
        playState =2;
    }
    else if(action == "resume")
    {
      myDFPlayer.start();
    }
    else if(action == "resume")
    {
      myDFPlayer.start();
    }
    else if(action == "loopOne")
    {
      int number = myDFPlayer.readCurrentFileNumber();
      myDFPlayer.loop(number);
    }



}

void handleNodeRed(String payload){
  deserializeJson( doc, payload);//step 3
  
  
  //Serial.print("doc[uTest]");
  String uTest = doc["uTest"];
  //Serial.println(uTest);
  if(uTest != "null")
  {
   
  }
  else 
  {
 
    String jAuto = doc["auto"];
    String action = doc["action"];
    uint8_t volume = doc["volume"];
    /*
    Serial.print("action:");
    Serial.println(action);
    
    Serial.print("volumn:");
    Serial.println(volume);
    */
    if(action !="null")
    {
      actionHandle(action);
    }
    if(volume !=0)
    {
        ledAlert(4);
        myDFPlayer.volume(volume);

    }
   
    if(jAuto =="on")
    {
 
        bAuto = true;
    }
    else if(jAuto == "off")
    {
 
        bAuto = false;
    }
    String jRelay = doc["action"]["relay"];
    String jDelay = doc["action"]["delay"];
    if(jRelay =="on")
    {
 

    }
    else if(jRelay =="off")
    {
 
    }
    if(action !="null")
    {
      
      //delayTime = jDelay.toInt();
    }
    
    //soilValue
    /*
    if(getSoilValue == "on")
    {


      //swSerial.println(soilValue);
    }
    */
   
  }
}
