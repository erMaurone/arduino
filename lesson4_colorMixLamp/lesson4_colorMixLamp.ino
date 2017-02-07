const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin=10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue =0;
int greenSensorValue = 0;
int blueSensorValue =0;

void setup() {
  Serial.begin(9600);
  
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);   
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5); // it takes one millisecond for ADC (Analog Digital Conversion)
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);  
  
  Serial.print("Raw Sensor Values\t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\tBlue: ");
  Serial.print(blueSensorValue);
  Serial.print("\tGreen: ");
  Serial.println(greenSensorValue);
  
  redValue = redSensorValue /4;
  greenValue = greenSensorValue /4;
  blueValue = blueSensorValue /4;
  
  Serial.print("Mapped Sensor Values\tRed: ");
  Serial.print(redValue);
  Serial.print("\tBlue: ");
  Serial.print(blueValue);
  Serial.print("\tGreen: ");
  Serial.println(greenValue);
  
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);

}
