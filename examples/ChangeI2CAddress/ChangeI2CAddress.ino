/**
 * This example shows how to change the I2C address of the Nicla Sense Env board.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "NiclaSenseEnv.h"

void checkConnection(NiclaSenseEnv& device) {
    if (device.connected()) {
        Serial.print("🔌 Device (0x");
        Serial.print(device.deviceAddress(), HEX);
        Serial.println(") is connected.");
    } else {
        Serial.print("🤷 Device (0x");
        Serial.print(device.deviceAddress(), HEX);
        Serial.println(") could not be found. Please double-check the wiring.");
    }
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        // Wait for serial port to connect
    }

    // Initial and custom I2C addresses
    uint8_t currentI2CAddress = NiclaSenseEnv::DEFAULT_DEVICE_ADDRESS;
    uint8_t customI2CAddress = 0x22;

    NiclaSenseEnv device(currentI2CAddress);
    device.begin();
    checkConnection(device);

    Serial.print("🔧 Changing device address to 0x");
    Serial.print(customI2CAddress, HEX);
    Serial.println("...");
    
    // Setting the second parameter to true makes the change persistent
    device.setDeviceAddress(customI2CAddress, true);
    checkConnection(device);

    Serial.println("🔄 Resetting device to check if change is persistent...");
    device.reset();
    delay(2000);  // Wait for the device to reset
    checkConnection(device);
}

void loop() {
    // Code in the loop if needed
}
