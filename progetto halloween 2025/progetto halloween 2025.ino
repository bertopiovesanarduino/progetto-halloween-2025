int LED = 3;
int PIR = 10;

void setup() {
  Serial.begin(9600);

// initialize digital pin 3 as an output for LED

  pinMode(LED, OUTPUT);

//initialize digital pin 10 as input for PIR

  pinMode(PIR, INPUT);

//initialization time for PIR sensor to warm up

//blink LED to show that something is happening

  for(int i = 0; i < 1; i++) {

  Serial.println("partendo...");
  digitalWrite(LED, LOW);

  delay(3000);

  digitalWrite(LED, HIGH);

  delay(3000);

  }

}

void loop() {
  Serial.println("pronti!");
//read PIR sensor, if High light LED for 5 seconds

//if low, check again
  delay(500);

  if(digitalRead(PIR) == HIGH) {
  digitalWrite(LED, HIGH);
  Serial.println("trovato! :)");
  delay(3000);

  } 

  else {
  digitalWrite(LED, LOW);
  Serial.println("non trovato :(");
  }

}