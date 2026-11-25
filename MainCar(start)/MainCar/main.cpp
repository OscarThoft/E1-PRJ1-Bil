#include <avr/io.h>
#include <avr/interrupt.h>

#include "Sensor.h"
#include "motor.h"
#include "case.h"
#include "uart.h"
#include "Lyd.h"

volatile uint8_t count = 0;   // actual definition

namespace MotorSettinghw
{
	void counter(void)
	{
		count += 1;
	}

	
	void Sensor(void)
	{
		if (Inter::trigger)
		{
			Inter::trigger = 0;
			counter();
			Inter::delay_ms_long(5000);
		}

		// If locked AND sensor shows "no signal", unlock
		if (Inter::locked && !(PINE & ((1 << PE5) | (1 << PE4))))
		{
			Inter::locked = 0;
		}
	}
}

int main(void)
{
	Inter::inputport();
	Inter::interrupt_init();
	motor::initPB7_PWM();
	sei();

	while (1)
	{
		MotorSettinghw::MotorSetting();
	}
}
