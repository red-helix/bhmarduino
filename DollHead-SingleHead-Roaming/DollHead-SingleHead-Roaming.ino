
#include <Servo.h>

//Declare servo objects
Servo doll1; 

void setup() {
  doll1.attach(3); //Attach angular control for doll 1's neck to pin 1
  
}

void loop() {
//Main function

//Assume start positions 
  doll1.write(90); //Sets the angle of doll 1's neck to 60 degrees
  
delay(12000);

//Stare Position 1

  doll1.write(130);
  delay(12000);



//Stare Position 2
  doll1.write(70);  
  delay(15000);

  
//Stare Position 3

  doll1.write(30);
  delay(10000);

//Stare Position 4
  doll1.write(130);
  
  delay(10000); //Wait ten seconds, then reset back to starting positions.

}
