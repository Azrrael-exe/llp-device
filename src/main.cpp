#include <Arduino.h>
#include <settings.h>
#include <llp.h>
#include <analog_sensor.h>

DataPack input = DataPack();
AnalogSensor sensor = AnalogSensor(0x64, 1, 100);

void setup(){
    Serial.begin(115200);
    pinMode(0, INPUT);
    sensor.init(A0, 10);
}

void loop(){
    //delay(1000);
    DataPack out = sensor.run(input);

    out.write(Serial);
    
}