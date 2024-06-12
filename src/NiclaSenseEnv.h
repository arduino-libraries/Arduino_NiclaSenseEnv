#ifndef NICLA_LAMON_H
#define NICLA_LAMON_H

#include "I2CDevice.h"
#include "TemperatureHumiditySensor.h"
#include "IndoorAirQualitySensor.h"
#include "OutdoorAirQualitySensor.h"
#include "RGBLED.h"
#include "OrangeLED.h"

/**
 * @brief The NiclaSenseEnv class represents a NiclaSenseEnv device.
 * 
 * This class provides methods to interact with the device to enable and disable features,
 * query device information and retrieve sensor objects.
 * It inherits from the I2CDevice class.
 */
class NiclaSenseEnv : public I2CDevice {
public:

    /**
     * @brief Constructs a new NiclaSenseEnv object.
     *
     * @param bus The I2C bus to use (default is Wire).
     * @param deviceAddress The I2C device address (default is 0x21).
     */
    NiclaSenseEnv(TwoWire& bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);

    /**
     * @brief Constructs a new NiclaSenseEnv object.
     *
     * @param deviceAddress The I2C address of the NiclaSenseEnv device.
     */
    NiclaSenseEnv(uint8_t deviceAddress);


    /**
     * @brief Destroy the Nicla Sense Env object. This will call the end() method
     * while frees up allocated resources.
     */
    ~NiclaSenseEnv();

    /**
     * Returns the TemperatureHumiditySensor object to interact with the temperature and humidity sensor.
     *
     * @return The TemperatureHumiditySensor object.
     */
    TemperatureHumiditySensor& temperatureHumiditySensor();

    /**
     * @brief Returns the IndoorAirQualitySensor object to interact with the indoor air quality sensor.
     *
     * @return A reference to the IndoorAirQualitySensor object.
     */
    IndoorAirQualitySensor& indoorAirQualitySensor();

    /**
     * @brief Returns the OutdoorAirQualitySensor object to interact with the outdoor air quality sensor.
     *
     * @return The OutdoorAirQualitySensor object.
     */
    OutdoorAirQualitySensor& outdoorAirQualitySensor();

    /**
     * @brief Returns the RGBLED object to interact with the RGB LED.
     * 
     * @return RGBLED& The reference to the RGBLED object.
     */
    RGBLED& rgbLED();

    /**
     * @brief Returns a reference to the OrangeLED object to interact with the orange LED.
     * 
     * @return OrangeLED& Reference to the OrangeLED object.
     */
    OrangeLED& orangeLED();

    /**
     * @brief Ends the operation of the NiclaSenseEnv class.
     * 
     * This function is used to gracefully end the operation of the NiclaSenseEnv class.
     * It performs any necessary cleanup to free up resources. 
     * It gets called automatically when the object is destroyed.
     */
    void end();

    /**
     * @brief Writes the current configuration to the flash memory.
     *  Stores board register 0x00 … 0x0B in flash to be default after reset
     * 
     *  This affects the following properties:
     *  - UART baud rate
     *  - UART CSV output enabled
     *  - CSV delimiter
     *  - UART Debugging enabled
     *  - I2C Device address
     *  - Indoor air quality sensor mode
     *  - Outdoor air quality sensor mode
     *  - Temperature sensor enabled
     *  - Orange LED brightness
     *  - Orange LED error status enabled
     *  - RGB LED brightness
     *  - RGB LED color
     * 
     *  Make sure all these properties are in the desired state before calling this method.
     * 
     * @return true if the settings were successfully stored, false otherwise.
     */
    bool storeSettingsInFlash();

    /**
     * @brief Retrieves the serial number of the device.
     * 
     * @return The serial number as a String.
     */
    String serialNumber();

    /**
     * @brief Gets the numeric product ID.
     * 
     * @return The product ID.
     */
    int productID();

    /**
     * @brief Get the software revision number.
     * 
     * @return The software revision number.
     */
    int softwareRevision();

    /**
     * @brief Performs a soft reset of the device. 
     * Changes to the configuration that were not stored in flash will be lost.
     */
    void reset();

    /**
     * @brief Puts the device into deep sleep mode.
     * 
     * This function puts the device into deep sleep mode, conserving power
     * by disabling most of its functionalities. It is commonly used to
     * prolong the battery life of battery-powered devices.
     * The board can only be woken up by a hardware reset.
     */
    void deepSleep();

    /**
     * @brief Restores the factory settings.
     * This will reset among other properties the device address to the default value.
     * See storeSettingsInFlash() for a complete list of properties that are affected by this method.
     * 
     * @return true if the factory settings were successfully restored, false otherwise.
     */
    bool restoreFactorySettings();

    /**
     * @brief Get the current baud rate of the UART communication.
     * The supported values are: 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200
     * @return int The UART Baud Rate.
     */
    int UARTBaudRate();

