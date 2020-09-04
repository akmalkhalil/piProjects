#include <Servo.h>

// Sensor/potentiometer
const int sensorPin = A0;
const int sensorMax = 1023;
const int sensorMin = 600;
int sensorVal = 0;

// Servo
Servo serv;
const int servoPin = 9;
const int servoMax = 2400;
const int servoMin = 600;
const float maxAngle = 270.0;
int servoVal = 0;

int calcServ(int ang);
int pot2Ang(int x);// Wanted to use int val, but val is taken.


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  serv.attach(servoPin, servoMin,servoMax);
}

void loop() {
  // put your main code here, to run repeatedly:
//  sensorVal = analogRead(sensorPin);
//  Serial.println(sensorVal);
//  delay(100);//ms

//  serv.write(0);
//  Serial.println(0);
//  delay(3000);
//  serv.write(calcServ(90));
//  Serial.println(90);
//  delay(3000);
//  serv.write(calcServ(180));
//  Serial.println(180);
//  delay(3000);
//  serv.write(calcServ(270));
//  Serial.println(270);
//  delay(3000);

  sensorVal = analogRead(sensorPin);
  servoVal = pot2Ang(sensorVal);
  Serial.println(sensorVal);
  Serial.println(servoVal);
  Serial.println();
  serv.write(servoVal);
  
}


// The servo library only takes values between 0 (min) and 180 (max) but the physical servo is rotated between 0 and 270 (well my servo is 270) based on the PWM values put in
// This function will convert from the actual angle I want and a value in the range 0-180
int calcServ(int ang){
  return (int)( (float) ang * (180.0/maxAngle));
}
int pot2Ang(int x){
  return calcServ(x * maxAngle/sensorMax);
}
