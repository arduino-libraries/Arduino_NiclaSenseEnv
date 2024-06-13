#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include <Arduino.h>
#include <Wire.h>
#include "registers.h"
#include <array>

constexpr uint32_t I2C_TIMEOUT_MS = 1000;

/**
 * @brief Class for interacting with I2C devices.
 * 
 * This class provides methods for reading and writing to registers of an I2C device.
 * It also includes a method for checking if the device is connected.
 */
class I2CDevice {
public:
    /**
     * @brief Constructs an instance of the I2CDevice class.
     * 
     * @param bus The I2C bus to use (default is Wire).
     * @param deviceAddress The address of the I2C device (default is DEFAULT_DEVICE_ADDRESS).
     */
    I2CDevice(TwoWire &bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);
    
    /**
     * @brief Constructs an I2CDevice object with the specified device address.
     * 
     * @param deviceAddress The address of the I2C device.
     */
    I2CDevice(uint8_t deviceAddress);

    /**
     * @brief Checks if the device is connected to the I2C bus.
     * 
     * @return true if the device is connected, false otherwise.
     */
    bool connected();

    /**
     * @brief Initializes the I2C communication and checks if the device is connected.
     * 
     * @return true if the device is connected after initialization, false otherwise.
     */
    bool begin();

    /**
     * @brief Get the I2C device address.
     * 
     * @return uint8_t The I2C device address.
     */
    uint8_t deviceAddress() const;

    /**
     * @brief The default device address for the I2C device.
     */
    static constexpr uint8_t DEFAULT_DEVICE_ADDRESS = 0x21;

protected:
    /**
     * Reads the value from the specified register of the I2C device.
     *
     * @param registerInfo The information about the register to read from.
     * @return The value read from the register. The return type is defined via the template parameter.
     */
    template <typename T>
    T  readFromRegister(RegisterInfo registerInfo) {
        T data;
        bus.beginTransmission(i2cDeviceAddress);
        bus.write(registerInfo.address);
        bool success = bus.endTransmission(false) == 0;

        if(!success){
            return data; // Failed to read from register
        }

        bus.requestFrom(i2cDeviceAddress, registerInfo.bytes);
        
        // Wait for data to become available
        auto transmissionStart = millis();
        while (!bus.available() && millis() - transmissionStart < I2C_TIMEOUT_MS) {}

        if (bus.available()) {
            bus.readBytes(reinterpret_cast<char*>(&data), registerInfo.bytes);
        }
        return data;
    }

    /**
     * @brief Reads data from a specific register of the I2C device.
     * 
     * @tparam T The type of data to be read.
     * @tparam N The number of elements to be read.
     * @param aRegister The register to read from.
     * @param data The array where the read data will be stored.
     */
    template <typename T, size_t N>
    void readFromRegister(RegisterInfo aRegister, std::array<T, N>& data) {

        if(N != aRegister.bytes){
            return; // Array size and register size must match
        }

        // Begin the I2C communication
        bus.beginTransmission(i2cDeviceAddress);
        // Set the register address to read from
        bus.write(aRegister.address);
        // End transmission and request data
        bool success = bus.endTransmission(false) == 0;

        if(!success){
            return; // Failed to read from register
        }

        bus.requestFrom(i2cDeviceAddress, aRegister.bytes);

        // Wait for data to become available
        auto transmissionStart = millis();
        while (!bus.available() && millis() - transmissionStart < I2C_TIMEOUT_MS) {}

        // Read data into the array
        for (size_t i = 0; i < aRegister.bytes && bus.available(); ++i) {
            data[i] = bus.read();
        }
    }

    /**
     * @brief Writes a value to a register of the I2C device.
     * 
     * @tparam T The type of the value to write.
     * @param registerInfo The information of the register to write to.
     * @param value The value to write to the register.
     * @return true if the write operation was successful, false otherwise.
     */
    template <typename T>
    bool writeToRegister(RegisterInfo registerInfo, T value) {
        bus.beginTransmission(this->i2cDeviceAddress);
        bus.write(registerInfo.address);
        bus.write(reinterpret_cast<const uint8_t*>(&value), registerInfo.bytes);
        return bus.endTransmission() == 0;
    }

    /**
     * @brief Makes the value of a given register persistent.
     * @param registerInfo The register to make persistent.
     */
    bool persistRegister(RegisterInfo registerInfo);

    /**
     * @brief Reference to the I2C bus used by the device.
     */
    TwoWire& bus;

    /**
     * @brief The address of the I2C device as specified in the constructor.
     */
    uint8_t i2cDeviceAddress;
};

#endif