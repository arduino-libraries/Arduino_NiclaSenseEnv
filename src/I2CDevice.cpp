#include "I2CDevice.h"
#include <Arduino.h>


I2CDevice::I2CDevice(TwoWire& bus, uint8_t deviceAddress)
    : bus(bus), i2cDeviceAddress(deviceAddress) {}

I2CDevice::I2CDevice(uint8_t deviceAddress)
    : bus(Wire), i2cDeviceAddress(deviceAddress) {}

bool I2CDevice::persistRegister(RegisterInfo registerInfo){
    writeToRegister(DEFAULTS_REGISTER_INFO, registerInfo.address | (1 << 7));

    // Read bit 7 to check if the write is complete. When the write is complete, bit 7 will be 0.
    // Try 10 times with increasing delay between each try
    for (int i = 0; i < 10; ++i) {
        uint8_t defaultsRegisterData = readFromRegister<uint8_t>(DEFAULTS_REGISTER_INFO);
        if (!(defaultsRegisterData & (1 << 7))) {
            return true;
        }
        // Even a value of 1 us seems to work, but we start with 100 us to be safe.
        Serial.println("⌛️ Waiting for flash write to complete...");
        // Exponential sleep duration
        delayMicroseconds(100 * (2 << i));
    }

    return false;
}

bool I2CDevice::connected() {
    bus.beginTransmission(i2cDeviceAddress);
    return bus.endTransmission() == 0;
}

bool I2CDevice::begin() {
    bus.begin();
    return connected();
}

uint8_t I2CDevice::deviceAddress() const {
    return i2cDeviceAddress;
}
