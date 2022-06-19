//#include <LiquidCrystal.h>
//LiquidCrystal lcd(13, 12, 11, 10, 9, 8);    
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(6,7);
//#include <Servo.h>
//Servo myservo;
//
//int pos = 0;
//int pos1 = 0;
//int value = 0;
//int value1 = 0;
//float voltage;
//float voltage1;
//float R1 = 47000.0;
//float R2 = 33000.0;
//
//
//const int analogInPin1 = A1; 
//const int analogInPin2 = A2;  
//const int analogInPin3 = A3; 
//
//const int l3 = 4;
//const int l4 = 5;  
//  
//int sensorValue = 0;
//int sensorValue1 = 0;   
//int sensorValue2 = 0;   
//int i=0;
// int u=0;
//
//
//    int n=0;
//void setup() 
//{
//    Serial.begin(9600);
//
//      pinMode(l3, OUTPUT);
//        pinMode(l4, OUTPUT);
//  lcd.begin(16, 2);
//  lcd.print("SOLAR BASED              ");
//  lcd.setCursor(0, 1);
//  lcd.print("AIR COOLER                ");
//  myservo.attach(3);  //Specify here the pin number on which the signal pin of ESC is connected.
//  myservo.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
//  delay(5000);   
//}
//
//void loop() 
//{
//pos = map(analogRead(A0), 0, 1023, 0, 180);
//myservo.write(pos);   
//pos1=map(pos, 0, 180, 0, 1500);
//Serial.println(pos1);
//
////if(i==0)
////{
////esc_signal.write(40);    
////delay(15);
////esc_signal.write(45);
////delay(15);
////esc_signal.write(50);  
////delay(15);
////esc_signal.write(55);    
////delay(15);
////esc_signal.write(60);
////delay(15);
////esc_signal.write(65);
////delay(15);
////esc_signal.write(70);    
////delay(15);
////esc_signal.write(75);
////delay(15);
////esc_signal.write(80);  
////delay(15);
////esc_signal.write(85);    
////delay(15);
////esc_signal.write(65);
////delay(15);
////esc_signal.write(70);
////delay(15);
////i=1;
////
////}
////  
////if(i==1)
////{
////esc_signal.write(100);
////delay(15);
////i=1;
////} 
//
//
//digitalWrite(l3, HIGH);
//delay(10);
//digitalWrite(l4, HIGH);
//delay(10);
//digitalWrite(l3, LOW);
//digitalWrite(l4, LOW);
//
//  value = analogRead(A1);
//  value1 = analogRead(A2);
//  voltage = value * (5.5/1024)*((R1 + R2)/R2);
//  voltage1 = value1 * (6.0/1024)*((R1 + R2)/R2);
//
//  lcd.setCursor(8, 0);
//  lcd.print("Vi=");
//  lcd.print(voltage);
////    lcd.setCursor(0, 1);
// lcd.print("             ");
////  lcd.println(voltage1);
//
//if(voltage<=7)
//{
//   lcd.setCursor(0, 0);
//  lcd.print("BOOST M/");
//  
// 
//  
//  }
//  if(voltage>=8)
//{
//     lcd.setCursor(0, 0);
//  lcd.print("BUCK M/ ");
////  lcd.setCursor(0, 1);
////  lcd.print("AIR COOLER                ");
////   delay(200);
//  
//
//
//  
//
//  
//
//}
//
//    lcd.setCursor(0, 1);
//  lcd.print("speed=");
//    lcd.print(pos1);
//        lcd.print("        ");
//
//
//delay(800);}














#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);    
#include <SoftwareSerial.h>
SoftwareSerial mySerial(6,7);
#include <Servo.h>
Servo myservo;

int pos = 0;
int pos1 = 0;
int value = 0;
int value1 = 0;
float voltage;
float voltage1;
float R1 = 47000.0;
float R2 = 33000.0;


const int analogInPin1 = A1; 
const int analogInPin2 = A2;  
const int analogInPin3 = A3; 

const int l3 = 4;
const int l4 = 5;  
  
int sensorValue = 0;
int sensorValue1 = 0;   
int sensorValue2 = 0;   
int i=0;
 int u=0;


    int n=0;
void setup() 
{
    Serial.begin(9600);

      pinMode(l3, OUTPUT);
        pinMode(l4, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("solar pv");
  lcd.setCursor(0, 1);
  lcd.print("AIR COOLER                      ");
  myservo.attach(3);  //Specify here the pin number on which the signal pin of ESC is connected.
  myservo.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);   
}

void loop() 
{
pos = map(analogRead(A0), 0, 1023, 0, 170);
myservo.write(pos);   
pos1=map(pos, 0, 170, 0, 1500);
Serial.println(pos1);

//if(i==0)
//{
//esc_signal.write(40);    
//delay(15);
//esc_signal.write(45);
//delay(15);
//esc_signal.write(50);  
//delay(15);
//esc_signal.write(55);    
//delay(15);
//esc_signal.write(60);
//delay(15);
//esc_signal.write(65);
//delay(15);
//esc_signal.write(70);    
//delay(15);
//esc_signal.write(75);
//delay(15);
//esc_signal.write(80);  
//delay(15);
//esc_signal.write(85);    
//delay(15);
//esc_signal.write(65);
//delay(15);
//esc_signal.write(70);
//delay(15);
//i=1;
//
//}
//  
//if(i==1)
//{
//esc_signal.write(100);
//delay(15);
//i=1;
//} 


digitalWrite(l3, HIGH);
delay(10);
digitalWrite(l4, HIGH);
delay(10);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);

  value = analogRead(A1);
  value1 = analogRead(A2);
  voltage = value * (5.5/1024)*((R1 + R2)/R2);
  voltage1 = value1 * (6.0/1024)*((R1 + R2)/R2);

  lcd.setCursor(0, 0);
  lcd.print("Vin =");
  lcd.print(voltage);
//    lcd.setCursor(0, 1);
 lcd.print("   ");
//  lcd.println(voltage1);
delay(1000);
if(voltage<=7)
{
  lcd.begin(16, 2);
  lcd.print("BOOST MODE");
  lcd.setCursor(0, 1);
  lcd.print("AIR COOLER                      ");
  delay(200);
  
  }
  if(voltage>=8)
{
    lcd.begin(16, 2);
  lcd.print("BUCK MODE");
  lcd.setCursor(0, 1);
  lcd.print("AIR COOLER                      ");
   delay(200);
  }
  lcd.begin(16, 2);
  lcd.print("speed=");
    lcd.print(pos1);
        lcd.print("  ");
  lcd.setCursor(0, 1);
  lcd.print("AIR COOLER                      ");
  delay(300);

  

}
