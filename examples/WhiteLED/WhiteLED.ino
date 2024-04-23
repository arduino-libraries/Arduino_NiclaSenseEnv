/**
 * This example shows how to control the white LED on the Nicla Sense Env board.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "NiclaSenseEnv.h"

void pulseLED(WhiteLED& led) {
    // Fade in
    for (uint8_t i = 0; i < 64; ++i) {
        led.setBrightness(i);
        delay(10);
    }

    // Fade out
    for (int8_t i = 63; i >= 0; --i) {
        led.setBrightness(i);
        delay(10);
    }
}

void setup() {
    Serial.begin(115200);
    
    // Wait for Serial to be ready with a timeout of 5 seconds
    for(auto start = millis(); !Serial && millis() - start < 5000;);

    NiclaSenseEnv device;

    if (device.begin()) {
        auto whiteLED = device.whiteLED();
        
        Serial.print("🔢 White LED error status enabled: ");
        Serial.println(whiteLED.errorStatusEnabled());
        Serial.print("💡 White LED brightness: ");
        Serial.println(whiteLED.brightness());

        pulseLED(whiteLED);

        // Enable sensor error indication on white LED (LED should turn off if sensors are okay)
        whiteLED.setErrorStatusEnabled(true);
    } else {
        Serial.println("🤷 Device could not be found. Please double-check the wiring.");
    }
}

void loop() {
    // Your main code here
}
