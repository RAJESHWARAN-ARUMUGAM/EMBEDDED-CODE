#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
const char *ssid = "CMCC-ALLY TECH";  
const char *password = "10112019"; 
const char *host = "https://myprojectfinal.in.in";  
String strs[3];
int StringCount = 0;
String str="";
int k=0;

void setup()   
{ 
Serial.begin(9600);
WiFi.mode(WIFI_OFF);        
delay(1000);
WiFi.mode(WIFI_STA);  
WiFi.begin(ssid, password);     
Serial.println(""); 
Serial.print("Connecting");
while (WiFi.status() != WL_CONNECTED) 
{
    delay(500);
    Serial.print("*");
} 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
  delay(1000);
}

void loop() 
{

HTTPClient http;  
  String postData;  
 postData = "";  
 http.begin("http://myprojectfinal.in/message/sendapi.php");            
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);   
String payload = http.getString();
http.end();  
str=payload;
  while (str.length() > 0 && str != "0" )
  {
    int index = str.indexOf(',');
    if (index == -1) // No space found
    {
      strs[StringCount++] = str;
      break;
    }
    else
    {
      strs[StringCount++] = str.substring(0, index);
      str = str.substring(index+1);
    }
  }

  // Show the resulting substrings
  for (int i = 0; i < StringCount; i++)
  {
//    Serial.print(i);
//    Serial.print(": \"");
//    Serial.print(strs[i]);
//    Serial.println("\"");

k++;

 }


 if(k >= 3 && strs[0]!="")
{
  
Serial.print("AT\r");
delay(1000);
Serial.print("AT+CMGF=1\r");
delay(1000);
Serial.print("AT+CMGS=\"+91");
delay(1000);
Serial.print(strs[0]);
delay(1000);
Serial.print("\"\r");
delay(1000);
Serial.print(strs[1]);
Serial.print("\r");  
delay(1000);  
Serial.print((char)26);                   
delay(5000);
HTTPClient http;  
String postData; 
postData = ""; 
// Serial.print(postData);  
http.begin("http://myprojectfinal.in/message/messageapi.php?status=0&number="+String(strs[0]));            
http.addHeader("Content-Type", "application/x-www-form-urlencoded");
int httpCode = http.POST(postData);   
String payload = http.getString();
http.end();  
 k=0; 

strs[1]="";
strs[0]="";
} 

delay(100);


}




 


  
