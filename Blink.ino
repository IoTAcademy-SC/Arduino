/*
--------- >>> IOT Academy <<<----------
======== >>> Summer School <<<=======
Project Name = Blink
*/

#define Time 100
#define Led_PIN 13

void setup() {
  pinMode(Led_PIN, OUTPUT);
}

void loop() {
  digitalWrite(Led_PIN,HIGH);
  delay(Time);
  digitalWrite(Led_PIN,LOW);
  delay(Time);
}
