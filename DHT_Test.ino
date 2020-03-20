#include "DHT.h"
DHT dht;

void setup()
{
Serial.begin(9600);
Serial.println();
Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
dht.begin();
//dht.setup(D1); /* This function is no longer available in library */
}

void loop()
{
// delay(dht.getMinimumSamplingPeriod()); /* This function is no longer available in library */

float humidity = dht.readHumidity(); /* Get humidity value */
float temperature = dht.readTemperature(); /* Get temperature value */
// Serial.print(dht.getStatusString());/* This function is no longer available in library */
Serial.print("\t");
Serial.print(humidity, 1);
Serial.print("\t\t");
Serial.print(temperature, 1);
Serial.print("\t\t");
Serial.println(dht.convertFtoC(temperature), 1);/* Convert temperature to Fahrenheit units */
}
