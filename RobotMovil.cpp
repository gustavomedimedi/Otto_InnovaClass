#include "RobotMovil.h"

RobotMovil::RobotMovil(int piernaDer, int pieDer, int pieIzq, int piernaIzq, int trig, int echo)
  : pinPiernaDer(piernaDer), pinPieDer(pieDer), pinPieIzq(pieIzq), pinPiernaIzq(piernaIzq),
    trigPin(trig), echoPin(echo), pos(0), distance(0) {}

void RobotMovil::iniciar() {
  pierna_der.attach(pinPiernaDer, 300, 2600);
  pie_der.attach(pinPieDer, 300, 2600);
  pie_izq.attach(pinPieIzq, 300, 2600);
  pierna_izq.attach(pinPiernaIzq, 300, 2600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  resetear();
}

void RobotMovil::resetear() {
  pierna_der.write(90);
  pie_der.write(90);
  pie_izq.write(90);
  pierna_izq.write(90);
}

void RobotMovil::leerDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

int RobotMovil::obtenerDistancia() {
  return distance;
}

void RobotMovil::obstaculo(int distanciaUmbral, Accion accion) {
  leerDistancia();
  while (distance < distanciaUmbral) {
    accion();
    leerDistancia();
  }
}

void RobotMovil::caminar() {
  pasitoDER();
  delay(500);
  obstaculo(12, [this]() { this->resetear(); });
  delay(100);
  pasitoIZQ();
  delay(500);
  obstaculo(12, [this]() { this->resetear(); });
  delay(100);
}

void RobotMovil::pasitoDER() {
  for (pos = 90; pos >= 35; pos--) pie_der.write(pos), delay(5);
  for (pos = 90; pos >= 70; pos--) pie_izq.write(pos), delay(5);
  for (pos = 90; pos <= 135; pos++) {
    pierna_izq.write(pos);
    pie_der.write(pos - 55);
    delay(5);
  }
  for (pos = 70; pos <= 90; pos++) pie_izq.write(pos), delay(5);
  pie_der.write(90);
  pierna_izq.write(90);
}

void RobotMovil::pasitoIZQ() {
  for (pos = 90; pos <= 150; pos++) pie_izq.write(pos), delay(5);
  for (pos = 90; pos <= 110; pos++) pie_der.write(pos), delay(5);
  for (pos = 90; pos >= 45; pos--) {
    pierna_der.write(pos);
    pie_izq.write(pos + 60);
    delay(5);
  }
  for (pos = 110; pos >= 90; pos--) pie_der.write(pos), delay(5);
  pie_izq.write(90);
  pierna_der.write(90);
}

void RobotMovil::bailecito() {
  for (int i = 90; i >= 60; i--) pierna_der.write(i), delay(10);
  for (int i = 60; i <= 90; i++) pierna_der.write(i), delay(10);
  for (int i = 90; i <= 120; i++) pie_izq.write(i), delay(10);
  for (int i = 120; i >= 90; i--) pie_izq.write(i), delay(10);
  delay(100);
  for (int i = 90; i <= 120; i++) pierna_izq.write(i), delay(10);
  for (int i = 120; i >= 90; i--) pierna_izq.write(i), delay(10);
  for (int i = 90; i >= 70; i--) pie_der.write(i), delay(10);
  for (int i = 70; i <= 90; i++) pie_der.write(i), delay(10);
  delay(100);
}

void RobotMovil::dancelateral() {
  for (int i = 90; i <= 135; i++) pie_izq.write(i), delay(5);
  for (int i = 135; i >= 90; i--) pie_izq.write(i), delay(5);
  delay(100);
  for (int i = 90; i >= 45; i--) pie_der.write(i), delay(5);
  for (int i = 45; i <= 90; i++) pie_der.write(i), delay(5);
  delay(100);
}

void RobotMovil::saltito() {
  for (int i = 0; i <= 45; i++) {
    pie_izq.write(90 + i);
    pie_der.write(90 - i);
    delay(5);
  }
  delay(100);
  for (int i = 45; i >= 0; i--) {
    pie_izq.write(90 + i);
    pie_der.write(90 - i);
    delay(5);
  }
  delay(100);
}

void RobotMovil::caminata() {
  leerDistancia();
  delay(200);
  if (distance > 12) {
    adelante();
  } else {
    atras();
  }
}

void RobotMovil::adelante() {
  for (int i = 90; i >= 80; i--) pie_izq.write(i), pie_der.write(i), delay(5);
  for (int i = 60; i <= 120; i++) pierna_der.write(i), pierna_izq.write(i), delay(5);
  for (int i = 80; i <= 100; i++) pie_izq.write(i), pie_der.write(i), delay(5);
  for (int i = 120; i >= 60; i--) pierna_der.write(i), pierna_izq.write(i), delay(5);
  for (int i = 100; i >= 90; i--) pie_izq.write(i), pie_der.write(i), delay(5);

  
}

void RobotMovil::atras() {
  for (int i = 90; i <= 100; i++) pie_izq.write(i), pie_der.write(i), delay(5);
  for (int i = 60; i <= 120; i++) pierna_der.write(i), pierna_izq.write(i), delay(5);
  for (int i = 100; i >= 80; i--) pie_izq.write(i), pie_der.write(i), delay(5);
  for (int i = 120; i >= 60; i--) pierna_der.write(i), pierna_izq.write(i), delay(5);
  for (int i = 80; i <= 90; i++) pie_izq.write(i), pie_der.write(i), delay(5);
}