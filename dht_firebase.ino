#include <FirebaseArduino.h>
#include "DHT.h"
#include <Firebase.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h>
#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "tuto-1482a.firebaseio.com"
#define FIREBASE_AUTH "AxlFsc2rexQ2QsCBsEuBxhoB74bPBQQqYqcvYxD7"
#define WIFI_SSID "Hotspot"
#define WIFI_PASSWORD "qwerty123"
#define DHTPIN 14    // Data Pin of DHT 11 , for NodeMCU D5 GPIO no. is 14

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
 
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);
  
}

void loop() {
 
  float h = dht.readHumidity();
  Serial.print("Humidity = ");
  Serial.println(h);
  delay(100);
  float t = dht.readTemperature();
  Serial.print("Temperature = ");
  Serial.println(t);// Reading temperature as Celsius (the default)
  Firebase.setFloat ("Temp",t);
  Firebase.setFloat ("Humidity",h);
  delay(200);
}

