/*UNIVERDIDAD TECNICA DEL NORTE
*FICA-CITEL
*SISTEMAS EMBEBIDOS
*LABORATORIO#2
*PUERTOS DIGITALES Y COMUNICACION SERIAL
*LISSETH ALBAN
*/
 
#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
 
LiquidCrystal lcd(4, 6, 11, 12, 13, 14);//pines del arduino al LCD (RS E D4 D5 D6 D7) RESPECTIVAMENTE
RTC_DS1307 RTC;
 
void setup()
{
Wire.begin(); //configura el bus I2C estableciendo arduino como MASTER
RTC.begin();
if (! RTC.isrunning()) // se verifica si el modulo rtc esta en funcionamiento, de lo contrario, se imprime: RTC is NOT running!
{
lcd.println("RTC NO FUNCIONA");
delay(10000);
}
RTC.adjust(DateTime(__TIME__));
 
lcd.begin(16,2);
lcd.clear();
}
 
void loop()
{
mostrarRTCLCD(); //Se manda a llamar la funcion "mostrarRTCLCD" y despues se espera un tienpo de 1seg
delay(1000);
}
 
void mostrarRTCLCD() //Funcion que lee los datos de modulo RTC y despues los imprime en el display
{
DateTime now = RTC.now(); //obtiene datos del modulo RTC
lcd.clear();
lcd.setCursor(0,0);
if(now.day() < 10)
{
lcd.print("0");
}
lcd.setCursor(0,1);
if(now.hour() < 10)
{
lcd.print("0");
}
lcd.print(now.hour(), DEC); //imprime hora
lcd.print(':');
if(now.minute() < 10)
{
lcd.print("0");
}
lcd.print(now.minute(), DEC); //imprime minutos
lcd.print(':');
if(now.second() < 10)
{
lcd.print("0");
}
lcd.print(now.second(), DEC); //imprime segundos
}
