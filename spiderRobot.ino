#include <Servo.h>

// twelve servo objects can be created on most boards
Servo servoBase1, servoBase2, servoBase3, servoBase4; // create base servo object to control a servo

//Servo servoBases[4] = {servoBase1, servoBase2};  

Servo servoLeg1, servoLeg2, servoLeg3, servoLeg4;  // create leg servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  servoBase1.attach(10); // attaches the leg servo on pin 10 to the servo object--5
  servoBase2.attach(9); // attaches the leg servo on pin 9 to the servo object--4
  servoBase3.attach(8); // attaches the leg servo on pin 7 to the servo object--3
  servoBase4.attach(7); // attaches the leg servo on pin 6 to the servo object--2
  
  servoLeg1.attach(6);  // attaches the hinge ervo on pin 6 to the servo object
  servoLeg2.attach(5);  // attaches the hinge ervo on pin 5 to the servo object

  // base leg setup goes from 0 degrees to 50 degrees
//  for (pos = 10; pos <= 50; pos++) { 
//    // tell servo to go to position in variable 'pos' in steps of 1 degree
//    servoBase1.write(pos);             
//    servoBase2.write(pos);
//    servoBase3.write(pos);
//    servoBase4.write(pos);
//    
//    delay(4);                       // waits 4ms for the servo to reach the position
//  }
  
  // hinge leg setup
//  for (pos = 0; pos <= 130; pos++) { // goes from 0 degrees to  degrees
//    // in steps of 1 degree
//    servoLeg1.write(pos);              // tell servo to go to position in variable 'pos'
//    servoLeg2.write(pos);
//    delay(5);                       // waits 5ms for the servo to reach the position
//  }
//  for (pos = 130; pos >= 0; pos--) { // goes from 45 degrees to 0 degrees
//    servoLeg.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 15ms for the servo to reach the position
//  }
}

void loop() {
  baseLegIn(servoBase1); 
  hingeLegIn(servoLeg1);

  baseLegOut(servoBase1); 
  hingeLegOut(servoLeg1); 
}

//============================
//         BASE LEG          /
//============================

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
//         HINGE LEG         /
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
//       MOVEMENT          /
//==========================
void circular() {
  // move leg 1 & 3 in and out
//  baseLegIn(servoBase1); 
//  hingeLegIn(servoLeg1);
//
//  baseLegOut(servoBase1); 
//  hingeLegOut(servoLeg1);
//
//  baseLegIn(servoBase2); 
//  hingeLegIn(servoLeg2);
//
//  baseLegOut(servoBase2); 
//  hingeLegOut(servoLeg2);

  // move leg 2 & 4 in and out
  baseLegIn(servoBase3); 
//  hingeLegIn(servoLeg3);
//
  baseLegOut(servoBase3); 
//  hingeLegOut(servoLeg3); 
//
//  baseLegIn(servoBase4); 
//  hingeLegIn(servoLeg4);
//  
//  baseLegOut(servoBase4); 
//  hingeLegOut(servoLeg4); 
}
