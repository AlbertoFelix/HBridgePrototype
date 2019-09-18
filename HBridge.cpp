#include <Arduino.h>
#include <HBridge.h>

/*
Parâmetros para inicialização da ponte H

pin_pwm --> habilita a carga
pin_a --> faz a corrente passar pela carga em uma direção
pin_b --> faz a corrente passar pela carga na direção inversa do pin_a

*/

HBridgeMotor::HBridgeMotor(int pin_pwm, int pin_a, int pin_b){
  pinMode(pin_pwm, OUTPUT);
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);

  _pin_pwm = pin_pwm;
  _pin_a = pin_a;
  _pin_b = pin_b;
}

/*
Acionar o motor definindo um parâmetro chamado velocidade
Valores de -100 à -1 fazem a corrente passar pela carga em uma direção com a velocidade entre 1 e 100
Valores de 1 à 100 fazem a corrente passar pela carga em direção inversa com a velocidade entre 1 e 100
*/

void HBridgeMotor::acionar(int velocidade){
  velocidade = limite(velocidade, -100, 100);
  if(velocidade > 0){
    digitalWrite(_pin_a, HIGH);
    digitalWrite(_pin_b, LOW);
    analogWrite(_pin_pwm, map(velocidade, 1, 100, 1, 255));
  }else{
    digitalWrite(_pin_a, LOW);
    digitalWrite(_pin_b, HIGH);
    analogWrite(_pin_pwm, map(-velocidade, 0, 100, 0, 255));
  }
}

/*
Parar --> função bloqueia a passagem da corrente em ambas as direções
*/

void HBridgeMotor::parar(){
  digitalWrite(_pin_a, LOW);
  digitalWrite(_pin_b, LOW);
}

/*
Função para limitar a velocidade superior e inferior, caso o parâmetro de velocidade
seja maior ou menor usaremos o valor default superior ou inferior
*/
int HBridgeMotor::limite(int valor, int superior, int inferior){
  valor=valor > superior ? superior:valor;
  valor=valor < inferior ? inferior:valor;
  return valor;
}