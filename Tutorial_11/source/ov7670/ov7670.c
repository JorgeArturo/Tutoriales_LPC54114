/*
 * ov7670.c
 *
 *  Created on: 4 jul. 2020
 *      Author: Dell-i3
 */


#include "ov7670.h"
#include "regs.h"

const uint8_t resolVGA[9][2] = {{REG_CLKRC,0x00},	//Without Scaling Clock
							   	{REG_COM7,0x00},		//
								{REG_COM3,0x00},
								{REG_COM14,0x00},
								{SCALING_XSC,0x3A},
								{SCALING_YSC,0x35},
								{SCALING_DCWCTR,0x11},
								{SCALING_PCLK_DIV,0xF0},
								{REG_SCALING_PCLK_DELAY,0x02}};

const uint8_t resolVGARGBMode[9][2] = {{REG_CLKRC,0x00},	//Without Scaling Clock
										{REG_COM7,0x01},		//
										{REG_COM3,0x00},
										{REG_COM14,0x00},
										{SCALING_XSC,0x3A},
										{SCALING_YSC,0x35},
										{SCALING_DCWCTR,0x11},
										{SCALING_PCLK_DIV,0xF0},
										{REG_SCALING_PCLK_DELAY,0x02}};

const uint8_t resolQVGARProcessedBayerGBMode[9][2] = {{REG_CLKRC,0x00},	//Without Scaling Clock
														{REG_COM7,0x11},		//
														{REG_COM3,0x04},
														{REG_COM14,0x1A},
														{SCALING_XSC,0x3A},
														{SCALING_YSC,0x35},
														{SCALING_DCWCTR,0x11},
														{SCALING_PCLK_DIV,0xF9},
														{REG_SCALING_PCLK_DELAY,0x02}};

/*
const uint8_t ImageScalingCommands[][] = {	{REG_COM3, 0x0C},		//Enable Scaling,Enable Zoom
											{SCALING_DCWCTR, 0x11},	//Scaling Horizontal and vertical by 2
											{REG_COM4, 0x19},		//DCW and scaling PCKL, Scaling params, divided by 2
											{SCALING_PCLK_DIV,0x01}, //Divided by 2
											{},
};
*/

extern uint8_t rowex[50112];

uint8_t read_byte_port(void){

	uint8_t bytedata = 0;

	bytedata = (((GPIO->B[BOARD_D0_PORT][BOARD_D0_PIN]) << 0) |
			   ((GPIO->B[BOARD_D1_PORT][BOARD_D1_PIN]) << 1) |
			   ((GPIO->B[BOARD_D2_PORT][BOARD_D2_PIN]) << 2) |
			   ((GPIO->B[BOARD_D3_PORT][BOARD_D3_PIN]) << 3) |
			   ((GPIO->B[BOARD_D4_PORT][BOARD_D4_PIN]) << 4) |
			   ((GPIO->B[BOARD_D5_PORT][BOARD_D5_PIN]) << 5) |
			   ((GPIO->B[BOARD_D6_PORT][BOARD_D6_PIN]) << 6) |
			   ((GPIO->B[BOARD_D7_PORT][BOARD_D7_PIN]) << 7));


	return bytedata;

}

/*
 *  In. cmd  = comando
 * */


uint8_t Camera_OV7670_I2C_WrReg(uint8_t cmd,uint8_t dt){

	if(I2C_MasterStart(FLEXCOMM4_PERIPHERAL, CAM_ADDR, kI2C_Write) != kStatus_Success)
		return 1;
	if(I2C_MasterWriteBlocking(FLEXCOMM4_PERIPHERAL, &cmd, 1, kI2C_TransferNoStopFlag) != kStatus_Success)
		return 2;
	if(I2C_MasterWriteBlocking(FLEXCOMM4_PERIPHERAL, &dt, 1, kI2C_TransferDefaultFlag) != kStatus_Success)
		return 3;
	if(I2C_MasterStop(FLEXCOMM4_PERIPHERAL)!=kStatus_Success)
		return 4;

	return 0;

}

/*
 *  In. cmd  = comando
 * */


