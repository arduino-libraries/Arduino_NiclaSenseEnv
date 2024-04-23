#ifndef OUTDOOR_AIR_QUALITY_SENSOR_H
#define OUTDOOR_AIR_QUALITY_SENSOR_H

#include "I2CDevice.h"

/**
 * @brief Enum class for the different modes of the OutdoorAirQualitySensor.
 */
enum class OutdoorAirQualitySensorMode {
    powerDown = 0, ///< Mode to turn off the sensor and reduce power consumption
    cleaning = 1, ///< Cleaning mode to perform a thermal cleaning cycle of the MOx element
    outdoorAirQuality = 2, ///< Mode to measure outdoor air quality
    defaultMode = powerDown // Can't use default as it's a reserved keyword
};

/**
 * @class OutdoorAirQualitySensor
 * @brief Class representing an outdoor air quality sensor (ZMOD4510)
 *
 * This class provides functionality to interact with an outdoor air quality sensor.
 * It allows reading the air quality data from the sensor.
 */
class OutdoorAirQualitySensor : public I2CDevice {
public:

    /**
     * @brief Constructs an instance of the OutdoorAirQualitySensor class.
     *
     * @param bus The I2C bus to which the sensor is connected. Defaults to Wire.
     * @param deviceAddress The I2C device address of the sensor. Defaults to 0x21.
     */
    OutdoorAirQualitySensor(TwoWire& bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);

    /**
     * @brief Constructs an instance of the OutdoorAirQualitySensor class.
     *
     * @param deviceAddress The address of the sensor device.
     */
    OutdoorAirQualitySensor(uint8_t deviceAddress);

    /**
     * @brief Retrieves the EPA air quality index. Range is 0 to 500.
     * The" EPA AQI" is strictly following the EPA standard and is based on 
     * the 1-hour or 8-hour average of the O3 concentrations (concentration dependent).
     *
     * @return The air quality index as an integer.
     */
    int airQualityIndex();

    /**
     * @brief Gets the outdoor air quality index from the ZMOD4510 sensor and interprets it in terms of air quality.
     * 
     * @return The interpreted air quality index as a string.
     * Possible values are: Good, Moderate, Unhealthy for Sensitive Groups, Unhealthy, Very Unhealthy, Hazardous.
     */
    String airQualityIndexInterpreted();

    /**
     * @brief Get the fast air quality index. Range is 0 to 500.
     * As the standard averaging leads to a very slow response, especially during testing and evaluation, 
     * "Fast AQI" provides quicker results with a 1-minute averaging.
     * 
     * @return int The fast air quality index.
     */
    int fastAirQualityIndex();

    /**
     * @brief Get the NO2 value from the outdoor air quality sensor.
     * 
     * @return The NO2 concentration in ppb.
     */
    float NO2();

    /**
     * @brief Get the O3 value from the outdoor air quality sensor.
     * 
     * @return The O3 concentration in ppb.
     */
    float O3();

    /**
     * @brief Get the mode of the outdoor air quality sensor.
     * Possible values are: powerDown, cleaning, outdoorAirQuality.
     * The default mode is powerDown. This is because the sensor needs several hours to start 
     * outputting valuable data due to the sensor's internal algorithm and chemical compound.
     * This property represents the numeric value of the mode. See OutdoorAirQualitySensorMode for more information.
     * 
     * @return OutdoorAirQualitySensorMode The mode of the sensor.
     */
    OutdoorAirQualitySensorMode mode();

    /**
     * @brief Sets the mode of the outdoor air quality sensor.
     * 
     * This function allows you to set the mode of the outdoor air quality sensor.
     * Possible values are: powerDown, cleaning, outdoorAirQuality.
     * See OutdoorAirQualitySensorMode for more information.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the mode to make the change persistent.
     * 
     * Note on cleaning mode:
     * The cleaning mode performs a thermal cleaning cycle of the MOx element. It can eliminate some light pollution 
     * residues from production and packaging and improves the stabilization processes in the sensor. 
     * The function heats up the sensor to allow thermal desorption and catalytic combustion of the residues. 
     * The cleaning cycle can be executed only once in the sensor lifetime and shall be started after product assembly. 
     * Please ensure cleaning was completed before power-off/reset and do not interrupt while cleaning.
     * The cleaning procedure takes 1 minute (blocking).
     * 
     * @param sensorMode The mode to set for the sensor.
     */
    void setMode(OutdoorAirQualitySensorMode sensorMode);

    /**
     * @brief Gets the outdoor air quality sensor mode as a string.
     * 
     * @return The mode as string. Possible values are: powerDown, cleaning, outdoorAirQuality.
     */
    String modeString();

    /**
     * @brief Checks if the outdoor air quality sensor is enabled.
     * 
     * @return true if the sensor is enabled, false otherwise.
     */
    bool enabled();

    /**
     * @brief Sets the enabled state of the outdoor air quality sensor.
     * When disabled the sensor goes in power down mode.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the enabled state to make the change persistent.
     * @param isEnabled True to enable the sensor, false to disable it.
     */
    void setEnabled(bool isEnabled);
};

#endif