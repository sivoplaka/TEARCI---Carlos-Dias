#include <Arduino.h>

const int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); 
  Serial.println("Ligado");
  delay(200);                   
  digitalWrite(LED_PIN, LOW);   
  Serial.println("Desligado");
  delay(200);                   
}
