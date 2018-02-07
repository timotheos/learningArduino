#include <Stepper.h>

// Variables
const int PPR = 200;
const int max_speed = 20;

// Motors connected to the top plate
// Motor Y in pins 10-13
Stepper topMotor1(PPR, 6, 7, 8, 9);
int     topMotor1Pins[] = { 1, 2, 3 };
int speed_1 = 0;
int direction_1 = 1;
int position_1 = analogRead(topMotor1Pins[0]);
// Motor X in pins 6-9
Stepper topMotor2(PPR, 10, 11, 12 ,13);
int     topMotor2Pins[] = { 2, 4, 5 };
int speed_2 = 0;
int direction_2 = 1;
int position_2 = analogRead(topMotor2Pins[0]);

// Motors connected to the top plate
// Motor Y in pins 24-27
Stepper midMotor1(PPR, 34, 35, 36, 37);
int     midMotor1Pins[] = { 3, 46, 47 };
int speed_3 = 0;
int direction_3 = 1;
int position_3 = analogRead(midMotor1Pins[0]);
// Motor X in pins 32-35
Stepper midMotor2(PPR, 2, 3, 4, 5);
int     midMotor2Pins[] = { 4, 48, 49 };
int speed_4 = 0;
int direction_4 = 1;
int position_4 = analogRead(midMotor2Pins[0]);

// Joystick 1 trigger values
// Y axis
int topForwardLimit = 30, topForwardTrigger = 39;
int topIdle_1 = 51;
int topBackwardTrigger = 180, topBackwardLimit = 613;
int joystick1Limit_y[] = { topForwardLimit, topForwardTrigger, topBackwardTrigger, topBackwardLimit };

// X axis
int topLeftLimit = 300, topLeftTrigger = 580;
int topIdle_2 = 680;
int topRightTrigger = 720, topRightLimit = 1023;
int joystick1Limit_x[] = { topLeftLimit, topLeftTrigger, topRightTrigger, topRightLimit };

// Joystick 2 trigger values
// Y axis
int midForwardLimit = 0, midForwardTrigger = 420;
int midIdle_1 = 493;
int midBackwardTrigger = 600, midBackwardLimit = 1023;
int joystick2Limit_y[] = { midForwardLimit, midForwardTrigger, midBackwardTrigger, midBackwardLimit };

// X axis
int midLeftLimit = 0, midLeftTrigger = 420;
int idle_2 = 503;
int midRightTrigger = 600, midRightLimit = 1023;
int joystick2Limit_x[] = { midLeftLimit, midLeftTrigger, midRightTrigger, midRightLimit };


void setup() {
  // // Pins 2-5 set up as inputs with pullup resistors. Sensors are active-low.
  for (int i = 2; i <= 5; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
  // for (int i = 46; i <= 49; i++)
  // {
  //   pinMode(i, INPUT_PULLUP);
  // }
}

void loop() {
  motorControl(joystick1Limit_y, max_speed, topMotor1Pins, topMotor1, speed_1, direction_1, position_1);
  motorControl(joystick1Limit_x, max_speed, topMotor2Pins, topMotor2, speed_2, direction_2, position_2);
  // motorControl(joystick2Limit_y, max_speed, midMotor1Pins, midMotor1, speed_3, direction_3, position_3);
  // motorControl(joystick2Limit_x, max_speed, midMotor2Pins, midMotor2, speed_4, direction_4, position_4);
}

int motorControl(int joystickTrigger[], int speed, int motorPins[], Stepper motor,
  int speed_now, int direction_now, int position_now) {

  if (position_now > joystickTrigger[2] and digitalRead(motorPins[1]) == HIGH) {
    speed_now = map(position_now, joystickTrigger[2], joystickTrigger[3], 0, speed);
    direction_now = -1;
  }

  if (position_now < joystickTrigger[1] and digitalRead(motorPins[2]) == HIGH) {
    speed_now = map(position_now, joystickTrigger[0], joystickTrigger[1], speed, 0);
  }

  if (speed_now > 0) {
    motor.setSpeed(speed_now);
    motor.step(direction_now);
  }
}
