// Arduino Project Book's Project 3
// Lite up LED in step if tempurate increases
//

const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);
  for(int pinNumber = 3; pinNumber < 6; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
    int sensorVal = analogRead(sensorPin);
    float voltage = (sensorVal/1024.0) * 5.0;
    float temp = (voltage - 0.5) * 100;
    Serial.print("Sensor Value:");
    Serial.print(sensorVal);
    Serial.print(", Volt:");
    Serial.print(voltage);
    Serial.print(", degree in C:");
    Serial.println(temp);
    checkTemp(temp);
    delay(250);
}

void checkTemp(float temp){
  if(baselineTemp >= temp){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    for (int i=1; i<4; i++){
      if(temp >= baselineTemp + 2*i){
        digitalWrite(2+i, HIGH);
      } else {
        digitalWrite(2+i, LOW);
      }
    }
  }    
}

