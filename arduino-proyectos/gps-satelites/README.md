
# Propuesta de Trabajo: Rastreador y localizador de personas.

Este proyecto permite obtener datos de latitud y longitud desde un módulo GPS conectado a un Arduino.

## Objetivo:
*Mandar la ubicación de la persona que practica senderismo, mediante mensajes sms a una o más personas.*

## Hardware utilizado

- Arduino Uno
- Módulo GPS NEO-6M
- Conexión RX/TX

## Requerimientos
Características:
1. Usa GPS
2. No usa la GPRS 
3. Usa la red celular - Conexión a la red móvil
4. Usa SD
5. No utiliza red wifi
6. Obtiene posicion cada 2 hrs 
7. Comunica la posicion obtenida en 6 usando mensajes SMS
8. Para zonas rurales y campo abierto (mientras haya 3)
9. La cantidad de mensajes que se enviará será de 10 mensajes
10. Aplicación para celular (opcional)

## Código

- `GPS_reader.ino`: script para leer datos `$GPGGA` vía Serial

## Salida esperada
- Cantidad de Satélites al instante.
- Latitud: -41.123456 Longitud: -71.987654

[Diagrama-de-Flujo](https://drive.google.com/file/d/1MvYVMCX9AJ9mTIO3pQfe5HQFLFGDXnZP/view?usp=sharing)
--

> 📢 Nota: Este proyecto fue desarrollado en colaboración con Matías Jorquera, Yamila Carabante y Guillermo Sotelo como parte de una práctica académica en 2021.

