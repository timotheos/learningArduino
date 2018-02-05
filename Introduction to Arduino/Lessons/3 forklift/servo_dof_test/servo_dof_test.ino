#include <Servo.h>

Servo myServo;
int iterations = 1;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(4);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int pos = 160; // change this for testing values 

  while(pos >= 0) {
    Serial.print("Degrees now: ");
    Serial.print(pos);
    Serial.print("\n");

    myServo.write(pos);
    delay(2000);
    myServo.write(0);
    delay(1000);
    pos = pos - 10;
  }
}

