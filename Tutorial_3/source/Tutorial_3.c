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
 * @file    Tutorial_2.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC54114_cm4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

uint8_t StartAddress[1024] = {"La DMA puede llevar a problemas de coherencia de caché. Imagine una CPU equipada con una memoria caché y una memoria externa que se pueda acceder directamente por los dispositivos que utilizan DMA. Cuando la CPU accede a X lugar en la memoria, el valor actual se almacena en la caché. Si se realizan operaciones posteriores en X, se actualizará la copia en caché de X, pero no la versión de memoria externa de X. Si la caché no se vacía en la memoria antes de que otro dispositivo intente acceder a X, el dispositivo recibirá un valor caducado de X.Del mismo modo, si la copia en caché de X no es invalidada cuando un dispositivo escribe un nuevo valor en la memoria, entonces la CPU funcionará con un valor caducado de X.Este problema puede ser abordado en el diseño del sistema de las siguientes dos formas:Los sistemas de caché coherente implementan un método en el hardware externo mediante el cual se escribe una señal en el controlador de caché, la cual realiza una invalidación de la caché para ...."};
uint8_t EndAddress[1024];

usart_transfer_t rcit;
volatile bool txOnGoing = false;
volatile bool rxOnGoing = false;

void FLEXCOMM0_USART_CALLBACK(USART_Type *base, usart_dma_handle_t *handle, status_t status, void *userData){
    userData = userData;

    if (kStatus_USART_TxIdle == status)
    {
        txOnGoing    = false;
    }

    if (kStatus_USART_RxIdle == status)
    {
        rxOnGoing     = false;
    }

}

/* TODO: insert other definitions and declarations here. */

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

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

        rcit.data = EndAddress;
        rcit.dataSize = 10;
        rxOnGoing = true;

        if(USART_TransferReceiveDMA(FLEXCOMM0_PERIPHERAL, &FLEXCOMM0_USART_DMA_Handle, &rcit) == kStatus_Success);
        while(rxOnGoing);
        PRINTF("%s\r\n",EndAddress);

    }
    return 0 ;
}
