#include <Servo.h>
#include <SoftwareSerial.h>
Servo myservo; 

int servoPin = 9;
int bendVal = 0;


SoftwareSerial mySerial(11, 10); // RX, TX

void setup() {
  myservo.attach(servoPin);

  Serial.begin(9600);
  mySerial.begin(4800);
}

void loop() {
  while (mySerial.available()>0){  
    byte input = mySerial.read();
    bendVal = (int) input;
    
    //Serial.println(bendVal);
    
    // Todo: find ranges for each bend sensor
    setServoDegree(bendVal);
    //Todo: how to control speed
    
    //should set the servo every 5 seconds
    delay(1000);
  }
  

  
}

void setServoDegree(int degree) {
  Serial.println(degree);
  // just to make sure we aren't hurting the servo
  if (degree > 180){
    degree = 180;
  } else if(degree < 0){
    degree = 0;
  }
   myservo.write(degree); // sets the servo position according to the scaled value
   
}

