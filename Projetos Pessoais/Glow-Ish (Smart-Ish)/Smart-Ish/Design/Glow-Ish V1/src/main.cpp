#include <Arduino.h>

//const int LDR = 36;
//const int PIR = 13;
const int led = 2;

void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
}