/******************************************************************************************************************
Proyecto GPS - SmartTechData GPS (2021)

Participantes:
  - Matías Jorquera
  - Yamila Carabante
  - Guillermo Sotelo
  - Daniela Colque Chura
  
 DESCRIPCION: 
   Sketch que permite el envío de un sms de la ubicación de la persona.
 
 * ****************************************************************************************************************/

/* 
 *  Conexion pines
 ****************************
 *  Arduido     GPS 
 *    D3 (Tx)   Rx
 *    D2 (Rx)   Tx
 ****************************    
 *              SIM800L
 *    D7        Rx
 *    D8        Tx
 ****************************
*/

#include <SoftwareSerial.h> // Incluimos SoftwareSerial
#include <TinyGPS.h>        // Incluimos TinyGPS

float latitud, longitud;    // Variable que guarda la latitud y longitud
int contador = 0;            // Variable para controlar la cantidad de mensajes enviados 

TinyGPS gps;                         // Declaramos el objeto GPS
SoftwareSerial SerialComSim800(8,7); // Declaramos el objeto SerialComSim800 en los pines D8 y D7 del arduido

//Declaramos las variables para la obtención de datos
int year;
byte month, day, hour, minute, second, hundredths;
unsigned long chars;
unsigned short sentences, failed_checksum;

void setup()
{
  Serial.begin(9600);         //Iniciamos el puerto serie
  SerialComSim800.begin(9600);// Iniciamos el puerto serie del SIM800L
  
  // Imprimimos en el monitor serial:
  Serial.println("");
  Serial.println("Bienvenido al GPS Rastreador");
  Serial.println("----Buscando Senal----");
  Serial.println("");
}

void loop()
{
  while(Serial.available())
  {
    int c=Serial.read();
    if(gps.encode(c))
    {
      gps.f_get_position(&latitud, &longitud);
      Serial.print("Latitud/Longitud: ");
      Serial.print(latitud,5); //Imprimir latitud con 5 decimales
      Serial.print(", ");
      Serial.println(longitud,5);
      
      gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
      Serial.print("Fecha: "); Serial.print(day, DEC); Serial.print("/");
      Serial.print(month, DEC); Serial.print("/"); Serial.print(year);
      Serial.print("Hora: "); Serial.print(hour, DEC); Serial.print(":");
      Serial.print(minute, DEC); Serial.print(":"); Serial.print(second, DEC);
      Serial.print(":"); Serial.print(hundredths, DEC);
      Serial.print("Altitud (metros): "); Serial.println(gps.f_altitude());
      Serial.print("Rumbo (grados)"); Serial.println(gps.f_course());
      Serial.print("Velocidad(kmph): "); Serial.print(gps.f_speed_kmph());
      Serial.print("Satelites: "); Serial.println(gps.satellites());
      Serial.println();
      
      gps.stats(&chars,&sentences,&failed_checksum);
    }
   }

   if((contador==0)||(contador<=7))
   {
     Serial.println("Configuracion Completa!");
      Serial.println("Enviando SMS...");

      //Se establece el formato de SMS en ASCII
      SerialComSim800.write("AT+CMGF=1\r\n");
      delay(100);

      //Enviar comando para un nuevo SMS al número establecido
      SerialComSim800.write("AT+CMGS=\"+542944487730\"\r\n");
      Serial.print("Mensaje para: +5492944487730\"\r\n ");
      delay(100);

      //Enviar contenido del SMS
      SerialComSim800.println("Latitud/Longitud: ");
      SerialComSim800.print(latitud, 5);
      SerialComSim800.print(" ");
      SerialComSim800.print(longitud, 5);
      delay(7200000); // 2h (7200000) entre mensaje y mensaje

      //Enviar Ctrl+Z
      SerialComSim800.write((char)26);
      delay(200);

      Serial.println("Mensaje enviado!");
   }
 }
 
