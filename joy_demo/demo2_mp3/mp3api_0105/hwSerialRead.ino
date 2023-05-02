
void hwSerialRead()
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
  //{"uTest":123}
  if(s != "")
  {
    //Serial.println(s);
    
    handleNodeRed(s);
  }  
  
}
