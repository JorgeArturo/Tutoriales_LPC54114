/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2020
 * Generated linker script file for LPC54114J256
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.23
 * MCUXpresso IDE v11.1.1 [Build 3241] [2020-03-02] on 8/06/2020 04:17:37 PM
 */

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x40000 /* 256K bytes (alias Flash) */  
  SRAM1 (rwx) : ORIGIN = 0x20010000, LENGTH = 0x10000 /* 64K bytes (alias RAM) */  
  SRAM0 (rwx) : ORIGIN = 0x20000000, LENGTH = 0x10000 /* 64K bytes (alias RAM2) */  
  SRAMX (rwx) : ORIGIN = 0x4000000, LENGTH = 0x8000 /* 32K bytes (alias RAM3) */  
  SRAM2 (rwx) : ORIGIN = 0x20020000, LENGTH = 0x8000 /* 32K bytes (alias RAM4) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH = 0x0  ; /* PROGRAM_FLASH */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_PROGRAM_FLASH = 0x0 + 0x40000 ; /* 256K bytes */  
  __top_Flash = 0x0 + 0x40000 ; /* 256K bytes */  
  __base_SRAM1 = 0x20010000  ; /* SRAM1 */  
  __base_RAM = 0x20010000 ; /* RAM */  
  __top_SRAM1 = 0x20010000 + 0x10000 ; /* 64K bytes */  
  __top_RAM = 0x20010000 + 0x10000 ; /* 64K bytes */  
  __base_SRAM0 = 0x20000000  ; /* SRAM0 */  
  __base_RAM2 = 0x20000000 ; /* RAM2 */  
  __top_SRAM0 = 0x20000000 + 0x10000 ; /* 64K bytes */  
  __top_RAM2 = 0x20000000 + 0x10000 ; /* 64K bytes */  
  __base_SRAMX = 0x4000000  ; /* SRAMX */  
  __base_RAM3 = 0x4000000 ; /* RAM3 */  
  __top_SRAMX = 0x4000000 + 0x8000 ; /* 32K bytes */  
  __top_RAM3 = 0x4000000 + 0x8000 ; /* 32K bytes */  
  __base_SRAM2 = 0x20020000  ; /* SRAM2 */  
  __base_RAM4 = 0x20020000 ; /* RAM4 */  
  __top_SRAM2 = 0x20020000 + 0x8000 ; /* 32K bytes */  
  __top_RAM4 = 0x20020000 + 0x8000 ; /* 32K bytes */  
