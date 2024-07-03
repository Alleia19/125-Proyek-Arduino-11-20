/*************************************
 * Program : Project 12. Baca RPM motor DC
 * Input   : Sensor Optocoupler
 * Output  : LCD 2x16, Motor DC
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
word count;
word rpm;
word rps;
byte pwm;

void setup(){
  pinMode(6,OUTPUT);
  analogWrite(6, 255);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(" Baca RPM Motor");
  lcd.setCursor(0,1);
  lcd.print("      DC");
  delay(2000);
  
  //----------------seting interupsi 0
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(0, readCount, FALLING);
  delay(50);
  pwm=220;
  lcd.clear();
}

void loop(){
    lcd.setCursor(0,0);
    lcd.print("PWM:");
    lcd.setCursor(0, 1);
    lcd.print("RPM:");
    delay(1000);
    
    if(pwm == 0) pwm = 250;
    pwm=pwm-10;
    
    for(char i=0; i<7; i++){
      analogWrite(6, pwm);
      delay(1000);     
      //---------total lubang 36
      rps = count/36;
      //---------1 menit 60 dtk
      rpm = rps*60;
      
      lcd.setCursor(4, 0);
      lcd.print(pwm);
      lcd.print("   ");
      lcd.setCursor(4, 1);
      lcd.print(rpm);
      lcd.print("    ");
      count = 0;
    }
}

void readCount(){
    count++;
}

