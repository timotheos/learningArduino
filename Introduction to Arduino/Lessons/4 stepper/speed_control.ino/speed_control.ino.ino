/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>
/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 150
int potUpperLimit = 48;
int potLowerLimit = 57;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper myStepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int stepCount = 0;

void setup() {
  // do nothing
}

int treatValue(int data) {
  return (data * 9 / 1024) + 48;
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(treatValue(sensorReading), potUpperLimit, potLowerLimit, 0, 130); // change first two valuvs
  // set the motor speed:
  if (motorSpeed > 75) {
    myStepper.setSpeed(motorSpeed - 75);
    // step 1/100 of a revolution:
    myStepper.step(STEPS / 100);
  }
  else if (motorSpeed < 70) {
    myStepper.setSpeed(70 - motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step( -STEPS / 100);
  }
  else {}
}
