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

// ----------------------------------------------------------------------------

#include "tinudht.h"

// ----------------------------------------------------------------------------



// ----------------------------------------------------------------------------

uint8_t tinudht_read(TinuDHT *ptinudht) {

	uint32_t timeout = 0;
	gpio_pin_config_t gpio_pin;
	uint8_t bit_index = 7;
	uint8_t data_index = 0;
	uint8_t data_byte = 0;
	uint8_t checksum = 0;	// NOTE: Should change to 16-bit.
	uint32_t len = 0;

	//uint32_t timeouts[40];

	// Send request to DHT11


	gpio_pin.outputLogic = false;					// Set line to LO
	gpio_pin.pinDirection = kGPIO_DigitalOutput;	// Set port as output

	GPIO_PinInit(BOARD_DHT11_Sensor_GPIO, BOARD_DHT11_Sensor_PORT, BOARD_DHT11_Sensor_PIN, &gpio_pin);

	StandardTimer_ms(18);	// Keep line to LO for 18 mS
	// Pull to HI and wait for response
	GPIO_PortSet(BOARD_DHT11_Sensor_GPIO, BOARD_DHT11_Sensor_PORT, 1U << BOARD_DHT11_Sensor_PIN); // Set to 1, internal pull-up. (optional)

	StandardTimer_us(20);	// Wait 20 uS for response

	// Setup pin as input, pulls to HI and wait for response

	gpio_pin.outputLogic = true;				// Set to 1, internal pull-up. (optional)
	gpio_pin.pinDirection = kGPIO_DigitalInput;	// Set port as input

	GPIO_PinInit(BOARD_DHT11_Sensor_GPIO, BOARD_DHT11_Sensor_PORT, BOARD_DHT11_Sensor_PIN, &gpio_pin);
	// Acknowledge from DHT11
	// NOTE: the timeout should be the equivalent of ~ 80 uS
	timeout = TINUDHT_ACK_TIMEOUT;

	while(!GPIO_PinRead(BOARD_DHT11_Sensor_GPIO, BOARD_DHT11_Sensor_PORT, BOARD_DHT11_Sensor_PIN)){	// Wait for LO-to-HI

		if (--timeout == 0)
			return TINUDHT_ERROR_ACK_TIMEOUT;

	}
	timeout = TINUDHT_ACK_TIMEOUT;

	while(GPIO_PinRead(BOARD_DHT11_Sensor_GPIO, BOARD_DHT11_Sensor_PORT, BOARD_DHT11_Sensor_PIN)){	// Wait for HI-to-LO

		if (--timeout == 0)
			return TINUDHT_ERROR_ACK_TIMEOUT;

	}


	// Read the data - 40 bits (5 bytes),
	for (uint8_t i = 0; i < 40; i++) {

		// Wait for the bit start
		// NOTE: the timeout should be the equivalent of ~ 50 uS
		timeout = 0;

		while(!GPIO_PinRead(BOARD_DHT11_Sensor_GPIO, BOARD_DHT11_Sensor_PORT, BOARD_DHT11_Sensor_PIN)){	// Wait for LO-to-HI

			if (timeout == TINUDHT_BITSTART_TIMEOUT)
				return TINUDHT_ERROR_BIT_TIMEOUT;

			timeout++;
		}

		// Wait for the bit end
		// NOTE: the timeout should be the equivalent of ~ 70 uS
		timeout = 0;
		len = 0;

		while(GPIO_PinRead(BOARD_DHT11_Sensor_GPIO, BOARD_DHT11_Sensor_PORT, BOARD_DHT11_Sensor_PIN)){	// Wait for HI-to-LO

			if (timeout == TINUDHT_BITEND_TIMEOUT)
				return TINUDHT_ERROR_BIT_TIMEOUT;
			else if(timeout >= TINUDHT_BITLEN)
				len = 1;

			timeout++;

		}
		//timeouts[i] = timeout;
		//
		// Determine the bit value

		data_byte = (data_byte << 1); // Shift left to make space for the next bit.

		if (len) data_byte |= 1; // Add a "1" at the end. Otherwise it will remain a "0".

		if (bit_index == 0) {	// Next byte?

			ptinudht->data[data_index] = data_byte;	// Store next byte to the data array.
			//PRINTF("%u\r\n",data_byte);
			if (data_index < 4) checksum += data_byte;	// Add next byte to the checksum.

			data_index++;	// Next byte.
			bit_index = 7;	// Restart at MSB
			data_byte = 0;	// Clear

		} else bit_index--;
	}
	//checksum &= 0xff; // NOTE: Uncomment this after changing checksum to 16-bit.
	// NOTE: On DHT11 data[1],data[3] are always zero so not used.
	if (ptinudht->checksum != checksum) return TINUDHT_ERROR_CHECKSUM;
	//PRINTF("%u,%u\r\n",ptinudht->checksum,checksum);
	//for(uint8_t i=0;i<40;i++) PRINTF("t[%u] = %u\r\n",i,timeouts[i]);
	return TINUDHT_OK;
}


void StandardTimer_ms(uint32_t _t){


	// 1  / 96 Mhz = 10.416 nS = 1 ms =  96006 ticks
	uint32_t ticks = _t * 96006;

	while(ticks--);


}

void StandardTimer_us(uint32_t _t){

	// 1 / 96 Mhz = 10.416 nS = 1 us = 96 ticks

	uint32_t ticks = _t * 96;

	while(ticks--);


}
