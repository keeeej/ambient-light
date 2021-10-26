#include <Arduino.h>

const int ledPin = 11;
const int sensorPin = A1;

int sensorValue = 0;
int pinValue = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  sensorValue = map(analogRead(sensorPin), 0, 1023, 0, 255);
  delay(5);
  Serial.print("sensor: ");
  Serial.println(sensorValue);

  pinValue = -sensorValue + 255;
  analogWrite(ledPin, pinValue);
  delay(5);
  Serial.print("pin: ");
  Serial.println(pinValue);
}