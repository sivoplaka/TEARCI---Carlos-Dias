const int pinRed = 9;
const int pinGreen = 6;
const int pinBlue = 5;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);

  analogWrite(pinRed, r);
  analogWrite(pinGreen, g);
  analogWrite(pinBlue, b);
  
  delay(1000);
}
