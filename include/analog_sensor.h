#include <input_device.h>
//Malok
class AnalogSensor: public InputDevice {
private:
    uint8_t pin;
    uint8_t samples;
    uint8_t counter;
    float value;
    uint16_t buffer[10];
    long sample_time;
    long timer;
public:
    AnalogSensor(uint16_t device_id, uint16_t threshold, long sample_time): InputDevice(device_id, threshold, sample_rate) {
      this->sample_time = sample_time;
    };
    bool init(uint8_t pin, uint8_t samples);
    uint16_t read();
};

bool AnalogSensor::init(uint8_t pin, uint8_t samples){
    this->pin = pin;
    this->counter = 0;
    this->samples = samples;
    this->timer = millis();
}

uint16_t AnalogSensor::read(){
  if (millis() - this->timer >= this->sample_time) {
    this->read_timer = millis();
    this->counter = this->counter + 1;
    this->buffer[this->counter] = analogRead(this->pin);
    //Serial.println(this->buffer[this->counter]);
  }
  if(this->counter >= this->samples){
    this->counter = 0;
    long sum = 0;
    for(int i = 0; i < this->samples; i++){
      sum += buffer[i];
    }
    this->value = float(sum)/this->samples;
  }
 
  return this->value;
}