#include <string.h>

#define Channel_1 13
#define Channel_2 9
#define Channel_3 10
#define Channel_4 11
#define BUFFER_SIZE 50

char rx_buffer[BUFFER_SIZE]; 
unsigned int writeindex=0;

//#############Interupt Ring Buffer##############//
void Rx_interupt(){
  if(Serial.available()){
    rx_buffer[writeindex++]=Serial.read();
      if(writeindex>=BUFFER_SIZE)
      writeindex=0;   
  }
}
//#############Buffer Cleaner###################//
void Clean_Buffer(){

  int Clean;

  for(Clean=0;Clean<BUFFER_SIZE;Clean++){
    rx_buffer[Clean]=0;
  }
  writeindex=0;
  
}
//#############Main Function###################//
void setup() {
    pinMode(Channel_1,OUTPUT);
    pinMode(Channel_2,OUTPUT);
    pinMode(Channel_3,OUTPUT);
    pinMode(Channel_4,OUTPUT);

    Serial.begin(9600);
    
}
//#############Loop Function###################//
void loop() {
  Rx_interupt(); 
  
  if(strstr(rx_buffer,"CH1_ON")){
  digitalWrite(Channel_1,HIGH);
  delay(50);
  Clean_Buffer();
  }
  else if(strstr(rx_buffer,"CH1_OFF")){
  digitalWrite(Channel_1,LOW);
  delay(50);
  Clean_Buffer();
  }
  else if(strstr(rx_buffer,"CH2_ON")){
  digitalWrite(Channel_2,HIGH);
  delay(50);
  Clean_Buffer();
  }
  else if(strstr(rx_buffer,"CH2_OFF")){
  digitalWrite(Channel_2,LOW);
  delay(50);
  Clean_Buffer();
  }
  else if(strstr(rx_buffer,"CH3_ON")){
  digitalWrite(Channel_3,HIGH);
  delay(50);
  Clean_Buffer();
  }
  else if(strstr(rx_buffer,"CH3_OFF")){
  digitalWrite(Channel_3,LOW);
  delay(50);
  Clean_Buffer();
  }
  else if(strstr(rx_buffer,"CH4_ON")){
  digitalWrite(Channel_4,HIGH);
  delay(50);
  Clean_Buffer();
  }
  else if(strstr(rx_buffer,"CH4_OFF")){
  digitalWrite(Channel_4,LOW);
  delay(50);
  Clean_Buffer();
  }

}
