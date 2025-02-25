#include <Arduino.h>

//declaração dos pinos
const int S1R = 6;
const int S1Y = 7;
const int S1G = 8;
const int S2R = 9;
const int S2Y = 10;
const int S2G = 11;

//declaração dos estados
enum ESTADO
{
	estado1,
  estado2
};
ESTADO estado = estado1;

void setup() {
  //configuração
  pinMode(S1R, OUTPUT);
  pinMode(S1Y, OUTPUT);
  pinMode(S1G, OUTPUT);
  pinMode(S2R, OUTPUT);
  pinMode(S2Y, OUTPUT);
  pinMode(S2G, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //início do loop com o switch case
  switch (estado)
  {
  case estado1:
    digitalWrite(S2Y, LOW);//desliga o amarelo do S2 e o vermelho no S1
    digitalWrite(S1R, LOW);
    digitalWrite(S1G, HIGH);//liga o verde do S1 e o vermelho do S2
    digitalWrite(S2R, HIGH);
    delay(2000);
    digitalWrite(S1G, LOW);//mantém o S2 e passa o S1 para amarelo
    digitalWrite(S1Y, HIGH);
    delay(2000);
    estado = estado2;//segue para o estado2
    break;
  case estado2:
    //código do estado 2
    digitalWrite(S2G, HIGH);//passa o S2 para verde, desligando o vermelho
    digitalWrite(S2R, LOW);
    digitalWrite(S1R, HIGH);//passa o S1 para vermelho, desligando o amarelo
    digitalWrite(S1Y, LOW);
    delay (2000);
    digitalWrite(S2G, LOW);//mantém o vermelho no S1 e passa a amarelo o S2
    digitalWrite(S2Y, HIGH);
    delay(2000);
    estado = estado1;//retorna ao estado1
    break;
  }
}
