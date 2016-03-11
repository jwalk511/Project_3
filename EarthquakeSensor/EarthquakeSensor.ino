/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
void Write(int num);

int DOT = 60;
int DASH = DOT * 3;
int MIDDLE = 1;
int TOPMIDDLE = 3;
int TOPLEFT = 2;
int TOPRIGHT = 4;
int BOTTOMMIDDLE = 7;
int BOTTOMLEFT = 5;
int BOTTOMRIGHT = 6;
int DECIMAL = 8;

int counter = 0;

const int POWER = 13;
const int kPinTilt = 11;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode (POWER, OUTPUT);
  pinMode (kPinTilt, INPUT);
  for (int i = 1; i <= 8; i++) {
      pinMode(i, OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  counter = 0;
  for (int i = 1; i < 10; i++) {
      if (digitalRead(kPinTilt) == HIGH) {
        counter++;
      }
      delay(100);
  }
  Write(counter);
}

void Write(int num) {
  
  for (int i = 1; i <= 8; i++) {
     digitalWrite(i, LOW);
  }
  
   switch (num) {
      case 0: 
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(TOPRIGHT, HIGH);
         digitalWrite(TOPLEFT, HIGH);
         digitalWrite(BOTTOMLEFT, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         digitalWrite(BOTTOMMIDDLE, HIGH);
         break;
         
      case 1:
         digitalWrite(TOPLEFT, HIGH);
         digitalWrite(BOTTOMLEFT, HIGH);
         break;
         
      case 2:
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(TOPRIGHT, HIGH);
         digitalWrite(MIDDLE, HIGH);
         digitalWrite(BOTTOMLEFT, HIGH);
         digitalWrite(BOTTOMMIDDLE, HIGH);
         break;

      case 3:
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(TOPRIGHT, HIGH);
         digitalWrite(MIDDLE, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         digitalWrite(BOTTOMMIDDLE, HIGH);
         break;
         
      case 4:
         digitalWrite(TOPRIGHT, HIGH);
         digitalWrite(TOPLEFT, HIGH);
         digitalWrite(MIDDLE, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         break;
         
      case 5:
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(TOPLEFT, HIGH);
         digitalWrite(MIDDLE, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         digitalWrite(BOTTOMMIDDLE, HIGH);
         break;
         
      case 6:
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(MIDDLE, HIGH);
         digitalWrite(TOPLEFT, HIGH);
         digitalWrite(BOTTOMLEFT, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         digitalWrite(BOTTOMMIDDLE, HIGH);
         break;
         
      case 7:
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(TOPRIGHT, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         break;
         
      case 8:
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(TOPRIGHT, HIGH);
         digitalWrite(TOPLEFT, HIGH);
         digitalWrite(MIDDLE, HIGH);
         digitalWrite(BOTTOMLEFT, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         digitalWrite(BOTTOMMIDDLE, HIGH);
         break;

      case 9:
         digitalWrite(TOPMIDDLE, HIGH);
         digitalWrite(TOPRIGHT, HIGH);
         digitalWrite(TOPLEFT, HIGH);
         digitalWrite(MIDDLE, HIGH);
         digitalWrite(BOTTOMRIGHT, HIGH);
         digitalWrite(BOTTOMMIDDLE, HIGH);
         break;

      case '.':

         digitalWrite(DECIMAL, HIGH);
         break;
   }
}

