/*************************************
 * Program : Project 16. Data logger 2 sensor suhu
 * Input   : 2 Sensor LM35, RTC DS1307, SD Card
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <SPI.h>
#include <SD.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define DS1307_ADDRESS 0x68
byte zero = 0x00;

File myFile;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int adc; 
int suhu1, suhu2;
int waktu;

byte second ,minute,hour, weekDay;
byte monthDay,month,year;

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  Wire.begin();
//===========================CS SD card  
  pinMode(10, OUTPUT);
//===========================Tombol
  pinMode(8, INPUT);  
  digitalWrite(8, 1);
//===========================Inisialisasi SD card
  lcd.clear();
  lcd.print("  Inisialisasi");
  lcd.setCursor(0,1);
  lcd.print("    SD card..");  
  Serial.println("Inisialisasi SD card..");
  delay(1000);  
  if (!SD.begin(10)) {
    lcd.setCursor(0,1);
    lcd.print(" SD card Gagal!  ");
    Serial.print(" SD card Gagal!  ");
    while(1);
  }
  lcd.setCursor(0,1);
  lcd.print("SD card Berhasil ");
  Serial.println("SD card Berhasil ");
  delay(2000); 
  lcd.clear();
}

void loop(){
//========================Baca ADC
  adc = analogRead(A0);
  suhu1 = (adc*5)/10;
  adc = analogRead(A1);
  suhu2 = (adc*5)/10;
//========================baca RTC
  bacaRTC();
//========================Display LCD
  lcd.setCursor(0,0);
  lcd.print("S1:");
  lcd.print(suhu1);
  lcd.print("C  S2:");
  lcd.print(suhu2);
  lcd.print("C  ");
  lcd.setCursor(0,1);
  lcd.print("Jam:");
  lcd.print(hour); 
  lcd.print(":");
  lcd.print(minute);
  lcd.print(":");
  lcd.print(second);
  lcd.print("  ");
  waktu++;
//============================simpan data setelah 10detik
if (waktu==10){
  myFile = SD.open("data1.txt", FILE_WRITE);
  if (myFile) {
    lcd.clear();
    lcd.print("Simpan data....");
    lcd.setCursor(0,1);
    lcd.print("file->data1.txt");
    
    myFile.print("Suhu 1=");
    myFile.print(suhu1);
    myFile.print("C, Suhu 2=");
    myFile.print(suhu2);
    myFile.print("C ");

    bacaRTC();
    myFile.print(monthDay);
    myFile.print("/");
    myFile.print(month);
    myFile.print("/");
    myFile.print(year); 
    myFile.print(" ");
    myFile.print(hour); 
    myFile.print(":");
    myFile.print(minute);
    myFile.print(":");
    myFile.println(second);

    myFile.close();
  } 
  else {
    lcd.clear();
    lcd.print("error opening");
    lcd.setCursor(0,1);
    lcd.print(" data1.txt");
    delay(2000);
  }
  waktu=0;
  delay(2000);
  lcd.clear();
}
//=========================tombol 1 baca isi file data1.txt
  if(digitalRead(8)==0){ 
    myFile = SD.open("data1.txt");
    if (myFile) {
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Send data SD card");
       while (myFile.available()) {
          Serial.write(myFile.read());
       }
       myFile.close();
       delay(1000);
    } 
    else {
       lcd.clear();
       lcd.print("error opening");
       lcd.setCursor(0,1);
       lcd.print(" data1.txt");
    }
    delay(500);
  }
  
  delay(1000);
}

byte decToBcd(byte val){
  return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val)  {
  return ( (val/16*10) + (val%16) );
}

void bacaRTC(){
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  second = bcdToDec(Wire.read());
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read() & 0b111111);
  weekDay = bcdToDec(Wire.read());
  monthDay = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}
