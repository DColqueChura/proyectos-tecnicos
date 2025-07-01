#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

// --- Configuración DHT11 ---
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// --- Configuración LCD I2C ---
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// --- Configuración Wi-Fi y ThingSpeak ---
/*Definimos como constantes Char las credenciales de acceso a la red WiFi*/
const char* ssid     = " ";
const char* password = " ";
unsigned long channelID = ;       // tu Channel ID
const char* writeAPIKey = " ";  // tu Write API Key

//Definimos el cliente WiFi que usaremos
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(1000); 

  //Inicia DHT11
  /*Imprimimos una frase, e iniciamos nuestro sensor DHT*/
  Serial.println("Sensores Instalados y listos");
  dht.begin();

  //Inicia LCD
  Wire.begin(21, 22);  //Inicializa el bus I2C en los pines por defecto del ESP32
  lcd.begin();
  lcd.backlight();

  // Conecta Wi-Fi
  WiFi.begin(ssid, password);
  /*Iniciamos la conexión a la red WiFi, y se imprimirán caracteres indicando el tiempo que tarda la conexión*/
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  /*Una vez conextado, se imprimirá una frase y se iniciará la conexión a la Plataforma usando el cliente definido anteriormente*/
  Serial.println("WiFi conectado");

  //Inicia ThinkSpeak
  ThingSpeak.begin(client);
  delay(500);
}

void loop(){
  /*Usamos un retardo de 5 segundos, y utilizamos la función Medición para la lectura de los sensores*/
  delay(5000);
  medicion();
  /*Hacemos la conexión y envío de datos a la plataforma, utilizando las credenciales definidas anteriormente*/
  ThingSpeak.writeFields(channelID,writeAPIKey);
  /*Imprimimos una frase indicando el envío, y agregamos un retardo de 10 segundos*/
  Serial.println("Datos enviados a ThingSpeak!");
  delay(10000);
}

/*Definimos la función Medición*/
void medicion() {
  lcd.clear();
  //Lee sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  /*Imprimimos los valores obtenidos en el terminal Serial*/
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C  ");
  //-----LCD por I2C
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C  ");

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.println(" %");
  //-----LCD por I2C
  lcd.setCursor(0,1);
  lcd.print("Hum:  ");
  lcd.print(h);
  lcd.print(" %");
  Serial.println("-----------------------------------------");
  /*Indicamos el orden de envío por campos o Field, en el orden definido de la plataforma, junto a los valores del sensor*/
  ThingSpeak.setField(1,t);
  ThingSpeak.setField(2,h);
}
