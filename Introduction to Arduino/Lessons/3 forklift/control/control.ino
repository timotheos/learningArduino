#include <Servo.h>
#define arr_len(x) ( sizeof(x) / sizeof(*x) )

/*
  Because this structure has limitations, tests have been done to determine
  the working angles.

  Take note that Servos rotate clockwise given a positive value.
*/

// Servo definitions
Servo servo_swivel;
Servo servo_lift;
Servo servo_reach;

// theta, y, x
Servo servoArray[] = { servo_swivel, servo_lift, servo_reach };
int servoPins[]  = { 9, 11, 13 };

int swivel_dof[] = { 0, 180 };
int lift_dof[]   = { 40, 170 };
int reach_dof[]  = { 10, 110 };

// Input definitions

int joystickPins[]  = { 38, A1, A2 }; // start, y, x
int dialPin         = A0;
int input_dial, input_y, input_x;
int inputArray[]    = { input_dial, input_y, input_x };

void setup() {
  // put your setup code here, to run once:
  // initializeServo(servoArray, servoPins);
  servo_swivel.attach(8);
  servo_lift.attach(A14);
  servo_reach.attach(A15);
}

void loop() {
  // put your main code here, to run repeatedly:
  knobControl(dialPin, input_dial, servo_swivel);

  // Joystick Control

}

/*
void initializeServo(Servo array[], int pins[]) {
  for(int i = 0; i < arr_len(array[]); i++) {
    array[i].attach(pins[i]);
  }
}
*/

void knobControl(int pin, int input, Servo output) {
  // Potentiometer Control
  input = analogRead(pin);               // reads the value of the potentiometer (value between 0 and 1023)
  input = map(input, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  output.write(input);                   // sets the servo position according to the scaled value
  delay(15);                             // waits for the servo to get there
}
/*
void joystick() {
  // read the switch:
  int switchState = digitalRead(switchPin);
  // if it's changed and it's high, toggle the mouse state:
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      mouseIsActive = !mouseIsActive;
      // turn on LED to indicate mouse state:
      digitalWrite(ledPin, mouseIsActive);
    }
  }
  // save switch state for next comparison:
  lastSwitchState = switchState;

  // read and scale the two axes:
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);

  // if the mouse control state is active, move the mouse:
  if (mouseIsActive) {
    Mouse.move(xReading, yReading, 0);
  }

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  if (digitalRead(mouseButton) == HIGH) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  delay(responseDelay);

}
*/
