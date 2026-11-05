
/*
The customer enters a room full of mannequins. When they cross the door threshold, they break a small beam-break sensor at ankle-height.
The beam break sensor uses the NC/COM leads. So long as the sensor sees the light it's reflecting, the circuit is closed. The circuit becomes open when the light is interrupted.
The mannequin heads then heads swivel on servos, following the group as they move through the room. 
This is done by changing the servo angles after periodic delays. The Servo Arduino library is employed for this.

The code is linear and avoids function definitions/calls for easy field adjustments.
*/

#include <Servo.h>

//Declare servo objects
Servo doll1; //Doll 1 near room entrance
Servo doll2; //Shorter doll next to Doll1
Servo doll3; //Doll 3 is next to the actor dressed up as a doll. The actor roams freely.
Servo doll4; //Doll 4 is next to the wire shelf
Servo doll5; //Doll 5 is next to the speaker
Servo doll6; //Doll 6 is next to the actor dressed up as a doll


const int breakSensor=11; //Maps pin #11 to the state of the beam-break sensor


void setup() {
  doll1.attach(1); //Attach angular control for doll 1's neck to pin 1
  doll2.attach(2); //Attach angular control for doll 2's neck to pin 2
  doll3.attach(3); //Attach angular control for doll 3's neck to pin 3
  doll4.attach(4); //Attach angular control for doll 4's neck to pin 4
  doll5.attach(5); //Attach angular control for doll 5's neck to pin 5
  doll6.attach(6); //Attach angular control for doll 6's neck to pin 6
  pinMode(breakSensor, INPUT_PULLUP); //Declares pin 11 as a dry contact sensor whose digital state will read LOW when activated.
  
}

void loop() {
//Main function

//Assume start positions 
  doll1.write(60); //Sets the angle of doll 1's neck to 60 degrees
  doll2.write(70); //Sets the angle of doll 2's neck to 70 degrees
  doll3.write(40); //Sets the angle of doll 3's neck to 40 degrees
  doll4.write(30); //Sets the angle of doll 4's neck to 30 degrees
  doll5.write(140); //Sets the angle of doll 5's neck to 140 degrees
  doll6.write(70); //Sets the angle of doll 6's neck to 70 degrees
  

while (digitalRead(breakSensor) == HIGH) {
    // When the beam-break sensor has 100% of the light reflected back to it, the digital read is HIGH, or NOT TRIPPED, so this while loop runs forever. This is our idle state.
}

//If the beam break sensor can no longer detect its own light source, the while loop is broken, and the doll necks move.

delay(2000);

//Stare Position 1

  doll1.write(90);
  doll2.write(115);
  doll3.write(150);
  delay(1000);
  doll4.write(180);
  doll5.write(60);
  doll6.write(0);
  delay(2000);


//Stare Position 2
  doll1.write(70);  
  delay(1000);
  doll2.write(90);
  doll3.write(120);
  doll4.write(180);
  delay(1000);
  doll5.write(60);
  doll6.write(0);
  delay(1000);

//Stare Position 3

  doll1.write(50);
  doll2.write(60);
  delay(1000);
  doll3.write(80);
  doll4.write(180);
  delay(2000);
  doll5.write(100);
  doll6.write(30);
  delay(3000);


//Stare Position 4
  doll1.write(30);
  doll2.write(40);
  doll3.write(70);
  delay(1000);
  doll4.write(50);
  doll5.write(110);
  doll6.write(30);


  delay(10000); //Wait ten seconds, then reset back to starting positions.

}
