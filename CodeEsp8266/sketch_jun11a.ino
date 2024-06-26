#define BLYNK_TEMPLATE_ID "TMPL2R2QjpC61"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "hBuIcKstbpEGblB8gEKYwXuF45-Xdi7L"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Substitua com suas credenciais Wi-Fi
char ssid[] = "iPhone de campo";
char pass[] = "credito12";

// Token do Blynk (substitua pelo token copiado do aplicativo)
char auth[] = BLYNK_AUTH_TOKEN;

void setup()
{
  // Inicializa a serial e o Blynk
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Configura os pinos como saída
  pinMode(5, OUTPUT); // GPIO5 (D1)
  pinMode(4, OUTPUT); // GPIO4 (D2)
  pinMode(0, OUTPUT); // GPIO0 (D3)
  pinMode(2, OUTPUT); // GPIO2 (D4)
}

void loop()
{
  Blynk.run();
}

// Funções Blynk para controle dos LEDs
BLYNK_WRITE(V1) {
  int estado = param.asInt();
  digitalWrite(5, estado); // GPIO5 (D1)
}

BLYNK_WRITE(V2) {
  int estado = param.asInt();
  digitalWrite(4, estado); // GPIO4 (D2)
}

BLYNK_WRITE(V3) {
  int estado = param.asInt();
  digitalWrite(0, estado); // GPIO0 (D3)
}

BLYNK_WRITE(V4) {
  int estado = param.asInt();
  digitalWrite(2, estado); // GPIO2 (D4)
}

