/*************************************
 * Program : Project 20. Digital Thermometer Tampilan Bargraph
 * Input   : Sensor LM35 
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

unsigned int adc,tempLM,a,b,i;

byte bargraph1[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};
byte bargraph2[8] = {
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000
};
byte bargraph3[8] = {
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100
};
byte bargraph4[8] = {
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110
};
byte bargraph5[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
// suhu : 0 - 100
// bar : 15x5 = 50

//============================================
void setup(void) {
  lcd.begin(16, 2);
  lcd.createChar(1, bargraph1);
  lcd.createChar(2, bargraph2);
  lcd.createChar(3, bargraph3);
  lcd.createChar(4, bargraph4);
  lcd.createChar(5, bargraph5);
  
  lcd.print("Digital Therm");
  lcd.setCursor(0,1);  
  lcd.write(byte(1)); 
  delay(1000);  
  lcd.clear();
  lcd.print("Dig Thermo 0-75C");
}
//===========================================
void loop(void) {  
  adc = analogRead(0);   
  tempLM=(adc*5)/10;
  lcd.setCursor(0,1);  
 
  if(tempLM>5){
    a=tempLM/5;
    b=tempLM%5;
    for(i=0;i<a;i++){
      lcd.write(5);
    }  
    if(b==1){
      lcd.write(1);
    }
    else if(b==2){
      lcd.write(2);
    }
    else if(b==3){
      lcd.write(3);
    }
    else if(b==4){
      lcd.write(4);
    }     
  }
  delay(2000);
}




