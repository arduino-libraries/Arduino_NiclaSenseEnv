#include "I2CDevice.h"

/**
 * @brief Represents a color with red, green, and blue components.
 */
struct LEDColor {
    uint8_t red;    /**< The red component of the color. */
    uint8_t green;  /**< The green component of the color. */
    uint8_t blue;   /**< The blue component of the color. */
};

/**
 * @brief Represents the on-board RGB LED that can be controlled using I2C communication.
 * 
 * The RGBLED class provides methods to control the color and brightness of the LED, as well as enable features like indoor air quality status indicator.
 * It inherits from the I2CDevice class and can be used with an I2C bus to communicate with the RGB LED device.
 */
class RGBLED : public I2CDevice {
public:

    /**
     * @brief Constructs an instance of the RGBLED class.
     *
     * @param bus The I2C bus to communicate with the RGBLED device. Default is Wire.
     * @param deviceAddress The I2C address of the RGBLED device. Default is DEFAULT_DEVICE_ADDRESS.
     */
    RGBLED(TwoWire& bus = Wire, uint8_t deviceAddress = DEFAULT_DEVICE_ADDRESS);

    /**
     * @brief Initializes an instance of the RGBLED class with the specified device address.
     * 
     * @param deviceAddress The address of the RGB LED device.
     */
    RGBLED(uint8_t deviceAddress);

    /**
     * Enables the indoor air quality status indicator on the RGB LED.
     * When enabled, the RGB LED will change color based on the air quality (red = bad, green = good)
     * @param brightness The brightness level of the indicator (0-255).
     * @param persist If true, the change will be saved to flash memory.
     *                When persist is True, the brightness will also be persisted.
     * @return True if the mode was set successfully, false otherwise.
     */
    bool enableIndoorAirQualityStatus(uint8_t brightness = 255, bool persist = false);

    /**
     * @brief Sets the RGB values of the LED.
     *
     * This function sets the red, green, and blue values of the LED using individual values.
     * Note: A value of 0, 0, 0 will set the color based on the IAQ value from the Indoor Air Quality sensor.
     * @param r The red value (0-255).
     * @param g The green value (0-255).
     * @param b The blue value (0-255).
     * @param persist If true, the change will be saved to flash memory.
     * @return True if the color was set successfully, false otherwise.
     */
    bool setColor(uint8_t r, uint8_t g, uint8_t b, bool persist = false);

    /**
     * @brief Sets the RGB color of the LED using a LEDColor object.
     * The LEDColor object contains the red, green, and blue values that can be changed individually.
     * Note: A value of 0, 0, 0 will set the color based on the IAQ value from the Indoor Air Quality sensor.
     * @param color The RGB color to set.
     * @param persist If true, the change will be saved to flash memory.
     * @return True if the color was set successfully, false otherwise.
     */
    bool setColor(LEDColor color, bool persist = false);

    /**
     * @brief Gets the current RGB color of the LED.
     * 
     * @return The current RGB color as a LEDColor object.
     */
    LEDColor color();

    /**
     * @brief Get the brightness of the RGB LED (0-255)
     * 
     * @return The brightness value as a uint8_t.
     */
    uint8_t brightness();

    /**
     * @brief Sets the brightness of the RGB LED.
     * This function allows you to adjust the brightness of the RGB LED.
     * @param brightness The brightness level to set (0-255).
     * @param persist If true, the change will be saved to flash memory.
     * @return True if the brightness was set successfully, false otherwise.
     */
    bool setBrightness(uint8_t brightness, bool persist = false);
};
