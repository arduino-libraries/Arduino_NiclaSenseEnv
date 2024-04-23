#include "I2CDevice.h"

/**
 * @brief Represents the white on-board LED controlled via I2C.
 * 
 * The WhiteLED class provides methods to control the brightness and error status of the white LED.
 * It inherits from the I2CDevice class.
 */
class WhiteLED : public I2CDevice {
public:

    /**
     * @brief Constructs a WhiteLED object.
     * 
     * @param bus The I2C bus to use (default is Wire).
     * @param deviceAddress The I2C device address (default is 0x21).
     */
    WhiteLED(TwoWire& bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);

    /**
     * @brief Constructs a WhiteLED object with the specified device address.
     * 
     * @param deviceAddress The I2C address of the WhiteLED device.
     */
    WhiteLED(uint8_t deviceAddress);

    /**
     * Gets the brightness of the white LED.
     * @return The brightness of the white LED. Range is 0 to 63.
     */
    uint8_t brightness();

    /**
     * Sets the brightness of the white LED.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the white LED brightness to make the change persistent.
     * @param brightness : The brightness of the white LED. Range is 0 to 63.
     */
    void setBrightness(uint8_t brightness = 63);

    /**
     * Determines whether the white LED is used to indicate an error status of one of the sensors.
     * @return True if the white LED is used for error status, false otherwise.
     */
    bool errorStatusEnabled();

    /**
     * Enables or disables the white LED to indicate an error status of one of the sensors.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after enabling/disabling the white LED error status to make the change persistent.
     * @param enabled : Whether to enable or disable the white LED error status.
     */
    void setErrorStatusEnabled(bool enabled);
};
