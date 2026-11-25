#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

namespace Inter {

	extern volatile uint8_t locked;
	extern volatile uint8_t trigger;
	extern volatile uint8_t count;

	void inputport();
	void interrupt_init();
	void delay_ms_long(volatile uint16_t ms);
	void counter();
	void Sensor();
}

#endif