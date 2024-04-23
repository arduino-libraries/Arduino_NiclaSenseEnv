#include "I2CDevice.h"

/**
 * @brief Represents a color with red, green, and blue components.
 */
struct Color {
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
     * Enables the indoor air quality status feature on the RGB LED.
     * When enabled, the RGB LED will change color based on the air quality (red = bad, green = good)
     */
    void enableIndoorAirQualityStatus();

    /**
     * Enables the indoor air quality status indicator on the RGB LED.
     * When enabled, the RGB LED will change color based on the air quality (red = bad, green = good)
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after enabling the indoor air quality status to make the change persistent.
     * @param brightness The brightness level of the indicator (0-255).
     */
    void enableIndoorAirQualityStatus(uint8_t brightness);

    /**
     * @brief Sets the RGB values of the LED.
     *
     * This function sets the red, green, and blue values of the LED using individual values.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the color to make the change persistent.
     * @param r The red value (0-255).
     * @param g The green value (0-255).
     * @param b The blue value (0-255).
     */
    void setColor(uint8_t r, uint8_t g, uint8_t b);

    /**
     * Sets the RGB values of the LED along with the specified brightness.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the color to make the change persistent.
     * @param r The red value (0-255).
     * @param g The green value (0-255).
     * @param b The blue value (0-255).
     * @param brightness The brightness value (0-255).
     */
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness) ;

    /**
     * @brief Sets the RGB color of the LED using a Color object.
     * The Color object contains the red, green, and blue values that can be changed individually.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the color to make the change persistent.
     * @param color The RGB color to set.
     */
    void setColor(Color color);

    /**
     * @brief Sets the RGB color and brightness of the LED using a Color object.
     * Call Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the color / brightness to make the change persistent.
     * @param color The desired RGB color.
     * @param brightness The desired brightness level (0-255).
     */
    void setColor(Color color, uint8_t brightness);

    /**
     * @brief Gets the current RGB color of the LED.
     * 
     * @return The current RGB color as a Color object.
     */
    Color color();

    /**
     * @brief Get the brightness of the RGB LED (0-255)
     * 
     * @return The brightness value as a uint8_t.
     */
    uint8_t brightness();

    /**
     * @brief Sets the brightness of the RGB LED.
     * This function allows you to adjust the brightness of the RGB LED.
     * Call storeSettingsInFlash() on NiclaSenseEnv instance after changing the brightness to make the change persistent.
     * @param brightness The brightness level to set (0-255).
     */
    void setBrightness(uint8_t brightness);
};
