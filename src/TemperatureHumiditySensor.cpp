#include "TemperatureHumiditySensor.h"

TemperatureHumiditySensor::TemperatureHumiditySensor(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

TemperatureHumiditySensor::TemperatureHumiditySensor(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

float TemperatureHumiditySensor::temperature() {
    float temperature = this->readFromRegister<float>(TEMPERATURE_REGISTER_INFO);
    // A value of 0x00 00 96 c3 (unpacked -300) indicates that the temperature sensor is not ready
    // This was discovered by trial and error
    if (temperature == -300) {
        return NAN;  // Return a negative value to indicate an error
    }
    return temperature;
}

float TemperatureHumiditySensor::humidity() {
    return this->readFromRegister<float>(HUMIDITY_REGISTER_INFO);
}

bool TemperatureHumiditySensor::enabled() {
    uint8_t status = this->readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    return (status & 1) != 0;
}

bool TemperatureHumiditySensor::setEnabled(bool enabled, bool persist) {
    // Read the current status and update the least significant bit with the new value
    uint8_t status = this->readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    
    // Check if current value is already the desired value
    if (static_cast<bool>(status & 1) == enabled) {
        return true;
    }

    status = enabled ? (status | 1) : (status & 0xFE);
    this->writeToRegister(STATUS_REGISTER_INFO, status);

    if(persist) {
        return this->persistRegister(STATUS_REGISTER_INFO);
    }

    return true;
}
