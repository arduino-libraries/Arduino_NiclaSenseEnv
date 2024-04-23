#include "OutdoorAirQualitySensor.h"

OutdoorAirQualitySensor::OutdoorAirQualitySensor(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

OutdoorAirQualitySensor::OutdoorAirQualitySensor(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

int OutdoorAirQualitySensor::airQualityIndex() {
    return readFromRegister<uint16_t>(ZMOD4510_EPA_AQI_REGISTER_INFO);
}

String OutdoorAirQualitySensor::airQualityIndexInterpreted() {
    int airQualityValue = airQualityIndex();
    if (airQualityValue <= 50) {
        return "Good";
    } else if (airQualityValue <= 100) {
        return "Moderate";
    } else if (airQualityValue <= 150) {
        return "Unhealthy for Sensitive Groups";
    } else if (airQualityValue <= 200) {
        return "Unhealthy";
    } else if (airQualityValue <= 300) {
        return "Very Unhealthy";
    } else {
        return "Hazardous";
    }
}

int OutdoorAirQualitySensor::fastAirQualityIndex() {
    return readFromRegister<uint16_t>(ZMOD4510_FAST_AQI_REGISTER_INFO);
}

float OutdoorAirQualitySensor::NO2() {
    return readFromRegister<float>(ZMOD4510_NO2_REGISTER_INFO);
}

float OutdoorAirQualitySensor::O3() {
    return readFromRegister<float>(ZMOD4510_O3_REGISTER_INFO);
}

OutdoorAirQualitySensorMode OutdoorAirQualitySensor::mode() {
    uint8_t data = readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    // Read bits 4 and 5
    return OutdoorAirQualitySensorMode((data >> 4) & 3);
}

void OutdoorAirQualitySensor::setMode(OutdoorAirQualitySensorMode sensorMode) {
    uint8_t currentRegisterData = readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    uint8_t mode = static_cast<uint8_t>(sensorMode); // convert to numeric type

    // Check if the existing value is already the same
    if ((currentRegisterData & (3 << 4)) == (mode << 4)) {
        return;
    }

    // Overwrite bits 4 and 5 with the new value
    writeToRegister<uint8_t>(STATUS_REGISTER_INFO, (currentRegisterData & ~(3 << 4)) | (mode << 4));
}

String OutdoorAirQualitySensor::modeString() {
    auto value = mode();
    if (value == OutdoorAirQualitySensorMode::powerDown) {
        return "powerDown";
    } else if (value == OutdoorAirQualitySensorMode::cleaning) {
        return "cleaning";
    } else if (value == OutdoorAirQualitySensorMode::outdoorAirQuality) {
        return "outdoorAirQuality";
    } else {
        return "unknown";
    }
}

bool OutdoorAirQualitySensor::enabled() {
    return mode() != OutdoorAirQualitySensorMode::powerDown;
}

void OutdoorAirQualitySensor::setEnabled(bool isEnabled) {
    // Ignore the request if the sensor is already in the desired state to maintain the current mode
    if (isEnabled == enabled()) {
        return;
    }
    if (isEnabled) {
        setMode(OutdoorAirQualitySensorMode::defaultMode);
    } else {
        setMode(OutdoorAirQualitySensorMode::powerDown);
    }
}
