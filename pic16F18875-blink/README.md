# Parpadeo de LED en Ensamblador con PIC16F18875 y MPLAB X IDE

Este proyecto implementa un ejemplo básico de parpadeo de un LED utilizando lenguaje ensamblador (Assembly) con el microcontrolador PIC16F18875. El objetivo es comprender el uso de instrucciones básicas como `bsf`, `bcf` y la creación de retardos por software, ejecutado sobre una placa Curiosity HPC.

## Herramientas utilizadas

-  **MPLAB X IDE**
- **XC8 Assembler (modo Assembly)**
- **Placa Curiosity HPC**
- **PIC16F18875**

## 📁 Estructura del código

- `led_parpadeo.s`: archivo fuente en ensamblador. Implementa:
  - Encendido y apagado del pin RA4 usando instrucciones `bsf` y `bcf`.
  - Bucles de retardo por software para generar una frecuencia de parpadeo de ~1 segundo.

## ⚙️ Funcionamiento

El LED conectado al pin **RA4** parpadea con un intervalo aproximado de **1 segundo**, generado mediante retardos por software en un bucle principal.

## 🧠 Objetivos didácticos

- Aprender a manipular registros de salida (`PORTA`) a bajo nivel.
- Comprender la lógica de bucles en lenguaje ensamblador.
- Usar MPLAB X para compilar y cargar código Assembly en microcontroladores PIC.

## 📷 Resultado esperado

> El LED en el pin RA4 se enciende y apaga cada segundo.
