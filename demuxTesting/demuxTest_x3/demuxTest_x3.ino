  // Testing out using 3x CD4051BE Demultiplexer ICs

String leds[8] = {"000","001","010","011","100","101","110","111"};
int controlPins[3] = {4,3,2}; // Connect to C,B,A in order
int signalPin = 9; // Connect to common

int sig2 = 10;
int sig3 = 11;
int control2[3] = {7,6,5};
int control3[3] = {13,12,8};

int counter = 0;
void setLED(int i, int state);
void setLED2(int ledN, int state);

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<3;i++){
    pinMode(controlPins[i], OUTPUT);
    pinMode(control2[i], OUTPUT);
    pinMode(control3[i], OUTPUT);
  }
  pinMode(signalPin, OUTPUT);
  digitalWrite(signalPin, HIGH);
  pinMode(sig2, OUTPUT);
  pinMode(sig3, OUTPUT);
  digitalWrite(sig2, HIGH);
  digitalWrite(sig3, HIGH);

}



void loop() {

  if (counter < 24){
    setLED(counter % 8, HIGH);
    delay(500);
  } else if (counter < 72) {
    //counter = 0;
    setLED2(counter % 24, HIGH);
    delay(200);
  } else {
    counter = 0;
  }
  counter = (counter + 1);
}

// For each demux, loops through each LED attached to it
// (so end up with 3 LEDs on at a time)
void setLED(int i, int state){
  //for (char const &c: leds[i]) {
  String led = leds[i];
  for (int j=0;j<3;j++) {
    if (led[j] == '1') {
      digitalWrite(controlPins[j],HIGH);
      digitalWrite(control2[j],HIGH);
      digitalWrite(control3[j],HIGH);
    } else {
      digitalWrite(controlPins[j],LOW);
      digitalWrite(control3[j],LOW);
      digitalWrite(control2[j],LOW);
    }
  }
  //digitalWrite(signalPin, state);
  digitalWrite(signalPin,HIGH);
  digitalWrite(sig2,HIGH);
  digitalWrite(sig3,HIGH);
}

// Loops through each LED and puts them on in order
// So have one LED on at a time
void setLED2(int ledN, int state){
  // there's gonna be a better way to do this but this is what I'm going with for now
  int i = ledN%8;
  String led = leds[i];
  digitalWrite(signalPin,LOW);
  digitalWrite(sig2,LOW);
  digitalWrite(sig3,LOW);
  if (ledN<8){
    // Then it's the first demultiplexer    
    digitalWrite(signalPin,HIGH);
    for (int j=0;j<3;j++) { // In a serious program this should be pulle out to its own function
      if (led[j] == '1') {
        digitalWrite(controlPins[j],HIGH);
      } else { digitalWrite(controlPins[j],LOW);}
    }
  } else if (ledN < 16){
    // Then it's the second demultiplexer
    digitalWrite(sig2,HIGH);
    for (int j=0;j<3;j++) {
      if (led[j] == '1') {
        digitalWrite(control2[j],state);
      } else { digitalWrite(control2[j],LOW);}
     }
  } else if (ledN < 24) {
    // Then it's the third demultiplexer
    digitalWrite(sig3,HIGH);
    for (int j=0;j<3;j++) {
      if (led[j] == '1') {
        digitalWrite(control3[j],state);
      } else { digitalWrite(control3[j],LOW);}
    }
  } else {
    // Something's gone wrong if we're here
  }
}
