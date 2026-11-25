#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Sensor.h"

namespace Inter {

	volatile uint8_t locked  = 0;
	volatile uint8_t trigger = 0;
	volatile uint8_t count   = 0;

	void inputport()
	{
		DDRE  &= ~(1 << PE5);   // PE5 input
		PORTE |=  (1 << PE5);   // enable pull-up
	}

	void interrupt_init()
	{
		// Falling edge on INT5
		EICRB &= ~(1 << ISC50);
		EICRB |=  (1 << ISC51);

		EIMSK |= (1 << INT5);   // enable INT5
	}

	ISR(INT5_vect)
	{
		if (!locked) {
			trigger = 1;
			locked  = 1;
		}
	}

	void delay_ms_long(volatile uint16_t ms)
	{
		while (ms--) {
			_delay_ms(1);
		}
	}

	void counter()
	{
		count++;
	}

	void Sensor()
	{
		if (trigger) {
			trigger = 0;
			counter();
			delay_ms_long(200);   // realistisk debounce
		}

		// Unlock when sensor is inactive
		if (locked && !(PINE & (1 << PE5))) {
			locked = 0;
		}
	}
}