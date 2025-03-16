#include <WiFi.h>
#include <PubSubClient.h>
#include <Stepper.h>

// Configuração da rede WiFi
const char* ssid = "CasaD";
const char* password = "";

// Configuração do servidor MQTT
const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;
const char* mqttTopicCommand = "tapete/comando";
const char* mqttTopicStatus = "tapete/status";
const char* mqttTopicCount = "tapete/contagem";

WiFiClient espClient;
PubSubClient client(espClient);

// Configuração do motor de passo
const int stepsPerRevolution = 2048;
#define IN1 19
#define IN2 18
#define IN3 16
#define IN4 17
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// Máquina de estados
enum EstadoTapete { E1_INTERACAO, E2_LIGAR, E3_CONTAGEM, E4_DESLIGAR };
EstadoTapete estadoAtual = E1_INTERACAO;

// Variáveis globais
int contagemPecas = 0;
bool tapeteLigado = false;
unsigned long ultimoTempo = 0;

void callbackMQTT(char* topic, byte* payload, unsigned int length) {
  String mensagem;
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }
  if (mensagem == "ON") {
    estadoAtual = E2_LIGAR;
  } else if (mensagem == "OFF") {
    estadoAtual = E4_DESLIGAR;
  }
}

void conectarWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");
  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());
}

void conectarMQTT() {
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callbackMQTT);
  while (!client.connected()) {
    Serial.println("Conectando ao MQTT...");
    if (client.connect("ESP32_Tapete")) {
      Serial.println("Conectado ao MQTT");
      client.subscribe(mqttTopicCommand);
    } else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  conectarWiFi();
  conectarMQTT();
  
  myStepper.setSpeed(5);
}

void loop() {
  client.loop();
  
  switch (estadoAtual) {
    case E1_INTERACAO:
      // Aguarda interação via MQTT
      break;
    
    case E2_LIGAR:
      tapeteLigado = true;
      contagemPecas = 0;
      ultimoTempo = millis();
      estadoAtual = E3_CONTAGEM;
      break;
    
    case E3_CONTAGEM:
      if (tapeteLigado && millis() - ultimoTempo >= 5000) { // Contagem a cada 5 segundos
        myStepper.step(stepsPerRevolution / 10); // Movimento gradual
        contagemPecas++;
        Serial.print("Contagem de peças: ");
        Serial.println(contagemPecas);
        client.publish(mqttTopicCount, String(contagemPecas).c_str()); // Publica no MQTT
        ultimoTempo = millis();
      }
      if (contagemPecas >= 10) {
        estadoAtual = E4_DESLIGAR;
      }
      break;
    
    case E4_DESLIGAR:
      tapeteLigado = false;
      client.publish(mqttTopicStatus, "Desligado");
      Serial.println("Tapete desligado");
      estadoAtual = E1_INTERACAO;
      break;
  }
}