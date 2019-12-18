//programmng the esp8266 to act as a server 

//my pc is coomunicating with esp8266

#include<ESP8266WiFi.h>
const char* ssid= "Rekha Vishwanath";
const char* pass ="rakshith1999Preksha2003" ;

WiFiServer server(80);
void setup() {
  
  Serial.begin(115200);
  Serial.println("..");
  WiFi.begin(ssid,pass);
Serial.print("Connecting to: ");
Serial.print (ssid);
while(WiFi.status()!=WL_CONNECTED) {
    delay(500);
    Serial.print(".");// put your setup code here, to run once:

}
Serial.println("Connected successfully");

server.begin();
Serial.println(" Server has begun on IP" );
Serial.print(WiFi.localIP());
}
//this loop helps the server to listen to the client
void loop() {
WiFiClient clientobj = server.available ();
if(!clientobj)
{
return;
}

Serial.println("New client");
while(!clientobj.available())
{
}
String req = clientobj.readString();
Serial.println(req);


String resp= " http/1.1 200 OK\r\n Context-type:text/html\r\n\r\n <!DOCTYPE HTML><html><body>""Hi from ESP""</body></html>"    ;         //  \r \n for new line
clientobj.print(resp);

delay(100);
clientobj.stop();
}
// if there is client available it will come here otherwise i keeps looping

