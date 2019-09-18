/*
Biblioteca para uso do Shield Ponte H
Utilizada para controlar o acionamento, rotação e velocidade do motor

₢ Trio Parada Dura 2019 - IFPB(Campina Grande)
Software livre para uso do shield ponte H desenvolvido na disciplina 
Técnicas de Prototipagem do Curso de Engenharia de Computação.


*/

#ifndef HBridge_h
#define HBridge_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

class HBridgeMotor{
    public:
        HBridgeMotor(int pin_pwn, int pin_a, int pin_b);
        HBridgeMotor(HardwareSerial *serial);
        void acionar(int velocidade);
        void parar();
    private:
        int limite(int valor, int superior, int inferior);
        int _pin_pwm, _pin_a, _pin_b, _velocidade;
        HardwareSerial * _hardSerial;

};

#endif