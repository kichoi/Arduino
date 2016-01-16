
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;


void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Happy New Year!");   
  lcd.setCursor(0,1);
  lcd.print("Degree C=");
}

void loop() {
  
  int sensorValue = analogRead(sensorPin);
  float voltage = (sensorValue/1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
  Serial.print("Sensor Value=");
  Serial.print(sensorValue);
  Serial.print("\t volt=");
  Serial.print(voltage);
  Serial.print("\t degree C=");
  Serial.println(temperature);
  lcd.setCursor(11,1);
  lcd.print(temperature);
  delay(3000);
  
}
