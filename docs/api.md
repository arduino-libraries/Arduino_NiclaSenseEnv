# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class ` [`I2CDevice`](#class_i2_c_device) | Class for interacting with I2C devices.
`class ` [`IndoorAirQualitySensor`](#class_indoor_air_quality_sensor) | Represents an indoor air quality sensor.
`class ` [`NiclaSenseEnv`](#class_nicla_sense_env) | The [NiclaSenseEnv](#class_nicla_sense_env) class represents a [NiclaSenseEnv](#class_nicla_sense_env) device.
`class ` [`OrangeLED`](#class_orange_l_e_d) | Represents the orange on-board LED controlled via I2C.
`class ` [`OutdoorAirQualitySensor`](#class_outdoor_air_quality_sensor) | Class representing an outdoor air quality sensor (ZMOD4510)
`class ` [`RGBLED`](#class_r_g_b_l_e_d) | Represents the on-board RGB LED that can be controlled using I2C communication.
`class ` [`TemperatureHumiditySensor`](#class_temperature_humidity_sensor) | Represents a temperature and humidity sensor.
`struct ` [`LEDColor`](#struct_l_e_d_color) | Represents a color with red, green, and blue components.
`struct ` [`RegisterInfo`](#struct_register_info) | Structure representing information about a register.

# class `I2CDevice` <a id="class_i2_c_device" class="anchor"></a>

Class for interacting with I2C devices.

This class provides methods for reading and writing to registers of an I2C device. It also includes a method for checking if the device is connected.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`I2CDevice`](#class_i2_c_device_1ad2c7ba058304618c57a943641199f6cb) | Constructs an instance of the [I2CDevice](#class_i2_c_device) class. |
| [`I2CDevice`](#class_i2_c_device_1a289cb79c378556b6e76718549ffda236) | Constructs an [I2CDevice](#class_i2_c_device) object with the specified device address. |
| [`connected`](#class_i2_c_device_1a405cf71de1fecc94f8464ac49da259fb) | Checks if the device is connected to the I2C bus. |
| [`begin`](#class_i2_c_device_1ad84a76d9a379620773094b11ec51388b) | Initializes the I2C communication and checks if the device is connected. |
| [`deviceAddress`](#class_i2_c_device_1a8bb9879afb70813ff090b4debda304bd) | Get the I2C device address. |

## Members

### `I2CDevice` <a id="class_i2_c_device_1ad2c7ba058304618c57a943641199f6cb" class="anchor"></a>

```cpp
I2CDevice(TwoWire & bus, uint8_t deviceAddress)
```

Constructs an instance of the [I2CDevice](#class_i2_c_device) class.

#### Parameters
* `bus` The I2C bus to use (default is Wire). 

* `deviceAddress` The address of the I2C device (default is DEFAULT_DEVICE_ADDRESS).
<hr />

### `I2CDevice` <a id="class_i2_c_device_1a289cb79c378556b6e76718549ffda236" class="anchor"></a>

```cpp
I2CDevice(uint8_t deviceAddress)
```

Constructs an [I2CDevice](#class_i2_c_device) object with the specified device address.

#### Parameters
* `deviceAddress` The address of the I2C device.
<hr />

### `connected` <a id="class_i2_c_device_1a405cf71de1fecc94f8464ac49da259fb" class="anchor"></a>

```cpp
bool connected()
```

Checks if the device is connected to the I2C bus.

#### Returns
true if the device is connected, false otherwise.
<hr />

### `begin` <a id="class_i2_c_device_1ad84a76d9a379620773094b11ec51388b" class="anchor"></a>

```cpp
bool begin()
```

Initializes the I2C communication and checks if the device is connected.

#### Returns
true if the device is connected after initialization, false otherwise.
<hr />

### `deviceAddress` <a id="class_i2_c_device_1a8bb9879afb70813ff090b4debda304bd" class="anchor"></a>

```cpp
uint8_t deviceAddress() const
```

Get the I2C device address.

#### Returns
uint8_t The I2C device address.
<hr />

# class `IndoorAirQualitySensor` <a id="class_indoor_air_quality_sensor" class="anchor"></a>

```cpp
class IndoorAirQualitySensor
  : public I2CDevice
```

Represents an indoor air quality sensor.

The [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) class provides methods to retrieve various air quality parameters such as sulfur odor, odor intensity, ethanol level, CO2 level, TVOC level, air quality index, and more. It also allows setting the mode of the sensor and enabling/disabling it.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`IndoorAirQualitySensor`](#class_indoor_air_quality_sensor_1ad9dc9985e9643926edca85f9a96a783f) | Constructor for the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) class. |
| [`IndoorAirQualitySensor`](#class_indoor_air_quality_sensor_1ad499896d44f4132d4154ed32afa055a5) | Constructor for the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) class. |
| [`sulfurOdor`](#class_indoor_air_quality_sensor_1aa7bd7a6871f9ea9e2d8de919eeec13d5) | Get the sulfur odor-detected value (true or false) |
| [`odorIntensity`](#class_indoor_air_quality_sensor_1a39e649261d4b82100c8eb18d52571507) | Get the odor intensity value. |
| [`ethanol`](#class_indoor_air_quality_sensor_1af2a30f73ea9bfc1d6d6f7fe14d57124a) | Get the ethanol value. |
| [`CO2`](#class_indoor_air_quality_sensor_1a550a39cc5f3704f6e7f6b900a9ac4734) | Get the CO2 value in ppm. |
| [`TVOC`](#class_indoor_air_quality_sensor_1a8d2bab744275aec5b8e7b17c6dbcce1e) | Get the TVOC value in (mg/m3) |
| [`airQuality`](#class_indoor_air_quality_sensor_1a3e8ff13bda1d06802f2a1ec36f798b27) | Get the air quality value. The common range is 0 to ~5. |
| [`airQualityInterpreted`](#class_indoor_air_quality_sensor_1a60c0554991d417487511919ef0e1345d) | Get the interpreted air quality value. The possible values are "Very Good", "Good", "Medium", "Poor" and "Bad". |
| [`relativeAirQuality`](#class_indoor_air_quality_sensor_1a8b2d1a5242db59cbec765fb5e07ff070) | Get the relative air quality value in percent (0 - 100%). |
| [`mode`](#class_indoor_air_quality_sensor_1a41a6102aba04ab632f9e5af95156d6a5) | Get the mode of the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor). |
| [`setMode`](#class_indoor_air_quality_sensor_1a83f035ed7cd3aeeb8a0f5a81001b9a71) | Set the mode of the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor). |
| [`modeString`](#class_indoor_air_quality_sensor_1aa3dedfc0ec438c3dc1902cb54811afe8) | Get the mode as a string. The possible values are "powerDown", "cleaning", "indoorAirQuality", "indoorAirQualityLowPower", "sulfur" and "unknown". |
| [`enabled`](#class_indoor_air_quality_sensor_1ae8f92df80d34f547700d3141a4f9be6e) | Check if the sensor is enabled. |
| [`setEnabled`](#class_indoor_air_quality_sensor_1ab93c70ff6a5075c424f3cc9dab63e00b) | Set the sensor enabled or disabled. When the sensor is enabled after being disabled, the sensor will go back to the indoorAirQuality mode. |

## Members

### `IndoorAirQualitySensor` <a id="class_indoor_air_quality_sensor_1ad9dc9985e9643926edca85f9a96a783f" class="anchor"></a>

```cpp
IndoorAirQualitySensor(TwoWire & bus, uint8_t deviceAddress)
```

Constructor for the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) class.

#### Parameters
* `bus` The I2C bus to use. 

* `deviceAddress` The I2C address of the device.
<hr />

### `IndoorAirQualitySensor` <a id="class_indoor_air_quality_sensor_1ad499896d44f4132d4154ed32afa055a5" class="anchor"></a>

```cpp
IndoorAirQualitySensor(uint8_t deviceAddress)
```

Constructor for the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) class.

#### Parameters
* `deviceAddress` The I2C address of the device.
<hr />

### `sulfurOdor` <a id="class_indoor_air_quality_sensor_1aa7bd7a6871f9ea9e2d8de919eeec13d5" class="anchor"></a>

```cpp
bool sulfurOdor()
```

Get the sulfur odor-detected value (true or false)

#### Returns
The sulfur odor value.
<hr />

### `odorIntensity` <a id="class_indoor_air_quality_sensor_1a39e649261d4b82100c8eb18d52571507" class="anchor"></a>

```cpp
float odorIntensity()
```

Get the odor intensity value.

#### Returns
The odor intensity value.
<hr />

### `ethanol` <a id="class_indoor_air_quality_sensor_1af2a30f73ea9bfc1d6d6f7fe14d57124a" class="anchor"></a>

```cpp
float ethanol()
```

Get the ethanol value.

#### Returns
The ethanol value.
<hr />

### `CO2` <a id="class_indoor_air_quality_sensor_1a550a39cc5f3704f6e7f6b900a9ac4734" class="anchor"></a>

```cpp
float CO2()
```

Get the CO2 value in ppm.

#### Returns
The CO2 value.
<hr />

### `TVOC` <a id="class_indoor_air_quality_sensor_1a8d2bab744275aec5b8e7b17c6dbcce1e" class="anchor"></a>

```cpp
float TVOC()
```

Get the TVOC value in (mg/m3)

#### Returns
The TVOC value.
<hr />

### `airQuality` <a id="class_indoor_air_quality_sensor_1a3e8ff13bda1d06802f2a1ec36f798b27" class="anchor"></a>

```cpp
float airQuality()
```

Get the air quality value. The common range is 0 to ~5.

#### Returns
The air quality value.
<hr />

### `airQualityInterpreted` <a id="class_indoor_air_quality_sensor_1a60c0554991d417487511919ef0e1345d" class="anchor"></a>

```cpp
String airQualityInterpreted()
```

Get the interpreted air quality value. The possible values are "Very Good", "Good", "Medium", "Poor" and "Bad".

#### Returns
The interpreted air quality value.
<hr />

### `relativeAirQuality` <a id="class_indoor_air_quality_sensor_1a8b2d1a5242db59cbec765fb5e07ff070" class="anchor"></a>

```cpp
float relativeAirQuality()
```

Get the relative air quality value in percent (0 - 100%).

#### Returns
The relative air quality value.
<hr />

### `mode` <a id="class_indoor_air_quality_sensor_1a41a6102aba04ab632f9e5af95156d6a5" class="anchor"></a>

```cpp
IndoorAirQualitySensorMode mode()
```

Get the mode of the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor).

#### Returns
The mode of the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) as an enum value.
<hr />

### `setMode` <a id="class_indoor_air_quality_sensor_1a83f035ed7cd3aeeb8a0f5a81001b9a71" class="anchor"></a>

```cpp
bool setMode(IndoorAirQualitySensorMode sensorMode, bool persist)
```

Set the mode of the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor).

Note on cleaning mode: The cleaning mode performs a thermal cleaning cycle of the MOx element. It can eliminate some light pollution residues from production and packaging and improves the stabilization processes in the sensor. The function heats up the sensor to allow thermal desorption and catalytic combustion of the residues. The cleaning cycle can be executed only once in the sensor lifetime and shall be started after product assembly. Please ensure cleaning was completed before power-off/reset and do not interrupt while cleaning. The cleaning procedure takes 1 minute (blocking).

Note on PBAQ mode: The PBAQ mode is a special mode to perform highly accurate and consistent air quality readings. It measures the total volatile organic compounds (TVOC) and equivalent ethanol (EtOH) concentration to meet Public Building Air Quality (PBAQ) standards.

Note on low power IAQ mode: This mode offers a much lower power consumption while keeping accurate and consistent sensor readings. For more accurate readings, use the default indoor air quality mode.

#### Parameters
* `sensorMode` The mode to set. See the IndoorAirQualitySensorMode enum class for possible values. 

* `persist` If true, the change will be saved to flash memory. When persist is true, the mode setting of [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) and [TemperatureHumiditySensor](#class_temperature_humidity_sensor) will also be persisted. 

#### Returns
True if the mode was set successfully, false otherwise.
<hr />

### `modeString` <a id="class_indoor_air_quality_sensor_1aa3dedfc0ec438c3dc1902cb54811afe8" class="anchor"></a>

```cpp
String modeString()
```

Get the mode as a string. The possible values are "powerDown", "cleaning", "indoorAirQuality", "indoorAirQualityLowPower", "sulfur" and "unknown".

#### Returns
The mode as a string.
<hr />

### `enabled` <a id="class_indoor_air_quality_sensor_1ae8f92df80d34f547700d3141a4f9be6e" class="anchor"></a>

```cpp
bool enabled()
```

Check if the sensor is enabled.

#### Returns
True if the sensor is enabled, false otherwise.
<hr />

### `setEnabled` <a id="class_indoor_air_quality_sensor_1ab93c70ff6a5075c424f3cc9dab63e00b" class="anchor"></a>

```cpp
bool setEnabled(bool isEnabled, bool persist)
```

Set the sensor enabled or disabled. When the sensor is enabled after being disabled, the sensor will go back to the indoorAirQuality mode.

#### Parameters
* `isEnabled` True to enable the sensor, false to disable it. 

* `persist` If true, the change will be saved to flash memory. When persist is true, the mode setting of [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) and [TemperatureHumiditySensor](#class_temperature_humidity_sensor) will also be persisted. 

#### Returns
True if the the sensor was enabled successfully.
<hr />

# class `NiclaSenseEnv` <a id="class_nicla_sense_env" class="anchor"></a>

```cpp
class NiclaSenseEnv
  : public I2CDevice
```

The [NiclaSenseEnv](#class_nicla_sense_env) class represents a [NiclaSenseEnv](#class_nicla_sense_env) device.

This class provides methods to interact with the device to enable and disable features, query device information and retrieve sensor objects. It inherits from the [I2CDevice](#class_i2_c_device) class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`NiclaSenseEnv`](#class_nicla_sense_env_1af28c5f5a56ca984525a4939b5d5287d7) | Constructs a new [NiclaSenseEnv](#class_nicla_sense_env) object. |
| [`NiclaSenseEnv`](#class_nicla_sense_env_1a8b3c73e53693c753b56f1fecc3a6c484) | Constructs a new [NiclaSenseEnv](#class_nicla_sense_env) object. |
| [`~NiclaSenseEnv`](#class_nicla_sense_env_1a4e86e540c8d0ab99d89dc3242029fe39) | Destroy the Nicla Sense Env object. This will call the [end()](#class_nicla_sense_env_1abba16f72b55ddfd648c8cde348eb6338) method while frees up allocated resources. |
| [`temperatureHumiditySensor`](#class_nicla_sense_env_1a73d8ae251e1463315f00da6d6420b9c6) | Returns the [TemperatureHumiditySensor](#class_temperature_humidity_sensor) object to interact with the temperature and humidity sensor. |
| [`indoorAirQualitySensor`](#class_nicla_sense_env_1a4c36a3cc7c0dc351a720fe3bd8ce2ede) | Returns the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) object to interact with the indoor air quality sensor. |
| [`outdoorAirQualitySensor`](#class_nicla_sense_env_1a13c8a3127acea0364f1e771a49ad89d6) | Returns the [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) object to interact with the outdoor air quality sensor. |
| [`rgbLED`](#class_nicla_sense_env_1aea2da7e61de2736756eba56b417eaa0b) | Returns the [RGBLED](#class_r_g_b_l_e_d) object to interact with the RGB LED. |
| [`orangeLED`](#class_nicla_sense_env_1a7938bdcc03918a9900538373e0c02156) | Returns a reference to the [OrangeLED](#class_orange_l_e_d) object to interact with the orange LED. |
| [`end`](#class_nicla_sense_env_1abba16f72b55ddfd648c8cde348eb6338) | Ends the operation of the [NiclaSenseEnv](#class_nicla_sense_env) class. |
| [`persistSettings`](#class_nicla_sense_env_1a6f53bfdf4e8cc338b51089c393c52102) | Writes the current configuration to the flash memory. Stores board register 0x00 … 0x0B in flash to be default after reset. |
| [`serialNumber`](#class_nicla_sense_env_1a8c580892d180c058380e6e497b36230a) | Retrieves the serial number of the device. |
| [`productID`](#class_nicla_sense_env_1acbf78abfcf07c50fdd8c92a9bf06f206) | Gets the numeric product ID. |
| [`softwareRevision`](#class_nicla_sense_env_1a9e3052e58371e04bf54f89d6d81762e9) | Get the software revision number. |
| [`reset`](#class_nicla_sense_env_1a4ad8e07e0725654b41fc136064217d3b) | Performs a soft reset of the device. Changes to the configuration that were not stored in flash will be lost. |
| [`deepSleep`](#class_nicla_sense_env_1a99862d3a542caf7f4d41737aa4bdfbfd) | Puts the device into deep sleep mode. |
| [`restoreFactorySettings`](#class_nicla_sense_env_1a904757d188d0fb3ba666aaa843eb224d) | Restores the factory settings. This will reset among other properties the device address to the default value. See [persistSettings()](#class_nicla_sense_env_1a6f53bfdf4e8cc338b51089c393c52102) for a complete list of properties that are affected by this method. |
| [`UARTBaudRate`](#class_nicla_sense_env_1a0f7f2b94995a62ab4cdd769135b508fb) | Get the current baud rate of the UART communication. The supported values are: 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200. |
| [`setUARTBaudRate`](#class_nicla_sense_env_1a79737e5057b01f00f7bcf2843effb708) | Sets the baud rate for the UART communication. |
| [`isUARTCSVOutputEnabled`](#class_nicla_sense_env_1ad8103d2fa499f68db4f67c34c3a7258d) | Checks if UART CSV output is enabled. |
| [`setUARTCSVOutputEnabled`](#class_nicla_sense_env_1adfbada386d88c33a6ade148127340e44) | Sets the UART CSV output enabled or disabled. Enables or disables CSV output over UART. |
| [`CSVDelimiter`](#class_nicla_sense_env_1ade2737be2b30f054a8f8135891584d0f) | Gets the CSV delimiter character. The default value is ','. |
| [`setCSVDelimiter`](#class_nicla_sense_env_1ad36a6447de4444ff06f5ddeb7f139351) | Sets the CSV delimiter for parsing CSV data. |
| [`isDebuggingEnabled`](#class_nicla_sense_env_1a0125ca9818f64b4fcbd014598022f360) | Checks if debugging is enabled. When debugging mode is enabled, the board will send additional debug messages over UART. |
| [`setDebuggingEnabled`](#class_nicla_sense_env_1a96d8b28ad1f50f012149c28b3a4f71f7) | Toggles the debugging mode. When debugging mode is enabled, the board will send additional debug messages over UART. |
| [`setDeviceAddress`](#class_nicla_sense_env_1adfa69a5f5536884bbf404fed3d48c368) | Sets the I2C address of the device. |

## Members

### `NiclaSenseEnv` <a id="class_nicla_sense_env_1af28c5f5a56ca984525a4939b5d5287d7" class="anchor"></a>

```cpp
NiclaSenseEnv(TwoWire & bus, uint8_t deviceAddress)
```

Constructs a new [NiclaSenseEnv](#class_nicla_sense_env) object.

#### Parameters
* `bus` The I2C bus to use (default is Wire). 

* `deviceAddress` The I2C device address (default is 0x21).
<hr />

### `NiclaSenseEnv` <a id="class_nicla_sense_env_1a8b3c73e53693c753b56f1fecc3a6c484" class="anchor"></a>

```cpp
NiclaSenseEnv(uint8_t deviceAddress)
```

Constructs a new [NiclaSenseEnv](#class_nicla_sense_env) object.

#### Parameters
* `deviceAddress` The I2C address of the [NiclaSenseEnv](#class_nicla_sense_env) device.
<hr />

### `~NiclaSenseEnv` <a id="class_nicla_sense_env_1a4e86e540c8d0ab99d89dc3242029fe39" class="anchor"></a>

```cpp
~NiclaSenseEnv()
```

Destroy the Nicla Sense Env object. This will call the [end()](#class_nicla_sense_env_1abba16f72b55ddfd648c8cde348eb6338) method while frees up allocated resources.

<hr />

### `temperatureHumiditySensor` <a id="class_nicla_sense_env_1a73d8ae251e1463315f00da6d6420b9c6" class="anchor"></a>

```cpp
TemperatureHumiditySensor & temperatureHumiditySensor()
```

Returns the [TemperatureHumiditySensor](#class_temperature_humidity_sensor) object to interact with the temperature and humidity sensor.

#### Returns
The [TemperatureHumiditySensor](#class_temperature_humidity_sensor) object.
<hr />

### `indoorAirQualitySensor` <a id="class_nicla_sense_env_1a4c36a3cc7c0dc351a720fe3bd8ce2ede" class="anchor"></a>

```cpp
IndoorAirQualitySensor & indoorAirQualitySensor()
```

Returns the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) object to interact with the indoor air quality sensor.

#### Returns
A reference to the [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) object.
<hr />

### `outdoorAirQualitySensor` <a id="class_nicla_sense_env_1a13c8a3127acea0364f1e771a49ad89d6" class="anchor"></a>

```cpp
OutdoorAirQualitySensor & outdoorAirQualitySensor()
```

Returns the [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) object to interact with the outdoor air quality sensor.

#### Returns
The [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) object.
<hr />

### `rgbLED` <a id="class_nicla_sense_env_1aea2da7e61de2736756eba56b417eaa0b" class="anchor"></a>

```cpp
RGBLED & rgbLED()
```

Returns the [RGBLED](#class_r_g_b_l_e_d) object to interact with the RGB LED.

#### Returns
[RGBLED](#class_r_g_b_l_e_d)& The reference to the [RGBLED](#class_r_g_b_l_e_d) object.
<hr />

### `orangeLED` <a id="class_nicla_sense_env_1a7938bdcc03918a9900538373e0c02156" class="anchor"></a>

```cpp
OrangeLED & orangeLED()
```

Returns a reference to the [OrangeLED](#class_orange_l_e_d) object to interact with the orange LED.

#### Returns
[OrangeLED](#class_orange_l_e_d)& Reference to the [OrangeLED](#class_orange_l_e_d) object.
<hr />

### `end` <a id="class_nicla_sense_env_1abba16f72b55ddfd648c8cde348eb6338" class="anchor"></a>

```cpp
void end()
```

Ends the operation of the [NiclaSenseEnv](#class_nicla_sense_env) class.

This function is used to gracefully end the operation of the [NiclaSenseEnv](#class_nicla_sense_env) class. It performs any necessary cleanup to free up resources. It gets called automatically when the object is destroyed.
<hr />

### `persistSettings` <a id="class_nicla_sense_env_1a6f53bfdf4e8cc338b51089c393c52102" class="anchor"></a>

```cpp
bool persistSettings()
```

Writes the current configuration to the flash memory. Stores board register 0x00 … 0x0B in flash to be default after reset.

This affects the following properties:

* UART baud rate

* UART CSV output enabled

* CSV delimiter

* UART Debugging enabled

* I2C Device address

* Indoor air quality sensor mode

* Outdoor air quality sensor mode

* Temperature sensor enabled

* Orange LED brightness

* Orange LED error status enabled

* RGB LED brightness

* RGB LED color

Make sure all these properties are in the desired state before calling this method.

#### Returns
true if the settings were successfully stored, false otherwise.
<hr />

### `serialNumber` <a id="class_nicla_sense_env_1a8c580892d180c058380e6e497b36230a" class="anchor"></a>

```cpp
String serialNumber()
```

Retrieves the serial number of the device.

#### Returns
The serial number as a String.
<hr />

### `productID` <a id="class_nicla_sense_env_1acbf78abfcf07c50fdd8c92a9bf06f206" class="anchor"></a>

```cpp
int productID()
```

Gets the numeric product ID.

#### Returns
The product ID.
<hr />

### `softwareRevision` <a id="class_nicla_sense_env_1a9e3052e58371e04bf54f89d6d81762e9" class="anchor"></a>

```cpp
int softwareRevision()
```

Get the software revision number.

#### Returns
The software revision number.
<hr />

### `reset` <a id="class_nicla_sense_env_1a4ad8e07e0725654b41fc136064217d3b" class="anchor"></a>

```cpp
void reset()
```

Performs a soft reset of the device. Changes to the configuration that were not stored in flash will be lost.

<hr />

### `deepSleep` <a id="class_nicla_sense_env_1a99862d3a542caf7f4d41737aa4bdfbfd" class="anchor"></a>

```cpp
void deepSleep()
```

Puts the device into deep sleep mode.

This function puts the device into deep sleep mode, conserving power by disabling most of its functionalities. It is commonly used to prolong the battery life of battery-powered devices. The board can only be woken up by a hardware reset.
<hr />

### `restoreFactorySettings` <a id="class_nicla_sense_env_1a904757d188d0fb3ba666aaa843eb224d" class="anchor"></a>

```cpp
bool restoreFactorySettings()
```

Restores the factory settings. This will reset among other properties the device address to the default value. See [persistSettings()](#class_nicla_sense_env_1a6f53bfdf4e8cc338b51089c393c52102) for a complete list of properties that are affected by this method.

#### Returns
true if the factory settings were successfully restored, false otherwise.
<hr />

### `UARTBaudRate` <a id="class_nicla_sense_env_1a0f7f2b94995a62ab4cdd769135b508fb" class="anchor"></a>

```cpp
int UARTBaudRate()
```

Get the current baud rate of the UART communication. The supported values are: 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200.

#### Returns
int The UART Baud Rate.
<hr />

### `setUARTBaudRate` <a id="class_nicla_sense_env_1a79737e5057b01f00f7bcf2843effb708" class="anchor"></a>

```cpp
bool setUARTBaudRate(int baudRate, bool persist)
```

Sets the baud rate for the UART communication.

#### Parameters
* `baudRate` The desired baud rate for the UART communication. The supported values are: 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200 

* `persist` Set to true to store the setting in flash, to false otherwise. 

#### Returns
True if the baud rate was set successfully, false otherwise.
<hr />

### `isUARTCSVOutputEnabled` <a id="class_nicla_sense_env_1ad8103d2fa499f68db4f67c34c3a7258d" class="anchor"></a>

```cpp
bool isUARTCSVOutputEnabled()
```

Checks if UART CSV output is enabled.

#### Returns
true if UART CSV output is enabled, false otherwise.
<hr />

### `setUARTCSVOutputEnabled` <a id="class_nicla_sense_env_1adfbada386d88c33a6ade148127340e44" class="anchor"></a>

```cpp
bool setUARTCSVOutputEnabled(bool enabled, bool persist)
```

Sets the UART CSV output enabled or disabled. Enables or disables CSV output over UART.

The column names and their order are: HS4001 sample counter, HS4001 temperature (degC), HS4001 humidity (RH), ZMOD4510 status, ZMOD4510 sample counter, ZMOD4510 EPA AQI, ZMOD4510 Fast AQI, ZMOD4510 O3 (ppb), ZMOD4510 NO2 (ppb), ZMOD4510 Rmox[0], ZMOD4510 Rmox[1], ZMOD4510 Rmox[2], ZMOD4510 Rmox[3], ZMOD4510 Rmox[4], ZMOD4510 Rmox[5], ZMOD4510 Rmox[6], ZMOD4510 Rmox[7], ZMOD4510 Rmox[8], ZMOD4510 Rmox[9], ZMOD4510 Rmox[10], ZMOD4510 Rmox[11], ZMOD4510 Rmox[12], ZMOD4410 status, ZMD4410 sample counter, ZMOD4410 IAQ, ZMOD4410 TVOC (mg/m^3), ZMOD4410 eCO2 (ppm), ZMOD4410 Rel IAQ, ZMOD4410 EtOH (ppm), ZMOD4410 Rmox[0], ZMOD4410 Rmox[1], ZMOD4410 Rmox[2], ZMOD4410 Rmox[3], ZMOD4410 Rmox[4], ZMOD4410 Rmox[5], ZMOD4410 Rmox[6], ZMOD4410 Rmox[7], ZMOD4410 Rmox[8], ZMOD4410 Rmox[9], ZMOD4410 Rmox[10], ZMOD4410 Rmox[11], ZMOD4410 Rmox[12], ZMOD4410 Rcda[0], ZMOD4410 Rcda[1], ZMOD4410 Rcda[2], ZMOD4410 Rhtr, ZMOD4410 Temp, ZMOD4410 intensity, ZMOD4410 odor The csv formatted line is sent when a sensor finishes a measurement. Only the columns for this sensor will be filled, the other columns will be empty.

#### Parameters
* `enabled` True to enable UART CSV output, false to disable. 

* `persist` True to store the setting in flash, false otherwise. When set to True, it will also persist the value set via `setDebuggingEnabled`. 

#### Returns
True if the CSV output mode was set successfully, false otherwise.
<hr />

### `CSVDelimiter` <a id="class_nicla_sense_env_1ade2737be2b30f054a8f8135891584d0f" class="anchor"></a>

```cpp
char CSVDelimiter()
```

Gets the CSV delimiter character. The default value is ','.

#### Returns
The CSV delimiter character.
<hr />

### `setCSVDelimiter` <a id="class_nicla_sense_env_1ad36a6447de4444ff06f5ddeb7f139351" class="anchor"></a>

```cpp
bool setCSVDelimiter(char delimiter, bool persist)
```

Sets the CSV delimiter for parsing CSV data.

#### Parameters
* `delimiter` The character to be used as the CSV delimiter. 

* `persist` If true, the change will be saved to flash memory. 

#### Returns
True if the delimiter was set successfully, false otherwise.
<hr />

### `isDebuggingEnabled` <a id="class_nicla_sense_env_1a0125ca9818f64b4fcbd014598022f360" class="anchor"></a>

```cpp
bool isDebuggingEnabled()
```

Checks if debugging is enabled. When debugging mode is enabled, the board will send additional debug messages over UART.

#### Returns
true if debugging is enabled, false otherwise.
<hr />

### `setDebuggingEnabled` <a id="class_nicla_sense_env_1a96d8b28ad1f50f012149c28b3a4f71f7" class="anchor"></a>

```cpp
bool setDebuggingEnabled(bool enabled, bool persist)
```

Toggles the debugging mode. When debugging mode is enabled, the board will send additional debug messages over UART.

#### Parameters
* `enabled` A boolean value indicating whether debugging is enabled or not. 

* `persist` If true, the change will be saved to flash memory. When setting this to true the value set via `setUARTCSVOutputEnabled` will also be persisted. 

#### Returns
True if the debugging mode was set successfully, false otherwise.
<hr />

### `setDeviceAddress` <a id="class_nicla_sense_env_1adfa69a5f5536884bbf404fed3d48c368" class="anchor"></a>

```cpp
bool setDeviceAddress(int address, bool persist)
```

Sets the I2C address of the device.

#### Parameters
* `address` The new I2C address. Valid values are 0 to 127. 

* `persist` If true, the change will be saved to flash memory. 

#### Returns
True if the address was set successfully, false otherwise.
<hr />

# class `OrangeLED` <a id="class_orange_l_e_d" class="anchor"></a>

```cpp
class OrangeLED
  : public I2CDevice
```

Represents the orange on-board LED controlled via I2C.

The [OrangeLED](#class_orange_l_e_d) class provides methods to control the brightness and error status of the orange LED. It inherits from the [I2CDevice](#class_i2_c_device) class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`OrangeLED`](#class_orange_l_e_d_1af92a1e92f3505ff5cc30b364e142a710) | Constructs a [OrangeLED](#class_orange_l_e_d) object. |
| [`OrangeLED`](#class_orange_l_e_d_1a31e760ce8acade6fdb3d42f4c0e2d9cd) | Constructs a [OrangeLED](#class_orange_l_e_d) object with the specified device address. |
| [`brightness`](#class_orange_l_e_d_1a62c8337f91700b78fdfaba6ab401d080) | Gets the brightness of the orange LED.  |
| [`setBrightness`](#class_orange_l_e_d_1a0bd65f00322cd251e02e8c48da95c112) | Sets the brightness of the orange LED. When persist is true, the `errorStatusEnabled` setting will also be persisted.  |
| [`errorStatusEnabled`](#class_orange_l_e_d_1a01b9f52a9cc4490df7ed2e0e59f17b71) | Determines whether the orange LED is used to indicate an error status of one of the sensors. When a board error condition occurs the LED blinks, independently of the brightness setting.  |
| [`setErrorStatusEnabled`](#class_orange_l_e_d_1af05da1e5e1cd5ff06f63e68d0b5a6017) | Enables or disables the orange LED to indicate an error status of one of the sensors. When persist is true, the brightness setting will also be saved to flash memory.  |

## Members

### `OrangeLED` <a id="class_orange_l_e_d_1af92a1e92f3505ff5cc30b364e142a710" class="anchor"></a>

```cpp
OrangeLED(TwoWire & bus, uint8_t deviceAddress)
```

Constructs a [OrangeLED](#class_orange_l_e_d) object.

#### Parameters
* `bus` The I2C bus to use (default is Wire). 

* `deviceAddress` The I2C device address (default is 0x21).
<hr />

### `OrangeLED` <a id="class_orange_l_e_d_1a31e760ce8acade6fdb3d42f4c0e2d9cd" class="anchor"></a>

```cpp
OrangeLED(uint8_t deviceAddress)
```

Constructs a [OrangeLED](#class_orange_l_e_d) object with the specified device address.

#### Parameters
* `deviceAddress` The I2C address of the [OrangeLED](#class_orange_l_e_d) device.
<hr />

### `brightness` <a id="class_orange_l_e_d_1a62c8337f91700b78fdfaba6ab401d080" class="anchor"></a>

```cpp
uint8_t brightness()
```

Gets the brightness of the orange LED. 
#### Returns
The brightness of the orange LED. Range is 0 to 255.
<hr />

### `setBrightness` <a id="class_orange_l_e_d_1a0bd65f00322cd251e02e8c48da95c112" class="anchor"></a>

```cpp
bool setBrightness(uint8_t brightness, bool persist)
```

Sets the brightness of the orange LED. When persist is true, the `errorStatusEnabled` setting will also be persisted. 
#### Parameters
* `brightness` : The brightness of the orange LED. Range is 0 to 255. 

* `persist` : If true, the brightness setting will be saved to flash memory. 

#### Returns
True if the brightness was set successfully, false otherwise.
<hr />

### `errorStatusEnabled` <a id="class_orange_l_e_d_1a01b9f52a9cc4490df7ed2e0e59f17b71" class="anchor"></a>

```cpp
bool errorStatusEnabled()
```

Determines whether the orange LED is used to indicate an error status of one of the sensors. When a board error condition occurs the LED blinks, independently of the brightness setting. 
#### Returns
True if the orange LED is used for error status, false otherwise.
<hr />

### `setErrorStatusEnabled` <a id="class_orange_l_e_d_1af05da1e5e1cd5ff06f63e68d0b5a6017" class="anchor"></a>

```cpp
bool setErrorStatusEnabled(bool enabled, bool persist)
```

Enables or disables the orange LED to indicate an error status of one of the sensors. When persist is true, the brightness setting will also be saved to flash memory. 
#### Parameters
* `enabled` : Whether to enable or disable the orange LED error status. 

* `persist` : If true, the change will be saved to flash memory. 

#### Returns
True if the mode was set successfully, false otherwise.
<hr />

# class `OutdoorAirQualitySensor` <a id="class_outdoor_air_quality_sensor" class="anchor"></a>

```cpp
class OutdoorAirQualitySensor
  : public I2CDevice
```

Class representing an outdoor air quality sensor (ZMOD4510)

This class provides functionality to interact with an outdoor air quality sensor. It allows reading the air quality data from the sensor.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`OutdoorAirQualitySensor`](#class_outdoor_air_quality_sensor_1a5bbf81b3261b90a71f17cab446809081) | Constructs an instance of the [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) class. |
| [`OutdoorAirQualitySensor`](#class_outdoor_air_quality_sensor_1accd7421bbe2fe5448feac1aa2cddc44f) | Constructs an instance of the [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) class. |
| [`airQualityIndex`](#class_outdoor_air_quality_sensor_1a47a84d5676fad41e7056034c9ee715ed) | Retrieves the EPA air quality index. Range is 0 to 500. The" EPA AQI" is strictly following the EPA standard and is based on the 1-hour or 8-hour average of the O3 concentrations (concentration dependent). |
| [`airQualityIndexInterpreted`](#class_outdoor_air_quality_sensor_1a320d4156004dd7ce245e842000179ba9) | Gets the outdoor air quality index from the ZMOD4510 sensor and interprets it in terms of air quality. |
| [`fastAirQualityIndex`](#class_outdoor_air_quality_sensor_1ab3735730d950d9a982860864a996cb3b) | Get the fast air quality index. Range is 0 to 500. As the standard averaging leads to a very slow response, especially during testing and evaluation, "Fast AQI" provides quicker results with a 1-minute averaging. |
| [`NO2`](#class_outdoor_air_quality_sensor_1ae43fb5d16f458cc40389a7a0bc8e0a94) | Get the NO2 value from the outdoor air quality sensor. |
| [`O3`](#class_outdoor_air_quality_sensor_1a58bba1f61d09a835619d6ebfa7dc90d2) | Get the O3 value from the outdoor air quality sensor. |
| [`mode`](#class_outdoor_air_quality_sensor_1ab75dff205e511781b3608c890d982a51) | Get the mode of the outdoor air quality sensor. Possible values are: powerDown, cleaning, outdoorAirQuality. The default mode is powerDown. This is because the sensor needs several hours to start outputting valuable data due to the sensor's internal algorithm and chemical compound. This property represents the numeric value of the mode. See OutdoorAirQualitySensorMode for more information. |
| [`setMode`](#class_outdoor_air_quality_sensor_1aaf6631c57808d0a3020d0db2357cb41e) | Sets the mode of the outdoor air quality sensor. |
| [`modeString`](#class_outdoor_air_quality_sensor_1a565d3198430da683ed037d268d2d02f8) | Gets the outdoor air quality sensor mode as a string. |
| [`enabled`](#class_outdoor_air_quality_sensor_1a6e02cc3c01e8d7725c0f104890323f19) | Checks if the outdoor air quality sensor is enabled. |
| [`setEnabled`](#class_outdoor_air_quality_sensor_1a9597a02011152347af8c4a6c9ee7b97d) | Sets the enabled state of the outdoor air quality sensor. When disabled the sensor goes in power down mode. When the sensor is enabled after being disabled, the sensor will go back to the outdoorAirQuality mode. |

## Members

### `OutdoorAirQualitySensor` <a id="class_outdoor_air_quality_sensor_1a5bbf81b3261b90a71f17cab446809081" class="anchor"></a>

```cpp
OutdoorAirQualitySensor(TwoWire & bus, uint8_t deviceAddress)
```

Constructs an instance of the [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) class.

#### Parameters
* `bus` The I2C bus to which the sensor is connected. Defaults to Wire. 

* `deviceAddress` The I2C device address of the sensor. Defaults to 0x21.
<hr />

### `OutdoorAirQualitySensor` <a id="class_outdoor_air_quality_sensor_1accd7421bbe2fe5448feac1aa2cddc44f" class="anchor"></a>

```cpp
OutdoorAirQualitySensor(uint8_t deviceAddress)
```

Constructs an instance of the [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) class.

#### Parameters
* `deviceAddress` The address of the sensor device.
<hr />

### `airQualityIndex` <a id="class_outdoor_air_quality_sensor_1a47a84d5676fad41e7056034c9ee715ed" class="anchor"></a>

```cpp
int airQualityIndex()
```

Retrieves the EPA air quality index. Range is 0 to 500. The" EPA AQI" is strictly following the EPA standard and is based on the 1-hour or 8-hour average of the O3 concentrations (concentration dependent).

#### Returns
The air quality index as an integer.
<hr />

### `airQualityIndexInterpreted` <a id="class_outdoor_air_quality_sensor_1a320d4156004dd7ce245e842000179ba9" class="anchor"></a>

```cpp
String airQualityIndexInterpreted()
```

Gets the outdoor air quality index from the ZMOD4510 sensor and interprets it in terms of air quality.

#### Returns
The interpreted air quality index as a string. Possible values are: Good, Moderate, Unhealthy for Sensitive Groups, Unhealthy, Very Unhealthy, Hazardous.
<hr />

### `fastAirQualityIndex` <a id="class_outdoor_air_quality_sensor_1ab3735730d950d9a982860864a996cb3b" class="anchor"></a>

```cpp
int fastAirQualityIndex()
```

Get the fast air quality index. Range is 0 to 500. As the standard averaging leads to a very slow response, especially during testing and evaluation, "Fast AQI" provides quicker results with a 1-minute averaging.

#### Returns
int The fast air quality index.
<hr />

### `NO2` <a id="class_outdoor_air_quality_sensor_1ae43fb5d16f458cc40389a7a0bc8e0a94" class="anchor"></a>

```cpp
float NO2()
```

Get the NO2 value from the outdoor air quality sensor.

#### Returns
The NO2 concentration in ppb.
<hr />

### `O3` <a id="class_outdoor_air_quality_sensor_1a58bba1f61d09a835619d6ebfa7dc90d2" class="anchor"></a>

```cpp
float O3()
```

Get the O3 value from the outdoor air quality sensor.

#### Returns
The O3 concentration in ppb.
<hr />

### `mode` <a id="class_outdoor_air_quality_sensor_1ab75dff205e511781b3608c890d982a51" class="anchor"></a>

```cpp
OutdoorAirQualitySensorMode mode()
```

Get the mode of the outdoor air quality sensor. Possible values are: powerDown, cleaning, outdoorAirQuality. The default mode is powerDown. This is because the sensor needs several hours to start outputting valuable data due to the sensor's internal algorithm and chemical compound. This property represents the numeric value of the mode. See OutdoorAirQualitySensorMode for more information.

#### Returns
OutdoorAirQualitySensorMode The mode of the sensor.
<hr />

### `setMode` <a id="class_outdoor_air_quality_sensor_1aaf6631c57808d0a3020d0db2357cb41e" class="anchor"></a>

```cpp
bool setMode(OutdoorAirQualitySensorMode sensorMode, bool persist)
```

Sets the mode of the outdoor air quality sensor.

This function allows you to set the mode of the outdoor air quality sensor. Possible values are: powerDown, cleaning, outdoorAirQuality. See OutdoorAirQualitySensorMode for more information.

Note on cleaning mode: The cleaning mode performs a thermal cleaning cycle of the MOx element. It can eliminate some light pollution residues from production and packaging and improves the stabilization processes in the sensor. The function heats up the sensor to allow thermal desorption and catalytic combustion of the residues. The cleaning cycle can be executed only once in the sensor lifetime and shall be started after product assembly. Please ensure cleaning was completed before power-off/reset and do not interrupt while cleaning. The cleaning procedure takes 1 minute (blocking).

#### Parameters
* `sensorMode` The mode to set for the sensor. 

* `persist` If true, the change will be saved to flash memory. When persist is true, the mode setting of [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) and [TemperatureHumiditySensor](#class_temperature_humidity_sensor) will also be persisted. 

#### Returns
True if the mode was set successfully, false otherwise.
<hr />

### `modeString` <a id="class_outdoor_air_quality_sensor_1a565d3198430da683ed037d268d2d02f8" class="anchor"></a>

```cpp
String modeString()
```

Gets the outdoor air quality sensor mode as a string.

#### Returns
The mode as string. Possible values are: powerDown, cleaning, outdoorAirQuality.
<hr />

### `enabled` <a id="class_outdoor_air_quality_sensor_1a6e02cc3c01e8d7725c0f104890323f19" class="anchor"></a>

```cpp
bool enabled()
```

Checks if the outdoor air quality sensor is enabled.

#### Returns
true if the sensor is enabled, false otherwise.
<hr />

### `setEnabled` <a id="class_outdoor_air_quality_sensor_1a9597a02011152347af8c4a6c9ee7b97d" class="anchor"></a>

```cpp
bool setEnabled(bool isEnabled, bool persist)
```

Sets the enabled state of the outdoor air quality sensor. When disabled the sensor goes in power down mode. When the sensor is enabled after being disabled, the sensor will go back to the outdoorAirQuality mode.

#### Parameters
* `isEnabled` True to enable the sensor, false to disable it. 

* `persist` If true, the change will be saved to flash memory. When persist is true, the mode setting of [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) and [TemperatureHumiditySensor](#class_temperature_humidity_sensor) will also be persisted. 

#### Returns
True if the enabled state was set successfully, false otherwise.
<hr />

# class `RGBLED` <a id="class_r_g_b_l_e_d" class="anchor"></a>

```cpp
class RGBLED
  : public I2CDevice
```

Represents the on-board RGB LED that can be controlled using I2C communication.

The [RGBLED](#class_r_g_b_l_e_d) class provides methods to control the color and brightness of the LED, as well as enable features like indoor air quality status indicator. It inherits from the [I2CDevice](#class_i2_c_device) class and can be used with an I2C bus to communicate with the RGB LED device.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`RGBLED`](#class_r_g_b_l_e_d_1aad82d7f79dc58ed0a9411cef254dafad) | Constructs an instance of the [RGBLED](#class_r_g_b_l_e_d) class. |
| [`RGBLED`](#class_r_g_b_l_e_d_1a350a112613fac1242743e4b1de07a057) | Initializes an instance of the [RGBLED](#class_r_g_b_l_e_d) class with the specified device address. |
| [`enableIndoorAirQualityStatus`](#class_r_g_b_l_e_d_1aa6fbd29854537566dee74d73875615c6) | Enables the indoor air quality status indicator on the RGB LED. When enabled, the RGB LED will change color based on the air quality (red = bad, green = good)  |
| [`setColor`](#class_r_g_b_l_e_d_1a04058a97af30f3eb3836f7dd1eeb1c01) | Sets the RGB values of the LED. |
| [`setColor`](#class_r_g_b_l_e_d_1aac7fba93bc4437940f6a525886135983) | Sets the RGB color of the LED using a [LEDColor](#struct_l_e_d_color) object. The [LEDColor](#struct_l_e_d_color) object contains the red, green, and blue values that can be changed individually. Note: A value of 0, 0, 0 will set the color based on the IAQ value from the Indoor Air Quality sensor. |
| [`color`](#class_r_g_b_l_e_d_1a0b5c265b6940d324faf112103e60e5ff) | Gets the current RGB color of the LED. |
| [`brightness`](#class_r_g_b_l_e_d_1ae0d4a3a49a797220fe19ee70e8f3ec67) | Get the brightness of the RGB LED (0-255) |
| [`setBrightness`](#class_r_g_b_l_e_d_1a72dd5b87e665205ca86de73a193ce42f) | Sets the brightness of the RGB LED. This function allows you to adjust the brightness of the RGB LED. |

## Members

### `RGBLED` <a id="class_r_g_b_l_e_d_1aad82d7f79dc58ed0a9411cef254dafad" class="anchor"></a>

```cpp
RGBLED(TwoWire & bus, uint8_t deviceAddress)
```

Constructs an instance of the [RGBLED](#class_r_g_b_l_e_d) class.

#### Parameters
* `bus` The I2C bus to communicate with the [RGBLED](#class_r_g_b_l_e_d) device. Default is Wire. 

* `deviceAddress` The I2C address of the [RGBLED](#class_r_g_b_l_e_d) device. Default is DEFAULT_DEVICE_ADDRESS.
<hr />

### `RGBLED` <a id="class_r_g_b_l_e_d_1a350a112613fac1242743e4b1de07a057" class="anchor"></a>

```cpp
RGBLED(uint8_t deviceAddress)
```

Initializes an instance of the [RGBLED](#class_r_g_b_l_e_d) class with the specified device address.

#### Parameters
* `deviceAddress` The address of the RGB LED device.
<hr />

### `enableIndoorAirQualityStatus` <a id="class_r_g_b_l_e_d_1aa6fbd29854537566dee74d73875615c6" class="anchor"></a>

```cpp
bool enableIndoorAirQualityStatus(uint8_t brightness, bool persist)
```

Enables the indoor air quality status indicator on the RGB LED. When enabled, the RGB LED will change color based on the air quality (red = bad, green = good) 
#### Parameters
* `brightness` The brightness level of the indicator (0-255). 

* `persist` If true, the change will be saved to flash memory. When persist is True, the brightness will also be persisted. 

#### Returns
True if the mode was set successfully, false otherwise.
<hr />

### `setColor` <a id="class_r_g_b_l_e_d_1a04058a97af30f3eb3836f7dd1eeb1c01" class="anchor"></a>

```cpp
bool setColor(uint8_t r, uint8_t g, uint8_t b, bool persist)
```

Sets the RGB values of the LED.

This function sets the red, green, and blue values of the LED using individual values. Note: A value of 0, 0, 0 will set the color based on the IAQ value from the Indoor Air Quality sensor. 
#### Parameters
* `r` The red value (0-255). 

* `g` The green value (0-255). 

* `b` The blue value (0-255). 

* `persist` If true, the change will be saved to flash memory. 

#### Returns
True if the color was set successfully, false otherwise.
<hr />

### `setColor` <a id="class_r_g_b_l_e_d_1aac7fba93bc4437940f6a525886135983" class="anchor"></a>

```cpp
bool setColor( LEDColor color, bool persist)
```

Sets the RGB color of the LED using a [LEDColor](#struct_l_e_d_color) object. The [LEDColor](#struct_l_e_d_color) object contains the red, green, and blue values that can be changed individually. Note: A value of 0, 0, 0 will set the color based on the IAQ value from the Indoor Air Quality sensor.

#### Parameters
* `color` The RGB color to set. 

* `persist` If true, the change will be saved to flash memory. 

#### Returns
True if the color was set successfully, false otherwise.
<hr />

### `color` <a id="class_r_g_b_l_e_d_1a0b5c265b6940d324faf112103e60e5ff" class="anchor"></a>

```cpp
LEDColor color()
```

Gets the current RGB color of the LED.

#### Returns
The current RGB color as a [LEDColor](#struct_l_e_d_color) object.
<hr />

### `brightness` <a id="class_r_g_b_l_e_d_1ae0d4a3a49a797220fe19ee70e8f3ec67" class="anchor"></a>

```cpp
uint8_t brightness()
```

Get the brightness of the RGB LED (0-255)

#### Returns
The brightness value as a uint8_t.
<hr />

### `setBrightness` <a id="class_r_g_b_l_e_d_1a72dd5b87e665205ca86de73a193ce42f" class="anchor"></a>

```cpp
bool setBrightness(uint8_t brightness, bool persist)
```

Sets the brightness of the RGB LED. This function allows you to adjust the brightness of the RGB LED.

#### Parameters
* `brightness` The brightness level to set (0-255). 

* `persist` If true, the change will be saved to flash memory. 

#### Returns
True if the brightness was set successfully, false otherwise.
<hr />

# class `TemperatureHumiditySensor` <a id="class_temperature_humidity_sensor" class="anchor"></a>

```cpp
class TemperatureHumiditySensor
  : public I2CDevice
```

Represents a temperature and humidity sensor.

This class provides methods to interact with a temperature and humidity sensor connected via I2C communication. It inherits from the [I2CDevice](#class_i2_c_device) class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`TemperatureHumiditySensor`](#class_temperature_humidity_sensor_1a8f23aec4475680dae3f402d0a59f253f) | Constructs a [TemperatureHumiditySensor](#class_temperature_humidity_sensor) object. |
| [`TemperatureHumiditySensor`](#class_temperature_humidity_sensor_1ad1d7d9bebb8c9e4ba90b2fcf98741ffd) | Constructs a [TemperatureHumiditySensor](#class_temperature_humidity_sensor) object with the specified device address. |
| [`temperature`](#class_temperature_humidity_sensor_1a2af4c91ac63927fbfc4f230aa3407a90) | Get the temperature value from the sensor in degrees Celsius. |
| [`humidity`](#class_temperature_humidity_sensor_1a5a0dc24688dbc874eed38f0f486150b1) | Get the relative humidity value (Range 0-100%). |
| [`enabled`](#class_temperature_humidity_sensor_1ac4f4a00cc2fd8a2d58c47cbca1ac7533) | Checks if the temperature and humidity sensor is enabled. |
| [`setEnabled`](#class_temperature_humidity_sensor_1a093f3e5dc45279ffdab11b85c417080d) | Sets the enabled state of the temperature and humidity sensor. When disabled the sensor goes in power down mode. When `persist` is true, the mode setting of [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) and [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) will also be persisted. |

## Members

### `TemperatureHumiditySensor` <a id="class_temperature_humidity_sensor_1a8f23aec4475680dae3f402d0a59f253f" class="anchor"></a>

```cpp
TemperatureHumiditySensor(TwoWire & bus, uint8_t deviceAddress)
```

Constructs a [TemperatureHumiditySensor](#class_temperature_humidity_sensor) object.

#### Parameters
* `bus` The I2C bus to communicate with the sensor. Default is Wire. 

* `deviceAddress` The I2C address of the sensor. Default is 0x21.
<hr />

### `TemperatureHumiditySensor` <a id="class_temperature_humidity_sensor_1ad1d7d9bebb8c9e4ba90b2fcf98741ffd" class="anchor"></a>

```cpp
TemperatureHumiditySensor(uint8_t deviceAddress)
```

Constructs a [TemperatureHumiditySensor](#class_temperature_humidity_sensor) object with the specified device address.

#### Parameters
* `deviceAddress` The I2C address of the temperature and humidity sensor.
<hr />

### `temperature` <a id="class_temperature_humidity_sensor_1a2af4c91ac63927fbfc4f230aa3407a90" class="anchor"></a>

```cpp
float temperature()
```

Get the temperature value from the sensor in degrees Celsius.

#### Returns
float The temperature value.
<hr />

### `humidity` <a id="class_temperature_humidity_sensor_1a5a0dc24688dbc874eed38f0f486150b1" class="anchor"></a>

```cpp
float humidity()
```

Get the relative humidity value (Range 0-100%).

#### Returns
The humidity value as a float.
<hr />

### `enabled` <a id="class_temperature_humidity_sensor_1ac4f4a00cc2fd8a2d58c47cbca1ac7533" class="anchor"></a>

```cpp
bool enabled()
```

Checks if the temperature and humidity sensor is enabled.

#### Returns
true if the sensor is enabled, false otherwise.
<hr />

### `setEnabled` <a id="class_temperature_humidity_sensor_1a093f3e5dc45279ffdab11b85c417080d" class="anchor"></a>

```cpp
bool setEnabled(bool enabled, bool persist)
```

Sets the enabled state of the temperature and humidity sensor. When disabled the sensor goes in power down mode. When `persist` is true, the mode setting of [IndoorAirQualitySensor](#class_indoor_air_quality_sensor) and [OutdoorAirQualitySensor](#class_outdoor_air_quality_sensor) will also be persisted.

#### Parameters
* `enabled` The desired enabled state. True to enable the sensor, false to disable it. 

* `persist` If true, the change will be saved to flash memory. 

#### Returns
true if the operation was successful, false otherwise.
<hr />

# struct `LEDColor` <a id="struct_l_e_d_color" class="anchor"></a>

Represents a color with red, green, and blue components.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`red`](#struct_l_e_d_color_1ae7023d24a0d94b1b77a32d2f3aadd581) | The red component of the color. |
| [`green`](#struct_l_e_d_color_1a2ea3a2b138f2281a3d861e0e377dd84f) | The green component of the color. |
| [`blue`](#struct_l_e_d_color_1a4580c3efc87cb738b66e95fc7b1818db) | The blue component of the color. |

## Members

### `red` <a id="struct_l_e_d_color_1ae7023d24a0d94b1b77a32d2f3aadd581" class="anchor"></a>

```cpp
uint8_t red
```

The red component of the color.
<hr />

### `green` <a id="struct_l_e_d_color_1a2ea3a2b138f2281a3d861e0e377dd84f" class="anchor"></a>

```cpp
uint8_t green
```

The green component of the color.
<hr />

### `blue` <a id="struct_l_e_d_color_1a4580c3efc87cb738b66e95fc7b1818db" class="anchor"></a>

```cpp
uint8_t blue
```

The blue component of the color.
<hr />

# struct `RegisterInfo` <a id="struct_register_info" class="anchor"></a>

Structure representing information about a register.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`address`](#struct_register_info_1a200fb9e57f2e1a3149d8f2c560ee2fcc) | The address of the register. |
| [`type`](#struct_register_info_1a99aa3254964c950cab5990069073cb9a) | The data type of the register. |
| [`bytes`](#struct_register_info_1a3c683c1eea6ed2f1917c82daf3293dc0) | The number of bytes of the register. |

## Members

### `address` <a id="struct_register_info_1a200fb9e57f2e1a3149d8f2c560ee2fcc" class="anchor"></a>

```cpp
uint8_t address
```

The address of the register.

<hr />

### `type` <a id="struct_register_info_1a99aa3254964c950cab5990069073cb9a" class="anchor"></a>

```cpp
const char * type
```

The data type of the register.

<hr />

### `bytes` <a id="struct_register_info_1a3c683c1eea6ed2f1917c82daf3293dc0" class="anchor"></a>

```cpp
size_t bytes
```

The number of bytes of the register.

<hr />

