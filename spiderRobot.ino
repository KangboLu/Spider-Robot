#include <Servo.h>
// twelve servo objects can be created on most boards
// try test individual servo first and then put other robot together
Servo servoBase1, servoBase2, servoBase3, servoBase4; // create base servo object to control a servo
Servo servoLeg1,  servoLeg2,  servoLeg3,  servoLeg4;  // create leg servo object to control a servo

int pos = 0;    // variable to store the servo position
int lightLevel; // light level reading variable
bool standing = 1; // storing the standing position

void setup() {
  // attach the base servo to specific pin to the servoBase object
  servoBase1.attach(10);
  servoBase2.attach(9);
  servoBase3.attach(8);
  servoBase4.attach(7);

  // attach the leg servo on specific pin to the servoLeg object
  servoLeg2.attach(6);
  servoLeg4.attach(5);
  servoLeg1.attach(4);
  servoLeg3.attach(3);

  // reset legs
  resetLegs();

  // sleep the mode
  //sleepMode();

  // reset again for testing
  //resetLegs();
  Serial.begin(9600); // establish serial connection
}

void loop() {
  // serial monitor with lightLevel reading
  lightLevel = analogRead(A0);
  Serial.print("light sensor value = ");
  Serial.print(lightLevel);
  Serial.println();

  // if loop to handle the sleep movement
  if (lightLevel > 300){
    if (standing != 0)
      sleepMode();
    standing = 0;  
  }
  // else statement to handle the movement
  else {
    if (!standing) {
      standing = 1;
      resetLegs(); 
      delay(500);
    }
    moveMode();
  }
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

//==========================
//       MOVEMENT          |
//==========================

void moveDownLeg(Servo &hinge, int side, int start, int finish) {
  // 2, 4 are 1; 1, 3 are 0
  if (side) {
    for (pos = start; pos >= finish; pos--) {
      // in steps of 1 degree
      hinge.write(pos);                // tell servo to go to position in variable 'pos'
      delay(6);                       // waits 5ms for the servo to reach the position
    }  
  } else {
    for (pos = start; pos <= finish; pos++) {
      // in steps of 1 degree
      hinge.write(pos);                // tell servo to go to position in variable 'pos'
      delay(6);                       // waits 5ms for the servo to reach the position
    }
  }
}

// move the robot down
void sleepMode() {
  servoBase1.write(180);
  servoBase2.write(0);
  servoBase3.write(180);
  servoBase4.write(0);

  moveDownLeg(servoLeg2, 1, 180, 100);
  moveDownLeg(servoLeg4, 1, 180, 100);
  moveDownLeg(servoLeg1, 0, 0, 80);
  moveDownLeg(servoLeg3, 0, 0, 80);
}

// move the robot
void moveMode() {
  // front movement
  servoBase3.write(160);
  delay(300);
  servoBase4.write(20);
  delay(300);
  servoBase3.write(180);
  delay(300);
  servoBase4.write(0);

  // back movement
  delay(300);
  servoBase1.write(160);
  delay(300);
  servoBase2.write(20);
  delay(300);
  servoBase1.write(180);
  delay(300);
  servoBase2.write(0);
  delay(300);
}
