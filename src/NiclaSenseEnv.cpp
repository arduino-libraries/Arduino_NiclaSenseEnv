#include "NiclaSenseEnv.h"
#include "registers.h"
#include <string>
#include <array>

// Define baud rate values corresponding to indices 0 - 7
const int baudRateMap[] = {1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};

NiclaSenseEnv::NiclaSenseEnv(TwoWire& bus, uint8_t deviceAddress) : I2CDevice(bus, deviceAddress) {}

NiclaSenseEnv::NiclaSenseEnv(uint8_t deviceAddress) : I2CDevice(deviceAddress) {}

NiclaSenseEnv::~NiclaSenseEnv() {
    // Ensure cleanup when the object is destroyed
    end();
}

TemperatureHumiditySensor& NiclaSenseEnv::temperatureHumiditySensor() {
    if (!temperatureSensorInstance) {
        temperatureSensorInstance = new TemperatureHumiditySensor(this->bus, this->i2cDeviceAddress);
    }
    return *temperatureSensorInstance;
}

IndoorAirQualitySensor& NiclaSenseEnv::indoorAirQualitySensor() {
    if (!indoorAirQualitySensorInstance) {
        indoorAirQualitySensorInstance = new IndoorAirQualitySensor(this->bus, this->i2cDeviceAddress);
    }
    return *indoorAirQualitySensorInstance;
}

OutdoorAirQualitySensor& NiclaSenseEnv::outdoorAirQualitySensor() {
    if (!outdoorAirQualitySensorInstance) {
        outdoorAirQualitySensorInstance = new OutdoorAirQualitySensor(this->bus, this->i2cDeviceAddress);
    }
    return *outdoorAirQualitySensorInstance;
}

RGBLED& NiclaSenseEnv::rgbLED() {
    if (!rgbLed) {
        rgbLed = new RGBLED(this->bus, this->i2cDeviceAddress);
    }
    return *rgbLed;
}

OrangeLED& NiclaSenseEnv::orangeLED() {
    if (!orangeLed) {
        orangeLed = new OrangeLED(this->bus, this->i2cDeviceAddress);
    }
    return *orangeLed;
}

void NiclaSenseEnv::end() {
    if (temperatureSensorInstance) {
        delete temperatureSensorInstance;
        temperatureSensorInstance = nullptr;
    }
    if (indoorAirQualitySensorInstance) {
        delete indoorAirQualitySensorInstance;
        indoorAirQualitySensorInstance = nullptr;
    }
    if (outdoorAirQualitySensorInstance) {
        delete outdoorAirQualitySensorInstance;
        outdoorAirQualitySensorInstance = nullptr;
    }
    if (rgbLed) {
        delete rgbLed;
        rgbLed = nullptr;
    }
    if (orangeLed) {
        delete orangeLed;
        orangeLed = nullptr;
    }
}

bool NiclaSenseEnv::persistSettings() {
    uint8_t controlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);

    writeToRegister(CONTROL_REGISTER_INFO, controlRegisterData | (1 << 7));

    // Read bit 7 to check if the write is complete. When the write is complete, bit 7 will be 0.
    // Try 10 times with increasing delay between each try
    for (int i = 0; i < 10; ++i) {
        controlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);
        if (!(controlRegisterData & (1 << 7))) {
            return true;
        }
        // Even a value of 1 us seems to work, but we start with 100 us to be safe.
        Serial.println("⌛️ Waiting for flash write to complete...");
        // Exponential sleep duration
        delayMicroseconds(100 * (2 << i));
    }
    
    return false;
}

String NiclaSenseEnv::serialNumber() {
    constexpr size_t size = SERIAL_NUMBER_REGISTER_INFO.bytes;
    std::array<uint8_t, size> serialNumber;
    readFromRegister<uint8_t, size>(SERIAL_NUMBER_REGISTER_INFO, serialNumber);

    // Construct serial number by concatenating each of the 6 bytes as a string
    std::string serialNumberString;
    for (auto byte : serialNumber) {
        serialNumberString += std::to_string(byte);
    }
    return String(serialNumberString.c_str());
}

int NiclaSenseEnv::productID() {
    return readFromRegister<uint8_t>(PRODUCT_ID_REGISTER_INFO);
}

int NiclaSenseEnv::softwareRevision() {
    return readFromRegister<uint8_t>(SW_REVISION_REGISTER_INFO);
}

void NiclaSenseEnv::reset() {
    uint8_t statusRegisterData = readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    writeToRegister(STATUS_REGISTER_INFO, statusRegisterData | (1 << 7));
}

void NiclaSenseEnv::deepSleep() {
    uint8_t statusRegisterData = readFromRegister<uint8_t>(STATUS_REGISTER_INFO);
    writeToRegister(STATUS_REGISTER_INFO, statusRegisterData | (1 << 6));
}

