#include <Arduino.h>

class Sensor
{
  public:
    const int trigger;
    const int echo;

    void detetar_carro_estado2();
    void saida_carro_estado3();
};

void Sensor::detetar_carro_estado2()
{
  do
    {
      distance_cm = medirDistancia();
      Serial.print("Distância: ");
      Serial.print(distance_cm);
      Serial.println(" cm");
      delay(100);
    } while (distance_cm <= 15); //enquanto nenhum carro for detetado <= 15cm
      estado = estado2; //passa para o próximo estado
    
};

void Sensor::saida_carro_estado3()
{
  do
    {
      distance_cm = medirDistancia();
      Serial.print("Distância: ");
      Serial.print(distance_cm);
      Serial.println(" cm");
      delay(100);
    } while (distance_cm <= 15); //enquanto nenhum carro for detetado <= 15cm

    estado = estado3; //passa para o próximo estado
}

class Semaforo
{
  public:
    const int Vermelho;
    const int Amarelo;
    const int Verde;
    const int trigger;
    const int echo;

    void ligar_verde();
    void ligar_vermelho();
    void ligar_amarelo();
};

void Semaforo::ligar_verde()
{
  digitalWrite(Verde, HIGH);
  digitalWrite(Amarelo, LOW);
  digitalWrite(Vermelho, LOW);
};

void Semaforo::ligar_vermelho()
{
  digitalWrite(Vermelho, HIGH);
  digitalWrite(Amarelo, LOW);
  digitalWrite(Verde, LOW);
};

void Semaforo::ligar_amarelo()
{
  digitalWrite(Vermelho, LOW);
  digitalWrite(Amarelo, HIGH);
  digitalWrite(Verde, LOW);
};

// typedef struct semaforo //defenir estrutura
// {
//   const int Vermelho;
//   const int Amarelo;
//   const int Verde;
//   const int trigger;
//   const int echo;
// };

Semaforo S1 = //configuração de estrutura do semaforo 1
{
  .Vermelho = 6,
  .Amarelo = 7,
  .Verde = 9
};

Semaforo S2 = //configuração de estrutura do semaforo 2
{
  .Vermelho = 9,
  .Amarelo = 10,
  .Verde = 11
};

Sensor sensor = //configuração de estrutura do sensor
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
    S1.ligar_verde();
    S2.ligar_vermelho();
    sensor.detetar_carro_estado2();
    break;
  case estado2:
    //passa S1 a amarelo e depois de 2s, S1 vermelho e S2 verde
    
    S1.ligar_amarelo();
    delay(2000);
    S2.ligar_verde();
    S1.ligar_vermelho();
    sensor.saida_carro_estado3();
    break;

  case estado3:
    //passa S2 a amarelo e depois de 2s, S2 vermelho e S1 verde
    delay(2000);
    S2.ligar_amarelo();
    
    delay(2000);
    S2.ligar_vermelho();
    S1.ligar_verde();

    delay(15000); //aguarda 15s antes de reiniciar o ciclo
    estado = estado1;
    break;
  }
}