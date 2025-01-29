#define RLED 5
#define YLED 6 
#define GLED 7

void setup() {
   
  pinMode(RLED, OUTPUT);
  pinMode(YLED,   OUTPUT);
  pinMode(GLED, OUTPUT);
}

void loop() {
  
  digitalWrite(GLED, HIGH);
  delay(5000);
  digitalWrite(GLED, LOW);
  delay(200);
  digitalWrite(YLED, HIGH);
  delay(2000);
  digitalWrite(YLED, LOW);
  delay(200);
  digitalWrite(RLED, HIGH);
  delay(5000); 
  digitalWrite(RLED, LOW);
  
}