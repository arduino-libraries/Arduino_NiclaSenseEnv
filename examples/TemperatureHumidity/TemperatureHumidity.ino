/**
 * Example of reading temperature and humidity from the Nicla Sense Env's HS4001 sensor.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 */

#include "Arduino_NiclaSenseEnv.h"  // Include the NiclaSenseEnv library

void displaySensorData(TemperatureHumiditySensor& sensor) {
    if (sensor.enabled()) {
        float temperature = sensor.temperature();
        if (isnan(temperature)) {
            Serial.println("🌡 Temperature: N/A");
        } else {
            Serial.print("🌡 Temperature: ");
            Serial.print(temperature, 2);
            Serial.println("°C");
        }
        Serial.print("💧 Relative Humidity: ");
        Serial.print(sensor.humidity(), 2);
        Serial.println();
    } else {
        Serial.println("🙅 Temperature sensor is disabled");
    }
}

void setup() {    
    Serial.begin(115200);
    while (!Serial) {
        // Wait for Serial to be ready
    }

    NiclaSenseEnv device;

    if (device.begin()) {
        Serial.println("🔌 Device is connected");
        auto temperatureSensor = device.temperatureHumiditySensor();
        displaySensorData(temperatureSensor);
        // Optionally disable the sensor
        // temperatureSensor.setEnabled(false);
    } else {
        Serial.println("🤷 Device could not be found. Please double check the wiring.");
    }
}

void loop() {
    // Your main code here
}
