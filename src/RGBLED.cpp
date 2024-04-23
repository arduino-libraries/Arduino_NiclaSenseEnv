#include "RGBLED.h"


RGBLED::RGBLED(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

RGBLED::RGBLED(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

void RGBLED::enableIndoorAirQualityStatus() {
    enableIndoorAirQualityStatus(255);  // Default maximum brightness
}

void RGBLED::enableIndoorAirQualityStatus(uint8_t brightness) {
    writeToRegister(RGB_LED_RED_REGISTER_INFO, 0);
    writeToRegister(GREEN_REGISTER_INFO, 0);
    writeToRegister(BLUE_REGISTER_INFO, 0);
    writeToRegister(INTENSITY_REGISTER_INFO, brightness);
}

void RGBLED::setColor(uint8_t r, uint8_t g, uint8_t b) {
    setColor(r, g, b, 255);  // Default maximum brightness
}

void RGBLED::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness) {
    writeToRegister(RGB_LED_RED_REGISTER_INFO, r);
    writeToRegister(GREEN_REGISTER_INFO, g);
    writeToRegister(BLUE_REGISTER_INFO, b);
    writeToRegister(INTENSITY_REGISTER_INFO, brightness);
}

void RGBLED::setColor(Color color) {
    setColor(color, 255);  // Default maximum brightness
}

void RGBLED::setColor(Color color, uint8_t brightness) {
    setColor(color.red, color.green, color.blue, brightness);
}

Color RGBLED::color() {
    uint8_t red = readFromRegister<uint8_t>(RGB_LED_RED_REGISTER_INFO);
    uint8_t green = readFromRegister<uint8_t>(GREEN_REGISTER_INFO);
    uint8_t blue = readFromRegister<uint8_t>(BLUE_REGISTER_INFO);
    return {red, green, blue};
}

uint8_t RGBLED::brightness() {
    return readFromRegister<uint8_t>(INTENSITY_REGISTER_INFO);
}

void RGBLED::setBrightness(uint8_t brightness) {
    writeToRegister(INTENSITY_REGISTER_INFO, brightness);
}
