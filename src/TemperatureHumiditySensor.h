#ifndef TEMPERATURE_HUMIDITY_SENSOR_H
#define TEMPERATURE_HUMIDITY_SENSOR_H

#include "I2CDevice.h"

#if __has_include(<cmath>)
    // If possible use the C++ cmath library as it uses mostly scoped values
    // and doesn't pollute the global namespace
    #include <cmath>
#else
    // If we want to support AVR boards, we need to use this instead of cmath
    #include <math.h>
#endif

/**
 * @brief Represents a temperature and humidity sensor.
 * 
 * This class provides methods to interact with a temperature and humidity sensor
 * connected via I2C communication. It inherits from the I2CDevice class.
 */
class TemperatureHumiditySensor : public I2CDevice {
public:

    /**
     * @brief Constructs a TemperatureHumiditySensor object.
     *
     * @param bus The I2C bus to communicate with the sensor. Default is Wire.
     * @param deviceAddress The I2C address of the sensor. Default is 0x21.
     */
    TemperatureHumiditySensor(TwoWire& bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);

    /**
     * @brief Constructs a TemperatureHumiditySensor object with the specified device address.
     *
     * @param deviceAddress The I2C address of the temperature and humidity sensor.
     */
    TemperatureHumiditySensor(uint8_t deviceAddress);

    /**
     * @brief Get the temperature value from the sensor in degrees Celsius.
     * 
     * @return float The temperature value.
     */
    float temperature();

    /**
     * @brief Get the relative humidity value (Range 0-100%).
     * 
     * @return The humidity value as a float.
     */
    float humidity();

    /**
     * @brief Checks if the temperature and humidity sensor is enabled.
     * 
     * @return true if the sensor is enabled, false otherwise.
     */
    bool enabled();

    /**
     * @brief Sets the enabled state of the temperature and humidity sensor.
     * When disabled the sensor goes in power down mode.
     * Call persistSettings() on NiclaSenseEnv instance after changing the enabled state to make the change persistent.
     * @param enabled The desired enabled state. True to enable the sensor, false to disable it.
     */
    void setEnabled(bool enabled);
};

#endif