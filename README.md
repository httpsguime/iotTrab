# Projeto de Automação Residencial com ESP8266 e Blynk

Este projeto visa criar um sistema de automação residencial utilizando o módulo ESP8266 NodeMCU, a plataforma Blynk e LEDs representando dispositivos elétricos. O sistema permite ligar e desligar os LEDs através de um aplicativo móvel.

## Componentes Necessários

- 1 x Módulo ESP8266 NodeMCU (v3 Lolin)
- 4 x LEDs
- 4 x Resistores de 150Ω
- Jumpers
- Protoboard
- Cabo USB

## Configuração do Hardware

1. Conecte os LEDs aos pinos GPIO do ESP8266:
   - LED1: Anodo ao GPIO5 (D1), Catodo ao GND
   - LED2: Anodo ao GPIO4 (D2), Catodo ao GND
   - LED3: Anodo ao GPIO0 (D3), Catodo ao GND
   - LED4: Anodo ao GPIO2 (D4), Catodo ao GND
   - **Nota:** Use resistores de 150Ω em série com os LEDs para limitar a corrente.

## Configuração do Software

### Passos para Configurar o Ambiente

1. **Instale o Arduino IDE:**
   - Baixe e instale o Arduino IDE a partir do [site oficial](https://www.arduino.cc/en/software).

2. **Adicione Suporte ao ESP8266 no Arduino IDE:**
   - Vá para `File` > `Preferences`.
   - Adicione `http://arduino.esp8266.com/stable/package_esp8266com_index.json` no campo "Additional Board Manager URLs".
   - Vá para `Tools` > `Board` > `Boards Manager` e instale o pacote "esp8266".

3. **Instale a Biblioteca Blynk:**
   - Vá para `Sketch` > `Include Library` > `Manage Libraries`.
   - Procure por "Blynk" e instale a biblioteca Blynk.

### Código

```cpp
//Substitua com suas credenciais do Blynk
#define BLYNK_TEMPLATE_ID "YourBlynkID"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "YourBlynkToken"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Substitua com suas credenciais Wi-Fi
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

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
```

### Passos para Carregar o Código

1. **Conecte o ESP8266 ao Computador:**
   - Use um cabo USB para conectar o ESP8266 ao seu computador.

2. **Configurar a Placa e a Porta no Arduino IDE:**
   - Vá para `Tools` > `Board` e selecione `NodeMCU 1.0 (ESP-12E Module)`.
   - Vá para `Tools` > `Port` e selecione a porta correta (por exemplo, `COM3` ou `/dev/ttyUSB0`).

3. **Carregar o Código:**
   - Clique no botão de upload (ícone de seta para a direita) no Arduino IDE para carregar o código para o ESP8266.

### Configuração do Blynk

1. **Baixe o Aplicativo Blynk:**
   - Baixe e instale o aplicativo Blynk no seu smartphone a partir da App Store ou Google Play.

2. **Crie uma Nova Conta e Novo Projeto:**
   - Abra o aplicativo Blynk e crie uma nova conta.
   - Crie um novo projeto e selecione o dispositivo como `NodeMCU`.

3. **Obtenha o Token de Autenticação:**
   - O token de autenticação será enviado para o seu e-mail. Copie esse token e substitua a variável `auth` no código pelo token recebido.

4. **Adicione Botões ao Projeto:**
   - Adicione quatro botões ao seu projeto Blynk e configure-os para controlar os pinos virtuais `V1`, `V2`, `V3`, e `V4`.

### Testando o Projeto

1. **Conecte o ESP8266 à Rede Wi-Fi:**
   - Quando o código for carregado com sucesso, o ESP8266 se conectará à rede Wi-Fi e ao Blynk Cloud.

2. **Controle os LEDs pelo Aplicativo Blynk:**
   - Abra o aplicativo Blynk no seu smartphone e use os botões para ligar e desligar os LEDs.

### Problemas Comuns

- **Falha ao Conectar ao ESP8266:**
  - Verifique se o cabo USB está funcionando corretamente.
  - Certifique-se de que os drivers USB estão instalados.
  - Verifique se as configurações da placa e da porta estão corretas no Arduino IDE.

- **Não Consegue Conectar ao Wi-Fi:**
  - Verifique se o SSID e a senha estão corretos.
  - Certifique-se de que a rede Wi-Fi é de 2.4 GHz (o ESP8266 não suporta 5 GHz).

### Contribuição

Se você encontrar algum problema ou tiver sugestões para melhorar este projeto, sinta-se à vontade para abrir uma issue ou enviar um pull request.

