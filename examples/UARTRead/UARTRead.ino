/**
 * This example shows how to read data from the UART port on the board.
 * It is meant to run on a board ONLY connected through UART to the Nicla Sense Env.
 * Boards that have an available I2C interface can connect to the Nicla Sense Env over I2C and read the data
 * in a much more efficient way.
 * 
 * A UART-only scenario requires the Nicla Sense Env to be powered through the VIN pin
 * as it won't be powered through the ESLOV connector.
 * You will need to connect the UART pins of the Nicla Sense Env to the UART pins of the host board.
 * On many Arduino boards the serial interface associated with those pins is Serial1.
 * Please check the documentation of your board to find out which serial interface to use.
 * 
 * IMPORTANT: UART output needs to be enabled beforehand on the Nicla Sense Env for this example to work.
 * You will need an I2C capable board to do so.
 * Connect Nicla Sense Env over I2C to that host board, and run the following code:
 * 
 * NiclaSenseEnv device;
 * device.begin(); 
 * device.setUARTCSVOutputEnabled(true, true); // Second parameter ensures that the settings are not lost after a reset
 * 
 * After that you can disconnect the Nicla Sense Env from the I2C host board and connect it to the UART host board.
 * You won't need to run the above code again, as the settings are stored permanently.
 * The code below is meant to run on the UART-only host board once the UART output is enabled.
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 * 
 */

#include "NiclaSenseEnvSerial.h"

NiclaSenseEnvSerial niclaSerial(Serial1);

void setup() {
    Serial.begin(115200);
    niclaSerial.begin();

    while (!Serial) {
        delay(100);
    }

    Serial.println("Serial ports initialized");
}

void loop() {
    bool updated = niclaSerial.update();

    if (!updated) {
        String err = niclaSerial.lastErrorMessage();
        if (err.length() > 0) {
            Serial.print("Error: ");
            Serial.println(err);
        }
        delay(100);
        return;
    }

    float temperature = niclaSerial.temperature();
    if (!isnan(temperature)) {
        Serial.print("🌡 HS4001 temperature (°C): ");
        Serial.println(temperature);
    }

    float humidity = niclaSerial.humidity();
    if (!isnan(humidity)) {
        Serial.print("💧 HS4001 humidity (%RH): ");
        Serial.println(humidity);
    }

    int epaAqi = niclaSerial.airQualityIndex();
    if (epaAqi >= 0) {
        Serial.print("🏭 ZMOD4510 EPA AQI: ");
        Serial.println(epaAqi);
        Serial.print("🏭 ZMOD4510 EPA AQI interpreted: ");
        Serial.println(niclaSerial.airQualityIndexInterpreted());
    }

    int fastAqi = niclaSerial.fastAirQualityIndex();
    if (fastAqi >= 0) {
        Serial.print("🏭 ZMOD4510 Fast AQI: ");
        Serial.println(fastAqi);
    }

    float o3 = niclaSerial.O3();
    if (!isnan(o3)) {
        Serial.print("🌬 ZMOD4510 O3 (ppb): ");
        Serial.println(o3);
    }

    float no2 = niclaSerial.NO2();
    if (!isnan(no2)) {
        Serial.print("🌬 ZMOD4510 NO2 (ppb): ");
        Serial.println(no2);
    }

    float iaq = niclaSerial.airQuality();
    if (!isnan(iaq)) {
        Serial.print("🏠 ZMOD4410 IAQ: ");
        Serial.println(iaq);
        Serial.print("🏠 ZMOD4410 IAQ interpreted: ");
        Serial.println(niclaSerial.airQualityInterpreted());
    }

    float relIaq = niclaSerial.relativeAirQuality();
    if (!isnan(relIaq)) {
        Serial.print("🏠 ZMOD4410 Rel IAQ: ");
        Serial.println(relIaq);
    }

    float co2 = niclaSerial.CO2();
    if (!isnan(co2)) {
        Serial.print("🌬 ZMOD4410 eCO2 (ppm): ");
        Serial.println(co2);
    }

    float tvoc = niclaSerial.TVOC();
    if (!isnan(tvoc)) {
        Serial.print("🌬 ZMOD4410 TVOC (mg/m^3): ");
        Serial.println(tvoc);
    }

    float ethanol = niclaSerial.ethanol();
    if (!isnan(ethanol)) {
        Serial.print("🍺 ZMOD4410 EtOH (ppm): ");
        Serial.println(ethanol);
    }

    float odorIntensity = niclaSerial.odorIntensity();
    if (!isnan(odorIntensity)) {
        Serial.print("👃 ZMOD4410 intensity: ");
        Serial.println(odorIntensity);
    }

    Serial.print("👃 ZMOD4410 odor: ");
    Serial.println(niclaSerial.sulfurOdor() ? "detected" : "not detected");

    Serial.println();
}