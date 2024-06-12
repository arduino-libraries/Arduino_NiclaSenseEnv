/**
 * This example shows how to control the orange LED on the Nicla Sense Env board.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "NiclaSenseEnv.h"

void pulseLED(OrangeLED& led) {
    // Fade in
    for (uint8_t i = 0; i < 255; ++i) {
        led.setBrightness(i);
        delay(4);
    }

    // Fade out
    for (int8_t i = 255; i >= 0; --i) {
        led.setBrightness(i);
        delay(4);
    }
}

void setup() {
    Serial.begin(115200);
    
    // Wait for Serial to be ready with a timeout of 5 seconds
    for(auto start = millis(); !Serial && millis() - start < 5000;);

    NiclaSenseEnv device;

    if (device.begin()) {
        auto orangeLED = device.orangeLED();
        
        Serial.print("🔢 Orange LED error status enabled: ");
        Serial.println(orangeLED.errorStatusEnabled());
        Serial.print("💡 Orange LED brightness: ");
        Serial.println(orangeLED.brightness());

        pulseLED(orangeLED);

        // Enable sensor error indication on orange LED (LED should turn off if sensors are okay)
        orangeLED.setErrorStatusEnabled(true);
    } else {
        Serial.println("🤷 Device could not be found. Please double-check the wiring.");
    }
}

void loop() {
    // Your main code here
}
