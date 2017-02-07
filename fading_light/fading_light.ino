/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

const int LED = 9;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int interval=20;
  fadeUp(255, interval);
  fadeDown(2, interval);  
  delay(1000);
  fadeUp(180, interval);
  fadeDown(2, interval);
}

void fadeUp(int maxIntensity, int interval) {
    for  (int i = 1; i<maxIntensity;i=i+1) {
      analogWrite(LED, i);  
      delay(interval); 
    }
 }
 
void fadeDown(int minIntensity, int interval) {
      for  (int i = 255;i > minIntensity; i=i-1  ) {
        analogWrite(LED, i);  
        delay(interval); 
      } 
 }

