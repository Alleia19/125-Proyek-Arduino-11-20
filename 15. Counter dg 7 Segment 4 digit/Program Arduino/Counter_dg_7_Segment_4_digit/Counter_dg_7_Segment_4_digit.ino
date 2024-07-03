/*************************************
 * Program : Project 
 * Input   : 3 Tombol Push ON 
 * Output  : 4 Seven Segment Display
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
unsigned int count;

int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;

int dig1 = 9;
int dig2 = 10;
int dig3 = 11;
int dig4 = 12;

           
void setup() {
  for(char i=2; i<13; i++){
    pinMode(i,OUTPUT);
  }
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  digitalWrite(A0,1);
  digitalWrite(A1,1);
  digitalWrite(A2,1);
}

void loop() {   
  char seg1 = int(count)/1000;
  char seg2 = (int(count)%1000)/100;
  char seg3 = (int(count)%100)/10;
  char seg4 = (int(count)%100)%10;  

  if (count < 10){
    seg1=10;
    seg2=10;
    seg3=10;
  }
  else if (count < 100){
    seg1=10;
    seg2=10;
  }
  else if (count < 1000){
    seg1=10;
  }
  
  digitalWrite(12,1);
  digitalWrite(9,0);
  displaySeg(seg1);
  delay(5);
  
  digitalWrite(9,1);
  digitalWrite(10,0);
  displaySeg(seg2);
  delay(5);
  
  digitalWrite(10,1);
  digitalWrite(11,0);
  displaySeg(seg3);
  delay(5);
  
  digitalWrite(11,1);
  digitalWrite(12,0);
  displaySeg(seg4);
  delay(5);

  
  if (digitalRead(A0)==0 && count < 9999){
    count++;
    delay(200);
  }
  else if(digitalRead(A1)==0 && count != 0){
    count--;
    delay(200);
  }
  else if(digitalRead(A2)==0){
    count=0;
  }
}

void displaySeg(char segment){
 switch (segment){
   case 0: digitalWrite(segA,0);
           digitalWrite(segB,0);
           digitalWrite(segC,0);
           digitalWrite(segD,0);
           digitalWrite(segE,0);
           digitalWrite(segF,0);
           digitalWrite(segG,1);
           break;
   case 1: digitalWrite(segA,1);
           digitalWrite(segB,0);
           digitalWrite(segC,0);
           digitalWrite(segD,1);
           digitalWrite(segE,1);
           digitalWrite(segF,1);
           digitalWrite(segG,1);
           break;
   case 2: digitalWrite(segA,0);
           digitalWrite(segB,0);
           digitalWrite(segC,1);
           digitalWrite(segD,0);
           digitalWrite(segE,0);
           digitalWrite(segF,1);
           digitalWrite(segG,0);
           break;
   case 3: digitalWrite(segA,0);
           digitalWrite(segB,0);
           digitalWrite(segC,0);
           digitalWrite(segD,0);
           digitalWrite(segE,1);
           digitalWrite(segF,1);
           digitalWrite(segG,0);
           break;
   case 4: digitalWrite(segA,1);
           digitalWrite(segB,0);
           digitalWrite(segC,0);
           digitalWrite(segD,1);
           digitalWrite(segE,1);
           digitalWrite(segF,0);
           digitalWrite(segG,0);
           break;
   case 5: digitalWrite(segA,0);
           digitalWrite(segB,1);
           digitalWrite(segC,0);
           digitalWrite(segD,0);
           digitalWrite(segE,1);
           digitalWrite(segF,0);
           digitalWrite(segG,0);
           break;
   case 6: digitalWrite(segA,0);
           digitalWrite(segB,1);
           digitalWrite(segC,0);
           digitalWrite(segD,0);
           digitalWrite(segE,0);
           digitalWrite(segF,0);
           digitalWrite(segG,0);
           break;
   case 7: digitalWrite(segA,0);
           digitalWrite(segB,0);
           digitalWrite(segC,0);
           digitalWrite(segD,1);
           digitalWrite(segE,1);
           digitalWrite(segF,1);
           digitalWrite(segG,1);
           break;
   case 8: digitalWrite(segA,0);
           digitalWrite(segB,0);
           digitalWrite(segC,0);
           digitalWrite(segD,0);
           digitalWrite(segE,0);
           digitalWrite(segF,0);
           digitalWrite(segG,0);
           break;
   case 9: digitalWrite(segA,0);
           digitalWrite(segB,0);
           digitalWrite(segC,0);
           digitalWrite(segD,0);
           digitalWrite(segE,1);
           digitalWrite(segF,0);
           digitalWrite(segG,0);
           break;
   case 10: digitalWrite(segA,1);
           digitalWrite(segB,1);
           digitalWrite(segC,1);
           digitalWrite(segD,1);
           digitalWrite(segE,1);
           digitalWrite(segF,1);
           digitalWrite(segG,1);
           break;
 }
}

