#include <RobotMovil.h>

// Pines conectados a los servos y sensor ultrasónico
const int pinPiernaDer = D6;
const int pinPieDer = D5;
const int pinPieIzq = D1;
const int pinPiernaIzq = D2;
const int trigPin = D8;
const int echoPin = D7;

// Instancia del robot
RobotMovil robot(pinPiernaDer, pinPieDer, pinPieIzq, pinPiernaIzq, trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  robot.iniciar();       // Inicializa servos y sensor
  robot.resetear();      // Posición neutral
}

void loop() {
  robot.caminata();       // Ejecuta pasos alternos con detección de obstáculos
  robot.caminata();
  robot.caminata();
  robot.resetear();
  delay(1000);
  robot.leerDistancia();
  Serial.print("Distancia detectada: ");
  Serial.println(robot.obtenerDistancia());
  delay(500);
  robot.saltito();
  robot.saltito();
  robot.saltito();
  robot.resetear();
  robot.bailecito();     // ¡Un poco de diversión!
  robot.resetear();
  robot.caminar(); 
  robot.caminar(); 
  robot.resetear();
  delay(1000);
}