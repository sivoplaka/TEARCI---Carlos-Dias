#include <Arduino.h>
//Motores
const int motorA1 = 3; // B-1A
const int motorA2 = 4; // B-2A
const int motorB1 = 5; // A-1A
const int motorB2 = 6; // A-2A

//Sensor ultrassónico
const int trigPin = 7;
const int echoPin = 8;

//Fins de curso
const int fimCursoEsquerdo = 9;
const int fimCursoDireito  = 10;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(fimCursoEsquerdo, INPUT_PULLUP);
  pinMode(fimCursoDireito, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  bool fimEsq = digitalRead(fimCursoEsquerdo) == HIGH;
  bool fimDir = digitalRead(fimCursoDireito) == HIGH;

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.print(" cm | Fim Esq: ");
  Serial.print(fimEsq);
  Serial.print(" | Fim Dir: ");
  Serial.println(fimDir);

  //Motores rodam para a esquerda
  if (distance <= 25 && !fimEsq) {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
  }
  //Motores rodam para a direita
  else if (distance > 25 && distance <= 50 && !fimDir) {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
  }
  //Motores parados
  else {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
  }

  delay(100);
}
