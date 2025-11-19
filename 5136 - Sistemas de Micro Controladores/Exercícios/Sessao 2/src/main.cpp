#include <Arduino.h>

unsigned long previous_time = millis();
unsigned long interval = 5000;

void setup()
{

}

void loop()
{
  //implementar temporizador
  //testar condição de tempo do intervalo 
  Serial.println(millis());
  Serial.println(previous_time);
  Serial.println("");
  if (millis() - previous_time > interval)
  {
    //correr o código
    
    //reset à variável
    previous_time = millis();
  }
}