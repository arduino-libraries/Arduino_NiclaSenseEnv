#include "I2CDevice.h"
#include <Arduino.h>


I2CDevice::I2CDevice(TwoWire& bus, uint8_t deviceAddress)
    : bus(bus), i2cDeviceAddress(deviceAddress) {}

I2CDevice::I2CDevice(uint8_t deviceAddress)
    : bus(Wire), i2cDeviceAddress(deviceAddress) {}

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