uint8_t Camera_OV7670_I2C_RdReg(uint8_t cmd){

	uint8_t rxdata;

	if(I2C_MasterStart(FLEXCOMM4_PERIPHERAL, CAM_ADDR, kI2C_Write) != kStatus_Success)
		return 0;
	if(I2C_MasterWriteBlocking(FLEXCOMM4_PERIPHERAL, &cmd, 1, kI2C_TransferDefaultFlag) != kStatus_Success)
		return 1;
	if(I2C_MasterStop(FLEXCOMM4_PERIPHERAL)!=kStatus_Success)
		return 2;
	if(I2C_MasterRepeatedStart(FLEXCOMM4_PERIPHERAL, CAM_ADDR, kI2C_Read) != kStatus_Success)
		return 3;
	if(I2C_MasterReadBlocking(FLEXCOMM4_PERIPHERAL, &rxdata, 1, kI2C_TransferDefaultFlag) != kStatus_Success)
		return 4;
	if(I2C_MasterStop(FLEXCOMM4_PERIPHERAL)!=kStatus_Success)
		return 5;

	return rxdata;

}


void Camera_VGA_Frame(uint32_t* coord){

	uint32_t y=0,x=0;
	//VSYNC Start Frame
	while(!GPIO_PinRead(BOARD_VSYNC_GPIO, BOARD_VSYNC_PORT, BOARD_VSYNC_PIN)); //VSYNC low
	while(GPIO_PinRead(BOARD_VSYNC_GPIO, BOARD_VSYNC_PORT, BOARD_VSYNC_PIN));  //VSYNC high

	while(!GPIO_PinRead(BOARD_HREF_GPIO, BOARD_HREF_PORT, BOARD_HREF_PIN));

	while(1){


		if(GPIO->B[BOARD_PCLK_PORT][BOARD_PCLK_PIN] && !GPIO->B[BOARD_HREF_PORT][BOARD_HREF_PIN]){

			x++;
			while(GPIO->B[BOARD_PCLK_PORT][BOARD_PCLK_PIN] && !GPIO->B[BOARD_HREF_PORT][BOARD_HREF_PIN] && !GPIO->B[BOARD_VSYNC_PORT][BOARD_VSYNC_PIN]);

		};

		while(!GPIO->B[BOARD_PCLK_PORT][BOARD_PCLK_PIN] && GPIO->B[BOARD_HREF_PORT][BOARD_HREF_PIN]);
		if(GPIO->B[BOARD_HREF_PORT][BOARD_HREF_PIN]) {rowex[y] = read_byte_port();y++;}
		while(GPIO->B[BOARD_PCLK_PORT][BOARD_PCLK_PIN] && GPIO->B[BOARD_HREF_PORT][BOARD_HREF_PIN]);

		if(!GPIO->B[BOARD_HREF_PORT][BOARD_HREF_PIN] && GPIO->B[BOARD_VSYNC_PORT][BOARD_VSYNC_PIN]) break;

	}

	*coord = y;
	coord++;
	*coord = x;

}


void Camera_ov7670_ResolVGA(void){

	for(uint8_t i=0;i<9;i++)
		Camera_OV7670_I2C_WrReg(resolVGA[i][0],resolVGA[i][1]);
	for(uint8_t i=0;i<9;i++)
		PRINTF("0x%X ",Camera_OV7670_I2C_RdReg(resolVGA[i][0]));
	PRINTF("\n");


}

void Camera_ov7670_ResolVGARGBMode(void){

	for(uint8_t i=0;i<9;i++)
		Camera_OV7670_I2C_WrReg(resolVGARGBMode[i][0],resolVGARGBMode[i][1]);
	for(uint8_t i=0;i<9;i++)
		PRINTF("0x%X ",Camera_OV7670_I2C_RdReg(resolVGARGBMode[i][0]));
	PRINTF("\n");

}

void Camera_ov7670_ResolQVGAProcessedBayerRGBMode(void){

	for(uint8_t i=0;i<9;i++)
		Camera_OV7670_I2C_WrReg(resolQVGARProcessedBayerGBMode[i][0],resolQVGARProcessedBayerGBMode[i][1]);
	for(uint8_t i=0;i<9;i++)
		PRINTF("0x%X ",Camera_OV7670_I2C_RdReg(resolQVGARProcessedBayerGBMode[i][0]));
	PRINTF("\n");

}
