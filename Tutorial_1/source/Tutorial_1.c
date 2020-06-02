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
 * @file    Tutorial_1.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC54114_cm4.h"
#include "fsl_debug_console.h"
#include "mx25r_flash.h"
/* TODO: insert other include files here. */

struct mx25r_instance mx25_instance;
struct mx25r_rdid_result mfg;
const char txt[11] = {"HOLA MUNDO"};
char txt_reader[1024];

/* TODO: insert other definitions and declarations here. */

transfer_cb_t inter_func_mx25r(void *transfer_prv, uint8_t *tx_data, uint8_t *rx_data, size_t dataSize, bool eof){

	spi_transfer_t xmit;

	xmit.txData = tx_data;
	xmit.rxData = rx_data;
	xmit.dataSize = dataSize;
	if(eof)
		xmit.configFlags = kSPI_FrameAssert;
	else
		xmit.configFlags = 0;

	SPI_MasterTransferBlocking(FLEXCOMM5_PERIPHERAL, &xmit);

	return mx25r_err_ok;

}

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

    if(mx25r_init(&mx25_instance, inter_func_mx25r, NULL) == mx25r_err_ok)
    	PRINTF("Inicializando memoria externa\n");

    if(mx25r_cmd_rdid(&mx25_instance,&mfg) == mx25r_err_ok)
    	PRINTF("rdid %X,%X,%X\r\n",mfg.device[0],mfg.device[1],mfg.manufacturer);

    if(mx25r_cmd_write(&mx25_instance, 0x000200, &txt, sizeof(txt)) == mx25r_err_ok)
    	PRINTF("Se ha escrito %d \n\r",sizeof(txt));

    if(mx25r_cmd_read(&mx25_instance, 0x000200, &txt_reader, sizeof(txt_reader)) == mx25r_err_ok)
    	PRINTF("Se ha leido %d \r\n",sizeof(txt_reader));

    PRINTF("%s\r\n",txt_reader);

    /* Force the counter to be placed into memory. */
    volatile static int i = 0;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

        for(i=1000000;i>0;i--);
        LED_BLUE_TOGGLE();
        LED_GREEN_TOGGLE();
        LED_RED_TOGGLE();

    }

    return 0 ;
}
