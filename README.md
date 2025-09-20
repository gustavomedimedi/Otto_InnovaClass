Here is the README.md file in Spanish for your GitHub repository.

-----

# Robot Otto: Wemos D1 Mini y Servos SG90

Este repositorio contiene el código para controlar un **Robot Otto** usando un microcontrolador **Wemos D1 Mini**, cuatro **servos SG90** y un sensor ultrasónico. El proyecto busca proporcionar una base para programar un robot Otto con movimientos avanzados y capacidades para evitar obstáculos.

## 🤖 Funcionalidades

  * **🚶‍♂️ Movimientos Básicos**: Incluye funciones para caminar hacia adelante (`adelante()`), caminar hacia atrás (`atras()`) y dar pasos con cada pierna (`pasitoDER()`, `pasitoIZQ()`).
  * **💃 Funciones de Baile**: El robot puede realizar un `bailecito()` y un `dancelateral()` (baile lateral), lo que le da un toque divertido y con personalidad.
  * **🤸‍♂️ Movimientos Especiales**: También se incluye la función `saltito()` (pequeño salto) para demostrar movimientos más dinámicos.
  * **👀 Detección de Obstáculos**: Utiliza un sensor ultrasónico para detectar obstáculos y reaccionar. La función `obstaculo()` permite que el robot se detenga y realice una acción específica cuando se acerca demasiado a un objeto.
  * **📐 Estructura del Código**: El código está organizado en una clase `RobotMovil`, lo que facilita la gestión del hardware y las funciones de movimiento del robot. Está escrito en C++ y utiliza el entorno de Arduino.

## ⚙️ Componentes de Hardware

  * **Microcontrolador**: Wemos D1 Mini
  * **Servos**: 4 servos SG90
  * **Fuente de Energía**: 4 pilas AAA y un portapilas
  * **Sensor**: Sensor de distancia ultrasónico (HC-SR04)

## 📋 Primeros Pasos

### Requisitos

  * Tener el IDE de Arduino instalado en tu computadora.
  * Haber añadido el soporte para la placa Wemos D1 Mini en el IDE de Arduino.
  * Bibliotecas necesarias: `Servo.h` y `functional`.

### Instalación

1.  Clona este repositorio en tu máquina local:
    ```bash
    git clone https://github.com/tu-usuario/nombre-del-repositorio.git
    ```
2.  Abre el archivo `RobotMovil.ino` (o el archivo principal de tu sketch) en el IDE de Arduino.
3.  Asegúrate de que los archivos `.h` y `.cpp` estén en el mismo directorio que tu archivo de sketch principal.
4.  Selecciona la placa **Wemos D1 R1** y el puerto COM correcto en el menú `Herramientas` del IDE de Arduino.
5.  Sube el código a tu Wemos D1 Mini.

## 🔧 Diagrama de Conexiones

Conecta tus componentes de la siguiente manera:

  * **Servos**:

      * **Pierna Derecha (`piernaDer`)**: Pin D4
      * **Pie Derecho (`pieDer`)**: Pin D5
      * **Pie Izquierdo (`pieIzq`)**: Pin D6
      * **Pierna Izquierda (`piernaIzq`)**: Pin D7
      * Conecta los cables VCC (rojo) y GND (marrón/negro) de todos los servos al VCC y GND del portapilas.

  * **Sensor Ultrasónico**:

      * **Pin Trig**: Pin D2
      * **Pin Echo**: Pin D3
      * Conecta VCC y GND a los pines 5V y GND del Wemos D1 Mini.

[Imagen de un diagrama de cableado que muestre un Wemos D1 Mini conectado a cuatro servos SG90 y un sensor ultrasónico]

## 💻 Ejemplo de Uso

Aquí tienes un ejemplo de cómo podrías usar la clase `RobotMovil` en tu archivo de sketch principal:

```cpp
#include "RobotMovil.h"

// Define los pines para los servos y el sensor ultrasónico
#define PIERNA_DER_PIN D4
#define PIE_DER_PIN D5
#define PIE_IZQ_PIN D6
#define PIERNA_IZQ_PIN D7
#define TRIG_PIN D2
#define ECHO_PIN D3

// Crea una instancia de la clase RobotMovil
RobotMovil robot(PIERNA_DER_PIN, PIE_DER_PIN, PIE_IZQ_PIN, PIERNA_IZQ_PIN, TRIG_PIN, ECHO_PIN);

void setup() {
  robot.iniciar(); // Inicializa los servos y los pines del sensor del robot
  delay(2000); // Espera un momento para que el robot esté listo
}

void loop() {
  // Ejemplo 1: Evitar obstáculos. Camina hacia adelante hasta que detecte un obstáculo y luego se reinicia.
  robot.caminar();

  // Ejemplo 2: Caminar de forma continua con evasión.
  // robot.caminata();

  // Ejemplo 3: ¡Movimientos de baile!
  // robot.bailecito();
  // robot.dancelateral();
  // robot.saltito();
}
```
![Imagen de WhatsApp 2025-09-19 a las 21 21 59_db4e2beb](https://github.com/user-attachments/assets/2e25c7c5-f6c1-4cfb-8f1e-aff88da88959)


No dudes en descomentar los ejemplos en la función `loop()` para probar los diferentes movimientos.

## 🤝 Contribuciones

¡Las contribuciones son bienvenidas\! Si encuentras algún problema o quieres mejorar el código, no dudes en abrir un *pull request*.
