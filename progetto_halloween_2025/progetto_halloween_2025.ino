#include <Stepper.h>

int rele = 3;
int PIR = 13;
bool fase = true;
bool fine = false;
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(15);

  pinMode(rele, OUTPUT);

//initialize digital pin 10 as input for PIR

  pinMode(PIR, INPUT);

//initialization time for PIR sensor to warm up

  Serial.println("partendo...");
  digitalWrite(rele, LOW);

  Serial.println("antiorario");
  myStepper.step(-stepsPerRevolution);

}

void loop() {

  delay(500);
  
  if (fine == false){
    if (fase == true){
      
      delay(500);

      if(digitalRead(PIR) == HIGH) {
        allarme();
      } 
      else {
        digitalWrite(rele, LOW);
        Serial.println("non trovato :(");
      }
    }
    
    else {

      if(digitalRead(PIR) == HIGH) {
        Serial.println("COLLASSO!!!");
        collasso();
      }

    }

  }
}

void allarme(){

  digitalWrite(rele, HIGH);
  Serial.println("trovato! :)");
  delay(1000);
  digitalWrite(rele, LOW);
  fase = false;
  delay(1000);
  Serial.println("in attesa...");

}

void collasso(){

  Serial.println("orario");
  myStepper.step(stepsPerRevolution);
  fine = true;

}