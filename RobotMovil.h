#ifndef ROBOTMOVIL_H
#define ROBOTMOVIL_H

#include <Arduino.h>
#include <Servo.h>
#include <functional> // ¡Nuevo!

typedef std::function<void()> Accion; // ¡Modificado!

class RobotMovil {
public:
  RobotMovil(int piernaDer, int pieDer, int pieIzq, int piernaIzq, int trig, int echo);

  void iniciar();
  void resetear();
  void leerDistancia();
  void caminar();
  void caminata();
  void adelante();
  void atras();
  void bailecito();
  void dancelateral();
  void saltito();
  void obstaculo(int distanciaUmbral, Accion accion);
  void pasitoDER();
  void pasitoIZQ();
  int obtenerDistancia();

private:
  Servo pie_izq, pie_der, pierna_der, pierna_izq;
  int pinPiernaDer, pinPieDer, pinPieIzq, pinPiernaIzq;
  int trigPin, echoPin;
  long duration;
  int distance;
  int pos;


};

#endif