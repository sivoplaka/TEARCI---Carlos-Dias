#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <Stepper.h>

// Configuração do motor de passo
const int stepsPerRevolution = 2048;
#define IN1 19
#define IN2 18
#define IN3 16
#define IN4 17
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// Credenciais do Access Point
const char* ssid = "Tapete";
const char* password = "12345678";

// Criação do servidor web
WebServer server(80);

// Variável para indicar se o tapete foi iniciado
bool tapeteIniciado = false;

// Página HTML para o controle
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>Controlo Industrial</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script>
    function iniciarTapete() {
      fetch('/start', { method: 'POST' })
        .then(() => {
          document.getElementById('startBtn').disabled = true;
          document.getElementById('startBtn').innerText = "Tapete iniciado";
        });
    }
  </script>
</head>
<body>
  <h1>Controlo Industrial</h1>
  <button id="startBtn" onclick="iniciarTapete()">Ligar Tapete</button>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", index_html);
}

void handleStart() {
  tapeteIniciado = true;
  server.send(200, "text/plain", "Tapete iniciado");
}

void setup() {
  Serial.begin(115200);
  
  // Configurar o ESP32 como Access Point
  WiFi.softAP(ssid, password);
  Serial.print("Access Point iniciado. IP: ");
  Serial.println(WiFi.softAPIP());

  myStepper.setSpeed(5);

  // Definir rotas do servidor
  server.on("/", HTTP_GET, handleRoot);
  server.on("/start", HTTP_POST, handleStart);

  server.begin();
}

void loop() {
  server.handleClient();
  if (tapeteIniciado) {
    myStepper.step(stepsPerRevolution); // O motor gira indefinidamente
  }
}