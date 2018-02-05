/*

This code is to make LED lights light up, based on binary numericals

*/

// globals
int timer = 0;
int pinCount = 9;
int pinArray[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10};
int binary[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256}; 

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<pinCount; i++) {
    pinMode(pinArray[i], OUTPUT);  
  };  
}

void loop() {
  // put your main code here, to run repeatedly:
  seq();
  toogle();
  clockTime();
}

void seq(){
  for (int i=0; i<pinCount; i++) {
    digitalWrite(pinArray[i], LOW);
  };
};

void toogle() {

  for(int i=0; i<pinCount; i++) {
    if( timer % binary[i] == 0 ) {
      digitalWrite(pinArray[i], !digitalRead(pinArray[i]));
    }
  };  

};

void clockTime() {
  delay(700);
  timer += 1 ;
};

