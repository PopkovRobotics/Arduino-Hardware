#include <Servo.h>
#include "Motor.h"
#include "Indicators.h"
#include "TrackerSensor.h"

#define PIN_SERVO     9
#define PWR_MOTOR     6
#define DIR_MOTOR     5

static uint16_t light_pins[COUNT_LIGHTS] = { 7, 8, 10, 11, 12 };
static uint16_t sensor_pins[COUNT_SENSORS] = { A0, A1, A2, A3, A4 };

Motor motor;
Indicator indicators;
TrackerSensor sensors;

void setup() {
  Serial.begin(115200);
  
  motor.begin(PWR_MOTOR, DIR_MOTOR);
  indicators.begin(light_pins);
  sensors.begin(sensor_pins);
}

void loop() {
  sensors.print(Serial);
  sensors.blackline();
}

