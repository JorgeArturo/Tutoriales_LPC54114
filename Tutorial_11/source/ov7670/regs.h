/*
 * regs.h
 *
 *  Created on: 4 jul. 2020
 *      Author: Dell-i3
 */

#ifndef OV7670_REGS_H_
#define OV7670_REGS_H_

#define FreqMax	24000000

#define CAM_ADDR	0x21

#define REG_RSVD	0xFF
/*
uint8_t Ov7670Regis[][] = {{REG_GAIN,0},
							{REG_BLUE,0},
							{REG_RED,0},
							{REG_VREF,0},
							{REG_COM1,0},
							{REG_BAVE,0},
							{REG_GbAVE,0},
							{REG_GbAVE,0},
							{REG_AECHH,0},
							{REG_RAVE,0},
							{REG_COM2,0},
							{REG_PID,0},
							{REG_VER,0},
							{REG_COM3,0},
							{REG_COM4,0},
							{REG_COM5,0},
							{REG_COM6,0},
							{REG_AECH,0},
							{REG_CLKRC,0},
							{REG_COM7,0},
							{REG_COM8,0},
							{REG_COM9,0},
							{REG_COM10,0},
							{REG_RSVD,0},
							{REG_HSTART,0},
							{REG_HSTOP,0},
							{REG_VSTART,0},
							{REG_VSTOP,0},
							{REG_PSHFT,0},
							{REG_MIDH,0},
							{REG_MIDL,0},
							{REG_MVFP,0},
							{REG_RSVD,0},
							{REG_ADCCTR0,0},
							{REG_ADCCTR1,0},
							{REG_ADCCTR2,0},
							{REG_ADCCTR3,0},
							{REG_AEW,0},
							{REG_AEB,0},
							{REG_VPT,0},
							{REG_BBIAS,0},
							{REG_GbBIAS,0},
							{REG_RSVD,0},
							{REG_EXHCH,0},
							{REG_EXHCL,0},
							{REG_RBIAS,0},
							{REG_ADVFL,0},
							{REG_ADVFH,0},
							{REG_YAVE,0},
							{REG_HSYST,0},
							{REG_HSYEN,0},
							{REG_HREF,0},
							{REG_CHLF,0},
							{REG_ARBLM,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_ADC,0},
							{REG_ACOM,0},
							{REG_OFON,0},
							{REG_TSLB,0},
							{REG_COM11,0},
							{REG_COM12,0},
							{REG_COM13,0},
							{REG_COM14,0},
							{REG_EDGE,0},
							{REG_COM15,0},
							{REG_COM16,0},
							{REG_COM17,0},
							{REG_AWBC1,0},
							{REG_AWBC2,0},
							{REG_AWBC3,0},
							{REG_AWBC4,0},
							{REG_AWBC5,0},
							{REG_AWBC6,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_REG4B,0},
							{REG_DNSTH,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_MTX1,0},
							{REG_MTX2,0},
							{REG_MTX3,0},
							{REG_MTX4,0},
							{REG_MTX5,0},
							{REG_MTX6,0},
							{REG_BRIGHT,0},
							{REG_CONTRAS,0},
							{REG_CONTRAS_CENTER,0},
							{REG_MTXS,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_RSVD,0},
							{REG_RSVD,0},


};
/*
/* Registers */
#define REG_GAIN    0x00  /* Gain lower 8 bits (rest in vref) */
#define REG_BLUE    0x01  /* blue gain */
#define REG_RED     0x02  /* red gain */
#define REG_VREF    0x03  /* Pieces of GAIN, VSTART, VSTOP */
#define REG_COM1    0x04  /* Control 1 */
#define REG_BAVE    0x05  /* U/B Average level */
#define REG_GbAVE   0x06  /* Y/Gb Average level */
#define REG_AECHH   0x07  /* AEC MS 5 bits */
#define REG_RAVE    0x08  /* V/R Average level */
#define REG_COM2    0x09  /* Control 2 */
#define REG_PID		0x0a  /* Product ID MSB */
#define REG_VER		0x0b  /* Product ID LSB */
#define REG_COM3    0x0c  /* Control 3 */
#define REG_COM4    0x0d  /* Control 4 */
#define REG_COM5    0x0e  /* All "reserved" */
#define REG_COM6    0x0f  /* Control 6 */
#define REG_AECH    0x10  /* More bits of AEC value */
#define REG_CLKRC   0x11  /* Clocl control */
#define REG_COM7    0x12  /* Control 7 */ //REG mean address.
#define REG_COM8    0x13  /* Control 8 */
#define REG_COM9    0x14  /* Control 9- gain ceiling */
#define REG_COM10   0x15  /* Control 10 */
//RSVD
#define REG_HSTART	0x17  /* Horiz start high bits */
#define REG_HSTOP   0x18  /* Horiz stop high bits */
#define REG_VSTART	0x19  /* Vert start high bits */
#define REG_VSTOP   0x1a  /* Vert stop high bits */
#define REG_PSHFT   0x1b  /* Pixel delay after HREF */
#define REG_MIDH    0x1c  /* Manuf. ID high */
#define REG_MIDL    0x1d  /* Manuf. ID low */
#define REG_MVFP    0x1e  /* Mirror / vflip */
//RSVD
#define REG_ADCCTR0	0x20
#define REG_ADCCTR1	0x21
#define REG_ADCCTR2	0x22
#define REG_ADCCTR3	0x23
#define REG_AEW     0x24  /* AGC upper limit */
#define REG_AEB     0x25    /* AGC lower limit */
#define REG_VPT     0x26  /* AGC/AEC fast mode op region */
#define REG_BBIAS	0x27
#define REG_GbBIAS	0x28
//RSVD
#define REG_EXHCH	0x2a
#define REG_EXHCL	0x2b
#define REG_RBIAS	0x2c
#define REG_ADVFL	0x2d
#define REG_ADVFH	0x2e
#define REG_YAVE	0x2f
#define REG_HSYST   0x30  /* HSYNC rising edge delay */
#define REG_HSYEN   0x31  /* HSYNC falling edge delay */
#define REG_HREF    0x32  /* HREF pieces */
#define REG_CHLF	0x33
#define REG_ARBLM	0x34
//RSVD
//RSVD
#define REG_ADC		0x37
#define REG_ACOM	0x38
#define REG_OFON	0x39
#define REG_TSLB    0x3a  /* lots of stuff */
#define REG_COM11   0x3b  /* Control 11 */
#define REG_COM12   0x3c  /* Control 12 */
#define REG_COM13   0x3d  /* Control 13 */
#define REG_COM14   0x3e  /* Control 14 */
#define REG_EDGE    0x3f  /* Edge enhancement factor */
#define REG_COM15   0x40  /* Control 15 */
#define REG_COM16   0x41  /* Control 16 */
#define REG_COM17   0x42  /* Control 17 */
#define REG_AWBC1	0x43
#define REG_AWBC2	0x44
#define REG_AWBC3	0x45
#define REG_AWBC4	0x46
#define REG_AWBC5	0x47
#define REG_AWBC6	0x48
//RSVD
//RSVD
#define REG_REG4B	0x4B
#define REG_DNSTH	0x4C
//RSVD
//RSVD
#define REG_MTX1  0x4f
#define REG_MTX2  0x50
#define REG_MTX3  0x51
#define REG_MTX4  0x52
#define REG_MTX5  0x53
#define REG_MTX6  0x54
#define REG_BRIGHT	0x55
#define REG_CONTRAS	0x56
#define REG_CONTRAS_CENTER	0x57
#define REG_MTXS	0x58
//RSVD 9
//RSVD A
//RSVD B
//RSVD C
//RSVD D
//RSVD E
//RSVD F
//RSVD 0
//RSVD 1
#define REG_LCC1	0x62
#define REG_LCC2	0x63
#define REG_LCC3	0x64
#define REG_LCC4	0x65
#define REG_LCC5	0x66
#define REG_MANU	0x67
#define REG_MANV	0x68
#define REG_GFIX    0x69  /* Fix gain control */
#define REG_GGAIN	0x6a
#define REG_DBLV	0x6b
#define REG_AWBCTR3	0x6c
#define REG_AWBCTR2	0x6d
#define REG_AWBCTR1	0x6e
#define REG_AWBCTR0	0x6f
#define SCALING_XSC	0x70
#define SCALING_YSC 0x71
#define SCALING_DCWCTR 0x72
#define SCALING_PCLK_DIV 0x73
#define REG_REG74	0x74
#define REG_REG75	0x75
#define REG_REG76	0x76
#define REG_REG77	0x77
//RSVD
//RSVD
#define REG_GAM1	0x7a
#define REG_GAM2	0x7b
#define REG_GAM3	0x7c
#define REG_GAM4	0x7d
#define REG_GAM5	0x7e
#define REG_GAM6	0x7f
#define REG_GAM7	0x80
#define REG_GAM8	0x81
#define REG_GAM9	0x82
#define REG_GAM10	0x83
#define REG_GAM11	0x84
#define REG_GAM12	0x85
#define REG_GAM13	0x86
#define REG_GAM14	0x87
#define REG_GAM15	0x88
#define REG_GAM16	0x89
//RSVD A
//RSVD B
//RSVD C
//RSVD D
//RSVD E
//RSVD F
//RSVD 0
//RSVD 1
#define REG_DMLNL	0x92
#define REG_DMLNH	0x93
#define REG_LCC6	0x94
#define REG_LCC7	0x95
//RSVD 6
//RSVD 7
//RSVD 8
//RSVD 9
//RSVD a
//RSVD b
//RSVD c
#define REG_BD50ST	0x9d
#define REG_BD60ST	0x9e
#define REG_HRL		0x9f
#define REG_LRL		0xa0
#define REG_DSP3	0xa1
#define REG_SCALING_PCLK_DELAY	0xa2
//RSVD 3
//RSVD 4
//RSVD 5
//RSVD 6
//RSVD 7
//RSVD 8
//RSVD 9
//RSVD A
//RSVD B
#define REG_STR_OPT	0xac
#define REG_STR_R	0xad
#define REG_STR_G	0xae
#define REG_STR_B	0xaf
//RSVD
//RSVD
//RSVD
#define REG_THL_ST	0xb3
//RSVD
#define	REG_THL_DLT	0xb5
//RSVD 6
//RSVD 7
//RSVD 8
//RSVD 9
//RSVD a
//RSVD b
//RSVD c
//RSVD d
#define REG_ADCHB	0xbe
#define REG_ADCHR	0xbf
#define REG_ADCHGb	0xc0
#define REG_ADCHGr	0xc1
//RSVD
//RSVD
//RSVD
//RSVD
//RSVD
//RSVD
//RSVD
#define REG_STCTR 0xc9

#define pgm_read_byte(addr) (*(const unsigned char *)(addr))

#endif /* OV7670_REGS_H_ */
