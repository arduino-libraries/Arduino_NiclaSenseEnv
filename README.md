# 🤖 Nicla Sense Env Arduino Library

[![Arduino Lint](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/actions/workflows/arduino-lint.yml) [![Compile Examples](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/actions/workflows/compile-examples.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/actions/workflows/compile-examples.yml) [![Spell Check](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/actions/workflows/spell-check.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/actions/workflows/spell-check.yml)

This library contains an API to read data from the Nicla Sense Env board and control its behaviour.  The board host three different sensors which can be read simultaneously: **ZMOD4410** (Indoor Air Quality), **ZMOD4510** (Outdoor Air Quality), **HS4001** (Temperature & Humidity).

## ✨ Features

This library supports the complete API exposed by the Nicla Sense Env sensor board over I2C.

- 🌈 RGB LED control
- ⚪️ White LED control
- 💤 Board control (sleep, reset, factory reset)
- 🔧 Board configuration (e.g. changing the I2C address)
- 🏠 Indoor Air Quality Sensor control
    - Change mode (Power down, cleaning, Indoor Air quality, sulfur detection)
    - Detect sulfur
    - Measure odor intensity
    - Measure ethanol level
    - Measure TVOC
    - Measure CO2
    - Measure air quality
- 🌳 Outdoor Air Quality Sensor control
    - Change mode (Power down, cleaning, Outdoor Air quality)
    - Measure NO2
    - Measure O3
    - Measure air quality
- 🌡 Temperature/Humidity Sensor Control
    - Change mode (Power down, temperature/humidity)
    - Read temperature
    - Read humidity
- 📄 UART CSV output

## 📖 Documentation
For more information on the features of this library and how to use them please read the documentation [here](./docs/).

## ✅ Supported Boards

The library was tested on the Arduino Portenta, Nano and MKR board families but it likely works on other boards that come with a modern Arduino core.
On Arduino boards, the default I2C interface is set to `Wire`. On other boards you may need to specify a different interface depending on the pinout. e.g.

```cpp
 NiclaSenseEnv device = NiclaSenseEnv(Wire1);
```

## ⚙️ Installation

The easiest way is to use the Arduino IDE or the Arduino CLI. As for the latter option you can install it with `arduino-cli lib install Arduino_NiclaSenseEnv`. You may need to update the index beforehand `arduino-cli lib update-index`

## 🧑‍💻 Developer Installation

Clone the repository and then run any example using the Arduino CLI. e.g. `arduino-cli compile examples/IndoorAirQuality/IndoorAirQuality.ino -b arduino:samd:mkrwifi1010 --library ./ -u -p /dev/cu.usbmodem14201`

## 🐛 Reporting Issues

If you encounter any issue, please open a bug report [here](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/issues). 

## 📕 Further Reading
- Indoor Air Quality: 
    - [A Sense of Clean Air](https://www.renesas.com/us/en/blogs/sense-clean-air)
    - [Overview of TVOC and Indoor Air Quality](https://www.renesas.com/us/en/document/whp/overview-tvoc-and-indoor-air-quality)
- Outdoor Air Quality: [Outdoor Air Quality: It’s Not Just About Urban Areas](https://www.renesas.com/us/en/blogs/outdoor-air-quality-its-not-just-about-urban-areas)
    
- Datasheets
    - [ZMOD4410 datasheet](https://www.renesas.com/us/en/document/dst/zmod4410-datasheet)
    - [ZMOD4510 datasheet](https://www.renesas.com/eu/en/document/dst/zmod4510-datasheet)
    - [HS4001 datasheet](https://www.renesas.com/us/en/document/dst/hs40xx-datasheet?r=1575071)

## 💪 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## 🤙 Contact

For questions, comments, or feedback on this library, please create an issue on this repository.

## ⚖️ License

This library is released under the [MPL-2.0 license](http://mozilla.org/MPL/2.0/).