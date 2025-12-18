#include "NiclaSenseEnvSerial.h"

/* CSV field definitions
Index, Description, Type
------------------------------------
0, "HS4001 sample counter", "uint32"
1, "HS4001 temperature (degC)", "float"
2, "HS4001 humidity (%RH)", "float"
3, "ZMOD4510 status", "uint8"
4, "ZMOD4510 sample counter", "uint32"
5, "ZMOD4510 EPA AQI", "uint16"
6, "ZMOD4510 Fast AQI", "uint16"
7, "ZMOD4510 O3 (ppb)", "float"
8, "ZMOD4510 NO2 (ppb)", "float"
9, "ZMOD4510 Rmox[0]", "float"
10, "ZMOD4510 Rmox[1]", "float"
11, "ZMOD4510 Rmox[2]", "float"
12, "ZMOD4510 Rmox[3]", "float"
13, "ZMOD4510 Rmox[4]", "float"
14, "ZMOD4510 Rmox[5]", "float"
15, "ZMOD4510 Rmox[6]", "float"
16, "ZMOD4510 Rmox[7]", "float"
17, "ZMOD4510 Rmox[8]", "float"
18, "ZMOD4510 Rmox[9]", "float"
19, "ZMOD4510 Rmox[10]", "float"
20, "ZMOD4510 Rmox[11]", "float"
21, "ZMOD4510 Rmox[12]", "float"
22, "ZMOD4410 status", "uint8"
23, "ZMD4410 sample counter", "uint32"
24, "ZMOD4410 IAQ", "float"
25, "ZMOD4410 TVOC (mg/m^3)", "float"
26, "ZMOD4410 eCO2 (ppm)", "float"
27, "ZMOD4410 Rel IAQ", "float"
28, "ZMOD4410 EtOH (ppm)", "float"
29, "ZMOD4410 Rmox[0]", "float"
30, "ZMOD4410 Rmox[1]", "float"
31, "ZMOD4410 Rmox[2]", "float"
32, "ZMOD4410 Rmox[3]", "float"
33, "ZMOD4410 Rmox[4]", "float"
34, "ZMOD4410 Rmox[5]", "float"
35, "ZMOD4410 Rmox[6]", "float"
36, "ZMOD4410 Rmox[7]", "float"
37, "ZMOD4410 Rmox[8]", "float"
38, "ZMOD4410 Rmox[9]", "float"
39, "ZMOD4410 Rmox[10]", "float"
40, "ZMOD4410 Rmox[11]", "float"
41, "ZMOD4410 Rmox[12]", "float"
42, "ZMOD4410 Rcda[0]", "float"
43, "ZMOD4410 Rcda[1]", "float"
44, "ZMOD4410 Rcda[2]", "float"
45, "ZMOD4410 Rhtr", "float"
46, "ZMOD4410 Temp", "float"
47, "ZMOD4410 intensity", "float"
48, "ZMOD4410 odor", "uint8"
*/

namespace {
constexpr size_t IDX_TEMPERATURE = 1;
constexpr size_t IDX_HUMIDITY = 2;
constexpr size_t IDX_EPA_AQI = 5;
constexpr size_t IDX_FAST_AQI = 6;
constexpr size_t IDX_O3 = 7;
constexpr size_t IDX_NO2 = 8;
constexpr size_t IDX_IAQ = 24;
constexpr size_t IDX_TVOC = 25;
constexpr size_t IDX_CO2 = 26;
constexpr size_t IDX_REL_IAQ = 27;
constexpr size_t IDX_ETHANOL = 28;
constexpr size_t IDX_ODOR_INTENSITY = 47;
constexpr size_t IDX_SULFUR_ODOR = 48;
}

NiclaSenseEnvSerial::NiclaSenseEnvSerial(HardwareSerial &serialPort) : _serial(&serialPort) {}

void NiclaSenseEnvSerial::begin(uint32_t baudRate, uint32_t config) {
    if (_serial == nullptr) {
        return;
    }
    _serial->begin(baudRate, config);
    while (!_serial) {
        delay(100);
    }
}

bool NiclaSenseEnvSerial::update() {
    _hasNewData = false;
    _lastErrorMessage = "";
    if (_serial == nullptr || !_serial->available()) {
        return false;
    }

    String csvLine = _serial->readStringUntil('\n');
    processCSVLine(csvLine);
    return _hasNewData;
}

float NiclaSenseEnvSerial::temperature() const { return _temperature; }
float NiclaSenseEnvSerial::humidity() const { return _humidity; }

int NiclaSenseEnvSerial::outdoorAirQualityIndex() const { return _epaAqi; }
int NiclaSenseEnvSerial::outdoorFastAirQualityIndex() const { return _fastAqi; }
float NiclaSenseEnvSerial::NO2() const { return _no2; }
float NiclaSenseEnvSerial::O3() const { return _o3; }

