#include "WhiteLED.h"

WhiteLED::WhiteLED(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

WhiteLED::WhiteLED(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

uint8_t WhiteLED::brightness() {
    // Read bits 0 - 5 from white_led register
    uint8_t data = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    return data & 63;
}

void WhiteLED::setBrightness(uint8_t brightness) {
    if (brightness > 63) {
        return; // Invalid brightness value
    }

    uint8_t currentRegisterData = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    // Overwrite bits 0 - 5 with the new value
    writeToRegister<uint8_t>(WHITE_LED_REGISTER_INFO, (currentRegisterData & ~63) | brightness);
}

bool WhiteLED::errorStatusEnabled() {
    // Read bit 7 from white_led register
    uint8_t data = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    return data & (1 << 7);
}

void WhiteLED::setErrorStatusEnabled(bool enabled) {
    uint8_t currentRegisterData = readFromRegister<uint8_t>(WHITE_LED_REGISTER_INFO);
    // Set bit 7 to 1 if enabled or 0 if disabled while keeping the other bits unchanged
    writeToRegister<uint8_t>(WHITE_LED_REGISTER_INFO, (currentRegisterData & ~(1 << 7)) | (enabled << 7));
}
