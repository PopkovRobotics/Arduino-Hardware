#include <Arduino.h>

#ifndef __INDICATORS_H__
#define __INDICATORS_H__

#define COUNT_LIGHTS        5
#define LEFT_IND            0
#define RIGHT_IND           1
#define HEAD_LIGHT          2
#define REAR_LIGHT          3
#define STOP_IND            4

class Indicators {
public:
    Indicators() = default;
    Indicators(uint16_t pins[COUNT_LIGHTS]);

    void begin(uint16_t pins[COUNT_LIGHTS]);

    void lights_off();
    void upd_indicators(uint8_t angle, uint8_t speed);

private:
    uint16_t _pins[COUNT_LIGHTS];

    const unsigned long _signal_freq = 500,
                        _deviation = 14;

    unsigned long _turn_time;
    bool _turn;
};

#endif // __INDICATORS_H__