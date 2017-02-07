/*
  Mauro Vilasi 
  185h January 2015
  Water Irrigation System
  
  A humidity sensor (leds green/red)
  A water resistor sensor (leds green/red)
  A potentiometer (set the level of humidity wanted - may set via a remote control)
  An infrared camera to monitor health (leds green/red)
  A button to generate a report (may be replaced by automatic updates)
  
 */
 
 #include <Servo.h>
const int numReadings=20;
const int humiditySensor = A0;
const int humidityPotentiometer = A1;
const int humidityRedLed = 12; 
const int humidityGreenLed = 13;
const int servoPWM = 3;
const int trigPin = 2;
const int echoPin = 4; 
int humidityThreshold = 128;
long duration, inches, cm;
Servo waterPump;


void setup() {
  pinMode(humidityRedLed, OUTPUT);
  pinMode(humidityGreenLed, OUTPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW); 
  waterPump.attach(servoPWM);
 
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  int humidityReceived = analogRead(humiditySensor);
  int humidityValue = map(humidityReceived, 0, 1023, 0, 255);
  
  humidityThreshold = map(analogRead(humidityPotentiometer), 0, 1023, 0, 255);
  int motorValue = map(humidityThreshold, 0, 255, 5, 175);
  long waterLevel = getWaterLevel();
  //long waterLevel = 5;
  
  if (humidityValue >= humidityThreshold) {
    digitalWrite(humidityGreenLed, HIGH);
    digitalWrite(humidityRedLed, LOW);
  } else {
    digitalWrite(humidityRedLed, HIGH);
    digitalWrite(humidityGreenLed, LOW);
    waterPump.write(motorValue);
  }
    
  // print the results to the serial monitor:
  Serial.print("humidityThreshold = " );
  Serial.print(humidityThreshold);
  Serial.print("\t humidity = ");
  Serial.print(humidityValue);
  Serial.print("\t water level = ");
  Serial.print(waterLevel);
  Serial.print("\t motor = ");
  Serial.println(motorValue);
  

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(50);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
} 

long getWaterLevel() {

  long total =0;
  for (int i = 0; i < numReadings; i++) {
    total = total + getWaterReading();
  }
    
  long avgDistance = total / numReadings;
  long metricDistance = microsecondsToCentimeters(avgDistance);
  return metricDistance;
  
}

long getWaterReading() {
   // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
     
    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH); 
    //long cm = duration /20 / 2;
    //return cm;
    return duration;
}


