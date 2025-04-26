/******************************************************************************************************************
SmartTechData GPS 2021

  + Matías Jorquera
  + Yamila Carabante
  + Guillermo Sotelo
  + Daniela Colque Chura
  
 * DESCRIPCION: Sketch que permite el envío de un sms desde el SIM800L
 
 * ****************************************************************************************************************/

#include <SoftwareSerial.h>

SoftwareSerial SerialComSim800(8,7); // en arduino TX  , RX 

void setup()
{
  //Serial.begin(15200);
  Serial.begin(9600);
  SerialComSim800.begin(9600);

  Serial.println("Iniciando..."); 
  //delay(2000);
  delay(1000);

  SerialComSim800.println("AT"); //check OK
  serialCheck();
 
  SerialComSim800.println("AT+CMGF=1"); // Formato SMS texto 
  serialCheck();
                      
  SerialComSim800.println("AT+CNMI=1,2,0,0,0"); 
  serialCheck();

  SerialComSim800.println("AT+CMGS=\"+5492944487730\""); // Envía el sms al número especificado
  serialCheck();
  
  SerialComSim800.print("Hola desde SIM800L");
  serialCheck();
  
  //SerialComSim800.write(26);  // Convencion ^Z -> 'Ctrl+z' -> 26DEC (1AHEX)  ASCII -> SUB.
}

void loop()
{
  serialCheck();
}

void serialCheck()
{
  delay(500);
  while (Serial.available()) 
  {
    SerialComSim800.write(Serial.read());
  }
  while(SerialComSim800.available()) 
  {
    Serial.write(SerialComSim800.read());
  }
  //delay(700);
}
