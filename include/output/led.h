#include <output/output_device.h>

class LedOutput: public OutputDevice {
private:
    uint8_t pin;
public:
    LedOutput(uint16_t device_id): OutputDevice(device_id){}
    bool init(uint8_t pin);
    uint16_t execute(uint16_t value);
    bool shouldRun(DataPack input);
};

bool LedOutput::init(uint8_t pin){
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
}

uint16_t LedOutput::execute(uint16_t value){
    uint16_t op_value = map(value, 0, 1024, 0, 255);
    analogWrite(this->pin, op_value);
    return op_value;
}

bool LedOutput::shouldRun(DataPack input){
    if(input.inWaiting() > 1) {
        return (input.getData(DEVICE_ID_KEY) == 0x64 && input.getData(DEVICE_TYPE_KEY) == INPUT_DEVICE_TYPE);
    }
    return false;
}