    /**
     * @brief Sets the baud rate for the UART communication.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the baud rate to make the change persistent.
     * @param baudRate The desired baud rate for the UART communication.
     The supported values are: 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200
     */
    void setUARTBaudRate(int baudRate);

    /**
     * @brief Checks if UART CSV output is enabled.
     * 
     * @return true if UART CSV output is enabled, false otherwise.
     */
    bool isUARTCSVOutputEnabled();

    /**
     * @brief Sets the UART CSV output enabled or disabled.
     *  Enables or disables CSV output over UART.
     *  Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the CSV output mode to make the change persistent.
     *
     *  The column names and their order are:
     *  HS4001 sample counter, HS4001 temperature (degC), HS4001 humidity (%RH), ZMOD4510 status, ZMOD4510 sample counter, 
     *  ZMOD4510 EPA AQI, ZMOD4510 Fast AQI, ZMOD4510 O3 (ppb), ZMOD4510 NO2 (ppb), ZMOD4510 Rmox[0], ZMOD4510 Rmox[1], ZMOD4510 Rmox[2], 
     *  ZMOD4510 Rmox[3], ZMOD4510 Rmox[4], ZMOD4510 Rmox[5], ZMOD4510 Rmox[6], ZMOD4510 Rmox[7], ZMOD4510 Rmox[8], ZMOD4510 Rmox[9], ZMOD4510 Rmox[10], 
     *  ZMOD4510 Rmox[11], ZMOD4510 Rmox[12], ZMOD4410 status, ZMD4410 sample counter, ZMOD4410 IAQ, ZMOD4410 TVOC (mg/m^3), ZMOD4410 eCO2 (ppm), 
     *  ZMOD4410 Rel IAQ, ZMOD4410 EtOH (ppm), ZMOD4410 Rmox[0], ZMOD4410 Rmox[1], ZMOD4410 Rmox[2], ZMOD4410 Rmox[3], ZMOD4410 Rmox[4], ZMOD4410 Rmox[5], 
     *  ZMOD4410 Rmox[6], ZMOD4410 Rmox[7], ZMOD4410 Rmox[8], ZMOD4410 Rmox[9], ZMOD4410 Rmox[10], ZMOD4410 Rmox[11], ZMOD4410 Rmox[12], ZMOD4410 Rcda[0], 
     *  ZMOD4410 Rcda[1], ZMOD4410 Rcda[2], ZMOD4410 Rhtr, ZMOD4410 Temp, ZMOD4410 intensity, ZMOD4410 odor
     *  The csv formatted line is sent when a sensor finishes a measurement. 
     *  Only the columns for this sensor will be filled, the other columns will be empty.
     * 
     * @param enabled True to enable UART CSV output, false to disable.
     */
    void setUARTCSVOutputEnabled(bool enabled);

    /**
     * @brief Gets the CSV delimiter character.
     * The default value is ','.
     * @return The CSV delimiter character.
     */
    char CSVDelimiter();

    /**
     * @brief Sets the CSV delimiter for parsing CSV data.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the CSV delimiter to make the change persistent.
     * @param delimiter The character to be used as the CSV delimiter.
     */
    void setCSVDelimiter(char delimiter);

    /**
     * @brief Checks if debugging is enabled.
     * When debugging mode is enabled, the board will send additional debug messages over UART.
     * @return true if debugging is enabled, false otherwise.
     */
    bool isDebuggingEnabled();

    /**
     * @brief Toggles the debugging mode.
     * When debugging mode is enabled, the board will send additional debug messages over UART.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the debugging mode to make the change persistent.
     * @param enabled A boolean value indicating whether debugging is enabled or not.
     */
    void setDebuggingEnabled(bool enabled);

    /**
     * @brief Sets the I2C address of the device.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the address to make the change persistent.
     * 
     * @param address The new I2C address. Valid values are 0 to 127.
     */
    void setDeviceAddress(int address);

private:
    /**
     * @brief Converts the given baud rate to its native value.
     *
     * This function takes a baud rate as input and returns its corresponding native value.
     *
     * @param baudRate The baud rate to convert. The possible values are 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200
     * @return The native value of the baud rate.
     */
    int baudRateNativeValue(int baudRate);
    
    // The following variables are used to cache the sensor objects.
    // They are initialized when the corresponding getter is called and destroyed when the end() method is called.
    TemperatureHumiditySensor* temperatureSensorInstance = nullptr;
    IndoorAirQualitySensor* indoorAirQualitySensorInstance = nullptr;
    OutdoorAirQualitySensor* outdoorAirQualitySensorInstance = nullptr;
    RGBLED* rgbLed = nullptr;
    OrangeLED* orangeLed = nullptr;
};

#endif
