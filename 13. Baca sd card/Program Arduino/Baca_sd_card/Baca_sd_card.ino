/*************************************
 * Program : Project 13. Baca sd card
 * Input   : SDCard Reader 
 * Output  : Serial Monitor
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <SPI.h>
#include <SD.h>

File myFile;

void setup(){
  Serial.begin(9600);  
  Serial.println("Inisialisasi SD card...");
  pinMode(10, OUTPUT);  
  if (!SD.begin(10)){
    Serial.println("Inisialisasi Gagal!");
    return;
  }
  Serial.println("Inisialisasi Berhasil.");  
//====================tulis data pada file data1.txt
  myFile = SD.open("data1.txt", FILE_WRITE);
  if (myFile) {
    myFile.println("Simpan file text \"data1.txt\" pada SD Card");   
    myFile.close();
  } 
  else {
    Serial.println("error buka file \"data1.txt\"");
  }
  
//====================baca isi file data1.txt  
  myFile = SD.open("data1.txt");
  if (myFile){
    Serial.println("Isi File data1.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  }  
  else{
    Serial.println("buka file data1.txt Error!!");
  }  
}

void loop()
{
}
