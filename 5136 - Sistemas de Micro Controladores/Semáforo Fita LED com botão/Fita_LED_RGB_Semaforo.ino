/*Código todo elaborado segundo a formação em aula transmitida pelo formador Miguel
e este tutorial: https://roboticsbackend.com/arduino-turn-led-on-and-off-with-button/
para entender como seria o código para o botão*/

//esta é, provavelmente a forma mais simples

//definir os periféricos
const int pinRed = 9;
const int pinGreen = 6;
const int pinBlue = 5;
const int BUTTON_PIN = 7;


void setup() {
  //definir o tipo de periféricos
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);//velocidade de resposta padrão para o Arduino Uno
}

void loop() {
      //liga a luz verde ao entrar no loop
      digitalWrite(pinRed, LOW);
      digitalWrite(pinBlue, LOW);
      digitalWrite(pinGreen, HIGH);
      
      //só quando é pressionado o botão, é que muda para amarelo e consequentemente para vermelho
      if (digitalRead(BUTTON_PIN) == HIGH)
      {
        digitalWrite(pinRed, HIGH);
        digitalWrite(pinBlue, LOW);
        digitalWrite(pinGreen, HIGH);
        delay(2000);
        digitalWrite(pinRed, HIGH);
        digitalWrite(pinBlue, LOW);
        digitalWrite(pinGreen, LOW);
        delay(4000);
        //no fim, regressa ao início do loop, para cor verde
      }
      
}