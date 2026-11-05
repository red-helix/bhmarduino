
#include <Servo.h>

/*This is from the Town Hall Room in 2026. Three mannequins sit in a row of pews. 
When the customer enters the room, they trip a beam-break sensor which causes the mannequins to slowly rock forward and backward.
With the doll heads, we achieve the 'jerkiness' by simply sending angle instructions to the servo motors. Here, we want a slower 'panning' effect.

For loops are employed to do this, with minimum and maximum angles. 
  The maximum angle reflects how far the mannequins will lurch forward. 
  The minimum angle reflects the mannequin sitting upright.

This rocking motion occurs 5 times when the sensor is tripped, then the mannequins return to an idle state. 
They *could* run on a continuous loop, but 12V servos were needed to make this work, and they run hot when in continuous use. Better to run sparingly.
*/


Servo myServo1;
Servo myServo2;
Servo myServo3;
const int buttonPin = 8;


void setup() {
  myServo1.attach(5);
  myServo2.attach(4);
  myServo3.attach(3);
 
  pinMode(buttonPin, INPUT_PULLUP); //Maps beam break sensor to pin #8, establishes it as a dry contact sensor in a Normally Open configuration.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
 

  myServo1.write(90); //start position: Old man in back row
  myServo2.write(90); //start position: Woman in middle row
  myServo3.write(90); //start position: Woman in front row

}

void loop() {
  
  
  int sensorState = digitalRead(buttonPin);
  Serial.println(sensorState); //Wiring the beam-break sensor in this room was a PITA, so serial output to track the sensor state.


  if (sensorState == LOW) { //Beam break sensor is tripped
    Serial.println("Program Active");
    int cycles=0;
    
    while (cycles<5) {
    
    digitalWrite(LED_BUILTIN, HIGH); //Energize  the Arduino's onboard yellow LED, so you can see when the program is active.
    

    for (int sway = 90; sway <= 130; sway++) {
      myServo1.write(sway);
      myServo2.write(sway);
      myServo3.write(sway);
      delay(67);  // 8000 ms / 30 degrees ≈ 267 ms per degree
  }

  // Pause at 130 degrees
  delay(1000);

  // Slowly pan back from 120 to 90 over approximately 8 seconds
  for (int pos = 130; pos >= 90; pos--) {
    myServo1.write(pos);
    myServo2.write(pos);
    myServo3.write(pos);
    delay(67);
  }

  cycles++; //Iterate cycles until it reaches 5, which stops the program.
  }

}
digitalWrite(LED_BUILTIN, LOW); //Turn off the Arduino's onboard yellow LED, indicating the mannequins should be idle.
Serial.println("Program Complete");
//sensorState = 100;

}
