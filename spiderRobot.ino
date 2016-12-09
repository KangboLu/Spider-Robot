#include <Servo.h>

Servo servoBase1, servoBase2;

//Servo servoBases[4] = {servoBase1, servoBase2};  // create base servo object to control a servo

Servo servoLeg1, servoLeg2;  // create leg servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  servoBase1.attach(8);
  servoBase2.attach(7);  // attaches the servo on pin 7 to the servo object
  servoLeg1.attach(6); // attaches the servo on pin 6 to the servo object
  servoLeg2.attach(5);

  // hinge leg setup
  for (pos = 0; pos <= 130; pos++) { // goes from 0 degrees to  degrees
    // in steps of 1 degree
    servoLeg1.write(pos);              // tell servo to go to position in variable 'pos'
    servoLeg2.write(pos);
    delay(5);                       // waits 5ms for the servo to reach the position
  }
//  for (pos = 130; pos >= 0; pos--) { // goes from 45 degrees to 0 degrees
//    servoLeg.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 15ms for the servo to reach the position
//  }
}

void loop() {

// in
  baseLegIn(servoBase1); 
  hingeLegIn(servoLeg1);
  
  baseLegIn(servoBase2); 
  hingeLegIn(servoLeg2);

// out
  baseLegOut(servoBase1); 
  hingeLegOut(servoLeg1);
  
  baseLegOut(servoBase2); 
  hingeLegOut(servoLeg2); 
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


