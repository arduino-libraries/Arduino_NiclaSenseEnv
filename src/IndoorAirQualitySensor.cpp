#include "IndoorAirQualitySensor.h"

IndoorAirQualitySensor::IndoorAirQualitySensor(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

IndoorAirQualitySensor::IndoorAirQualitySensor(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

bool IndoorAirQualitySensor::sulfurOdor() {
    return readFromRegister<bool>(ZMOD4410_ODOR_CLASS_REGISTER_INFO);
}

float IndoorAirQualitySensor::odorIntensity() {
    return readFromRegister<float>(ZMOD4410_INTENSITY_REGISTER_INFO);
}

float IndoorAirQualitySensor::ethanol() {
    return readFromRegister<float>(ZMOD4410_ETOH_REGISTER_INFO);
}

float IndoorAirQualitySensor::CO2() {
    return readFromRegister<float>(ZMOD4410_ECO2_REGISTER_INFO);
}

float IndoorAirQualitySensor::TVOC() {
    return readFromRegister<float>(ZMOD4410_TVOC_REGISTER_INFO);
}

float IndoorAirQualitySensor::airQuality() {
    return readFromRegister<float>(ZMOD4410_IAQ_REGISTER_INFO);
}

String IndoorAirQualitySensor::airQualityInterpreted() {
    float iaqValue = airQuality();
    if (iaqValue <= 1.99) {
        return "Very Good";
    } else if (iaqValue <= 2.99) {
        return "Good";
    } else if (iaqValue <= 3.99) {
        return "Medium";
    } else if (iaqValue <= 4.99) {
        return "Poor";
    } else {
        return "Bad";
    }
}

float IndoorAirQualitySensor::relativeAirQuality() {
    return readFromRegister<float>(ZMOD4410_REL_IAQ_REGISTER_INFO);
}

IndoorAirQualitySensorMode IndoorAirQualitySensor::mode() {
    uint8_t data = readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    return IndoorAirQualitySensorMode((data >> 1) & 7);
}

bool IndoorAirQualitySensor::setMode(IndoorAirQualitySensorMode sensorMode, bool persist) {
    uint8_t currentRegisterData = readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    uint8_t mode = static_cast<uint8_t>(sensorMode); // convert to numeric type

    // Check if the existing value is already the same
    if ((currentRegisterData & (7 << 1)) == (mode << 1)) {
        return true;
    }
    if(!writeToRegister(STATUS_REGISTER_INFO, (currentRegisterData & ~(7 << 1)) | (mode << 1))){
        return false;
    }

    if(persist){
        return persistRegister(STATUS_REGISTER_INFO);
    }

    return true;
}

String IndoorAirQualitySensor::modeString() {
    auto value = mode();
    switch (value) {
        case IndoorAirQualitySensorMode::powerDown:
            return "powerDown";
        case IndoorAirQualitySensorMode::cleaning:
            return "cleaning";
        case IndoorAirQualitySensorMode::indoorAirQuality:
            return "indoorAirQuality";
        case IndoorAirQualitySensorMode::indoorAirQualityLowPower:
            return "indoorAirQualityLowPower";
        case IndoorAirQualitySensorMode::sulfur:
            return "sulfur";
        default:
            return "unknown";
    }
}

bool IndoorAirQualitySensor::enabled() {
    return mode() != IndoorAirQualitySensorMode::powerDown;
}

bool IndoorAirQualitySensor::setEnabled(bool isEnabled, bool persist) {
    if (isEnabled == enabled()) {
        return true;
    }

    auto mode = isEnabled ? IndoorAirQualitySensorMode::indoorAirQuality : IndoorAirQualitySensorMode::powerDown;
    return setMode(mode, persist);
}
