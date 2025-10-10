#include <Servo.h>

int teso = 10
int nonteso = 30
int LED = 3;
int PIR = 10;
bool fase = true
bool fine = false
//il pin LED sarebbe il pin per il relè collegato alla sirena solo che no ci avevo sbatti di scriverlo di nuovo :)

void setup() {
  Serial.begin(9600);
  Servo myservo;
  myservo.attach(9);
// initialize digital pin 9 as an output for LED
  myservo.write(teso);

  pinMode(LED, OUTPUT);

//initialize digital pin 10 as input for PIR

  pinMode(PIR, INPUT);

//initialization time for PIR sensor to warm up

//blink LED to show that something is happening

  for(int i = 0; i < 1; i++) {

  Serial.println("partendo...");
  digitalWrite(LED, LOW);

  delay(6000);

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

  myservo.write(nonteso);
  fine = true

}