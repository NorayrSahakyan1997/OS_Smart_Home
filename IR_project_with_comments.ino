
#include <IRremote.h> //Library which allows us to communicate from our devise to arduino board.
int RECV_PIN = 3;  // Send the sign to the 3 deod(receiver).We power the 3-rd pin.
int led1 = 13; //
int val = 0;
//red

#define code1 0x538BC81 //The hashing code we generate from remote controller program, as we get them we can use the codes for creating bond among the reomte and the application.

IRrecv irrecv(RECV_PIN); //Here we mention which kind of signal we want to receive.
decode_results results; // As we receive the code we setup/.
void setup(){
 
irrecv.enableIRIn(); 
pinMode(led1, OUTPUT);
Serial.begin(9600);
}
void loop() {
  
 
if (irrecv.decode(&results)) { //
unsigned int value = results.value;
Serial.println(value); //Print the receiving value, for checking whether we receive the desired one and compare.
switch(value) { //If our code 1 compares with the value and they are equal it starts doing the below code .
case code1:
if(val == 0){ //If val equals 0 it means that our LID is swithed off, so the program needs to turn the LED on.
digitalWrite(led1,1);
val = 1; //As we switch on the light, we make our variable false in this case 1, for the next time for turning off the light.
}

else if(val == 1){ //If this block works, it means that our LID is on, we need to switch of the light.
digitalWrite(led1,0);
val = 0;
}
Serial.println(val);
break; 

delay(50); //Delay is the thread function , which makes our application sleep for 50 miliseconds, which is equal to 1/50 second.


}
irrecv.resume();
}
}
