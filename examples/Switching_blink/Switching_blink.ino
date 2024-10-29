#include "Arduino.h"
#include "EasyPDLC.h"    //PDLC library

#define OUT_EN 3   //connect Pin ArduinoUNO 3 to 50_Hz_PWM
#define SHCP   2   //connect Pin ArduinoUNO 2 to SHCP
#define STCP   6   //connect Pin ArduinoUNO 6 to STCP
#define DSIN   7   //connect Pin ArduinoUNO 7 to DSIN 
EasyPDLC en(OUT_EN,SHCP, STCP, DSIN); //Initialisation 'en' protocole

void setup() 
{
}

void loop()
{
  while(true)
  {
    e.SetPDLC(0b0101010101);
    e.Latch();
    delay(1000);
    e.SetPDLC(0b1010101010);
    e.Latch();
    delay(1000);
  }
}