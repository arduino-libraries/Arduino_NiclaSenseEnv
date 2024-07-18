/**
 * This example shows how to control the RGB LED on the Nicla Sense Env board.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "Arduino_NiclaSenseEnv.h"

void pulseLED(RGBLED &led) {
    Serial.println("🌈 RGB values: " + String(led.color().red) + ", " + String(led.color().green) + ", " + String(led.color().blue));

    for (int i = 0; i <= 255; i++) {
        led.setBrightness(i);
        delay(2);
    }

    for (int i = 255; i >= 0; i--) {
        led.setBrightness(i);
        delay(2);
    }
}

void pulseColors(RGBLED &led) {
    led.setColor({255, 0, 0});  // Red
    pulseLED(led);

    // Color can be set via Color struct or 3 separate uint8_t values
    led.setColor(0, 255, 0);  // Green
    pulseLED(led);

    Color blueColor = {0, 0, 255};
    led.setColor(blueColor);  // Blue
    pulseLED(led);
    
    led.setColor({255, 255, 255});  // White
    pulseLED(led);
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        // Wait for serial port to connect.
    }

    NiclaSenseEnv device;

    if (device.begin()) {
        auto rgbLED = device.rgbLED();

        Serial.println("💡 RGB LED brightness: " + String(rgbLED.brightness()));
        pulseColors(rgbLED);

        // Re-enable indoor air quality indication on RGB LED
        IndoorAirQualitySensorMode iaqMode = device.indoorAirQualitySensor().mode();

        if (iaqMode == IndoorAirQualitySensorMode::indoorAirQuality || iaqMode == IndoorAirQualitySensorMode::indoorAirQualityLowPower) {
            Serial.println("🏠 Enabling indoor air quality indication on RGB LED");
            // Set indoor air quality LED to full brightness
            rgbLED.enableIndoorAirQualityStatus(255);
        }
    } else {
        Serial.println("🤷 Device could not be found. Please double check the wiring.");
    }
}

void loop() {
    // Do nothing in the loop
}
