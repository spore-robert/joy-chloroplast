
void swSerialRead()
{
  
  String s;
  while(swSerial.available())
  {
    char c = swSerial.read();
    if(c!='\n')
    {
      s=s+c;
    } 
    delay(5); 

    
  }
  if(s!="")
  {
    Serial.println(s);
 
    handleNodeRed(s);
  }  
  
}
