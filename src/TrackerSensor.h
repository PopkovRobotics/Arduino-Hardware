#include <Arduino.h>

#ifndef __TRACKER_SENSOR_H___
#define __TRACKER_SENSOR_H___

#define COUNT_SENSORS     5

class TrackerSensor {
public:
    typedef enum {
        Analog_Mode = 0,
        Digital_Mode,
    } Mode_t;

    TrackerSensor() = default;
    TrackerSensor(uint16_t pins[COUNT_SENSORS]);

    void begin(uint16_t pins[COUNT_SENSORS]);

    void weights(float w[COUNT_SENSORS]);

    uint16_t read(uint8_t number, Mode_t mode);
    uint16_t* read_all(Mode_t mode, HardwareSerial* serial = NULL, bool print = false);

    uint16_t* print(Mode_t mode, HardwareSerial* serial);

    float blackline();
private:
    uint16_t _pins[COUNT_SENSORS];

    float _weights[COUNT_SENSORS]; 
};

#endif // __TRACKER_SENSOR_H___