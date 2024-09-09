#include "RGBLED.h"


RGBLED::RGBLED(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

RGBLED::RGBLED(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

bool RGBLED::enableIndoorAirQualityStatus(uint8_t brightness, bool persist) {
    return setColor(0, 0, 0, persist) && setBrightness(brightness, persist);
}

bool RGBLED::setColor(uint8_t r, uint8_t g, uint8_t b, bool persist) {
    if(!writeToRegister(RGB_LED_RED_REGISTER_INFO, r)) return false;
    if(!writeToRegister(RGB_LED_GREEN_REGISTER_INFO, g)) return false;
    if(!writeToRegister(RGB_LED_BLUE_REGISTER_INFO, b)) return false;

    if (persist) {
        return persistRegister(RGB_LED_RED_REGISTER_INFO) &&
               persistRegister(RGB_LED_GREEN_REGISTER_INFO) &&
               persistRegister(RGB_LED_BLUE_REGISTER_INFO);
    }

    return true;
}

bool RGBLED::setColor(LEDColor color, bool persist) {
    return setColor(color.red, color.green, color.blue, persist);
}

LEDColor RGBLED::color() {
    uint8_t red = readFromRegister<uint8_t>(RGB_LED_RED_REGISTER_INFO);
    uint8_t green = readFromRegister<uint8_t>(RGB_LED_GREEN_REGISTER_INFO);
    uint8_t blue = readFromRegister<uint8_t>(RGB_LED_BLUE_REGISTER_INFO);
    return {red, green, blue};
}

uint8_t RGBLED::brightness() {
    return readFromRegister<uint8_t>(INTENSITY_REGISTER_INFO);
}

bool RGBLED::setBrightness(uint8_t brightness, bool persist) {
    if(!writeToRegister(INTENSITY_REGISTER_INFO, brightness)) return false;

    if (persist) {
        return persistRegister(INTENSITY_REGISTER_INFO);
    }

    return true;
}
