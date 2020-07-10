/*
 * ov7670.h
 *
 *  Created on: 4 jul. 2020
 *      Author: Dell-i3
 */

#ifndef OV7670_OV7670_H_
#define OV7670_OV7670_H_


#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_debug_console.h"



uint8_t read_byte_port(void);
uint8_t Camera_OV7670_I2C_WrReg(uint8_t cmd,uint8_t dt);
uint8_t Camera_OV7670_I2C_RdReg(uint8_t cmd);
void Camera_VGA_Frame(uint32_t* coord);
void Camera_ov7670_ResolVGA(void);
void Camera_ov7670_ResolVGARGBMode(void);

#endif /* OV7670_OV7670_H_ */
