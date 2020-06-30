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
 * @file    Tutorial_1_DualCore_MASTER.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC54114_cm4.h"
#include "fsl_debug_console.h"
#include "boot_multicore_slave.h"
#include "fsl_mailbox.h"
#include "fsl_adc.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

uint32_t *myADCresults;
uint32_t adc_data[2];

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    MAILBOX_Init(MAILBOX);

    while(MAILBOX_GetMutex(MAILBOX) == 0);

    PRINTF("Hello World from MASTER\n");

    /* Start slave CPU. */
    boot_multicore_slave();

    MAILBOX_SetMutex(MAILBOX);
    while(MAILBOX_GetMutex(MAILBOX) == 0);

    /* Force the counter to be placed into memory. */
    volatile static double i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

        MAILBOX_SetMutex(MAILBOX);
        while(MAILBOX_GetMutex(MAILBOX) == 0);
        myADCresults = (uint32_t*)MAILBOX_GetValue(MAILBOX, kMAILBOX_CM0Plus);
        MAILBOX_ClearValueBits(MAILBOX, kMAILBOX_CM0Plus, 0xffffffff);

        adc_data[0] = *myADCresults++;
        adc_data[1] = *myADCresults;

        PRINTF("Joystick %u potenciometer %u\r\n",adc_data[0],adc_data[1]);

        for(i = 50000;i>0;i--);

    }
    return 0 ;
}
