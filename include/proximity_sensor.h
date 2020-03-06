#include <input_device.h>

class ProximitySensor: public InputDevice {
private:
    uint8_t pin;
    uint8_t samples;
public:
    ProximitySensor(uint16_t device_id, uint16_t threshold, long sample_time): InputDevice(device_id, threshold, sample_rate) {};
    bool init(uint8_t pin, uint8_t samples);
    uint16_t read();
};

bool ProximitySensor::init(uint8_t pin, uint8_t samples){
    this->pin = pin;
    this->samples = samples;
    this->read_timer = millis();
}

uint16_t ProximitySensor::read(){
  long suma=0;
  for(int i=0; i < this->samples; i++)
  {
    suma=suma+ analogRead(this->pin);
  }  
  float adc=suma/this->samples;
  float distancia_cm = 500 * pow(adc, -0.6) - 10;
  uint16_t distancia_mm = (unsigned int) (distancia_cm * 10);
  return(distancia_mm);
}