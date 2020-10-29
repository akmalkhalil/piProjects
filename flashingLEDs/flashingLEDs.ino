int pins[] = {3,5,6,9,10,11};
const int buttonPin = 2;
const int potPin = A0;

int i;
int buttonState = 0;// value 1-5 representing which flashing pattern used
bool buttonRelease = false;
bool buttonPressed = LOW;// value of button
int delTime = 0;// the value of the potentiometer

void runThrough();
void bounce();
void allFlash();



void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  for (i = 0; i<6; i++){
    pinMode(pins[i], OUTPUT);
  }
  i=0;
  pinMode(buttonPin, INPUT);

  ////Serial.begin(9600);
}

void loop() {
  if (buttonPressed == HIGH) {
    //Serial.write(buttonPressed);
    buttonPressed = digitalRead(buttonPin);
    if (buttonPressed == LOW) {
      buttonRelease = true;
      ////Serial.write("\nRelease\n");
    }
  } else {
    buttonPressed = digitalRead(buttonPin);
  }

  if (buttonRelease) {
    buttonState = (buttonState + 1) %5;
    buttonRelease = false;
  }

  delTime = analogRead(potPin);
  //Serial.println(delTime);

  switch (buttonState){
    case 0:
      runThrough();
      break;
    case 1:
      bounce();
      break;
    default:
      allFlash();
      break;
  }
  
}


void runThrough(){
  if (i==0){
    digitalWrite(pins[5],LOW);
  } else {
    digitalWrite(pins[i-1],LOW);
  }
  digitalWrite(pins[i],HIGH);
  delay(delTime);

  i = (i+1)%6; 
}


void bounce() {
  // TODO
  if (i==0){
    digitalWrite(pins[5],LOW);
  } else {
    digitalWrite(pins[i-1],LOW);
  }
  digitalWrite(pins[i],HIGH);
  delay(delTime);

  i = (i+1)%6; 
}

void allFlash(){
  i = (i+1) % 2;
  if (i == 0){
    for (int j=0; j<6; j++){
      digitalWrite(pins[j],LOW);
    }
  } else {
    for (int j=0; j<6; j++){
      digitalWrite(pins[j],HIGH);
    }
  }
  delay(delTime);
  
}
