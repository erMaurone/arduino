#include <Servo.h>

Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;
const int quietKnock = 30;
const int loudKnock = 800;

boolean locked = false;
//it is really difficult to get a consistent count of knocks
//as the piezo readings can vary greatly - 
// consider using map to mitigate, i.e.:
//outputValue = map(sensorValue, 0, 1023, 0, 255);
//see https://www.arduino.cc/en/Tutorial/AnalogInOutSerial
int numberOfKnocks = 0;

void setup() {

  myServo.attach(9);
  pinMode(yellowLed , OUTPUT);
  pinMode(redLed , OUTPUT);
  pinMode(greenLed , OUTPUT);
  pinMode(switchPin , INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  if (locked == false) {
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH) {
      locked =true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      numberOfKnocks = 0;
      Serial.println("The box is locked");
      delay(10000);
    } 
  }

  if(locked == true) {
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 5) {
      if (checkForKnock(knockVal) == true) {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more to go");
    }
    if(numberOfKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked");
    }
  }
}

  boolean checkForKnock(int value) {
    if(value > quietKnock && value < loudKnock) {
      digitalWrite(yellowLed, HIGH);
      delay(50);
      digitalWrite(yellowLed, LOW);
      Serial.print("Valid knock of value ");
      Serial.println(value);

      return true;
    } else {
      Serial.print("Bad knock value ");
      Serial.println(value);
      return false;
      }
}

 


