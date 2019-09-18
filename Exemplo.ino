#include <HBridge.h>

#define pin_pwm 9
#define pin_a 7
#define pin_b 8

HBridgeMotor motor(pin_pwm, pin_a, pin_b);

void setup(){
    motor.parar(); //Parar motor
}

void loop(){
    motor.acionar(100); //Motor girando na velocidade máxima em uma direção
    delay(1000);
    motor.parar();
    delay(1000);
    motor.acionar(-100); //Motor girando na velocidade máxima na direção inversa
    delay(1000);
}