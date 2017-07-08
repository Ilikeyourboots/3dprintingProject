#include "pitches.h"
int bendSensorPin = A0; //LED connected
int sensorValue = 0;
int otherArduino = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(otherArduino, OUTPUT);
}  

void loop() {
  byte brightness;
  // put your main code here, to run repeatedly:
  // read the value from the sensor:
  int sensorValue = analogRead(bendSensorPin);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  brightness = 256 * (voltage/2);
  
  analogWrite(otherArduino, voltage);
  
  delay(1);
}
