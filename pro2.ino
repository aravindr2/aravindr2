#include <SPI.h>
#include <Servo.h>
#include <MFRC522.h>
#include<TimeLib.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define SS_PIN 10 
#define RST_PIN 9
#define SS 2
LiquidCrystal_I2C lcd(0x27,20,4);
Servo m2; 
Servo myservo; 
MFRC522 mf(SS_PIN , RST_PIN); 
MFRC522 mfrc522(SS, RST_PIN); 
String card_ID=""; 

//Add as many cards you want 
String Name1="185";
String Name2="184";
String Name3="115";
String Name4="139";
String Name5="79 DD 81 2F";
String Name6="89 48 C9 2F";

int NumbCard[6];
int j=0;  
int statu[6];
int s=0;  
int pos=0;
int d=90;
int  RedLed=7;
int  GreenLed=6;
int  Buzzer=5;
int re;
int se;
String Log;
String Name;
String Number;
int n ;
int bal;
int tr,a,b,c;
int minbal;
int ID=1;
void setup() {
 
  Serial.begin(9600);
  SPI.begin();  
  mfrc522.PCD_Init(); 
  mf.PCD_Init(); 
   myservo.attach(3);
    m2.attach(4);
    myservo.write(pos); 
    m2.write(pos);
  Serial.println("CLEARSHEET");                
  Serial.println("ID,Date,Name,Number,Card ID,Time ,Time OUT,BAL");
  pinMode(RedLed,OUTPUT);
  pinMode(GreenLed,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  lcd.init();
  
  lcd.backlight();
  
   Serial.println("..........");            

  delay(200);
   }
   
void loop() {
  re=( ! mf.PICC_IsNewCardPresent()) && ( ! mfrc522.PICC_IsNewCardPresent());
  se=( ! mf.PICC_ReadCardSerial())&& ( ! mfrc522.PICC_ReadCardSerial());
  if ( re){
   return;
   }
   
 if ( se) {
 return;}
 

 for (byte i = 0; i < mf.uid.size; i++) {
     card_ID += mf.uid.uidByte[i];
     
 }
for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID = mfrc522.uid.uidByte[i];
     
 }
 Serial.println(card_ID);

   
       if(card_ID==Name1){
           Name=" R.ARAVIND ";
      
       lcd.print(" R.ARAVIND ");
       delay(1000);
       lcd.init();
       Number="TN 58 BD 0087";
       j=0;
       s=0;
       
        lcd.print(Number);
       delay(1000);
       lcd.init(); 
       }
      else if(card_ID==Name2){
       Name="S.K.ARUN";
       lcd.print("  S.K.ARUN ");
       delay(2000);lcd.init(); 
        Number="TN 58 AJ 2387";
       j=1;
       s=1;
      
        lcd.print(Number);
       delay(2000);
       lcd.init(); 
           }
      else if(card_ID==Name3){
       Name="R.RAMSURYAA";
      lcd.print("R.RAMSURYAA ");
       delay(2000);lcd.init(); 
        Number="TN 22 F 6912";
      j=2;
       s=2;
    
        lcd.print(Number);
       delay(2000);  
  lcd.init(); 
      }
      else if(card_ID==Name4){
       Name="Fourth employee";
       Number="89101";
       j=3;
       s=3;
      }
      else if(card_ID==Name5){
       Name="Fiveth employee";
       Number="789101";
       j=4;
       s=4;
      }
      else if(card_ID==Name6){
       Name="Sixth employee";
       Number="789101";
       j=5;
       s=5;
      }
      else{
          digitalWrite(GreenLed,LOW);
          digitalWrite(RedLed,HIGH);
          goto cont;
     }

      if(NumbCard[j] == 1 && statu[s] == 0){
      statu[s]=1;
    
       Serial.println(",");
      Serial.print("DATA,");
      Serial.print(ID);
      Serial.print(",");
      Serial.print("DATE");
      Serial.print(",");
      Serial.print(Name);
      Serial.print(",");
      Serial.print(Number); 
      Serial.print(",");
      Serial.print(card_ID); 
      Serial.print(",");
      Serial.print("");
      Serial.print(",");
      Serial.println("TIME");
       Serial.print("BALANCE"); 
    Serial.print(bal);
      ID=ID+1;
      digitalWrite(GreenLed,LOW);
      digitalWrite(RedLed,HIGH);
      digitalWrite(Buzzer,HIGH);
      delay(30);
      digitalWrite(Buzzer,LOW);
     
 
      myservo.write(d);
    
      lcd.print(" Thank You Out ");
       delay(8000);  
       myservo.write(pos);  
                  
       delay(2000);  
       lcd.init(); 
     
      }
      else if(NumbCard[j] == 0){
      NumbCard[j] = 1;
      n++;
       minbal=500;
       bal=minbal-100; lcd.init(); 
      lcd.print("Balance is "); lcd.print(bal); 
       lcd.init(); 
      lcd.print(" Welcome IN ");
      
      digitalWrite(GreenLed,HIGH);
      delay(2000); 
     m2.write(d);
       delay(7000);  
     
      
     m2.write(pos);
       delay(1000);  
       lcd.init(); 
    Serial.print("DATA,");
      Serial.print(ID);
      Serial.print(",");
      Serial.print("DATE");
      Serial.print(",");
      Serial.print(Name);
      Serial.print(",");
      Serial.print(Number); 
      Serial.print(",");
      Serial.print(card_ID); 
      Serial.print(",");
        Serial.print(bal);
       Serial.print(",");
      Serial.print("TIME");
      Serial.print(",");
      Serial.println("");
      Serial.print(bal);
       Serial.print(",");
     
      digitalWrite(Buzzer,HIGH);
      delay(30);
      digitalWrite(Buzzer,LOW);
      ID=ID+1;
       
      }
      else if(statu[s] == 1){
      lcd.print(" Welcome -3 ");
       delay(2000);
       lcd.init(); 
       tr=bal-50;
        lcd.print(" Balance is "); 
        lcd.print(tr);
        myservo.write(d);
        m2.write(d);
       delay(8000);  
       myservo.write(pos);
       m2.write(pos);
       delay(2000);  
       
        delay(2000); 
     
          delay(2000); 
        lcd.init(); 
      }
      else if(statu[s] == 2){
      lcd.print(" Welcome -4 ");
       delay(2000);}
      delay(1000);
     
cont:
delay(2000);
digitalWrite(GreenLed,LOW);
digitalWrite(RedLed,LOW);
card_ID="";

}
    void printTime() {
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(",");
}
    
