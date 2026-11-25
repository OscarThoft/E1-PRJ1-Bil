#ifndef Mot_H
#define Motor_H
#include <math.h>
#include <avr/io.h>


namespace motor {

	// Initialize hardware PWM on PB7 (OC0A)
	void initPB7_PWM() {
		// Set PB7 as output
		DDRB |= (1 << PB7);

		// Fast PWM: WGM01 = 1, WGM00 = 1
		TCCR0A = (1 << WGM01) | (1 << WGM00);

		// Non-inverting mode on OC0A
		TCCR0A |= (1 << COM0A1);

		// Prescaler = 64 ? PWM ? 976 Hz
		TCCR0B = (1 << CS01) | (1 << CS00);

		// Set duty (0–255)
		//round(dutyCycle);
	}

	// Set duty cycle at runtime (0–255)
	void setDutyPB7(uint8_t dutyCycle) {
		OCR0A = dutyCycle;;
	}
	
	void initBackward() {
		DDRL |= (1 << PL3);    // PL3 som output
		PORTL |= (1 << PL3);   // PL3 HIGH
	}

	void initForward() {
		DDRL |= (1 << PL3);    // PL3 som output
		PORTL &= ~(1 << PL3);  // PL3 LOW
	}
	
}

#endif
