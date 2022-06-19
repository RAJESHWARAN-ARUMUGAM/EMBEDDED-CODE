#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <Adafruit_Fingerprint.h>
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(6, 7);
#else
#define mySerial Serial1
#endif
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
uint8_t id;
int i=0;
int j=0;
int k=0;
int l=0;
int m=0;int rfid[13];
void setup()   
{ 
pinMode(A5,INPUT);  
pinMode(2,OUTPUT);
Serial.begin(9600);
digitalWrite(2,LOW);
lcd.begin(16, 2);
lcd.print(" IOT BASED ANTI ");
lcd.setCursor(0, 1) ;
lcd.print(" THEFT SYSTEM");
lcd.print("          ");
  delay(2000);
while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  //Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {

    lcd.setCursor(0, 0) ;
 
lcd.print("FP OK                          ");
delay(500);
    
  } else {lcd.setCursor(0, 0) ;
    lcd.print("FP NOT      OK                          ");delay(500);
    while (1) { delay(1); }
  }

  //Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  //Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  //Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
//  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
//  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
//  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
//  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
//  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;











  
}

void loop() {
 
 if(analogRead(A5)<=100)
 {
  lcd.setCursor(0, 0) ;
 
lcd.print("ANTI THEFT SYS      ");
lcd.setCursor(0, 1) ;  
lcd.print("DRIVER MODE    ");
delay(500);
i=1;
}
 if(analogRead(A5)>=1000)
 {
  lcd.setCursor(0, 0) ;
 
lcd.print("ANTI THEFT SYS      ");
lcd.setCursor(0, 1) ;  
lcd.print("PARKING MODE    ");
delay(500);
i=2;
}  
if(i==2)
{
  
  if(analogRead(A1)<=300 ||analogRead(A2)>=350 || analogRead(A3)>=350)
{
  j++;
 lcd.setCursor(12, 1) ;
 lcd.print(j); lcd.print("   "); delay(1000);
 if(j>15)
 {
Serial.println("THEFT ATTEMPT");
digitalWrite(2,HIGH);
delay(1000);
digitalWrite(2,LOW);
 }
}

//Serial.println(analogRead(A1));
//Serial.println(analogRead(A2));
//Serial.println(analogRead(A3));


  
  if(analogRead(A0)<=70)
{
Serial.println("THEFT ATTEMPT");
digitalWrite(2,HIGH);
delay(1000);
digitalWrite(2,LOW);
}
  
  
  
  }


if(i==1){
  
 if (Serial.available()) {

    rfid[0]=Serial.read();
    rfid[1]=Serial.read();
    rfid[2]=Serial.read();
    rfid[3]=Serial.read();
    rfid[4]=Serial.read();
    rfid[5]=Serial.read();
    rfid[6]=Serial.read();
    rfid[7]=Serial.read();
    rfid[8]=Serial.read();
    rfid[9]=Serial.read();
    rfid[10]=Serial.read();
    rfid[11]=Serial.read();
if(rfid[0]=='1')
{ 
  k=1;
  }

  if(rfid[0]=='2')
{ k=404;Serial.println("face not matched");
  }
}

  getFingerprintID();
  delay(50);  
    lcd.setCursor(0, 0) ;
 
lcd.print("FACE:");
lcd.print(k);
lcd.print("                     ");
lcd.setCursor(0, 1) ;  
lcd.print("FP:");
lcd.print(l);lcd.print("                     ");
delay(1000);

  
  
    if(analogRead(A0)<=70)
{
Serial.println("ACCIDENT DETECT");

}
  
  
  
  
  
  
  
  
  
  }


  

delay(100);
  
  
  
  
  
  }


  uint8_t getFingerprintEnroll() {

  int p = -1;
  //Serial.print("Waiting for valid finger to enroll as #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
     // Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
     // Serial.println("Imaging error");
      break;
    default:
      //Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
     // Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
     // Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
     // Serial.println("Could not find fingerprint features");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }

  //Serial.println("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
 // Serial.print("ID "); Serial.println(id);
  p = -1;
 // Serial.println("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
     // Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      //Serial.println("Imaging error");
      break;
    default:
      //Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
     // Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      //Serial.println("Could not find fingerprint features");
      return p;
    default:
     // Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  //Serial.print("Creating model for #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    //Serial.println("Prints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    //Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    //Serial.println("Fingerprints did not match");
    return p;
  } else {
    //Serial.println("Unknown error");
    return p;
  }

 // Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    //Serial.println("Stored!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    //Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
   // Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    //Serial.println("Error writing to flash");
    return p;
  } else {
    //Serial.println("Unknown error");
    return p;
  }

  return true;
}


uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
     // Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
     // Serial.println("No finger detected");
            
//      if(analogRead(A1)<=50)
//      {
//   lcd.setCursor(0, 0);
//  lcd.print("L1 : ");
//  lcd.print("YES  ");
//delay(100);
//        
//        }
//        else
//        {
//                 lcd.setCursor(0, 0);
//  lcd.print("L1 : ");
//  lcd.print("NO  ");
//delay(100);
//
//          }
//
//
//      if(analogRead(A2)<=50)
//      {
//    lcd.setCursor(8, 0);
//  lcd.print("L2 :");
//  lcd.print("YES  ");
//delay(100);
//        
//        }
//        else
//        {
//                 lcd.setCursor(8, 0);
//  lcd.print("L2 :");
//  lcd.print("NO  ");
//delay(100);
//
//          }
//
//
//
//      if(analogRead(A3)<=50)
//      {
//    lcd.setCursor(8, 1);
//  lcd.print("L3 :");
//  lcd.print("YES  ");
//delay(100);
//        
//        }
//        else
//        {
//                 lcd.setCursor(8, 1);
//  lcd.print("L3 :");
//  lcd.print("NO  ");
//delay(100);

       //   }




          
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
     // Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
     // Serial.println("Imaging error");
      return p;
    default:
    //  Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
     // Serial.println("Could not find fingerprint features");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    //Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
   // Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("THEFT ATTEMPT");

l=404;
lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("FP     ");
  lcd.setCursor(0, 1);
 lcd.print("not find a match");
delay(1000);
    

    
    return p;
  } else {
   // Serial.println("Unknown error");
    return p;
  }

  // found a match!
  //Serial.print("Found ID #"); Serial.print(finger.fingerID);
 // Serial.print(" with confidence of "); Serial.println(finger.confidence);
 
  if(finger.fingerID==1)
  {
    lcd.begin(16, 2);
lcd.print("VEHICLE            ");
lcd.setCursor(0, 1) ;
lcd.print("START .........         ");
lcd.print("          ");l=1;
  delay(3000);
  }
if(finger.fingerID==2)
{l=1;
      lcd.begin(16, 2);
lcd.print("VEHICLE            ");
lcd.setCursor(0, 1) ;
lcd.print("START .........         ");
lcd.print("          ");
delay(3000);
} 



if(finger.fingerID==3)
{

l=1;
      lcd.begin(16, 2);
lcd.print("VEHICLE            ");
lcd.setCursor(0, 1) ;
lcd.print("START .........         ");
lcd.print("          ");
delay(3000);
} 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  //Serial.print("Found ID #"); Serial.print(finger.fingerID);
  //Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
