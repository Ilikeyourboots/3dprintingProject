#include <Servo.h>
#include "pitches.h"
Servo myservo; 

int otherArduino = 3;
int servoPin = 9;
int bendVal = 0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(otherArduino, INPUT);
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bendVal = analogRead(otherArduino);
  val = map(bendVal, 0, 4, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  //myservo.write(val); // sets the servo position according to the scaled value
  Serial.println(val);
  delay(500);
  //Todo: how to control speed
}
