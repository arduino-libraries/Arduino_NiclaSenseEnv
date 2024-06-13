#include "I2CDevice.h"

/**
 * @brief Represents the orange on-board LED controlled via I2C.
 * 
 * The OrangeLED class provides methods to control the brightness and error status of the orange LED.
 * It inherits from the I2CDevice class.
 */
class OrangeLED : public I2CDevice {
public:

    /**
     * @brief Constructs a OrangeLED object.
     * 
     * @param bus The I2C bus to use (default is Wire).
     * @param deviceAddress The I2C device address (default is 0x21).
     */
    OrangeLED(TwoWire& bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);

    /**
     * @brief Constructs a OrangeLED object with the specified device address.
     * 
     * @param deviceAddress The I2C address of the OrangeLED device.
     */
    OrangeLED(uint8_t deviceAddress);

    /**
     * Gets the brightness of the orange LED.
     * @return The brightness of the orange LED. Range is 0 to 255.
     */
    uint8_t brightness();

    /**
     * Sets the brightness of the orange LED.
     * Call persistSettings() on NiclaSenseEnv instance after changing the orange LED brightness to make the change persistent.
     * @param brightness : The brightness of the orange LED. Range is 0 to 63.
     */
    void setBrightness(uint8_t brightness = 63);

    /**
     * Determines whether the orange LED is used to indicate an error status of one of the sensors.
     * When a board error condition occurs the LED blinks, independently of the brightness setting.
     * @return True if the orange LED is used for error status, false otherwise.
     */
    bool errorStatusEnabled();

    /**
     * Enables or disables the orange LED to indicate an error status of one of the sensors.
     * Call persistSettings() on NiclaSenseEnv instance after enabling/disabling the orange LED error status to make the change persistent.
     * @param enabled : Whether to enable or disable the orange LED error status.
     */
    void setErrorStatusEnabled(bool enabled);
};
