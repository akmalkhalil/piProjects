String leds[8] = {"000","001","010","011","100","101","110","111"};
int controlPins[3] = {4,3,2}; // Connect to C,B,A in order
int signalPin = 11; // Connect to common

int counter = 0;
void setLED(int i, int state);

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<3;i++){
    pinMode(controlPins[i], OUTPUT);
  }
  pinMode(signalPin, OUTPUT);
  digitalWrite(signalPin, HIGH);

}



void loop() {
  // put your main code here, to run repeatedly:
  setLED(counter, HIGH);

  counter = (counter + 1) % 8;
  delay(500);
}

void setLED(int i, int state){
  //for (char const &c: leds[i]) {
  String led = leds[i];
  for (int j=0;j<3;j++) {
    if (led[j] == '1') {
      digitalWrite(controlPins[j],HIGH);
    } else {
      digitalWrite(controlPins[j],LOW);
    }
  }
  //digitalWrite(signalPin, state);
}
