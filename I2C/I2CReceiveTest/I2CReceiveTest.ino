// For more, see https://dronebotworkshop.com/i2c-arduino-raspberry-pi/

// WARNING: be careful when communicating with devices of different voltage levels
// e.g. pi at 3.3V and arduino at 5v
/* For I2C need 3 wires
 *  SDA - A4
 *  SCL - A5
 *  Ground
 */

#include <Wire.h>

const int ledpin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);
  Serial.begin(9600);
  
  Wire.begin(0x8); // Without an argument passed, that would make this the master,
                   // By passing an argument we make this arduino the receiver
  
  // What function to call when receive data
  Wire.onReceive(receiveEvent);// https://www.arduino.cc/en/Reference/WireOnReceive
}

// @param numBytes: the number of bytes received from master
void receiveEvent(int numBytes) {
  while (Wire.available()) {// available() returns number of bytes available for retrieval
    int c = Wire.read(); // example code I've seen uses char c, not int c.
    Serial.write("character recieved:");
    Serial.write(c);
    Serial.write("\n");
    if (c == 1){
      digitalWrite(ledpin, 1);
      Serial.write("LED on\n");
    } else if (c == 0){
      digitalWrite(ledpin, 0);
      Serial.write("LED off\n");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
