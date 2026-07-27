# ESP-IDF Arduino Component Example

Este proyecto demuestra cómo integrar el *framework* de **Arduino** como un componente dentro de un proyecto nativo de **ESP-IDF**.

Permite combinar la potencia y las herramientas profesionales de ESP-IDF con la simplicidad de las librerías de Arduino para el microcontrolador ESP32.

---

## 🛠️ Modos de Ejecución (menuconfig)

El proyecto permite elegir la estructura del código mediante `sdkconfig`. Puedes seleccionar entre el punto de entrada nativo de ESP-IDF (`app_main`) o la estructura tradicional de Arduino (`setup` y `loop`).

### Cómo cambiar el modo:

1. Abre la herramienta de configuración:
   ```bash
   idf.py menuconfig