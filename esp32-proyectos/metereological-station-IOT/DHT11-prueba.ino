#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include "DHT.h"
#define DHTPIN 4 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 test!"));
  dht.begin();
}
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } else {
    // Línea 1: temperatura
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" °C ");
    // Línea 2: humedad
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println(" % ");
    // Línea 3: separador
    Serial.println("-----------------------");// línea en blanco opcional entre lecturas
    }
}
