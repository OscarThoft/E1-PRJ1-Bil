#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

namespace Inter {

	volatile uint8_t locked  = 0;
	volatile uint8_t trigger = 0;
	volatile uint8_t count   = 0;

	// -----------------------------
	// Configure PE5 + PE4 as inputs
	// -----------------------------
	void inputport()
	{
		DDRE  &= ~((1 << PE5) | (1 << PE4));   // inputs
		PORTE |=  ((1 << PE5) | (1 << PE4));   // pull-ups
	}

	// -----------------------------
	// Configure INT4 + INT5
	// Both falling edge
	// -----------------------------
	void interrupt_init()
	{
		// INT4: ISC41=1, ISC40=0
		// INT5: ISC51=1, ISC50=0
		EICRB &= ~((1 << ISC40) | (1 << ISC50));   // clear low bits
		EICRB |=  ((1 << ISC41) | (1 << ISC51));   // set high bits

		EIMSK |= (1 << INT4) | (1 << INT5);        // enable both
	}

	// -----------------------------
	// INT5 ISR
	// -----------------------------
	ISR(INT5_vect)
	{
		if (!locked) {
			trigger = 1;
			locked  = 1;
		}
	}

	// -----------------------------
	// INT4 ISR
	// -----------------------------
	ISR(INT4_vect)
	{
		if (!locked) {
			trigger = 1;
			locked  = 1;
		}
	}

	// -----------------------------
	// Long delay (safe)
	// -----------------------------
	void delay_ms_long(volatile uint16_t ms)
	{
		while (ms--) {
			_delay_ms(1);
		}
	}

	// -----------------------------
	// Counter
	// -----------------------------
	void counter()
	{
		count++;
	}

	// -----------------------------
	// Main sensor logic
	// -----------------------------
	void Sensor()
	{
		if (trigger) {
			trigger = 0;
			counter();
			delay_ms_long(200);   // debounce
		}

		// Unlock when BOTH sensors return HIGH (inactive)
		if (locked && (PINE & ((1 << PE5) | (1 << PE4)))) {
			locked = 0;
		}
	}
}