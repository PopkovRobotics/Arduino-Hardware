#include <Arduino.h>

#ifndef __MOTOR_H__
#define __MOTOR_H__

class Motor {
public:
    typedef enum {
        Forward = 0,
        Backward,
    } Direction_t;

    Motor() = default;
    Motor(uint16_t pwm_motor, uint16_t dir_motor);

    void begin(uint16_t pwm_motor, uint16_t dir_motor);
  
    void direction(Direction_t dir);
  
    void speed(uint8_t speed_motor);

private:
  uint16_t _pwm_motor,
           _dir_motor;

  Direction_t _dir;
};

#endif // __MOTOR_H__