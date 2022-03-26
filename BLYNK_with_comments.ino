#include <BlynkSimpleEsp8266.h>
char auth[] = "_yQXCJe2bHM09G8IcrhIcCvj2LE0eqQe"; //Device ID.
char ssid[] = "Ucom7072_2.4G"; //Wifi name
char pass[] = "159753gai498"; //Wifi password.

BLYNK_WRITE(V0) //We defined it from the BLYNK application. Virtual pin VO.
{
  int val = param.asInt(); //Initialize the variable val and make it equal to the received id as the INT.
  if(val == 1){ // As we receive the number one, it menas that we need to turn the light on, we send the message with the method digitalWrite(14,1)
    digitalWrite(14,1);
  }
  if(val == 0){  // As we receive the number 0, it menas that we need to turn the light off, we send the message with the method digitalWrite(14,0)
    digitalWrite(14,0);
  }
}


void setup() {
  // put your setup code here, to run once:

pinMode(14,OUTPUT) ;
Blynk.begin (auth,ssid,pass);
Serial.begin(9600);
}


  
void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}
