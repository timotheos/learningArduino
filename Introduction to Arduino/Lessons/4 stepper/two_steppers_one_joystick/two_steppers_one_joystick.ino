/*
Dual Stepper Motor Control (Arduino UNO R3)
Controls the speed and direction of two stepper motors
via two analog inputs. Used to achieve two-dimensional
movement controlled by a joystick. End-of-track sensors
prevent damage to the structure and motors.
Based on "Speed Control" example of the Stepper lib.
Please note the Stepper library produces a bipolar sequence.
By swapping the two middle cables, a unipolar seq. is obtained.
By Eduardo Rivas, David Escobar y Ángel Moreno
for Universidad Don Bosco of El Salvador, 2013.
 */

#include <Stepper.h>

// Set steps per revolution
const int PPR = 200;

// Motor Y in pins 10-13
Stepper motor1(PPR, 10,11,12,13);
// Motor X in pins 6-9
Stepper motor2(PPR, 6,7,8,9);

void setup() {
  // Pins 2-5 set up as inputs with pullup resistors. Sensors are active-low.
  for (int i = 2; i <= 5; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  int speed_max = 30;

  // MOTOR 1 CONTROL Y
  int speed_1 = 0;
  int direction_1 = 1;
  // Get joystick position on A1
  int position_1 = analogRead(1);
  // joystick trigger positions
  int forwardLimit = 1, forwardTrigger = 20;
  // idle_1 = 38;
  int backwardTrigger = 100, backwardLimit = 570;
  int triggerValues_1[] = { forwardLimit, forwardTrigger, backwardTrigger, backwardLimit };


  if (position_1 > backwardTrigger and digitalRead(2) == HIGH) {
    speed_1 = map(position_1, backwardTrigger, backwardLimit, 0, speed_max);
    direction_1 = -1;
  }

  if (position_1 < forwardTrigger and digitalRead(3) == HIGH) {
    speed_1 = map(position_1, forwardLimit, forwardTrigger, speed_max, 0);
  }

  if (speed_1 > 0) {
    motor1.setSpeed(speed_1);
    motor1.step(direction_1);
  }

  // MOTOR 2 CONTROL X
  int speed_2 = 0;
  int direction_2 = 1;
  int position_2 = analogRead(2);
  int leftLimit = 0, leftTrigger = 462;
  // idle_2 = 521;
  int rightTrigger = 562, rightLimit = 1023;
  int triggerValues_2[] = { leftLimit, leftTrigger, rightTrigger, rightLimit };

  if (position_2 > rightTrigger and digitalRead(4) == HIGH) {
    speed_2 = map(position_2, rightTrigger, rightLimit, 0, speed_max);
  }

  if (position_2 < leftTrigger and digitalRead(5) == HIGH) {
    speed_2 = map(position_2, leftLimit, leftTrigger, speed_max, 0);
    direction_2 = -1;
  }

  if (speed_2 > 0) {
    motor2.setSpeed(speed_2);
    motor2.step(direction_2);
  }
}
