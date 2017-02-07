
const int sensorPin = A0;
const float baselineTemp = 19.0;

void setup() {
  Serial.begin(9600);
  for (int pinNumber = 11; pinNumber < 14; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Serial Value: ");
  Serial.print(sensorVal);

  //convert the ADC redint to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  //convert the voltage to temperature in deggress;
  float temperature = (voltage - 0.5) * 100;
  Serial.print(", Temperature: ");
  Serial.print(temperature);
  Serial.println();

  //how many leads to light up?
  //every two degree C we light up a led

  if (temperature < baselineTemp) {
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  } else if (temperature >= baselineTemp + 2 &&
             temperature < baselineTemp + 4) {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  } else if (temperature >= baselineTemp + 4 &&
            temperature < baselineTemp + 6) {
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  } else if ( temperature > baselineTemp + 6) {
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
  
  delay(100);
}
