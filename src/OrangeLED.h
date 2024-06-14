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
     * When persist is true, the `errorStatusEnabled` setting will also be persisted.
     * @param brightness : The brightness of the orange LED. Range is 0 to 255.
     * @param persist : If true, the brightness setting will be saved to flash memory.
     * @return True if the brightness was set successfully, false otherwise.
     */
    bool setBrightness(uint8_t brightness, bool persist = false);

    /**
     * Determines whether the orange LED is used to indicate an error status of one of the sensors.
     * When a board error condition occurs the LED blinks, independently of the brightness setting.
     * @return True if the orange LED is used for error status, false otherwise.
     */
    bool errorStatusEnabled();

    /**
     * Enables or disables the orange LED to indicate an error status of one of the sensors.
     * When persist is true, the brightness setting will also be saved to flash memory.
     * @param enabled : Whether to enable or disable the orange LED error status.
     * @param persist : If true, the change will be saved to flash memory.
     * @return True if the mode was set successfully, false otherwise.
     */
    bool setErrorStatusEnabled(bool enabled, bool persist = false);
};
