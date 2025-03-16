#include <Arduino.h>

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int ldrPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
  Serial.println("Setup completo");
}

void loop() {
  // o LDR liga ou desliga se o valor lido for maior ou menor que 500
  int LDRValue = analogRead(ldrPin);
  if (LDRValue > 200)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    Serial.println(String(LDRValue) + " > 200 - Leds desligados");
  }
  else
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    Serial.println(String(LDRValue) + " < 200 - Leds ligados");
  }
  delay(100);
}