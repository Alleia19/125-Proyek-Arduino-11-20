/*************************************
 * Program : Project 19. Digital thermometer dengan thermocouple
 * Input   : Sensor Thermocouple 
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
 #include <max6675.h> 
 #include <LiquidCrystal.h> 
 #include <Wire.h> 
  
 int DO = 8; 
 int CS = 9; 
 int CLK = 10; 
  
 MAX6675 themp(CLK, CS, DO); 

 int suhuC, suhuF;
  
 LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
   uint8_t degree[8]  = {140,146,146,140,128,128,128,128}; 
  
 void setup() { 
   lcd.begin(16, 2); 
   lcd.createChar(0, degree); 
   delay(500); 
   lcd.clear(); 
   lcd.setCursor(0, 0); 
   lcd.print("    Digital"); 
   lcd.setCursor(0, 1); 
   lcd.print("  Thermometer"); 
   delay(2000);
   lcd.clear(); 
 } 
  
 void loop() { 
   suhuC=themp.readCelsius(); 
   lcd.setCursor(0, 0); 
   lcd.print("Suhu:"); 
   lcd.print(suhuC); 
   lcd.write((byte)0); 
   lcd.print("C "); 
   
   suhuF=themp.readFahrenheit();
   lcd.setCursor(5, 1); 
   lcd.print(suhuF); 
   lcd.write((byte)0); 
   lcd.print("F  ");
   delay(1000); 
 }


