/*************************************
 * Program : Project 14. Baca ultrasonic display Android
 * Input   : Sensor Ultrasonic HC-SR04 
 * Output  : Module Bluetooth HC05
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <SoftwareSerial.h>
const int rxpin = 2; 
const int txpin = 3; 
SoftwareSerial hc05(rxpin, txpin); 

int trig_pin = 8;
int echo_pin = 9;
long echotime; 
float distance;

void setup() {
  hc05.begin (9600);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime= pulseIn(echo_pin, HIGH);
  distance= 0.0001*((float)echotime*340.0)/2.0;
  
  hc05.print("*T"+String(echotime)+"*");
  hc05.print("*D"+String(distance,1)+"*");
  if (distance<20) hc05.print("*LR255G0B0*"); //Red
  if (distance>=20&&distance<=50) hc05.print("*LR255G200B0*"); //Orange
  if (distance>50) hc05.print("*LR0G255B0*"); //Green
  
  delay(100);
}