bool NiclaSenseEnv::restoreFactorySettings() {
    uint8_t boardControlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);
    writeToRegister(CONTROL_REGISTER_INFO, boardControlRegisterData | (1 << 5));
    delayMicroseconds(100); // Wait for the default I2C address recovery to take effect (if changed)
    setDeviceAddress(DEFAULT_DEVICE_ADDRESS);

    // Try 10 times with increasing delay between each try
    for (int i = 0; i < 10; ++i) {
        // Read bit 5 to check if the reset is complete. When the reset is complete, bit 5 will be 0.
        boardControlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);
        
        if ((boardControlRegisterData & (1 << 5)) == 0) {
            return persistSettings();
        }
        Serial.println("⌛️ Waiting for factory reset to complete...");
        // Exponential sleep duration
        delayMicroseconds(100 * (2 << i));
    }
    
    return false;
}

int NiclaSenseEnv::UARTBaudRate() {
    uint8_t uartControlRegisterData = readFromRegister<uint8_t>(UART_CONTROL_REGISTER_INFO) & 7;
    return baudRateMap[uartControlRegisterData];
}

void NiclaSenseEnv::setUARTBaudRate(int baudRate) {
    int baudRateIndex = baudRateNativeValue(baudRate);
    if (baudRateIndex == -1) {
        return; // Baud rate not found
    }

    uint8_t uartControlRegisterData = readFromRegister<uint8_t>(UART_CONTROL_REGISTER_INFO);
    if ((uartControlRegisterData & 7) == baudRateIndex) {
        return; // Value is already the same
    }
    writeToRegister(UART_CONTROL_REGISTER_INFO, (uartControlRegisterData & ~7) | baudRateIndex);
}

bool NiclaSenseEnv::isUARTCSVOutputEnabled() {
    uint8_t boardControlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);
    return (boardControlRegisterData & (1 << 1)) != 0;
}

void NiclaSenseEnv::setUARTCSVOutputEnabled(bool enabled) {
    uint8_t boardControlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);
    if ((boardControlRegisterData & 2) == static_cast<int>(enabled)) {
        return; // Value is already the same
    }
    writeToRegister(CONTROL_REGISTER_INFO, (boardControlRegisterData & ~2) | (enabled << 1));
}

char NiclaSenseEnv::CSVDelimiter() {
    uint8_t csvDelimiterRegisterData = readFromRegister<uint8_t>(CSV_DELIMITER_REGISTER_INFO);
    return static_cast<char>(csvDelimiterRegisterData);
}

void NiclaSenseEnv::setCSVDelimiter(char delimiter) {
    char currentDelimiter = CSVDelimiter();
    if (currentDelimiter == delimiter) {
        return; // Value is already the same
    }

    // Define prohibited delimiters
    const char prohibitedDelimiters[] = {'\r', '\n', '\\', '"', '\''};

    for (auto prohibitedDelimiter : prohibitedDelimiters) {
        if (delimiter == prohibitedDelimiter) {
            return; // Delimiter is prohibited
        }
    }

    // Use ASCII code of the delimiter character
    writeToRegister(CSV_DELIMITER_REGISTER_INFO, static_cast<uint8_t>(delimiter));
}

bool NiclaSenseEnv::isDebuggingEnabled() {
    uint8_t boardControlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);
    return (boardControlRegisterData & 1) != 0;
}

void NiclaSenseEnv::setDebuggingEnabled(bool enabled) {
    uint8_t boardControlRegisterData = readFromRegister<uint8_t>(CONTROL_REGISTER_INFO);
    if ((boardControlRegisterData & 1) == static_cast<int>(enabled)) {
        return; // Value is already the same
    }
    writeToRegister(CONTROL_REGISTER_INFO, (boardControlRegisterData & ~1) | enabled);
}

void NiclaSenseEnv::setDeviceAddress(int address) {
    if (address < 0 || address > 127) {
        return; // Invalid address
    }
    uint8_t addressRegisterData = readFromRegister<uint8_t>(SLAVE_ADDRESS_REGISTER_INFO);
    // Check bits 0 - 6
    if ((addressRegisterData & 127) == address) {
        return; // Value is already the same
    }
    writeToRegister(SLAVE_ADDRESS_REGISTER_INFO, (addressRegisterData & ~127) | address);
    delayMicroseconds(100); // Wait for the new address to take effect
    this->i2cDeviceAddress = address;
}

// Function to get the index for a given baud rate
int NiclaSenseEnv::baudRateNativeValue(int baudRate) {
    for (int i = 0; i < 8; ++i) {
        if (baudRateMap[i] == baudRate) {
            return i;
        }
    }
    return -1; // Baud rate not found
}
