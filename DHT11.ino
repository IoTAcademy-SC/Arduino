/*
--------- >>> IOT Academy <<<----------
======== >>> Summer School <<<=======
Project Name = DHT11
*/

#include <dht.h>

dht DHT;

#define DHT11_PIN 7
#define BAUDRATE 9600
#define Time 2000


void setup() {
 Serial.begin(BAUDRATE);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(Time);
}
