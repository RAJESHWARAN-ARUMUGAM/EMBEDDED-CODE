#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleDHT.h>
#include <LiquidCrystal.h>


const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pinDHT11 = A1;
SimpleDHT11 dht11(pinDHT11);
int i=0;
int j=0;
int k=0;
char inChar;
const int mo=A0;

const int T=A3;
const int pm=3;
const int sp=4;
int t;
float cel;

void setup() 
{
 
  lcd.begin(16, 2);
  lcd.print(" AGRI MONITOR          ");




   pinMode(pm, OUTPUT);  

   digitalWrite(pm,LOW);

 Serial.begin(9600);

}

void loop() {
//Serial.print(analogRead(A2)); 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" AGRI MONITOR            ");    
  delay(1000);
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
  Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  


lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("HUMM:");
lcd.print(humidity);
lcd.print(" ");
lcd.print("TEM:");
lcd.print(temperature);
lcd.setCursor(0, 1);
lcd.print("WATER LEVEL:");
lcd.print(((analogRead(A2)-1023)*-1));
delay(500);

if(analogRead(A2)<600)
{
      
  digitalWrite(pm,LOW);
    Serial.print("*pump off ");
    Serial.print("*Temp  VALUE:");
    Serial.print(int(temperature));
    Serial.print(" HUMM:");
    Serial.print((int)humidity);
    Serial.print(" TEM:");
    Serial.print(int(temperature));
    Serial.print(" WL:");
    Serial.print(((analogRead(A2)-1023)*-1));
     delay(5000);
  
 }
else
  {

  digitalWrite(pm,HIGH);
  Serial.print("*pump on");


    Serial.print(" HUMM:");
    Serial.print((int)humidity);
    Serial.print(" TEM:");
    Serial.print(int(temperature));
    Serial.print(" WL:");
    Serial.print(((analogRead(A2)-1023)*-1));
     delay(5000);
  
  }





if (int(temperature)>=40)
  { 
    Serial.print("*Temp HIGH VALUE:");
   Serial.print(int(temperature));
    Serial.print(" HUMM:");
    Serial.print((int)humidity);
    Serial.print(" TEM:");
    Serial.print(int(temperature));
    Serial.print(" WL:");
    Serial.print(((analogRead(A2)-1023)*-1));
     delay(5000);
  }

delay(100);
  
  
  }
