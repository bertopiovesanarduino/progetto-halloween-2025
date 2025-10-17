#include <Stepper.h>

int relè = 3;
int PIR = 13;
bool fase = true;
bool fine = false;
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(15);

  pinMode(relè, OUTPUT);

//initialize digital pin 10 as input for PIR

  pinMode(PIR, INPUT);

//initialization time for PIR sensor to warm up

  Serial.println("partendo...");
  digitalWrite(relè, LOW);

  Serial.println("antiorario");
  myStepper.step(-stepsPerRevolution);

}

void loop() {

  delay(500);
  
  if (fine == false){
    if (fase == true){

      if(digitalRead(PIR) == HIGH) {
        allarme();
      } 

      else {
        digitalWrite(relè, LOW);
        Serial.println("non trovato :(");
      }
    }
    else{

      if(digitalRead(PIR) == HIGH) {
        collasso();
      }

    }

  }
}

void allarme(){

  digitalWrite(relè, HIGH);
  Serial.println("trovato! :)");
  delay(1000);
  digitalWrite(relè, LOW);
  fase = false;
  delay(1000);

}

void collasso(){

  Serial.println("orario");
  myStepper.step(stepsPerRevolution);
  fine = true;

}