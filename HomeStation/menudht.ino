#include "DHT.h"

//sensor de temperatura e umidade
#define DHTPIN A0              //Pino analogico em que o sensor DHT11 esta conectado
#define DHTTYPE DHT11          //Definindo o tipo do sensor: DHT11
DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 12; // Pino em que o led deve estar conectado
int read;      // variavel para ler dados do serial

void setup() {
  // inicializa comunicacao com o serial:
  Serial.begin(9600);
  // inicializa o led como output:
  pinMode(ledPin, OUTPUT);
  dht.begin();
  
  Serial.print("\n");
  Serial.println("###############");
  Serial.println("###   Menu  ###");
  Serial.println("###############");
  Serial.println("\n Digite o numero do item desejado:");
  Serial.println("(1) - Temperatura Atual");
  Serial.println("(2) - Humidade ");
  Serial.println("(3) - Piscar LED");
}

void loop() {
  
  //Valor da Umidade
  float Humi = dht.readHumidity();
  //Valor da temperatura
  float Temp = dht.readTemperature();
  
  if (Serial.available() > 0) {
    // leitura do byte mais antigo do buffer:
    read = Serial.read();
  
  switch (read) {
      case '1':
        Serial.print("\n Temperatura atual: ");
        Serial.print(Temp);
        Serial.print(" C");
        break;
      case '2':
        Serial.print("\n Humidade atual: ");
        Serial.print(Humi);
        Serial.print(" UR");
        break;
      case '3':
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        break;
      default:
      Serial.println("\n Opcao Invalida");
      Serial.print("\n");
      Serial.println("##############");
      Serial.println("###  Menu  ###");
      Serial.println("##############");
      Serial.println("Digite o numero do item desejado:");
      Serial.println("(1) - Temperatura Atual");
      Serial.println("(2) - Humidade ");
      Serial.println("(3) - Piscar LED");

        }
    }
}
