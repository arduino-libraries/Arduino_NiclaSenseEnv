#ifndef INDOOR_AIR_QUALITY_SENSOR_H
#define INDOOR_AIR_QUALITY_SENSOR_H

#include "I2CDevice.h"

/**
 * @brief Enum class for the different modes of the IndoorAirQualitySensor.
 */
enum class IndoorAirQualitySensorMode {
    powerDown = 0, ///< Mode to turn off the sensor and reduce power consumption
    cleaning = 1, ///< Cleaning mode to perform a thermal cleaning cycle of the MOx element
    indoorAirQuality = 2, ///< Mode to measure indoor air quality
    indoorAirQualityLowPower = 3, ///< Low power indoor air quality mode with lower accuracy
    pbaq = 4, ///< Public Building Air Quality mode
    sulfur = 5, ///< Mode to detect sulfur odor
    defaultMode = indoorAirQuality // Can't use default as it's a reserved keyword
};


/**
 * @class IndoorAirQualitySensor
 * @brief Represents an indoor air quality sensor.
 * 
 * The IndoorAirQualitySensor class provides methods to retrieve various air quality parameters such as sulfur odor, odor intensity, ethanol level, CO2 level, TVOC level, air quality index, and more.
 * It also allows setting the mode of the sensor and enabling/disabling it.
 */
class IndoorAirQualitySensor : public I2CDevice {
public:

    /**
     * @brief Constructor for the IndoorAirQualitySensor class.
     * @param bus The I2C bus to use.
     * @param deviceAddress The I2C address of the device.
     */
    IndoorAirQualitySensor(TwoWire& bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);        

    /**
     * @brief Constructor for the IndoorAirQualitySensor class.
     * @param deviceAddress The I2C address of the device.
     */
    IndoorAirQualitySensor(uint8_t deviceAddress);

    /**
     * @brief Get the sulfur odor-detected value (true or false)
     * @return The sulfur odor value.
     */
    bool sulfurOdor();

    /**
     * @brief Get the odor intensity value.
     * @return The odor intensity value.
     */
    float odorIntensity();

    /**
     * @brief Get the ethanol value.
     * @return The ethanol value.
     */
    float ethanol();

    /**
     * @brief Get the CO2 value in ppm.
     * @return The CO2 value.
     */
    float CO2();

    /**
     * @brief Get the TVOC value in (mg/m3)
     * @return The TVOC value.
     */
    float TVOC();

    /**
     * @brief Get the air quality value. The common range is 0 to ~5
     * @return The air quality value.
     */
    float airQuality();

    /**
     * @brief Get the interpreted air quality value.
     * The possible values are "Very Good", "Good", "Medium", "Poor" and "Bad".
     * @return The interpreted air quality value.
     */
    String airQualityInterpreted();

    /**
     * @brief Get the relative air quality value in percent (0 - 100%).
     * @return The relative air quality value.
     */
    float relativeAirQuality();

    /**
     * @brief Get the mode of the IndoorAirQualitySensor.
     * @return The mode of the IndoorAirQualitySensor as an enum value.
     */
    IndoorAirQualitySensorMode mode();

    /**
     * @brief Set the mode of the IndoorAirQualitySensor.
     * 
     * Note on cleaning mode:
     * The cleaning mode performs a thermal cleaning cycle of the MOx element. It can eliminate some light pollution 
     * residues from production and packaging and improves the stabilization processes in the sensor. 
     * The function heats up the sensor to allow thermal desorption and catalytic combustion of the residues. 
     * The cleaning cycle can be executed only once in the sensor lifetime and shall be started after product assembly. 
     * Please ensure cleaning was completed before power-off/reset and do not interrupt while cleaning.
     * The cleaning procedure takes 1 minute (blocking).
     * 
     * Note on PBAQ mode:
     * The PBAQ mode is a special mode to perform highly accurate and consistent air quality readings.
     * It measures the total volatile organic compounds (TVOC) and equivalent ethanol (EtOH) concentration 
     * to meet Public Building Air Quality (PBAQ) standards.
     * 
     * Note on low power IAQ mode:
     * This mode offers a much lower power consumption while keeping accurate and consistent sensor readings.
     * For more accurate readings, use the default indoor air quality mode.
     * 
     * @param sensorMode The mode to set. See the IndoorAirQualitySensorMode enum class for possible values.
     * @param persist If true, the change will be saved to flash memory.
     *                When persist is true, the mode setting of OutdoorAirQualitySensor and TemperatureHumiditySensor will also be persisted.
     * @return True if the mode was set successfully, false otherwise.
     */
    bool setMode(IndoorAirQualitySensorMode sensorMode, bool persist = false);

    /**
     * @brief Get the mode as a string. 
     * The possible values are "powerDown", "cleaning", "indoorAirQuality", 
     * "indoorAirQualityLowPower", "sulfur" and "unknown".
     * @return The mode as a string.
     */
    String modeString();

    /**
     * @brief Check if the sensor is enabled.
     * @return True if the sensor is enabled, false otherwise.
     */
    bool enabled();

    /**
     * @brief Set the sensor enabled or disabled.
     * When the sensor is enabled after being disabled, the sensor will go back to the indoorAirQuality mode.
     * @param isEnabled True to enable the sensor, false to disable it.
     * @param persist If true, the change will be saved to flash memory.
     *                When persist is true, the mode setting of IndoorAirQualitySensor and TemperatureHumiditySensor will also be persisted.
     * @return True if the the sensor was enabled successfully.
     */
    bool setEnabled(bool isEnabled, bool persist = false);
};

#endif