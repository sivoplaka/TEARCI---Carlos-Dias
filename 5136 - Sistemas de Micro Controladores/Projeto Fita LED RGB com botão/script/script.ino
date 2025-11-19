const int pinRed = 9;
const int pinGreen = 6;
const int pinBlue = 5;

enum ESTADO
{
	RED;
  YELLOW;
  GREEN;
};
ESTADO estado = GREEN;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  switch (estado)
	{
		case RED:
      analogWrite(pinRed, 255);
      analogWrite(pinGreen, 0);
      analogWrite(pinRed, 0);
      delay(8000);
      estado = GREEN;
			break;
		case YELLOW:
      analogWrite(pinRed, 255);
      analogWrite(pinGreen, 255);
      analogWrite(pinRed, 0);
      delay(3000);
      estado = RED;
			break;
    case GREEN:
      analogWrite(pinRed, 0);
      analogWrite(pinGreen, 255);
      analogWrite(pinRed, 0);
      delay(5000);
      estado = YELLOW;
      break;
		default: //para o caso de ele entrar num estado que não se estava à espera
			//código
			break:
}