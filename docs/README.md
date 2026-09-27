# 📖 Documentation

## 💻 Usage

To use this library you can include the umbrella header `Arduino_NiclaSenseEnv.h` which includes other header files from the library. Then you need to initialize the device object which gives you access to the different sensor and actuator objects:

```cpp
#include "Arduino_NiclaSenseEnv.h"

void setup(){
    NiclaSenseEnv device;

    if (device.begin()) {
        Serial.println("🔌 Device is connected");

        auto indoorAirQualitySensor = device.indoorAirQualitySensor();
        // ...
        auto outdoorAirQualitySensor = device.outdoorAirQualitySensor();
        // ...
        auto temperatureSensor = device.temperatureHumiditySensor();
        // ...
        auto rgbLED = device.rgbLED();
        // ...
        auto orangeLED = device.orangeLED();
        // ...
    }
}
```
Once the desired object is obtained you can call functions on these objects such as `temperatureSensor.temperature()`. A complete list of these functions can be found in the [API documentation](./api.md).

## 🧑‍💻 API
The API documentation can be found [here](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/blob/main/docs/api.md).

## 👀 Examples

The following scripts are examples of how to use the Nicla Sense Env board with Python:

- [BoardControl.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/BoardControl/BoardControl.ino): Shows how to print the device information of the Nicla Sense Env, how to disable sensors and how to reset the device or put it to sleep.
- [ChangeI2CAddress.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/ChangeI2CAddress/ChangeI2CAddress.ino): Demonstrates how to change the board's I2C address.
- [FactoryReset.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/FactoryReset/FactoryReset.ino): Demonstrates how to perform a factory reset on the board.
- [IndoorAirQuality.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/IndoorAirQuality/IndoorAirQuality.ino): Demonstrates how to read the indoor air quality data from the board's sensors.
- [OutdoorAirQuality.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/OutdoorAirQuality/OutdoorAirQuality.ino): Demonstrates how to read the outdoor air quality data from the board's sensors.
- [RGBLED.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/RGBLED/RGBLED.ino): Demonstrates how to control the board's RGB LED.
- [TemperatureHumidity.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/TemperatureHumidity/TemperatureHumidity.ino): Demonstrates how to read the temperature and humidity data from the board's sensors.
- [UARTRead.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/UARTRead/UARTRead.ino): Shows how to read data from the UART port on the board when not connecting to it over I2C.
- [OrangeLED.ino](https://github.com/arduino-libraries/Arduino_NiclaSenseEnv/tree/main/examples/OrangeLED/OrangeLED.ino): Demonstrates how to control the board's orange LED.
