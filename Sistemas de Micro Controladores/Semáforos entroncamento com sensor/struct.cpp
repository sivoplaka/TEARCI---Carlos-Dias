#include <Arduino.h>



typedef struct semaforo //defenir estrutura
{
  const int Vermelho;
  const int Amarelo;
  const int Verde;
  const int trigger;
  const int echo;
};

semaforo S1 = //configuração de estrutura do semaforo 1
{
  .Vermelho = 6,
  .Amarelo = 7,
  .Verde = 9
};

semaforo S2 = //configuração de estrutura do semaforo 2
{
  .Vermelho = 9,
  .Amarelo = 10,
  .Verde = 11
};

semaforo sensor = //configuração de estrutura do sensor
{
  .trigger = 3,
  .echo = 2
};

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
  pinMode(S1.Vermelho, OUTPUT);
  pinMode(S1.Amarelo, OUTPUT);
  pinMode(S1.Verde, OUTPUT);
  pinMode(S2.Vermelho, OUTPUT);
  pinMode(S2.Amarelo, OUTPUT);
  pinMode(S2.Verde, OUTPUT);
  pinMode(sensor.trigger, OUTPUT);
  pinMode(sensor.echo, INPUT);
  Serial.begin(9600);
}

//função para medir a distância com o sensor ultrassónico
float medirDistancia()
{
  digitalWrite(sensor.trigger, HIGH); //envia um pulso de disparo
  delayMicroseconds(10);       
  digitalWrite(sensor.trigger, LOW);  //desliga o pulso de disparo
  duration_us = pulseIn(sensor.echo, HIGH); //mede o tempo de retorno do sinal
  return duration_us * 0.017; //faz a conversão para centímetros
}

void loop()
{
  switch (estado)
  {
  case estado1:
    //S1 verde e S2 vermelho
    // Ciclo para detetar um carro com o sensor
    digitalWrite(S1.Verde, HIGH);
    digitalWrite(S1.Vermelho, HIGH);

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
    digitalWrite(S1.Verde, LOW);
    digitalWrite(S1.Amarelo, HIGH);
    delay(2000);
    digitalWrite(S1.Amarelo, LOW);
    digitalWrite(S2.Vermelho, LOW);
    digitalWrite(S2.Verde, HIGH);
    digitalWrite(S1.Vermelho, HIGH);

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
    digitalWrite(S2.Verde, LOW);
    digitalWrite(S2.Amarelo, HIGH);
    delay(2000);
    digitalWrite(S2.Amarelo, LOW);
    digitalWrite(S2.Vermelho, HIGH);
    digitalWrite(S1.Vermelho, LOW);
    digitalWrite(S1.Verde, HIGH);

    delay(15000); //aguarda 15s antes de reiniciar o ciclo
    estado = estado1;
    break;
  }
}