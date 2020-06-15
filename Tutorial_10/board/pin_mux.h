/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO010_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Controls input glitch filter.: Filter enabled. Noise pulses below approximately 10 ns are filtered out. */
#define PIO010_FILTEROFF_ENABLED 0x00u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO010_FUNC_ALT0 0x00u
/*!
 * @brief Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-up. Pull-up resistor enabled. */
#define PIO010_MODE_PULL_UP 0x02u

/*! @name PIO0_10 (number 45), J2[11]/P0_10-FC2_SCK-CT32B3_MAT0
  @{ */
#define BOARD_DHT11_Sensor_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_DHT11_Sensor_PORT 0U   /*!<@brief PORT device name: 0U */
#define BOARD_DHT11_Sensor_PIN 10U   /*!<@brief 0U pin index: 10 */
                                     /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins_cm4(void); /* Function assigned for the Cortex-M4F */

#define PIO023_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO023_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO023_I2CSLEW_I2C_MODE 0x00u /*!<@brief Controls slew rate of I2C pad.: I2C mode. */
#define PIO024_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO024_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO024_I2CSLEW_I2C_MODE 0x00u /*!<@brief Controls slew rate of I2C pad.: I2C mode. */

/*! @name PIO0_23 (number 1), J4[9]/JS3[1]/JS4[3]/U10[7]/U12[D6]/BRIDGE_SCL
  @{ */
#define BOARD_LINK2MCU_SCL_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_LINK2MCU_SCL_PIN 23U /*!<@brief 0U pin index: 23 */
                                   /* @} */

/*! @name PIO0_24 (number 2), J4[10]/JS2[1]/JS5[3]/U10[5]/U12[E6]/SW1/BRIDGE_SDA-WAKEUP
  @{ */
#define BOARD_LINK2MCU_SDA_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_LINK2MCU_SDA_PIN 24U /*!<@brief 0U pin index: 24 */
                                   /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLink2MCUPins(void); /* Function assigned for the Cortex-M4F */

#define PIO024_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO024_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO031_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO031_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO04_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO04_FUNC_ALT0 0x00u         /*!<@brief Selects pin function.: Alternative connection 0. */

/*! @name PIO0_24 (number 2), J4[10]/JS2[1]/JS5[3]/U10[5]/U12[E6]/SW1/BRIDGE_SDA-WAKEUP
  @{ */
#define BOARD_SW1_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_SW1_PORT 0U   /*!<@brief PORT device name: 0U */
#define BOARD_SW1_PIN 24U   /*!<@brief 0U pin index: 24 */
                            /* @} */

/*! @name PIO0_31 (number 13), J2[17]/J3[2]/P1[7]/U3[4]/SW2/P0_31-PDM0_CLK-ISP0_EN
  @{ */
#define BOARD_SW2_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_SW2_PORT 0U   /*!<@brief PORT device name: 0U */
#define BOARD_SW2_PIN 31U   /*!<@brief 0U pin index: 31 */
                            /* @} */

/*! @name PIO0_4 (number 38), J4[7]/U9[12]/SW3/BRIDGE_T_INTR-ISP1
  @{ */
#define BOARD_SW3_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_SW3_PORT 0U   /*!<@brief PORT device name: 0U */
#define BOARD_SW3_PIN 4U    /*!<@brief 0U pin index: 4 */
                            /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitBUTTONsPins(void); /* Function assigned for the Cortex-M4F */

#define PIO029_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO029_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO110_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO110_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO19_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO19_FUNC_ALT0 0x00u         /*!<@brief Selects pin function.: Alternative connection 0. */

/*! @name PIO1_9 (number 29), J9[5]/D2[3]/P1_9-BLUE_LED
  @{ */
#define BOARD_LED_BLUE_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_LED_BLUE_PORT 1U   /*!<@brief PORT device name: 1U */
#define BOARD_LED_BLUE_PIN 9U    /*!<@brief 1U pin index: 9 */
                                 /* @} */

/*! @name PIO1_10 (number 30), J9[8]/D2[4]/P1_10-SCT4-LED_GREEN
  @{ */
#define BOARD_LED_GREEN_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_LED_GREEN_PORT 1U   /*!<@brief PORT device name: 1U */
#define BOARD_LED_GREEN_PIN 10U   /*!<@brief 1U pin index: 10 */
                                  /* @} */

/*! @name PIO0_29 (number 11), J2[5]/D2[1]/P0_29-CT32B0_MAT3-RED
  @{ */
