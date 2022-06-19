#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i=0;
int j=0;
int k=0;
int k1=0;
void setup()   
{ 
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
lcd.begin(16, 2);
lcd.print("AIR POLLUTION ");
lcd.setCursor(0, 1) ;
lcd.print("MONITORING");
delay(1000);
lcd.clear();
}

void loop() 
{
  i++;
 
lcd.begin(16, 2);
lcd.print("AIR POLLUTION ");
lcd.setCursor(0, 1) ;
lcd.print("MONITORING");
delay(1030);
lcd.clear();
k=analogRead(A0);
k1=analogRead(A1);
lcd.setCursor(0,0);
lcd.print("CO2:");  
lcd.print(k);
lcd.setCursor(0,1);
lcd.print("CH3:"); 
lcd.print(k1); lcd.print("       "); 
lcd.print(i);   
delay(3030);
  if((i%10)==0)
  {
Serial.print("CO2:");  
Serial.println(k);
Serial.print("CH3:"); 
Serial.println(k1);
if(i>=10)
{
i=0;
}
}
  }
