/**
 * Example of reading various sensor properties from the Nicla Sense Env's outdoor air quality sensor ZMOD4510.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "Arduino_NiclaSenseEnv.h"

void displaySensorData(OutdoorAirQualitySensor& sensor) {
    if (sensor.enabled()) {
        Serial.print("🔧 Outdoor air quality sensor mode: ");
        Serial.println(sensor.modeString());
        Serial.print("🌳 Outdoor air quality value: ");
        Serial.println(sensor.airQualityIndex());
        Serial.print("🌳 Outdoor air quality: ");
        Serial.println(sensor.airQualityIndexInterpreted());
        Serial.print("🌳 Fast outdoor air quality index: ");
        Serial.println(sensor.fastAirQualityIndex());
        Serial.print("🌳 NO2 (ppb): ");
        Serial.println(sensor.NO2(), 2);
        Serial.print("🌳 O3 (ppb): ");
        Serial.println(sensor.O3(), 2);
    } else {
        Serial.println("🙅 Outdoor air quality sensor is disabled");
    }
}


void setup() {
    Serial.begin(115200);
    while (!Serial) {
        // Wait for serial port to connect.
    }

    NiclaSenseEnv device;

    if (device.begin()) {
        Serial.println("🔌 Device is connected");
        auto outdoorAirQualitySensor = device.outdoorAirQualitySensor();

        // Enable outdoor air quality sensor (disabled by default)
        // Please note that it may take some time for the sensor to deliver the first data
        // Use setEnabled(true, true) make the change persistent
        outdoorAirQualitySensor.setEnabled(true);
        displaySensorData(outdoorAirQualitySensor);

        // Optionally disable the sensor
        // outdoorAirQualitySensor.setEnabled(false);
    } else {
        Serial.println("🤷 Device could not be found. Please double-check the wiring.");
    }
}

void loop() {
    // Your code here
}