String NiclaSenseEnvSerial::outdoorAirQualityIndexInterpreted() const {
    int airQualityValue = outdoorAirQualityIndex();
    if (airQualityValue < 0) {
        return String("unknown");
    }
    if (airQualityValue <= 50) {
        return "Good";
    } else if (airQualityValue <= 100) {
        return "Moderate";
    } else if (airQualityValue <= 150) {
        return "Unhealthy for Sensitive Groups";
    } else if (airQualityValue <= 200) {
        return "Unhealthy";
    } else if (airQualityValue <= 300) {
        return "Very Unhealthy";
    } else {
        return "Hazardous";
    }
}

float NiclaSenseEnvSerial::indoorAirQuality() const { return _iaq; }

String NiclaSenseEnvSerial::indoorAirQualityInterpreted() const {
    float iaqValue = indoorAirQuality();
    if (isnan(iaqValue)) {
        return String("unknown");
    }
    if (iaqValue <= 1.99f) {
        return "Very Good";
    } else if (iaqValue <= 2.99f) {
        return "Good";
    } else if (iaqValue <= 3.99f) {
        return "Medium";
    } else if (iaqValue <= 4.99f) {
        return "Poor";
    } else {
        return "Bad";
    }
}

float NiclaSenseEnvSerial::indoorRelativeAirQuality() const { return _relativeIaq; }
float NiclaSenseEnvSerial::CO2() const { return _co2; }
float NiclaSenseEnvSerial::TVOC() const { return _tvoc; }
float NiclaSenseEnvSerial::ethanol() const { return _ethanol; }
float NiclaSenseEnvSerial::odorIntensity() const { return _odorIntensity; }
bool NiclaSenseEnvSerial::sulfurOdor() const { return _sulfurOdor; }

String NiclaSenseEnvSerial::lastErrorMessage() const { return _lastErrorMessage; }

void NiclaSenseEnvSerial::processCSVLine(String data) {
    if (data.length() == 0) {
        return;
    }

    if (data.startsWith("INFO:") || data.startsWith("WARNING:")) {
        return; // Informational messages are ignored
    }

    if (data.startsWith("ERROR:")) {
        _lastErrorMessage = data;
        return;
    }

    auto fields = splitFields(data);

    if (fields[IDX_TEMPERATURE].length()) {
        setFloatField(_temperature, fields[IDX_TEMPERATURE]);
    }
    if (fields[IDX_HUMIDITY].length()) {
        setFloatField(_humidity, fields[IDX_HUMIDITY]);
    }
    if (fields[IDX_EPA_AQI].length()) {
        setIntField(_epaAqi, fields[IDX_EPA_AQI]);
    }
    if (fields[IDX_FAST_AQI].length()) {
        setIntField(_fastAqi, fields[IDX_FAST_AQI]);
    }
    if (fields[IDX_O3].length()) {
        setFloatField(_o3, fields[IDX_O3]);
    }
    if (fields[IDX_NO2].length()) {
        setFloatField(_no2, fields[IDX_NO2]);
    }
    if (fields[IDX_IAQ].length()) {
        setFloatField(_iaq, fields[IDX_IAQ]);
    }
    if (fields[IDX_REL_IAQ].length()) {
        setFloatField(_relativeIaq, fields[IDX_REL_IAQ]);
    }
    if (fields[IDX_CO2].length()) {
        setFloatField(_co2, fields[IDX_CO2]);
    }
    if (fields[IDX_TVOC].length()) {
        setFloatField(_tvoc, fields[IDX_TVOC]);
    }
    if (fields[IDX_ETHANOL].length()) {
        setFloatField(_ethanol, fields[IDX_ETHANOL]);
    }
    if (fields[IDX_ODOR_INTENSITY].length()) {
        setFloatField(_odorIntensity, fields[IDX_ODOR_INTENSITY]);
    }
    if (fields[IDX_SULFUR_ODOR].length()) {
        int odorFlag = static_cast<int>(fields[IDX_SULFUR_ODOR].toInt());
        _sulfurOdor = odorFlag != 0;
        _hasNewData = true;
    }
}

std::array<String, NiclaSenseEnvSerial::CSV_FIELD_COUNT> NiclaSenseEnvSerial::splitFields(String data) {
    std::array<String, NiclaSenseEnvSerial::CSV_FIELD_COUNT> fields;
    size_t idx = 0;
    while (idx < NiclaSenseEnvSerial::CSV_FIELD_COUNT - 1) {
        int delimiterPos = data.indexOf(_delimiter);
        if (delimiterPos < 0) {
            break;
        }
        fields[idx++] = data.substring(0, delimiterPos);
        data = data.substring(delimiterPos + 1);
    }
    if (idx < NiclaSenseEnvSerial::CSV_FIELD_COUNT) {
        fields[idx] = data;
    }
    return fields;
}

void NiclaSenseEnvSerial::setFloatField(float &field, const String &value) {
    if (value.length() == 0) {
        return;
    }
    field = static_cast<float>(value.toDouble());
    _hasNewData = true;
}

void NiclaSenseEnvSerial::setIntField(int &field, const String &value) {
    if (value.length() == 0) {
        return;
    }
    field = static_cast<int>(value.toInt());
    _hasNewData = true;
}
