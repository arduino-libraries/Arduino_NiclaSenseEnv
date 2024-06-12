#include "OrangeLED.h"

OrangeLED::OrangeLED(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

OrangeLED::OrangeLED(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

uint8_t OrangeLED::brightness() {
    // Read bits 0 - 5 from orange_led register
    uint8_t data = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    return data & 63;
}

void OrangeLED::setBrightness(uint8_t brightness) {
    if (brightness > 63) {
        return; // Invalid brightness value
    }

    uint8_t currentRegisterData = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    // Overwrite bits 0 - 5 with the new value
    writeToRegister<uint8_t>(WHITE_LED_REGISTER_INFO, (currentRegisterData & ~63) | brightness);
}

bool OrangeLED::errorStatusEnabled() {
    // Read bit 7 from orange_led register
    uint8_t data = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    return data & (1 << 7);
}

void OrangeLED::setErrorStatusEnabled(bool enabled) {
    uint8_t currentRegisterData = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    // Set bit 7 to 1 if enabled or 0 if disabled while keeping the other bits unchanged
    writeToRegister<uint8_t>(WHITE_LED_REGISTER_INFO, (currentRegisterData & ~(1 << 7)) | (enabled << 7));
}
