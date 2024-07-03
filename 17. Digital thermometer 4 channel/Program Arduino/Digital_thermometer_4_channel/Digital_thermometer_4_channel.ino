/*************************************
 * Program : Project 17. Digital thermometer 4 channel
 * Input   : Sensor LM35
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int adc; 
int suhu1, suhu2, suhu3, suhu4;

void setup(){   
  lcd.begin(16, 2);
  lcd.print("  Thermometer");
  lcd.setCursor(0, 1);
  lcd.print("Digital 4CH LM35");     
  delay(2000);
  lcd.clear();
  lcd.print("T1:      T2:   ");
  lcd.setCursor(0, 1);
  lcd.print("T3:      T4:   ");  
}

void loop(){
  adc = analogRead(0); 
  suhu1 = (adc*5)/10;   
  delay(200);
  adc = analogRead(1); 
  suhu2 = (adc*5)/10;   
  delay(200);
  adc = analogRead(2); 
  suhu3 = (adc*5)/10;   
  delay(200);
  adc = analogRead(3); 
  suhu4 = (adc*5)/10;   
  delay(200);
//-----------tampilkan ke LCD  
  lcd.setCursor(3,0);
  lcd.print(suhu1);
  lcd.print("C ");
  lcd.setCursor(12,0);
  lcd.print(suhu2);
  lcd.print("C ");
  lcd.setCursor(3,1);
  lcd.print(suhu3);
  lcd.print("C ");
  lcd.setCursor(12,1);
  lcd.print(suhu4);
  lcd.print("C ");
  delay(200);             
}

