#include "Indicators.h"

#include "indicators.h"

Indicators::Indicators(uint16_t pins[COUNT_LIGHTS]) {
    begin(pins);
}

void Indicators::begin(uint16_t pins[COUNT_LIGHTS]) {
	memcpy(_pins, pins, sizeof(uint16_t) * COUNT_LIGHTS);
	_turn_time = 0;
	_turn = false;
	
    for(uint8_t i = 0; i < COUNT_LIGHTS; i++)
        pinMode(_pins[i], OUTPUT);

    digitalWrite(_pins[HEAD_LIGHT], HIGH);
}

void Indicators::lights_off() {
    for(uint8_t i = 0; i < COUNT_LIGHTS; i++)
        digitalWrite(_pins[i], LOW);
}

void Indicators::upd_indicators(uint8_t angle, uint8_t speed) {
    unsigned long time_current = millis();
  
    if(speed == 0)
        digitalWrite(_pins[STOP_IND], HIGH);
    else
        digitalWrite(_pins[STOP_IND], LOW);

    if(angle > (90 - _deviation) && !_turn) {
        digitalWrite(_pins[LEFT_IND], HIGH);

        _turn = true;
        _turn_time = time_current;
    }else if(angle < (90 - _deviation) && !_turn) {
        digitalWrite(_pins[RIGHT_IND], HIGH);

        _turn = true;
        _turn_time = time_current;
    }
    
    if(_turn && (time_current - _turn_time) >= _signal_freq) {
        digitalWrite(_pins[LEFT_IND], LOW);
        digitalWrite(_pins[RIGHT_IND], LOW);

        _turn = false;
    }
}