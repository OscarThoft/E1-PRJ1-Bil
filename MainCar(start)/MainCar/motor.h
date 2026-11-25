#ifndef MOTOR_H
#define MOTOR_H

#include <avr/io.h>

namespace motor {
	void initPB7_PWM();
	void initForward();
	void initBackward();
	void setDutyPB7(uint8_t dutyCycle);
}

#endif