# Mini Estación Meteorológica IoT con ESP32, DHT11 y OLED (Arduino IDE)

## Descripción del proyecto

Este proyecto consiste en una mini estación meteorológica basada en el microcontrolador ESP32. Utiliza un sensor DHT11 para medir temperatura y humedad, muestra los datos localmente en una pantalla OLED I2C, y los publica en tiempo real en la plataforma ThingSpeak mediante WiFi.

El proyecto fue desarrollado en Arduino IDE y cumple una doble función de visualización: local (OLED) y remota (ThingSpeak).


## Cómo utilizar este proyecto

1. Leer el archivo `ARQ-ESTACION-METEREOLOGICA-ESP32.pdf` para conocer el alcance y objetivos del proyecto.
2. Realizar pruebas individuales:
   - Ejecutar `DHT11-prueba.ino` para comprobar el sensor DHT11.
   - Ejecutar `I2C-prueba.ino` para verificar el funcionamiento de la pantalla OLED.
3. Si ambas pruebas son exitosas, abrir `main.ino` y completar los siguientes datos:
   - Credenciales WiFi: `ssid` y `password`.
   - ID del canal y API Key de ThingSpeak.
4. Cargar el código al ESP32 y monitorear la salida en la pantalla OLED y en la web.


## Tecnologías utilizadas

- ESP32
- Sensor DHT11
- Pantalla OLED I2C (SSD1306)
- Arduino IDE
- Protocolo I2C
- ThingSpeak

## Archivos del proyecto

- `main.ino`: Código principal del proyecto.
- `DHT11-prueba.ino`: Test del sensor de humedad/temperatura.
- `I2C-prueba.ino`: Test de la pantalla OLED.
- `ARQ-ESTACION-METEREOLOGICA-ESP32.pdf`: Informe técnico del proyecto.

## Resultados

Este proyecto permitió implementar una estación meteorológica IoT con las siguientes funcionalidades:

- Lectura precisa de temperatura y humedad mediante el sensor DHT11.
- Visualización local de datos en una pantalla OLED I2C.
- Transmisión remota de los datos a la nube mediante la plataforma ThingSpeak.
- Posibilidad de monitorización en tiempo real desde cualquier dispositivo con acceso a Internet.





