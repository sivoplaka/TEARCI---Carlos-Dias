#include <Arduino.h>

// Definição dos pinos
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int ldrPin = A0;

void setup() {
  // configuração dos pinos
  pinMode(redPin, OUTPUT);
  Serial.println("Pino vermelho configurado como OUTPUT: " + String(redPin));
  
  pinMode(greenPin, OUTPUT);
  Serial.println("Pino verde configurado como OUTPUT: " + String(greenPin));
  
  pinMode(bluePin, OUTPUT);
  Serial.println("Pino azul configurado como OUTPUT: " + String(bluePin));
  
  pinMode(ldrPin, INPUT);
  Serial.println("Pino LDR configurado como INPUT: " + String(ldrPin));
  
  Serial.begin(9600);
  Serial.println("Setup completo");
}

void loop() {
  //controlo da intensidade da fita led rgb com o LDR
  int LDRValue = analogRead(ldrPin);
  int brilho = map(LDRValue, 60, 200, 0, 255);
  brilho = constrain(brilho, 0, 255);
  analogWrite(redPin, brilho);
  analogWrite(greenPin, brilho);
  analogWrite(bluePin, brilho);
  Serial.println("Range: 60 - 200: " + String(LDRValue) + " Brilho: " + String(brilho));
  delay(100);
}