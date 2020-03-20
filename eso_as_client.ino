//esp8266 as client



#include<ESP8266WiFi.h>
#include<ESP8266Client.h>
const char* ssid = "Rekha Vishwanatha";
const char* pass = "rakshith1999Preksha2003"

void setup() {

  Serial.begin(115200);
 WiFi.begin(ssid,pass);
 Serial.println("Connecting to ");
 Serial.print(ssid);// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
