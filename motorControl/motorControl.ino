#include <Servo.h>
#include <SoftwareSerial.h>
Servo myservo; 

int servoPin = 9;
int bendVal = 0;
int val = 0;

SoftwareSerial mySerial(5, 5); // RX, TX

void setup() {
  myservo.attach(servoPin);

  Serial.begin(9600);
  Serial.flush();
  mySerial.begin(4800);
  mySerial.flush();
}

void loop() {
  if (mySerial.available()>0){
    bendVal = mySerial.parseInt();
    val = map(bendVal, 0, 1023, 0, 180);     // Todo: find ranges for each bend sensor
    myservo.write(val); // sets the servo position according to the scaled value
    Serial.println(bendVal);
    //delay(500);
    //Todo: how to control speed
  }
}
