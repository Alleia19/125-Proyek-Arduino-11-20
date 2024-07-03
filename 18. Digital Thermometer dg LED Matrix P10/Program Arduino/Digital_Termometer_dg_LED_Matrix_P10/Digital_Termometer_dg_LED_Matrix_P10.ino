/*************************************
 * Program : Project 18. Digital Thermometer dg LED Matrix P10
 * Input   : Sensor LM35 
 * Output  : Modul Dotmatrik P10
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <SPI.h>        
#include <DMD.h>        
#include <TimerOne.h>   
#include "SystemFont5x7.h"
 
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
float a;
char b[5];
 
 
void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}
 
 
void setup(void)
{
 Timer1.initialize( 5000 );           
 Timer1.attachInterrupt( ScanDMD );
 dmd.clearScreen( true );
 Serial.begin(9600);   
}
 
 
void loop(void)
{
  dmd.clearScreen( true );
  a = 0;
  a = analogRead(A0);
  a = (5.0*a*100.0)/1024.0; 
  Serial.println(a);
  dtostrf(a, 4, 2, b);
  dmd.selectFont(SystemFont5x7);
  dmd.drawString( 2, 3, b, 5, GRAPHICS_NORMAL );
  delay(5000);   
}
