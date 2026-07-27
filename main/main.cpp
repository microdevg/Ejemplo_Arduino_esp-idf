//file: main.cpp
#include "Arduino.h"

//#define APP_MAIN
#ifdef APP_MAIN


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

#else

//file: main.cpp
#include "Arduino.h"

extern "C" void app_main(void)
{
    // Inicializa los componentes internos de Arduino (HAL, timers, etc.)
    initArduino();

    Serial.begin(115200);
    while(!Serial){
        ; // Espera a que el puerto serie se conecte
    }

    int counter = 0;
    char buff[25] = {0};

    // Bucle principal (equivalente al loop)
    while (true) {
        sprintf(buff, "Counter=%d\n", counter);
        Serial.print(buff);
        
        delay(1000); // Función de retardo de Arduino/FreeRTOS
        counter++;
    }
}

#endif