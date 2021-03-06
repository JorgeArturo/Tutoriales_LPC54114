/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v7.0
processor: LPC54114J256
package_id: LPC54114J256BD64
mcu_data: ksdk2_0
processor_version: 7.0.1
board: LPCXpresso54114
functionalGroups:
- name: BOARD_InitPeripherals_cm4
  UUID: 35304192-dcd2-4c25-bdf3-6c9c60ec1aa8
  called_from_default_init: true
  selectedCore: cm4
- name: BOARD_InitPeripherals_cm0plus
  UUID: 52029ed6-c35d-48dd-bb29-3c4ad79cee97
  selectedCore: cm0plus
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'msg'
- type_id: 'msg_6e2baaf3b97dbeef01c0043275f9a0e7'
- global_messages: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals_cm4 functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * ADC0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'ADC0'
- type: 'lpc_adc'
- mode: 'ADC'
- custom_name_enabled: 'false'
- type_id: 'lpc_adc_d74172b5bd0591c0d32a6c93c043a67f'
- functional_group: 'BOARD_InitPeripherals_cm4'
- peripheral: 'ADC0'
- config_sets:
  - fsl_adc:
    - doSelfCalibration: 'true'
    - enableTempSensor: 'false'
    - adcConfig:
      - clockMode: 'kADC_ClockAsynchronousMode'
      - clockSourceFreq: 'BOARD_BootClockHSRUN'
      - clockDividerNumber: '0'
      - resolution: 'kADC_Resolution12bit'
      - sampleTimeNumber: '0'
      - enableBypassCalibration: 'false'
    - thresholdConfig:
      - ADC_SetThreshold0: 'false'
      - thresholdSettingsPair0:
        - lowValue: '0'
        - highValue: '0'
      - ADC_SetThreshold1: 'false'
      - thresholdSettingsPair1:
        - lowValue: '0'
        - highValue: '0'
    - enableSeqConfigurationA: 'true'
    - adcConvSeqConfigA:
      - enableHighPriority: 'false'
      - adcConvSeqConfig:
        - triggerMaskM: '0U'
        - triggerPolarity: 'kADC_TriggerPolarityPositiveEdge'
        - enableSyncBypass: 'false'
        - enableSingleStep: 'false'
        - interruptMode: 'kADC_InterruptForEachSequence'
    - enableSeqConfigurationB: 'false'
    - adcConvSeqConfigB:
      - enableHighPriority: 'false'
      - adcConvSeqConfig:
        - triggerMaskM: '0U'
        - triggerPolarity: 'kADC_TriggerPolarityNegativeEdge'
        - enableSyncBypass: 'false'
        - enableSingleStep: 'false'
        - interruptMode: 'kADC_InterruptForEachConversion'
    - channels:
      - 0:
        - channelNumber: 'CH.11'
        - channelThresholdPair: 'thresholdPair0'
        - thresholdInterruptMode: 'kADC_ThresholdInterruptDisabled'
        - conversion_sequence: 'a'
      - 1:
        - channelNumber: 'CH.1'
        - channelThresholdPair: 'thresholdPair0'
        - thresholdInterruptMode: 'kADC_ThresholdInterruptDisabled'
        - conversion_sequence: 'a'
    - interrupt_sel: ''
    - enable_irq_seqA: 'false'
    - adc_interrupt_seqA:
      - IRQn: 'ADC0_SEQA_IRQn'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_irq_seqB: 'false'
    - adc_interrupt_seqB:
      - IRQn: 'ADC0_SEQB_IRQn'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_irq_thcmp: 'false'
    - adc_interrupt_thcmp:
      - IRQn: 'ADC0_THCMP_IRQn'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const adc_config_t ADC0configStruct = {
  .clockMode = kADC_ClockAsynchronousMode,
  .clockDividerNumber = 0,
  .resolution = kADC_Resolution12bit,
  .sampleTimeNumber = 0,
  .enableBypassCalibration = false
};
/* Conversion sequence A configuration structure */
const adc_conv_seq_config_t ADC0ConvSeqAConfigStruct = {
  .channelMask = 2048U | 2U,
  .triggerMask = 0U,
  .triggerPolarity = kADC_TriggerPolarityPositiveEdge,
  .enableSyncBypass = false,
  .enableSingleStep = false,
  .interruptMode = kADC_InterruptForEachSequence
};

void ADC0_init(void) {
  /* Perform self calibration */
  ADC_DoOffsetCalibration(ADC0_PERIPHERAL, ADC0_CLK_FREQ);
  /* Initialize ADC0 peripheral */
  ADC_Init(ADC0_PERIPHERAL, &ADC0configStruct);
  /* Configure the conversion sequence A */
  ADC_SetConvSeqAConfig(ADC0_PERIPHERAL, &ADC0ConvSeqAConfigStruct);
  /* Enable the conversion sequence A */
  ADC_EnableConvSeqA(ADC0_PERIPHERAL, true);
  /* Configure threshold compare interrupt on channel 11 */
  ADC_EnableThresholdCompareInterrupt(ADC0_PERIPHERAL, 11U, kADC_ThresholdInterruptDisabled);
  /* Configure threshold compare interrupt on channel 1 */
  ADC_EnableThresholdCompareInterrupt(ADC0_PERIPHERAL, 1U, kADC_ThresholdInterruptDisabled);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals_cm4(void)
{
  /* Initialize components */
  ADC0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals_cm4();
}
