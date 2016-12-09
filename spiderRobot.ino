#include <Servo.h>

Servo servoBase1;  // create base servo object to control a servo
Servo servoBase1;  // create base servo object to control a servo

Servo servoLeg;  // create leg servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  servoBase.attach(7);  // attaches the servo on pin 7 to the servo object
  servoLeg.attach(6); // attaches the servo on pin 6 to the servo object

  // hinge leg setup
  for (pos = 0; pos <= 130; pos++) { // goes from 0 degrees to  degrees
    // in steps of 1 degree
    servoLeg.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5ms for the servo to reach the position
  }
//  for (pos = 130; pos >= 0; pos--) { // goes from 45 degrees to 0 degrees
//    servoLeg.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 15ms for the servo to reach the position
//  }
}

void loop() {
  baseLegIn(servoBase); // move the base leg in
  hingeLegIn(servoLeg); // move the hinge leg in
  
  baseLegOut(servoBase); // move the base leg out
  hingeLegOut(servoLeg); // move the hinge leg out
}

//============================
//         BASE LEG          /
//============================

// function move the base leg in
void baseLegIn(Servo &base) {
  // goes from 0 degrees to 90 degrees in steps of 1 degree
  for (pos = 0; pos <= 90; pos++) { 
    // in steps of 1 degree
    base.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5ms for the servo to reach the position
  }
}

// function move the base leg out
void baseLegOut(Servo &base) {
  // goes from 90 degrees to 0 degrees in steps of 1 degree
  for (pos = 90; pos >= 0; pos--) { 
    base.write(pos);           // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5ms for the servo to reach the position
  }
}

//============================
//         HINGE LEG         /
//============================

// function move the hinge leg in
void hingeLegIn(Servo &hinge) {
  // goes from 0 degrees to 7 degrees in steps of 1 degree
  for (pos = 130; pos <= 140; pos++) {  
    hinge.write(pos);           // tell servo to go to position in variable 'pos'
    delay(3);                       // waits 5ms for the servo to reach the position
  }
}

// function move the hinge leg out
void hingeLegOut(Servo &hinge) {
  // goes from 7 degrees to 0 degrees in steps of 1 degree
  for (pos = 140; pos >= 90; pos--) {
    hinge.write(pos);           // tell servo to go to position in variable 'pos'
    delay(3);                       // waits 5ms for the servo to reach the position
  }
}


