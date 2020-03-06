#include <Arduino.h>
#include <settings.h>
#include <llp.h>
#include <sensor/analog/analog_sensor.h>
#include <output/led.h>

DataPack input = DataPack();
LedOutput led = LedOutput(0x55);
AnalogSensor sensor = AnalogSensor(0x64, 1, 100);

void setup(){
    Serial.begin(115200);
    sensor.init(A0, 10);
    led.init(5);
}

void loop(){
    delay(1000);
    DataPack out;
    out = sensor.run(input);
    out = led.run(out);
    out.write(Serial);
}