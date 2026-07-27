//file: main.cpp
#include "Arduino.h"

void setup(){
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }
}


int counter = 0;
char buff[25]={0};
void loop(){
    sprintf(buff,"Counter=%d\n",counter);
    Serial.print(buff);
    delay(1000);
    counter++;
}