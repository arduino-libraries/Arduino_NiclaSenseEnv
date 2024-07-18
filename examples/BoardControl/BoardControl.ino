/**
 * This example shows how to print the device information of the Nicla Sense Env, 
 * how to disable all sensors and how to reset the device or put it to sleep.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "Arduino_NiclaSenseEnv.h"

void printDeviceInfo(NiclaSenseEnv& device) {
    Serial.print("🔌 Device (0x");
    Serial.print(device.deviceAddress(), HEX);
    Serial.println(") connected.");
    Serial.print("🔢 Serial number: ");
    Serial.println(device.serialNumber());
    Serial.print("🔢 Product ID: ");
    Serial.println(device.productID());
    Serial.print("🔢 Software revision: ");
    Serial.println(device.softwareRevision());
    Serial.print("🔢 Baud rate: ");
    Serial.println(device.UARTBaudRate());
    Serial.print("🔢 CSV delimiter: ");
    Serial.println(device.CSVDelimiter());
    Serial.print("🔧 Debugging enabled: ");
    Serial.println(device.isDebuggingEnabled() ? "true" : "false");
    Serial.print("🔧 CSV output enabled: ");
    Serial.println(device.isUARTCSVOutputEnabled() ? "true" : "false");
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        // Wait for Serial to be ready
    }

    NiclaSenseEnv device;

    if (device.begin()) {
        printDeviceInfo(device);

        // Enable debugging and CSV output if desired
        // device.setDebuggingEnabled(true);
        // device.setUARTCSVOutputEnabled(true);

        // Disable all sensors
        Serial.println("🙅 Disabling all sensors...");
        device.temperatureHumiditySensor().setEnabled(false);
        device.indoorAirQualitySensor().setEnabled(false);
        device.outdoorAirQualitySensor().setEnabled(false);

        Serial.print("🔧 Temperature sensor enabled: ");
        Serial.println(device.temperatureHumiditySensor().enabled() ? "true" : "false");
        Serial.print("🔧 Indoor air quality sensor enabled: ");
        Serial.println(device.indoorAirQualitySensor().enabled() ? "true" : "false");
        Serial.print("🔧 Outdoor air quality sensor enabled: ");
        Serial.println(device.outdoorAirQualitySensor().enabled() ? "true" : "false");

        // Reset sensors to default state by resetting the device
        Serial.println("🔄 Resetting device...");
        device.reset();
        delay(2000);

        Serial.print("🔧 Temperature sensor enabled: ");
        Serial.println(device.temperatureHumiditySensor().enabled() ? "true" : "false");
        Serial.print("🔧 Indoor air quality sensor enabled: ");
        Serial.println(device.indoorAirQualitySensor().enabled() ? "true" : "false");
        Serial.print("🔧 Outdoor air quality sensor enabled: ");
        Serial.println(device.outdoorAirQualitySensor().enabled() ? "true" : "false");

        // Go to sleep. Device can only be woken up by pressing the reset button
        Serial.println("💤 Going to sleep...");
        device.deepSleep();
    } else {
        Serial.println("🤷 Device could not be found. Please double-check the wiring.");
    }
}

void loop() {
    // Code in the loop if needed
}
