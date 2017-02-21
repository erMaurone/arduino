import processing.serial.*;

Serial myPort;
PImage logo;
int bgcolor = 0;


void setup(){
  colorMode(HSB,255);
  logo = loadImage("http://arduino.cc/logo.png");
  //size(logo.width, logo.height);
  size(400,200);
  
  println("Available serial ports: ");
  println(Serial.list());
  println("Find arduino ... ");
  println(Serial.list()[0]);  
  println(Serial.list()[1]);
  println(Serial.list()[2]);
  println(Serial.list()[3]);

  //use the ouput above to determine the actual port 
  //in these runs bluetooth comes first.
  myPort = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  if (myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  background(bgcolor,255,255);
  image(logo,0,0);
}