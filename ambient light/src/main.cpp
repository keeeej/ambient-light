#include <Arduino.h>
#include "runtimer.h"

const int ledPin = 11;
const int sensorPin = A1;

intervalTimer timer1(2000);

int sensorValue = 0;
int pinValue = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() 
{
  if (timer1.expired())
  {
    sensorValue = map(analogRead(sensorPin), 0, 1023, 0, 255);
    pinValue = -sensorValue + 255;
    analogWrite(ledPin, pinValue);
  
    Serial.print("sensor: ");
    Serial.print(sensorValue);
    Serial.print(" | pin: ");
    Serial.println(pinValue);
  }
}