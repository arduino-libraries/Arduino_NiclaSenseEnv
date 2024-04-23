#ifndef REGISTERS_H
#define REGISTERS_H

/**
 * @brief Structure representing information about a register.
 */
struct RegisterInfo {
    uint8_t address; ///< The address of the register.
    const char* type; ///< The data type of the register.
    size_t bytes; ///< The number of bytes of the register.
};

// Define RegisterInfo structs
constexpr RegisterInfo STATUS_REGISTER_INFO{0x00, "uint8", 1};
constexpr RegisterInfo SLAVE_ADDRESS_REGISTER_INFO{0x01, "uint8", 1};
constexpr RegisterInfo CONTROL_REGISTER_INFO{0x02, "uint8", 1};
constexpr RegisterInfo WHITE_LED_REGISTER_INFO{0x03, "uint8", 1};
constexpr RegisterInfo RGB_LED_RED_REGISTER_INFO{0x04, "uint8", 1};
constexpr RegisterInfo GREEN_REGISTER_INFO{0x05, "uint8", 1};
constexpr RegisterInfo BLUE_REGISTER_INFO{0x06, "uint8", 1};
constexpr RegisterInfo INTENSITY_REGISTER_INFO{0x07, "uint8", 1};
constexpr RegisterInfo UART_CONTROL_REGISTER_INFO{0x08, "uint8", 1};
constexpr RegisterInfo CSV_DELIMITER_REGISTER_INFO{0x09, "uint8", 1};
constexpr RegisterInfo SW_REVISION_REGISTER_INFO{0x0C, "uint8", 1};
constexpr RegisterInfo PRODUCT_ID_REGISTER_INFO{0x0D, "uint8", 1};
constexpr RegisterInfo SERIAL_NUMBER_REGISTER_INFO{0x0E, "uint8", 1 * 6};
constexpr RegisterInfo SAMPLE_COUNTER_REGISTER_INFO{0x14, "uint32", 4};
constexpr RegisterInfo TEMPERATURE_REGISTER_INFO{0x18, "float", 4};
constexpr RegisterInfo HUMIDITY_REGISTER_INFO{0x1C, "float", 4};
constexpr RegisterInfo ZMOD4510_STATUS_REGISTER_INFO{0x23, "uint8", 1};
constexpr RegisterInfo ZMOD4510_SAMPLE_COUNTER_REGISTER_INFO{0x24, "uint32", 4};
constexpr RegisterInfo ZMOD4510_EPA_AQI_REGISTER_INFO{0x28, "uint16", 2};
constexpr RegisterInfo ZMOD4510_FAST_AQI_REGISTER_INFO{0x2A, "uint16", 2};
constexpr RegisterInfo ZMOD4510_O3_REGISTER_INFO{0x2C, "float", 4};
constexpr RegisterInfo ZMOD4510_NO2_REGISTER_INFO{0x30, "float", 4};
constexpr RegisterInfo ZMOD4510_RMOX_REGISTER_INFO{0x34, "float", 4 * 13};
constexpr RegisterInfo ZMOD4410_STATUS_REGISTER_INFO{0x6B, "uint8", 1};
constexpr RegisterInfo ZMOD4410_SAMPLE_COUNTER_REGISTER_INFO{0x6C, "uint32", 4};
constexpr RegisterInfo ZMOD4410_IAQ_REGISTER_INFO{0x70, "float", 4};
constexpr RegisterInfo ZMOD4410_TVOC_REGISTER_INFO{0x74, "float", 4};
constexpr RegisterInfo ZMOD4410_ECO2_REGISTER_INFO{0x78, "float", 4};
constexpr RegisterInfo ZMOD4410_REL_IAQ_REGISTER_INFO{0x7C, "float", 4};
constexpr RegisterInfo ZMOD4410_ETOH_REGISTER_INFO{0x80, "float", 4};
constexpr RegisterInfo ZMOD4410_RMOX_REGISTER_INFO{0x84, "float", 4 * 13};
constexpr RegisterInfo ZMOD4410_RCDA_REGISTER_INFO{0xB8, "float", 4 * 3};
constexpr RegisterInfo ZMOD4410_RHTR_REGISTER_INFO{0xC4, "float", 4};
constexpr RegisterInfo ZMOD4410_TEMP_REGISTER_INFO{0xC8, "float", 4};
constexpr RegisterInfo ZMOD4410_INTENSITY_REGISTER_INFO{0xCC, "float", 4};
constexpr RegisterInfo ZMOD4410_ODOR_CLASS_REGISTER_INFO{0xD0, "uint8", 1};

#endif