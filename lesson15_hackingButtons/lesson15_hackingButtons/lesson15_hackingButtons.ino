
const int octoPin = 2;

void setup() {
  pinMode(octoPin, OUTPUT);  

}

void loop() {
  digitalWrite(octoPin, HIGH);
  delay(15);
  digitalWrite(octoPin, LOW);

  delay(3000);

}
