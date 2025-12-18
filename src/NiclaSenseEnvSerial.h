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
    /** @brief Get the temperature value from the sensor in degrees Celsius. */
    float temperature() const;
    /** @brief Get the relative humidity value (Range 0-100%). */
    float humidity() const;

    // OutdoorAirQualitySensor compatible API
    /** @brief Retrieves the EPA air quality index. Range is 0 to 500. */
    int airQualityIndex() const;
    /** @brief Get the fast air quality index (1-minute averaging). */
    int fastAirQualityIndex() const;
    /** @brief Get the NO2 value from the outdoor air quality sensor (ppb). */
    float NO2() const;
    /** @brief Get the O3 value from the outdoor air quality sensor (ppb). */
    float O3() const;
    /** @brief Interprets the EPA AQI into a textual description. */
    String airQualityIndexInterpreted() const;

    // IndoorAirQualitySensor compatible API
    /** @brief Get the air quality value. Common range 0 to ~5. */
    float airQuality() const;
    /** @brief Get the interpreted air quality value (Very Good, Good, Medium, Poor, Bad). */
    String airQualityInterpreted() const;
    /** @brief Get the relative air quality value in percent (0 - 100%). */
    float relativeAirQuality() const;
    /** @brief Get the CO2 value in ppm. */
    float CO2() const;
    /** @brief Get the TVOC value in mg/m^3. */
    float TVOC() const;
    /** @brief Get the ethanol value in ppm. */
    float ethanol() const;
    /** @brief Get the odor intensity value. */
    float odorIntensity() const;
    /** @brief Get the sulfur odor-detected value (true or false). */
    bool sulfurOdor() const;

    /**
     * @brief Returns the last error message received over UART, empty when none.
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
