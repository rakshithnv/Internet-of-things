#include <Blynk.h>

#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#include<ESP8266WiFi.h>

String apikey= "HN6MRESCNCGSSZUO";
const char* ssid = "Rekha Vishwanath";
const char* pass = "rakshith1999Preksha2003";
const char* server= "api.thingspeak.com";
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 

WiFiClient client;
void setup(void)
{ 
WiFi.begin(ssid,pass);
 Serial.println();
 Serial.println("Connecting to ");
 Serial.print(ssid);// put your setup code here, to run once:
 while( WiFi.status()!= WL_CONNECTED)
{
  Serial.print(".");
  delay(500);
  }
    
  
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);

}
void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT");
    return;
    }
    //postStr=apikey+"&field1="+t+"&field2=+h+"\r\n\r\n"
  if (client.connect(server,80))
  {
    //HTTP POST request
     String postStr=apikey;  ////post string shoild hve apikey+ &field1 i.e temperature& field2="humidity"\\
    postStr+="&field1=";
    postStr+=String(t);
    postStr+="&field2=";
    postStr+=String(h);
    postStr+="\r\n\r\n";

client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apikey+"\n");
client.print("Content- Type: application/x-www-form-urlencoded\n");
client.print("Content-Length");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);    
    }
  client.stop();
  Serial.println("Waiting...");
  delay(15000);
}
