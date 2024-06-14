/**
 * This example shows how to read data from the UART port on the board.
 * It is meant to run on a board only connected through UART to the Nicla Sense Env.
 * This requires the Nicla Sense Env to be powered through the VIN pin or through 
 * the ESLOV connector of a host board.
 * You will need to connect the UART pins of the Nicla Sense Env to the UART pins of the board.
 * On many Arduino boards the serial interface associated with those pins is Serial1.
 * Please check the documentation of your board to find out which serial interface to use.
 * 
 * UART output needs to be enabled on the Nicla Sense Env for this example to work.
 * You can do so by connecting to the board over I2C to a host board, and running the following code:
 * 
 * NiclaSenseEnv device;
 * device.begin();
 * The second parameter ensures that the settings are not lost after a reset
 * device.setUARTCSVOutputEnabled(true, true);
 * 
 * Initial author: Sebastian Romero (s.romero@arduino.cc)
 * 
 */

#include <map>
#include <vector>
#include <tuple>

constexpr char DEFAULT_DELIMITER = ',';

std::map<u_int8_t, std::tuple<String, String>> csvFieldMapping = {
    {0, {"HS4001 sample counter", "uint32"}},
    {1, {"HS4001 temperature (degC)", "float"}},
    {2, {"HS4001 humidity (%RH)", "float"}},
    {3, {"ZMOD4510 status", "uint8"}},
    {4, {"ZMOD4510 sample counter", "uint32"}},
    {5, {"ZMOD4510 EPA AQI", "uint16"}},
    {6, {"ZMOD4510 Fast AQI", "uint16"}},
    {7, {"ZMOD4510 O3 (ppb)", "float"}},
    {8, {"ZMOD4510 NO2 (ppb)", "float"}},
    {9, {"ZMOD4510 Rmox[0]", "float"}},
    {10, {"ZMOD4510 Rmox[1]", "float"}},
    {11, {"ZMOD4510 Rmox[2]", "float"}},
    {12, {"ZMOD4510 Rmox[3]", "float"}},
    {13, {"ZMOD4510 Rmox[4]", "float"}},
    {14, {"ZMOD4510 Rmox[5]", "float"}},
    {15, {"ZMOD4510 Rmox[6]", "float"}},
    {16, {"ZMOD4510 Rmox[7]", "float"}},
    {17, {"ZMOD4510 Rmox[8]", "float"}},
    {18, {"ZMOD4510 Rmox[9]", "float"}},
    {19, {"ZMOD4510 Rmox[10]", "float"}},
    {20, {"ZMOD4510 Rmox[11]", "float"}},
    {21, {"ZMOD4510 Rmox[12]", "float"}},
    {22, {"ZMOD4410 status", "uint8"}},
    {23, {"ZMD4410 sample counter", "uint32"}},
    {24, {"ZMOD4410 IAQ", "float"}},
    {25, {"ZMOD4410 TVOC (mg/m^3)", "float"}},
    {26, {"ZMOD4410 eCO2 (ppm)", "float"}},
    {27, {"ZMOD4410 Rel IAQ", "float"}},
    {28, {"ZMOD4410 EtOH (ppm)", "float"}},
    {29, {"ZMOD4410 Rmox[0]", "float"}},
    {30, {"ZMOD4410 Rmox[1]", "float"}},
    {31, {"ZMOD4410 Rmox[2]", "float"}},
    {32, {"ZMOD4410 Rmox[3]", "float"}},
    {33, {"ZMOD4410 Rmox[4]", "float"}},
    {34, {"ZMOD4410 Rmox[5]", "float"}},
    {35, {"ZMOD4410 Rmox[6]", "float"}},
    {36, {"ZMOD4410 Rmox[7]", "float"}},
    {37, {"ZMOD4410 Rmox[8]", "float"}},
    {38, {"ZMOD4410 Rmox[9]", "float"}},
    {39, {"ZMOD4410 Rmox[10]", "float"}},
    {40, {"ZMOD4410 Rmox[11]", "float"}},
    {41, {"ZMOD4410 Rmox[12]", "float"}},
    {42, {"ZMOD4410 Rcda[0]", "float"}},
    {43, {"ZMOD4410 Rcda[1]", "float"}},
    {44, {"ZMOD4410 Rcda[2]", "float"}},
    {45, {"ZMOD4410 Rhtr", "float"}},
    {46, {"ZMOD4410 Temp", "float"}},
    {47, {"ZMOD4410 intensity", "float"}},
    {48, {"ZMOD4410 odor", "uint8"}}
};

std::map<String, String> parsedValuesMap;

// Function to convert a string to a float, handling exponents
float parseFloatWithExponent(const String &str) {
    // Convert the string to a double
    double value = str.toDouble();

    // Convert the double to a float
    return static_cast<float>(value);
}

// Function to process a CSV line
void processCSVLine(String data, char delimiter, std::map<String, String> &targetMap) {
    // Skip lines that start with INFO: or WARNING:
    if (data.startsWith("INFO:") || data.startsWith("WARNING:")) {
        return;
    }

    // Print the error message if the line starts with ERROR:
    if (data.startsWith("ERROR:")) {
        Serial.println(data);
        return;
    }

    // Split CSV line into fields
    std::vector<String> fields;
    size_t pos = 0;
    while ((pos = data.indexOf(delimiter)) != -1) {
        fields.push_back(data.substring(0, pos));
        data = data.substring(pos + 1);
    }
    fields.push_back(data);  // Last field

    // Map fields to their corresponding names and store in parsedValuesMap
    for (size_t i = 0; i < fields.size(); ++i) {
        // Use index as key to get tuple (name, type)
        auto [name, type] = csvFieldMapping[i];
        String fieldValue = fields[i];

        // Check if the field is empty
        if (fieldValue == "") {
            continue;
        }

        // Check if the field is a float based on the "type" property
        if (type == "float") {
            float floatValue = parseFloatWithExponent(fieldValue);
            targetMap[name] = String(floatValue);
        } else {
            targetMap[name] = fieldValue;
        }
    }
}

void setup(){
    Serial.begin(115200);
    Serial1.begin(38400, SERIAL_8N1);

    while (!Serial || !Serial1) {
        delay(100);
    }

    Serial.println("Serial ports initialized");
}


void loop() {
    if (!Serial1.available()) {
        delay(100);
        return;
    }

    String csvLine = Serial1.readStringUntil('\n');
    processCSVLine(csvLine, DEFAULT_DELIMITER, parsedValuesMap);

    // If map is empty, there was no data to parse
    if (parsedValuesMap.empty()) {
        Serial.println("No data to parse.");
        return;
    }

    // Print parsed values in the loop
    for (const auto &entry : parsedValuesMap) {
        Serial.print(entry.first + ": ");
        Serial.println(entry.second);
    }

    Serial.println();

    // Clear the map for the next iteration
    parsedValuesMap.clear();
}