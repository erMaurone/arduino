//processing code is in ~/Documents/Processing/
int analogValue = analogRead(A0);

void setup() {
  Serial.begin(9600);

}

void loop() {

    // no need to open a serial terminal but if you you get uncoherent characters.
    //little experiment commented out below shows it's due to representation
    // Print it out in many formats:
    //  Serial.print("=========");    
    // Read the analog input on pin 0:
    //analogValue = analogRead(A0/4);
    //Serial.println("=========");
    //Serial.println(analogValue);       // print as an ASCII-encoded decimal
    //Serial.println(analogValue, DEC);  // print as an ASCII-encoded decimal
    //Serial.println(analogValue, HEX);  // print as an ASCII-encoded hexadecimal
    //Serial.println(analogValue, OCT);  // print as an ASCII-encoded octal
    //Serial.println(analogValue, BIN);  // print as an ASCII-encoded binary  
    
    Serial.write(analogRead(A0)/4);
    delay(100);
}
