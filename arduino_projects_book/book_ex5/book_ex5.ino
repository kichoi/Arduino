
#include <Servo.h>

int potPin = A0;
int potVal;
int angle;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  angle = potVal;
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print("Pot Value=");
  Serial.print(potVal);
  Serial.print("\t angle=");
  Serial.println(angle);
  myServo.write(angle);
  delay(15);
}
