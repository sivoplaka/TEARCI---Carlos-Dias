#include <Arduino.h>

unsigned long previous_time = millis();
unsigned long interval = 10000;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if(millis() - previous_time > interval)
  {
    Serial.println("Tempo");

    previous_time = millis();
  }
}
