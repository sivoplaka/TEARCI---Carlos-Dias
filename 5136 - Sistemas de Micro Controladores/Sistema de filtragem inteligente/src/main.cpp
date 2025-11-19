#include <Arduino.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  switch (estado)
  {
  case testar_sensores:
    //testar sensores pressionando o botão
    if (digitalRead(BOTAO) == HIGH)
    {
      Serial.println("A testar sensores");
      delay(1000);
      Serial.println("Teste concluido");
      delay(1000);
    //voltar ao estado torneira fechada ou aberta consoante a leitura do caudalímetro
    if (digitalRead(CAUDALIMETRO) == HIGH)
    {
      estado = torneira_aberta;
    }
    else
    {
      estado = torneira_fechada;
    }
    break;
  case torneira_fechada:
    //manda analisar se há fuga de água, no estado fuga_de_agua
      estado = fuga_de_agua;
    
  case torneira_aberta:
    /* code */
    break; 
  case fuga_de_agua:
    /* code */
    break;
  case capacidade_maxima:
    /* code */
    break;
  case aviso_capacidade_maxima:
    /* code */
    break;

  default:
    break;
  }
}