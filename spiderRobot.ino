#include <Servo.h>
// twelve servo objects can be created on most boards

Servo servoBase1, servoBase2, servoBase3, servoBase4; // create base servo object to control a servo
Servo servoLeg1,  servoLeg2,  servoLeg3,  servoLeg4;  // create leg servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  // attaches the leg servo on specific pin to the servoBase object
  servoBase1.attach(10);
  servoBase2.attach(9);
  servoBase3.attach(8);
  servoBase4.attach(7);

  // attaches the hinge servo on specific pin to the servoLeg object
  servoLeg2.attach(6);
  servoLeg4.attach(5);
  servoLeg1.attach(4);  
  servoLeg3.attach(3);

  // reset legs
  resetLegs();
}

void loop() {
    
}

//=======================
//       TESTING        |
//=======================
void resetLegs() {
 /// testing
  servoBase1.write(180);
  servoBase2.write(0);
  servoBase3.write(180);
  servoBase4.write(0);
  
  servoLeg2.write(180);
  servoLeg4.write(180);
  servoLeg1.write(0);  
  servoLeg3.write(0);
}

// ============================
//|         BASE LEG          |
// ============================

// function move the base leg in
void baseLegIn(Servo &base) {
  // goes from 0 degrees to 50 degrees in steps of 1 degree
  for (pos = 40; pos <= 80; pos++) { 
    // in steps of 1 degree
    base.write(pos);                // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 5ms for the servo to reach the position
  }
}

// function move the base leg out
void baseLegOut(Servo &base) {
  // goes from 50 degrees to 0 degrees in steps of 1 degree
  for (pos = 80; pos >= 40; pos--) { 
    base.write(pos);                // tell servo to go to position in variable 'pos'
    delay(6);                       // waits 5ms for the servo to reach the position
  }
}

//============================
//         HINGE LEG         |
//============================

// function move the hinge leg in
void hingeLegIn(Servo &hinge) {
  // goes from podition 130 to 140 degree in steps of 1 degree
  for (pos = 0; pos <= 40; pos++) {  
    hinge.write(pos);               // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5ms for the servo to reach the position
  }
}

// function move the hinge leg out
void hingeLegOut(Servo &hinge) {
  // goes from position 140 to 90 degrees in steps of 1 degree
  for (pos = 40; pos >= 0; pos--) {
    hinge.write(pos);               // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5ms for the servo to reach the position
  }
}

//==========================
//       MOVEMENT          |
//==========================
void circular() {
  
}

void forward() {
  
}

void backward() {
  
}
