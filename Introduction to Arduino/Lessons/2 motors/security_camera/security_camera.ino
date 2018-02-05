#include <Servo.h>

Servo servo_x;
Servo servo_y;

int pos_x   = 90;
int pos_y   = 15;  // cannot be set to a different value learned_Jan_30 
int increment = 30;
int delay_t = 200;

void setup() {  // this sets up
  servo_x.attach(3);
  servo_y.attach(4);

  servo_x.write(pos_x);
  servo_y.write(pos_y);
}

void loop() {
  // let y sweep back and forth in 15
  for(pos_y = 15; pos_y <= 180; pos_y += increment) {
    sweep(servo_x, pos_x, increment, delay_t);
    servo_y.write(pos_y);
    delay(delay_t);
  }
  for(pos_y = 165; pos_y >= 0; pos_y -= increment) {
    sweep(servo_x, pos_x, increment, delay_t);
    servo_y.write(pos_y);
    delay(delay_t);
  }
}

// sweep goes from initial position to 180 to 0 and back to initial

void sweep(Servo servo, int pos_init, int degree_change, int t) { 

  int pos = pos_init; // placeholder for  
  
  for(pos; pos <= 180; pos += degree_change) {
    servo.write(pos);
    delay(t);
  }
  for(pos; pos  >   0; pos -= degree_change) {
    servo.write(pos);
    delay(t);
  }
  for(pos; pos <= pos_init; pos += degree_change) {
    servo.write(pos);
    delay(t);
  }
}
