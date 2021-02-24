#include "Motor.h"

Motor::Motor(uint16_t pwm_motor,uint16_t dir_motor) {
    begin(pwm_motor, dir_motor);
}

void Motor::begin(uint16_t pwm_motor, uint16_t dir_motor) {
	_pwm_motor = pwm_motor;
	_dir_motor = dir_motor;
	_dir = Forward;
	
    pinMode(_pwm_motor, OUTPUT); 
    pinMode(_dir_motor, OUTPUT);

    digitalWrite(_pwm_motor, LOW);
    digitalWrite(_dir_motor, LOW);
}

void Motor::direction(Direction_t dir) {
  if(this->_dir != dir) {
    digitalWrite(_pwm_motor, LOW);
    digitalWrite(_dir_motor, LOW);
    
    uint16_t tmp = _dir_motor;
    _dir_motor = _pwm_motor;
    _pwm_motor = tmp;
       
    this->_dir = dir;
  }
}

void Motor::speed(uint8_t speed_motor) {
  analogWrite(_pwm_motor, speed_motor);
}