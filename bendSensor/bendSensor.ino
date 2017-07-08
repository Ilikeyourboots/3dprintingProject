#include <SoftwareSerial.h>

int bendSensorPin = A0; //LED connected
int sensorValue = 0;

SoftwareSerial mySerial(5, 5); // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(4800);
  mySerial.flush();
}  

void loop() {
  // read the value from the sensor:
  int sensorValue = analogRead(bendSensorPin); // A value between 0 and 1023
  
  //Serial.println(sensorValue);
  mySerial.print(sensorValue);
  
  delay(1);
}
