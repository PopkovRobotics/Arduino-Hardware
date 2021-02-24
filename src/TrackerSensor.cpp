#include "TrackerSensor.h"

TrackerSensor::TrackerSensor(uint16_t pins[COUNT_SENSORS]) {
    begin(pins);
}

void TrackerSensor::begin(uint16_t pins[COUNT_SENSORS]) {
	memcpy(_pins, pins, sizeof(uint16_t) * COUNT_SENSORS);
	
    for(uint8_t i = 0; i < COUNT_SENSORS; i++)
        pinMode(_pins[i], INPUT);
}

void TrackerSensor::weights(float w[COUNT_SENSORS]) {
	memcpy(_weights, w, sizeof(float) * COUNT_SENSORS);
}

uint16_t TrackerSensor::read(uint8_t number, Mode_t mode) {
    if(mode == Analog_Mode)
        return analogRead(_pins[number]);
    else
        return digitalRead(_pins[number]);
}

uint16_t* TrackerSensor::read_all(Mode_t mode, HardwareSerial* serial, bool print) {
    uint16_t buffer[COUNT_SENSORS];

    for(uint8_t i = 0; i < COUNT_SENSORS; i++) {
        buffer[i] = read(i, mode);
        if(print) {
            serial->print(buffer[i]);
            serial->print(' ');
        }
    }
    if(print) serial->println(' ');
    return buffer;
}

uint16_t* TrackerSensor::print(Mode_t mode, HardwareSerial* serial) {
    return read_all(mode, serial, true);
}

float TrackerSensor::blackline() {
    float avg = 0, 
          sum = 0;

    for(uint8_t i = 0; i < COUNT_SENSORS; i++) {
        uint16_t value = read(i, Mode_t::Analog_Mode);
        avg += value * _weights[i];
        sum += value;
    }

    return avg / sum;
}