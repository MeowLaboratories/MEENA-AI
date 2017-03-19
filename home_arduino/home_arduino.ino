#include <SoftwareSerial.h>

SoftwareSerial BT(A0,A1); //rx,tx
SoftwareSerial HandSerial(A4,A5);

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
}

void loop()
{
  if ( BT.available() )
  {
    String ln = read_ln();
  
    Serial.println(ln);

    if(ln == "light on") digitalWrite(8,LOW);
    if(ln == "light off") digitalWrite(8,HIGH);
  }
  delay(100);
}


String read_ln() 
{
  String ln="";
  while(1 ) 
  {
    if(BT.available() ) {
      char ch=BT.read();
      if(ch=='#') 
        break;
       else
        ln=ln+ch;
    }
  }
  return ln;
}
