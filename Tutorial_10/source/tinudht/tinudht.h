/**
 * TinuDHT - Library for the DHT11 temperature/humidity sensors
 *
 * @author Neven Boyanov
 *
 * This is part of the Tinusaur/TinuDHT project.
 *
 * Copyright (c) 2018 Neven Boyanov, The Tinusaur Team. All Rights Reserved.
 * Distributed as open source software under MIT License, see LICENSE.txt file.
 * Retain in your source code the link http://tinusaur.org to the Tinusaur project.
 *
 * Source code available at: https://bitbucket.org/tinusaur/tinudht
 *
 */

#ifndef TINUDHT_H
#define TINUDHT_H

// ----------------------------------------------------------------------------
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include <stdint.h>

// ----------------------------------------------------------------------------

#define TINUDHT_OK					0
#define TINUDHT_ERROR_ACK_TIMEOUT	-1
#define TINUDHT_ERROR_BIT_TIMEOUT	-2
#define TINUDHT_ERROR_CHECKSUM		-3
#define TINUDHT_ACK_TIMEOUT 7680
#define TINUDHT_BITSTART_TIMEOUT 100
#define TINUDHT_BITEND_TIMEOUT 120
#define TINUDHT_BITLEN 80


// ----------------------------------------------------------------------------

typedef union {
	uint8_t data[5];
	struct {
		uint8_t humidity;
		uint8_t hum_dec;
		uint8_t temperature;
		uint8_t temp_dec;
		uint8_t checksum;
	};
} TinuDHT;

// ----------------------------------------------------------------------------

uint8_t tinudht_read(TinuDHT *ptinudht);
void StandardTimer_ms(uint32_t _t);
void StandardTimer_us(uint32_t _t);

// ----------------------------------------------------------------------------

#endif
