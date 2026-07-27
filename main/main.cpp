//file: main.cpp
#include "Arduino.h"

//#define APP_MAIN
#ifndef APP_MAIN
#include <WiFi.h>

// 1. Reemplaza con los datos de tu red Wi-Fi
const char* ssid     = "esp322026";
const char* password = "esp322026";

void setup() {
  // Inicializa la comunicación serie para ver los mensajes
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.print("Conectando a: ");
  Serial.println(ssid);

  // Configura el ESP32 en modo estación (cliente Wi-Fi) e inicia la conexión
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Espera activa mientras intenta conectarse
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Confirmación de conexión exitosa
  Serial.println("");
  Serial.println("¡Conexión Wi-Fi establecida!");
  Serial.print("Dirección IP asignada: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  
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