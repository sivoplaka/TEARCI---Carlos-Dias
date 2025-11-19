#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <TouchScreen.h>

// Pinos do display TFT
#define LCD_CS A3    
#define LCD_CD A2    
#define LCD_WR A1    
#define LCD_RD A0    
#define LCD_RESET A4 

// Pinos do touchscreen
#define YP A1  
#define XM A2  
#define YM 7   
#define XP 6   

// Calibração do toque (ajustada para landscape)
#define TS_MINX 214  
#define TS_MAXX 917  
#define TS_MINY 220  
#define TS_MAXY 937  

// Cores
#define BLACK   0x0000
#define WHITE   0xFFFF
#define GREEN   0x07E0
#define RED     0xF800

// Inicialização do display e touch
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Variáveis
String setpoint = "";
bool setpointEntered = false;

// Funções
void drawKeypad();
void drawSetpoint(bool confirmed = false);

void setup() {
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);  // ✅ Agora fica em modo LANDSCAPE (deitado)
  tft.fillScreen(BLACK);
  drawKeypad();
  drawSetpoint();
}

void loop() {
  TSPoint p = ts.getPoint();
  
  // Restaurar pinos após leitura do toque
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);

  if (p.z > ts.pressureThreshhold) {
    // 🔥 Ajustando os eixos do toque para modo paisagem 🔥
    int mappedX = map(p.y, TS_MINY, TS_MAXY, 0, 320);  
    int mappedY = map(p.x, TS_MINX, TS_MAXX, 0, 240);  

    Serial.print("Toque -> X: "); Serial.print(mappedX);
    Serial.print(" Y: "); Serial.println(mappedY);

    // Verificar se tocou no teclado
    if (mappedY > 60) {  
      int row = (mappedY - 60) / 50;  
      int col = mappedX / 80;        
      int key = row * 3 + col + 1;

      if (key == 10) {  
        setpoint += "0";  
      } 
      else if (key == 11) {  // Apagar o último caractere "<-"
        if (setpoint.length() > 0) {  
          setpoint.remove(setpoint.length() - 1);  
        }
      } 
      else if (key == 12) {  // Enter "E" (Confirmar setpoint)
        setpointEntered = true;  
        drawSetpoint(true);
        delay(1000);
        drawSetpoint(false);
      } 
      else if (key < 10) {  
        setpoint += String(key);  
      }

      drawSetpoint();
      delay(300);
    }
  }
}

// 🔥 Desenha o teclado corrigido para landscape 🔥
void drawKeypad() {
  tft.fillRect(0, 60, 320, 180, WHITE);  
  tft.setTextColor(BLACK);
  tft.setTextSize(2);

  String keys[4][3] = {
    {"1", "2", "3"},
    {"4", "5", "6"},
    {"7", "8", "9"},
    {"0", "<-", "E"}  // 🔥 Agora "<-" apaga e "E" confirma
  };

  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 3; col++) {
      int x = col * 80;
      int y = 60 + row * 50;
      tft.drawRect(x, y, 80, 50, BLACK);
      tft.setCursor(x + 30, y + 15);
      tft.print(keys[row][col]);
    }
  }
}

// 🔥 Atualiza o setpoint no display 🔥
void drawSetpoint(bool confirmed) {
  tft.fillRect(10, 10, 300, 40, BLACK);
  tft.setTextSize(2);
  tft.setTextColor(confirmed ? GREEN : WHITE);
  tft.setCursor(10, 25);
  tft.print("Setpoint: " + setpoint);
}
