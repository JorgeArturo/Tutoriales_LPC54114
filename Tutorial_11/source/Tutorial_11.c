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
 * @file    Tutorial_11.c
 * @brief   Application entry point.
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC54114_cm4.h"
#include "fsl_debug_console.h"
#include "ov7670/ov7670.h"
#include "ov7670/regs.h"
/* TODO: insert other include files here. */

uint8_t rowex[50112];
uint8_t test = 0;
uint32_t mycoord[2];
uint8_t c;
uint8_t cmd;
uint8_t data;
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


    for(double i=200000;i>0;i--);
    Camera_OV7670_I2C_WrReg(REG_COM7,0x80);
    for(double i=1000000;i>0;i--); //Aproximadamente 1 segundo.

    //PRINTF("PID 0x%X,VER 0x%X\n",Camera_OV7670_I2C_RdReg(REG_PID),Camera_OV7670_I2C_RdReg(REG_VER));
    //Camera_ov7670_ResolQVGAProcessedBayerRGBMode();
    Camera_OV7670_I2C_WrReg(REG_COM10,0x24);	//VSYNC Low-High-Low , Pclk only when HREF is HIGH
    Camera_OV7670_I2C_WrReg(REG_CLKRC, 0x05);	//Frecuencia de operacion a 2 Mhz
    //Camera_OV7670_I2C_WrReg(SCALING_DCWCTR, 0x22);	//Scaling 1/2x
    //Camera_OV7670_I2C_WrReg(REG_COM3, 0x06);		//Enable Zoom Horizontal & Vertical
    //Camera_OV7670_I2C_WrReg(REG_COM14, 0x1B);		//Manual Adjustament
    //Camera_OV7670_I2C_WrReg(REG_REG74, 0x02);
    Camera_OV7670_I2C_WrReg(REG_COM7,0x08); //Salida QCIF


    for(double i=3000000;i>0;i--);

	//for(uint16_t row=0;row<119;row++)
		//for(uint16_t col=0;col<159;col++)
			//USART_WriteBlocking(BOARD_DEBUG_UART_BASEADDR, &rowex[col][row], 1);

    //USART_WriteBlocking(BOARD_DEBUG_UART_BASEADDR,&rowex,1280);


    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

        c = (uint8_t)GETCHAR();
    	cmd = (uint8_t)GETCHAR();
    	data = (uint8_t)GETCHAR();
        if(c == 0xFE){

        	Camera_VGA_Frame(&mycoord);
        	USART_WriteBlocking(BOARD_DEBUG_UART_BASEADDR, &rowex, 50112);
        }
        else if(c == 0xFC){

        	Camera_OV7670_I2C_WrReg(cmd,data);
        }

    }
    return 0 ;
}
