PROCESSOR 16F18875
LIST
#include <xc.inc>
////////////////////////////////////////////////////////////////    

; PIC16F18875 Configuration Bit Settings

; Assembly source line config statements

; CONFIG1
  CONFIG  FEXTOSC = ECH         ; External Oscillator mode selection bits (EC above 8MHz; PFM set to high power)
  CONFIG  RSTOSC = LFINT        ; Power-up default value for COSC bits (LFINTOSC)
  CONFIG  CLKOUTEN = OFF        ; Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
  CONFIG  CSWEN = ON            ; Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
  CONFIG  FCMEN = ON            ; Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

; CONFIG2
  CONFIG  MCLRE = ON            ; Master Clear Enable bit (MCLR pin is Master Clear function)
  CONFIG  PWRTE = OFF           ; Power-up Timer Enable bit (PWRT disabled)
  CONFIG  LPBOREN = OFF         ; Low-Power BOR enable bit (ULPBOR disabled)
  CONFIG  BOREN = ON            ; Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
  CONFIG  BORV = LO             ; Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
  CONFIG  ZCD = OFF             ; Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
  CONFIG  PPS1WAY = ON          ; Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
  CONFIG  STVREN = ON           ; Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

; CONFIG3
  CONFIG  WDTCPS = WDTCPS_31    ; WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
  CONFIG  WDTE = ON             ; WDT operating mode (WDT enabled regardless of sleep; SWDTEN ignored)
  CONFIG  WDTCWS = WDTCWS_7     ; WDT Window Select bits (window always open (100%); software control; keyed access not required)
  CONFIG  WDTCCS = SC           ; WDT input clock selector (Software Control)

; CONFIG4
  CONFIG  WRT = OFF             ; UserNVM self-write protection bits (Write protection off)
  CONFIG  SCANE = available     ; Scanner Enable bit (Scanner module is available for use)
  CONFIG  LVP = ON              ; Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)

; CONFIG5
  CONFIG  CP = OFF              ; UserNVM Program memory code protection bit (Program Memory code protection disabled)
  CONFIG  CPD = OFF             ; DataNVM code protection bit (Data EEPROM code protection disabled)

// config statements should precede project file includes.

///////////////////////////////////////////////////////////////     
PSECT resetVec,class=CODE,delta=2
resetVec:
    PAGESEL main                ;Salta al Main
    goto    main     
PSECT code
 
 
main:

  //BSF	   RP0 ;SELECCIONAR EL BANCO 1
   //MOVLW  00000001B; 8BITS -> W
   // MOVWF  TRISA; W -> PORTB. RB0 - RB7
    CLRF   TRISA; PORTA COMO SALIDA de LEDS
    CLRF   TRISB; CONFIGURAMOS PUERTO B CCOMO SALIDA
    //CLRF   TRISB; CONFIGURAMOS PORTB COMO SALIDA
  //BCF	   RP0 ; SELECCIONAMOS EL BANCO 0
    
START:
    MOVLW  01000000B; 8BITS -> W
    MOVWF  PORTA; W -> PORTB. RB0 - RB7
    GOTO   DELAY1SEG
    MOVLW  00000000B; 8BITS -> W
    MOVWF  PORTA; W -> PORTB. RB0 - RB7
    GOTO   DELAY1SEG
    GOTO   START
    
DELAY1SEG:
    MOVLW   0x1f               ; Carga el valor 31n W
    MOVWF   0x22  ; Guarda W en el registro 0x22
DELAY_LOOP2:
    MOVLW   0xFF            ; Carga el valor 255 en W
    MOVWF   0x21 ;Guarda W en el registro 0x21
DELAY_LOOP1: 
    MOVLW   0xFF                ; Carga el valor 255 en W
    MOVWF   0x20                ; Guarda W en el registro 0x20

DELAY_LOOP:
    DECFSZ  0x20, F             ; Decrementa el registro 0x20 y salta si es cero
    GOTO    DELAY_LOOP          ; Repite el bucle
    DECFSZ  0x21, F             ; Decrementa el registro 0x21y salta si es cero
    GOTO    DELAY_LOOP1  
    DECFSZ  0x22, F             ; Decrementa el registro 0x20 y salta si es cero
    GOTO    DELAY_LOOP2  
 RETURN                      ; Retorna de la rutina de retardo    

    
       
    
    END main


