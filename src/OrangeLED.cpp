#include "OrangeLED.h"

OrangeLED::OrangeLED(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

OrangeLED::OrangeLED(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

uint8_t OrangeLED::brightness() {
    // Read bits 0 - 5 from orange_led register
    uint8_t data = readFromRegister<uint8_t>(ORANGE_LED_REGISTER_INFO);
    uint8_t brightness = data & 63;
    return map(brightness, 0, 63, 0, 255);
}

bool OrangeLED::setBrightness(uint8_t brightness, bool persist) {
    if (brightness > 255) {
        return false; // Invalid brightness value
    }

    uint8_t mappedBrightness = map(brightness, 0, 255, 0, 63);
    uint8_t currentRegisterData = readFromRegister<uint8_t>(ORANGE_LED_REGISTER_INFO);
    // Overwrite bits 0 - 5 with the new value
    writeToRegister<uint8_t>(ORANGE_LED_REGISTER_INFO, (currentRegisterData & ~63) | mappedBrightness);

    if (persist) {
        return persistRegister(ORANGE_LED_REGISTER_INFO);
    }

    return true;
}

bool OrangeLED::errorStatusEnabled() {
    // Read bit 7 from orange_led register
    uint8_t data = readFromRegister<uint8_t>(ORANGE_LED_REGISTER_INFO);
    return data & (1 << 7);
}

bool OrangeLED::setErrorStatusEnabled(bool enabled, bool persist) {
    uint8_t currentRegisterData = readFromRegister<uint8_t>(ORANGE_LED_REGISTER_INFO);
    // Set bit 7 to 1 if enabled or 0 if disabled while keeping the other bits unchanged
    writeToRegister<uint8_t>(ORANGE_LED_REGISTER_INFO, (currentRegisterData & ~(1 << 7)) | (enabled << 7));

    if (persist) {
        return persistRegister(ORANGE_LED_REGISTER_INFO);
    }

    return true;
}
