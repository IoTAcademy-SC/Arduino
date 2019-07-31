/*
--------- >>> IOT Academy <<<----------
======== >>> Summer School <<<=======
Project Name = Uart_Transmit
*/

#define BAUDRATE 9600
#define Time 500

void setup() {
Serial.begin(BAUDRATE);
}

void loop() {
Serial.write("IOTAcademy\r\n");
delay(Time);
}