#define BOARD_LED_RED_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_LED_RED_PORT 0U   /*!<@brief PORT device name: 0U */
#define BOARD_LED_RED_PIN 29U   /*!<@brief 0U pin index: 29 */
                                /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void); /* Function assigned for the Cortex-M4F */

#define PIO025_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO025_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO025_I2CSLEW_I2C_MODE 0x00u /*!<@brief Controls slew rate of I2C pad.: I2C mode. */
#define PIO026_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO026_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO026_I2CSLEW_I2C_MODE 0x00u /*!<@brief Controls slew rate of I2C pad.: I2C mode. */

/*! @name PIO0_25 (number 3), J1[1]/JS4[1]/U10[7]/P0_25-FC4_SCLX
  @{ */
#define BOARD_FC4_SCLX_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_FC4_SCLX_PIN 25U /*!<@brief 0U pin index: 25 */
                               /* @} */

/*! @name PIO0_26 (number 4), J1[3]/JS5[1]/U10[5]/P0_26-FC4_SDAX
  @{ */
#define BOARD_FC4_SDAX_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_FC4_SDAX_PIN 26U /*!<@brief 0U pin index: 26 */
                               /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSecureMCUPins(void); /* Function assigned for the Cortex-M4F */

#define PIO018_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO018_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO019_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO019_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO020_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO020_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO12_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO12_FUNC_ALT4 0x04u         /*!<@brief Selects pin function.: Alternative connection 4. */

/*! @name PIO0_18 (number 58), J1[11]/U5[2]/P0_18-FC5_TXD_SCL_MISO
  @{ */
#define BOARD_SPI_FLASH_MISO_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_SPI_FLASH_MISO_PIN 18U /*!<@brief 0U pin index: 18 */
                                     /* @} */

/*! @name PIO0_19 (number 59), J1[9]/J2[8]/U5[6]/P0_19-FC5_SCK-SPIFI_CSn
  @{ */
#define BOARD_SPI_FLASH_SCK_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_SPI_FLASH_SCK_PIN 19U /*!<@brief 0U pin index: 19 */
                                    /* @} */

/*! @name PIO0_20 (number 60), J1[13]/U5[5]/P0_20-FC5_RXD_SDA_MOSI
  @{ */
#define BOARD_SPI_FLASH_MOSI_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_SPI_FLASH_MOSI_PIN 20U /*!<@brief 0U pin index: 20 */
                                     /* @} */

/*! @name PIO1_2 (number 16), J9[7]/JS8[1]/U5[1]/P1_2-FC5_SSEL3
  @{ */
#define BOARD_SPI_FLASH_CS_PORT 1U /*!<@brief PORT device name: 1U */
#define BOARD_SPI_FLASH_CS_PIN 2U  /*!<@brief 1U pin index: 2 */
                                   /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSPI_FLASHPins(void); /* Function assigned for the Cortex-M4F */

#define PIO011_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO011_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO012_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO012_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO013_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO013_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO014_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO014_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO022_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO022_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO023_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO023_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO023_I2CSLEW_I2C_MODE 0x00u /*!<@brief Controls slew rate of I2C pad.: I2C mode. */
#define PIO024_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO024_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO024_I2CSLEW_I2C_MODE 0x00u /*!<@brief Controls slew rate of I2C pad.: I2C mode. */
#define PIO04_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO04_FUNC_ALT0 0x00u         /*!<@brief Selects pin function.: Alternative connection 0. */

/*! @name PIO0_4 (number 38), J4[7]/U9[12]/SW3/BRIDGE_T_INTR-ISP1
  @{ */
#define BOARD_BRIDGE_T_INTR_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_BRIDGE_T_INTR_PORT 0U   /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_T_INTR_PIN 4U    /*!<@brief 0U pin index: 4 */
                                      /* @} */

/*! @name PIO0_11 (number 46), J4[4]/U9[13]/BRIDGE_T_SCK
  @{ */
#define BOARD_BRIDGE_T_SCK_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_T_SCK_PIN 11U /*!<@brief 0U pin index: 11 */
                                   /* @} */

/*! @name PIO0_12 (number 47), J4[2]/U9[11]/BRIDGE_T_MOSI
  @{ */
#define BOARD_BRIDGE_T_MOSI_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_T_MOSI_PIN 12U /*!<@brief 0U pin index: 12 */
                                    /* @} */

/*! @name PIO0_13 (number 48), J4[3]/U15[4]/BRIDGE_T_MISO
  @{ */
#define BOARD_BRIDGE_T_MISO_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_T_MISO_PIN 13U /*!<@brief 0U pin index: 13 */
                                    /* @} */

