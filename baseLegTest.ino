int servoPin = 7;
bool flag = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pulseTime = 1250; // miliseconds to pause
  
  if (flag) {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseTime);
    digitalWrite(servoPin, LOW);
  }

  flag = false;
  delay(25);
}
