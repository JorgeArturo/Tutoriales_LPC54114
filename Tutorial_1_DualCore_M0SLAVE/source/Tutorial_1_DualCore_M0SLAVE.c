/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Tutorial_1_DualCore_M0SLAVE.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC54114_cm0plus.h"
#include "fsl_debug_console.h"
#include "fsl_mailbox.h"
#include "fsl_power.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
adc_result_info_t exAdc[2];
uint32_t adc_result_table[2];
/*
 * @brief   Application entry point.
 */
int main(void) {

	SystemCoreClockUpdate();

	MAILBOX_Init(MAILBOX);
	while(MAILBOX_GetMutex(MAILBOX) == 0);
	MAILBOX_SetMutex(MAILBOX);

    POWER_DisablePD(kPDRUNCFG_PD_ADC0);
    POWER_DisablePD(kPDRUNCFG_PD_VD7_ENA);
    POWER_DisablePD(kPDRUNCFG_PD_VREFP_SW);
    //POWER_DisablePD(kPDRUNCFG_PD_TEMPS);
    CLOCK_EnableClock(kCLOCK_Adc0); /* SYSCON->AHBCLKCTRL[0] |= SYSCON_AHBCLKCTRL_ADC0_MASK; */

    //Inicializacion de los pines
	BOARD_InitBootPins();

	//Inicializacion de Reloj para perifericos
    CLOCK_SetClkDiv(kCLOCK_DivAdcAsyncClk, 0U, true);
    CLOCK_SetClkDiv(kCLOCK_DivAdcAsyncClk, 2U, false);
    CLOCK_AttachClk(kFRO_HF_to_ADC_CLK);

    //Inicializacion para perifericos
	BOARD_InitBootPeripherals();

    PRINTF("Procesador M0+ Inicia...\n");

    /* Force the counter to be placed into memory. */

    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

    	while(MAILBOX_GetMutex(MAILBOX) == 0);

    	ADC_EnableConvSeqABurstMode(ADC0_PERIPHERAL,true);

    	while((ADC_GetStatusFlags(ADC0_PERIPHERAL)&kADC_GlobalOverrunFlagForSeqA) != kADC_GlobalOverrunFlagForSeqA);

    	ADC_EnableConvSeqABurstMode(ADC0_PERIPHERAL,false);

    	ADC_GetChannelConversionResult(ADC0_PERIPHERAL,1,&exAdc[0]);
    	ADC_GetChannelConversionResult(ADC0_PERIPHERAL,11,&exAdc[1]);

       	adc_result_table[0] = exAdc[0].result;
       	adc_result_table[1] = exAdc[1].result;

       	ADC_ClearStatusFlags(ADC0_PERIPHERAL,kADC_GlobalOverrunFlagForSeqA);

        MAILBOX_SetValue(MAILBOX, kMAILBOX_CM0Plus, &adc_result_table[0]);
        MAILBOX_SetMutex(MAILBOX);


    }
    return 0 ;
}
