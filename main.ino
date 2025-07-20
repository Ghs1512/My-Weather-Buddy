#include "thingProperties.h"
#include "DHT.h"
#define DHTpin 2 // D4 on the nodemcu ESP8266
#define DHTTYPE DHT11
DHT dht(DHTpin,DHTTYPE);
 
void setup() {
// Initialize serial and wait for port to open:
Serial.begin(9600);

// This delay gives the chance to wait for a Serial Monitor without blocking if none is found
delay(1500);
 
// Defined in thingProperties.h
initProperties();
 
// Connect to Arduino IoT Cloud
ArduinoCloud.begin(ArduinoIoTPreferredConnection);
 
/*
The following function allows you to obtain more information
related to the state of network and IoT Cloud connection and errors
the higher number the more granular information you’ll get.
The default is 0 (only errors).
Maximum is 4
*/
setDebugMessageLevel(2);
ArduinoCloud.printDebugInfo();
}
 
void loop() {
ArduinoCloud.update();
// Your code here
dht_sensor_getdata();
moisture_sensor_getdata();
time_val = ArduinoCloud.getLocalTime();
}
 
void onHumidityChange() {
// Do something
 
}
 
void onMsgChange() {
// Do something
}
void dht_sensor_getdata()
{
float hm= dht.readHumidity();
Serial.print("Humidity ");
Serial.println(hm);
float temp=dht.readTemperature();
Serial.print("Temperature ");
Serial.println(temp);
humidity_val=hm;
temp_val=temp;
}
/*
  Since TempVal is READ_WRITE variable, onTempValChange() is
  executed every time a new value is received from IoT Cloud.
*/
void moisture_sensor_getdata()  {
  // Add your code here to act upon TempVal change
  int moisture = analogRead(A0);
  moisture_val= map(moisture,1023,305,0,100);
  Serial.println("Moisture level is:");
  Serial.println(moisture_val);
}
/*
  Since Temperature is READ_WRITE variable, onTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperatureChange()  {
  // Add your code here to act upon Temperature change
}
/*
  Since HumidityVal is READ_WRITE variable, onHumidityValChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumidityValChange()  {
  // Add your code here to act upon HumidityVal change
}
/*
  Since TempVal is READ_WRITE variable, onTempValChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTempValChange()  {
  // Add your code here to act upon TempVal change
}
/*
  Since MoistureVal is READ_WRITE variable, onMoistureValChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMoistureValChange()  {
  // Add your code here to act upon MoistureVal change
}
/*
  Since PhotoresistorVal is READ_WRITE variable, onPhotoresistorValChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPhotoresistorValChange()  {
  // Add your code here to act upon PhotoresistorVal change
}
/*
  Since LdrVal is READ_WRITE variable, onLdrValChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLdrValChange()  {
  // Add your code here to act upon LdrVal change
  
}

/*int ldr_read()
{
  int ldr_val=int(analogRead(D1));
  
  
}*/
