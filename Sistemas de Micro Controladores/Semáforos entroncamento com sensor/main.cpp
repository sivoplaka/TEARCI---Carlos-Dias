#include <Arduino.h>

//declaração dos pinos
const int S1R = 6;
const int S1Y = 7;
const int S1G = 8;
const int S2R = 9;
const int S2Y = 10;
const int S2G = 11;
const int trigger = 3;
const int echo = 2;

//declaração dos estados
enum ESTADO
{
  estado1,
  estado2,
  estado3
};
ESTADO estado = estado1;

float duration_us, distance_cm;

void setup()
{
  //configuração dos pinos
  pinMode(S1R, OUTPUT);
  pinMode(S1Y, OUTPUT);
  pinMode(S1G, OUTPUT);
  pinMode(S2R, OUTPUT);
  pinMode(S2Y, OUTPUT);
  pinMode(S2G, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

//função para medir a distância com o sensor ultrassónico
float medirDistancia()
{
  digitalWrite(trigger, HIGH); //envia um pulso de disparo
  delayMicroseconds(10);       
  digitalWrite(trigger, LOW);  //desliga o pulso de disparo
  duration_us = pulseIn(echo, HIGH); //mede o tempo de retorno do sinal
  return duration_us * 0.017; //faz a conversão para centímetros
}

void loop()
{
  switch (estado)
  {
  case estado1:
    //S1 verde e S2 vermelho
    // Ciclo para detetar um carro com o sensor
    digitalWrite(S1G, HIGH);
    digitalWrite(S2R, HIGH);

    do
    {
      distance_cm = medirDistancia(); //atualiza a distância
      Serial.print("Distância: ");
      Serial.print(distance_cm);
      Serial.println(" cm");
      delay(100); //atraso para evitar sob leituras
    } while (distance_cm >= 15); //enquanto nenhum carro for detetado >= 15cm

    estado = estado2; //passa para o próximo estado
    break;

  case estado2:
    //passa S1 a amarelo e depois de 2s, S1 vermelho e S2 verde
    digitalWrite(S1G, LOW);
    digitalWrite(S1Y, HIGH);
    delay(2000);
    digitalWrite(S1Y, LOW);
    digitalWrite(S2R, LOW);
    digitalWrite(S2G, HIGH);
    digitalWrite(S1R, HIGH);

    do
    {
      distance_cm = medirDistancia();
      Serial.print("Distância: ");
      Serial.print(distance_cm);
      Serial.println(" cm");
      delay(100);
    } while (distance_cm <= 15); //enquanto nenhum carro for detetado <= 15cm

    estado = estado3; //passa para o próximo estado
    break;

  case estado3:
    //passa S2 a amarelo e depois de 2s, S2 vermelho e S1 verde
    delay(2000);
    digitalWrite(S2G, LOW);
    digitalWrite(S2Y, HIGH);
    delay(2000);
    digitalWrite(S2Y, LOW);
    digitalWrite(S2R, HIGH);
    digitalWrite(S1R, LOW);
    digitalWrite(S1G, HIGH);

    delay(15000); //aguarda 15s antes de reiniciar o ciclo
    estado = estado1;
    break;
  }
}
