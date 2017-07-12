#include <SoftwareSerial.h>

int bendSensorPin = A0; //LED connected
int sensorValue = 0;

SoftwareSerial mySerial(11, 10); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(4800);
}  

void loop() {
  // read the value from the sensor:
  unsigned int sensorValue = analogRead(bendSensorPin); // A value between 0 and 1023

  // mapping it over here so I an send the value in one byte
  unsigned int val = map(sensorValue, 0, 1023, 0, 180);

  byte data = (byte) val;
  
  mySerial.write(data);
  
  
  
  delay(5000);
}
