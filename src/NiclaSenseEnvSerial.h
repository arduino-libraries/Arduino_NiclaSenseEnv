#ifndef NICLA_SENSE_ENV_SERIAL_H
#define NICLA_SENSE_ENV_SERIAL_H

#include <Arduino.h>
#include <array>

/**
 * @brief Parses UART CSV output from Nicla Sense Env and exposes the same readings
 * available through the I2C sensor helper classes.
 */
class NiclaSenseEnvSerial {
public:
    /**
     * @brief Constructs a NiclaSenseEnvSerial parser bound to a UART interface.
     * @param serialPort HardwareSerial instance to read CSV data from.
     */
    explicit NiclaSenseEnvSerial(HardwareSerial &serialPort);

    /**
     * @brief Initialize the UART reader.
     * @param baudRate UART baud rate (defaults to 38400).
     * @param config Serial configuration (defaults to SERIAL_8N1).
     */
    void begin(uint32_t baudRate = 38400, uint32_t config = SERIAL_8N1);

    /**
     * @brief Poll the UART port and parse a CSV line when available.
     * @return true when new data was parsed during this call.
     */
    bool update();

    // TemperatureHumiditySensor compatible API
    /**
     * @brief Get the temperature value from the sensor in degrees Celsius.
     * @return Temperature in degrees Celsius, or NAN when unavailable.
     */
    float temperature() const;
    /**
     * @brief Get the relative humidity value.
     * @return Relative humidity percentage in the range 0-100, or NAN when unavailable.
     */
    float humidity() const;

    // OutdoorAirQualitySensor compatible API
    /**
     * @brief Retrieves the outdoor EPA air quality index.
     * @return AQI value in the range 0-500, or -1 when unavailable.
     */
    int outdoorAirQualityIndex() const;
    /**
     * @brief Get the outdoor fast air quality index (1-minute averaging).
     * @return Fast AQI value in the range 0-500, or -1 when unavailable.
     */
    int outdoorFastAirQualityIndex() const;
    /**
     * @brief Get the NO2 value from the outdoor air quality sensor.
     * @return Nitrogen dioxide concentration in ppb, or NAN when unavailable.
     */
    float NO2() const;
    /**
     * @brief Get the O3 value from the outdoor air quality sensor.
     * @return Ozone concentration in ppb, or NAN when unavailable.
     */
    float O3() const;
    /**
     * @brief Interprets the outdoor EPA AQI into a textual description.
     * @return Human-readable AQI category (e.g., Good, Moderate) or "unknown" when unavailable.
     */
    String outdoorAirQualityIndexInterpreted() const;

    // IndoorAirQualitySensor compatible API
    /**
     * @brief Get the indoor air quality value.
     * @return IAQ value (common range 0 to ~5), or NAN when unavailable.
     */
    float indoorAirQuality() const;
    /**
     * @brief Get the interpreted indoor air quality value.
     * @return Human-readable IAQ category (Very Good, Good, Medium, Poor, Bad) or "unknown" when unavailable.
     */
    String indoorAirQualityInterpreted() const;
    /**
     * @brief Get the indoor relative air quality value.
     * @return Relative IAQ percentage in the range 0-100, or NAN when unavailable.
     */
    float indoorRelativeAirQuality() const;

    /**
     * @brief Get the CO2 value.
     * @return Estimated CO2 concentration in ppm, or NAN when unavailable.
     */
    float CO2() const;
    /**
     * @brief Get the TVOC value.
     * @return Total volatile organic compounds concentration in mg/m^3, or NAN when unavailable.
     */
    float TVOC() const;
    /**
     * @brief Get the ethanol value.
     * @return Ethanol concentration in ppm, or NAN when unavailable.
     */
    float ethanol() const;
    /**
     * @brief Get the odor intensity value.
     * @return Odor intensity (sensor-specific scale), or NAN when unavailable.
     */
    float odorIntensity() const;
    /**
     * @brief Get the sulfur odor-detected flag.
     * @return true when sulfur odor is detected, false otherwise.
     */
    bool sulfurOdor() const;

    /**
     * @brief Returns the last error message received over UART, empty when none.
     * @return Error string from the device, or an empty String when no error is present.
     */
    String lastErrorMessage() const;

private:
    static constexpr size_t CSV_FIELD_COUNT = 49;

    /**
     * @brief Process one CSV line, mapping fields into cached values.
     * @param data The raw CSV line.
     */
    void processCSVLine(String data);
    /**
     * @brief Split a CSV line into fields using the configured delimiter.
     * @param data Raw CSV line.
     * @return Fixed-size array of CSV fields.
     */
    std::array<String, CSV_FIELD_COUNT> splitFields(String data);
    /**
     * @brief Parse and store a float field, marking data as updated when present.
     * @param field Destination variable.
     * @param value Raw string value to parse.
     */
    void setFloatField(float &field, const String &value);
    /**
     * @brief Parse and store an integer field, marking data as updated when present.
     * @param field Destination variable.
     * @param value Raw string value to parse.
     */
    void setIntField(int &field, const String &value);

    HardwareSerial *_serial = nullptr;
    char _delimiter = ',';
    bool _hasNewData = false;
    String _lastErrorMessage;

    float _temperature = NAN;
    float _humidity = NAN;
    int _epaAqi = -1;
    int _fastAqi = -1;
    float _no2 = NAN;
    float _o3 = NAN;
    float _iaq = NAN;
    float _relativeIaq = NAN;
    float _co2 = NAN;
    float _tvoc = NAN;
    float _ethanol = NAN;
    float _odorIntensity = NAN;
    bool _sulfurOdor = false;
};

#endif
