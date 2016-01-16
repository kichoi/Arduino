
// Arduino Project Book's Project 4
// Mixing COLOR LED
//

const int colorRPin = 9;
const int colorGPin = 11;
const int colorBPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;


void setup() {
  Serial.begin(9600);
  pinMode(colorRPin, OUTPUT);
  pinMode(colorGPin, OUTPUT);
  pinMode(colorBPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int redValue = analogRead(redSensorPin);
 delay(5);
 int greenValue = analogRead(greenSensorPin);
 delay(5);
 int blueValue = analogRead(blueSensorPin);
 Serial.print("Sensor Value: red=");
 Serial.print(redValue);
 Serial.print("\t green=");
 Serial.print(greenValue);
 Serial.print("\t blue=");
 Serial.println(blueValue);
 // analogWrite(colorRPin, redValue/4.0);
 analogWrite(colorGPin, greenValue/4.0);
 // analogWrite(colorBPin, blueValue/4.0);
}
