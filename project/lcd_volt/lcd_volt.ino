#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;
const float DivderRatio = 3.78;


void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("KTM 690 ENDURO");   
  lcd.setCursor(0,1);
  lcd.print("Volt =");
}

void loop() {
  
  int sensorValue = analogRead(sensorPin);
  float sensorVoltage = (sensorValue/1024.0) * 5.0;
  float vcc = sensorVoltage * DivderRatio;
  Serial.print("Sensor Value=");
  Serial.print(sensorValue);
  Serial.print("\t volt=");
  Serial.print(sensorVoltage);
  Serial.println("\t Vcc=");
  Serial.println(vcc);
  lcd.setCursor(11,1);
  lcd.print(vcc);
  delay(150);
}
