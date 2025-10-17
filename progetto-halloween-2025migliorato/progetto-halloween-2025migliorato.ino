/**
 * Halloween scary table
 * @author Alberto Piovesan
 */

#include <Stepper.h>

int rele = 3;
int PIR = 13;
bool fase = true;
bool fine = false;
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Initialize peripherals
  initPeripherals();
  // Setting initial conditions
  zero();
  // Wait 10 seconds before start loop() logic
  delay(10000);
}

void initPeripherals()
{
  Serial.begin(9600);
  myStepper.setSpeed(15);

  pinMode(rele, OUTPUT);

//initialize digital pin 10 as input for PIR

  pinMode(PIR, INPUT);

//initialization time for PIR sensor to warm up

  Serial.println("partendo...");
  digitalWrite(rele, LOW);
}

void zero()
{
  Serial.println("antiorario");
  myStepper.step(-stepsPerRevolution);
}

bool end = false;

void loop() {
  
  // Run only once
  if (end) return;

  // Wait for upfront from PIR
  waitForGuest();
  // Scare guest, alarm ON for 1 sec
  scareGuest();
  // Wait for another upfront from PIR (gest second move)
  waitForGuest();
  // Pull the leg with the winding up the wire
  moveTableLeg();

  // Run only once
  end = true;

}

void waitForGuest()
{
  // Wait for signal to be LOW
  while (digitalRead(0) == HIGH) { delay(500); }
  // Wait to upfront
  while (digitalRead(0) == LOW) { delay(500); }
}

void scareGuest()
{
  digitalWrite(0, HIGH);
  delay(1000);
  digitalWrite(0, LOW);
}

void moveTableLeg()
{
  Serial.println("orario");
  myStepper.step(stepsPerRevolution);
  fine = true;
}
