# 1) Reglas del juego (requisitos claros)

### Estados
- **DESARMADO**
- **ARMADO**
- **EN_ALARMA**

### Arranque
- El sistema **siempre inicia en modo DESARMADO**.

### Código por 3 pulsadores
Si la **secuencia correcta** es ingresada:
- Desde **DESARMADO → ARMADO**
- Desde **ARMADO o EN_ALARMA → DESARMADO**

### Sensor
- Solo se evalúa en modo **ARMADO**.  
- Si se activa el sensor → pasa a **EN_ALARMA**.

### Reset
- El **reset** devuelve el sistema a **DESARMADO**.

### Interfaz
- **Entradas:**
  - `reset`
  - `clock`
  - `btn[2:0]` → 3 pulsadores para el código
  - `sensor`
- **Salidas:**
  - `LED`
  - *(Opcional)* `buzzer/audio`
  - *(Opcional)* `BCD 7 segmentos`
