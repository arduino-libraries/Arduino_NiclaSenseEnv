/**
 * This example shows how to restore the factory settings of the Nicla Sense Env.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "NiclaSenseEnv.h"

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        // Wait for serial port to connect
    }

    // Change to your custom address if you have changed it before (e.g., 0x22)
    uint8_t customDeviceAddress = NiclaSenseEnv::DEFAULT_DEVICE_ADDRESS;

    NiclaSenseEnv device(customDeviceAddress);

    if (device.begin()) {
        Serial.println("🔌 Device connected.");

        // Restore factory settings
        Serial.println("🔄 Restoring factory settings...");
        bool success = device.restoreFactorySettings();
        Serial.print("🔧 Factory settings restored: ");
        Serial.println(success ? "true" : "false");
    } else {
        Serial.println("🤷 Device could not be found. Please double-check the wiring.");
    }
}

void loop() {
    // Code in the loop if needed
}
