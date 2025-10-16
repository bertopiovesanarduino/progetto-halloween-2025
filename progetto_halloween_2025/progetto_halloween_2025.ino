#include <Stepper.h>

int LED = 3;
int PIR = 13;
bool fase = true
bool fine = false
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
//il pin LED sarebbe il pin per il relè collegato alla sirena solo che no ci avevo sbatti di scriverlo di nuovo :)

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(15);

  pinMode(LED, OUTPUT);

//initialize digital pin 10 as input for PIR

  pinMode(PIR, INPUT);

//initialization time for PIR sensor to warm up

//blink LED to show that something is happening

  for(int i = 0; i < 1; i++) {

  Serial.println("partendo...");
  digitalWrite(LED, LOW);

  delay(6000);
  
  Serial.println("antiorario");
  myStepper.step(-stepsPerRevolution);

  }

}

void loop() {

  delay(500);
  
  if (fine == false){
    if (fase == true){

      if(digitalRead(PIR) == HIGH) {
        allarme();
      } 

      else {
        digitalWrite(LED, LOW);
        Serial.println("non trovato :(");
      }
    }
    else{

      if(digitalRead(PIR) == HIGH) {
        collasso()
      }

    }

  }
}

void allarme(){

  digitalWrite(LED, HIGH);
  Serial.println("trovato! :)");
  delay(3000);
  digitalWrite(LED, LOW);
  fase = false;

}

void collasso(){

  Serial.println("orario");
  myStepper.step(stepsPerRevolution);
  fine = true

}