/*! @name PIO0_14 (number 49), J2[12]/J4[1]/U9[14]/BRIDGE_T_SSEL-SPIFI_IO3
  @{ */
#define BOARD_BRIDGE_T_SSEL_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_T_SSEL_PIN 14U /*!<@brief 0U pin index: 14 */
                                    /* @} */

/*! @name PIO0_22 (number 63), J4[8]/P0_22-BRIDGE_GPIO
  @{ */
#define BOARD_BRIDGE_GPIO_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_BRIDGE_GPIO_PORT 0U   /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_GPIO_PIN 22U   /*!<@brief 0U pin index: 22 */
                                    /* @} */

/*! @name PIO0_23 (number 1), J4[9]/JS3[1]/JS4[3]/U10[7]/U12[D6]/BRIDGE_SCL
  @{ */
#define BOARD_BRIDGE_SCL_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_SCL_PIN 23U /*!<@brief 0U pin index: 23 */
                                 /* @} */

/*! @name PIO0_24 (number 2), J4[10]/JS2[1]/JS5[3]/U10[5]/U12[E6]/SW1/BRIDGE_SDA-WAKEUP
  @{ */
#define BOARD_BRIDGE_SDA_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_BRIDGE_SDA_PIN 24U /*!<@brief 0U pin index: 24 */
                                 /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPMod_SPI_I2C_BRIDGEPins(void); /* Function assigned for the Cortex-M4F */

#define PIO16_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO16_FUNC_ALT7 0x07u        /*!<@brief Selects pin function.: Alternative connection 7. */

/*! @name USB0_DP (number 5), J5[3]/U7[2]/USB_DP
  @{ */
/* @} */

/*! @name USB0_DM (number 6), J5[2]/U7[3]/USB_DM
  @{ */
/* @} */

/*! @name PIO1_6 (number 26), J1[14]/J5[1]/JP10[2]/P1_6-FC7_SCK-USB_VBUS
  @{ */
#define BOARD_USB_VBUS_PORT 1U /*!<@brief PORT device name: 1U */
#define BOARD_USB_VBUS_PIN 6U  /*!<@brief 1U pin index: 6 */
                               /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitUSBPins(void); /* Function assigned for the Cortex-M4F */

#define PIO00_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO00_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO01_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO01_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */

/*! @name PIO0_1 (number 32), U6[4]/U22[3]/P0_1-ISP_TX
  @{ */
#define BOARD_DEBUG_UART_TX_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_DEBUG_UART_TX_PIN 1U  /*!<@brief 0U pin index: 1 */
                                    /* @} */

/*! @name PIO0_0 (number 31), U18[4]/TO_MUX_P0_0-ISP_RX
  @{ */
#define BOARD_DEBUG_UART_RX_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_DEBUG_UART_RX_PIN 0U  /*!<@brief 0U pin index: 0 */
                                    /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void); /* Function assigned for the Cortex-M4F */

#define PIO015_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO015_FUNC_ALT2 0x02u        /*!<@brief Selects pin function.: Alternative connection 2. */
#define PIO016_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO016_FUNC_ALT5 0x05u        /*!<@brief Selects pin function.: Alternative connection 5. */
#define PIO017_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO017_FUNC_ALT5 0x05u        /*!<@brief Selects pin function.: Alternative connection 5. */

/*! @name PIO0_17 (number 53), J2[6]/P1[2]/U2[5]/U14[4]/IF_TMS_SWDIO-SPIFI_IO0
  @{ */
#define BOARD_DEBUG_SWD_SWDIO_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_DEBUG_SWD_SWDIO_PIN 17U /*!<@brief 0U pin index: 17 */
                                      /* @} */

/*! @name PIO0_16 (number 52), J2[4]/JS28/U4[4]/TCK-SWDCLK_TRGT-SPIFI_IO1
  @{ */
#define BOARD_DEBUG_SWD_SWDCLK_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_DEBUG_SWD_SWDCLK_PIN 16U /*!<@brief 0U pin index: 16 */
                                       /* @} */

/*! @name PIO0_15 (number 50), J2[10]/JS30/U4[12]/TDO-SWO_TRGT-SPIFI_IO2
  @{ */
#define BOARD_DEBUG_SWD_SWO_PORT 0U /*!<@brief PORT device name: 0U */
#define BOARD_DEBUG_SWD_SWO_PIN 15U /*!<@brief 0U pin index: 15 */
                                    /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSWD_DEBUGPins(void); /* Function assigned for the Cortex-M4F */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
