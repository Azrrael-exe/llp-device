#include <Arduino.h>
#include <settings.h>
#include <llp.h>
#include <ir_sensor.h>

DataPack input = DataPack();
IrSensor sensor = IrSensor(0x76, 1, 500);

void setup(){
    Serial.begin(115200);
    pinMode(3, INPUT);
    sensor.init(3);
}

void loop(){
    delay(1000);
    DataPack out = sensor.run(input);
    out.write(Serial);    
}