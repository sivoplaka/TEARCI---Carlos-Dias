/*Código todo elaborado segundo a formação em aula transmitida pelo formador Miguel
e este tutorial: https://roboticsbackend.com/arduino-turn-led-on-and-off-with-button/
para entender como seria o código para o botão*/

//definir os periféricos
const int pinRed = 9;
const int pinGreen = 6;
const int pinBlue = 5;
const int BUTTON_PIN = 7;

//configuração de estados para o switch case
enum ESTADO {
    GREEN,   
    YELLOW,
    RED
};

ESTADO estado = GREEN; //iniciar na luz verde


void setup() {
  //definir o tipo de periféricos
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);//velocidade de resposta padrão para o Arduino Uno
}

void loop() {
  //inicia o loop na cor verde
  switch (estado) {
    case GREEN:
      analogWrite(pinRed, 0);
      analogWrite(pinBlue, 0);
      analogWrite(pinGreen, 255);
      while (digitalRead(BUTTON_PIN) == HIGH) //enquanto o botão não for pressionado, fica em loop no while 
      {
        estado = YELLOW; //quando o botão é pressionado
      }
      break;

    case YELLOW:
      //liga a luz amarela
      analogWrite(pinRed, 255);
      analogWrite(pinBlue, 0);
      analogWrite(pinGreen, 255);
      delay(2000);
      estado = RED; //espera 2 segundos e muda de estado
      break;

    case RED:
      //liga a luz vermelha
      analogWrite(pinRed, 255);
      analogWrite(pinBlue, 0);
      analogWrite(pinGreen, 0);
      delay(4000); //espera 4 segundos e regressa ao ponto inicial
      estado = GREEN;
      break;
  }
}