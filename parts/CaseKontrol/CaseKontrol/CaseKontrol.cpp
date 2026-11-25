#include "motor.h"
#include "Sensor.h"
#define F_CPU 16000000UL
#include <util/delay.h>

namespace MotorSettinghw {

	void MotorSetting()
	{
		Inter::Sensor();

		switch (Inter::count)
		{
			case 0:
			motor::initForward();
			motor::setDutyPB7(0);
			break;

			case 1: //(gentager 32 gange)
			motor::initBackward();
			motor::setDutyPB7(60);
			Inter::delay_ms_long(1000);         // Kører baglæns i 0,5 sek.

			motor::initForward();
			motor::setDutyPB7(60);
			Inter::delay_ms_long(1000);         // NU kører den fremad i 0,5 sekunder, før den "resets"!
			
			motor::initBackward();
			motor::setDutyPB7(0);
			Inter::delay_ms_long(1000);
			break;
			case 2:
			motor::initForward();
			motor::setDutyPB7(0);
			break;
			
			case 3:
			motor::initBackward();
			motor::setDutyPB7(0.75 * 255);
			break;
			
			case 4:
			motor::initForward();
			motor::setDutyPB7(0.75 * 255);
			break;
			
			case 5:
			motor::initBackward();
			motor::setDutyPB7(0.75 * 255);
			break;

			case 6:
			motor::initForward();
			motor::setDutyPB7(0.75 * 255);
			break;
			
			case 7:
			motor::initBackward();
			motor::setDutyPB7(0.75 * 255);
			break;

			case 8:
			motor::initForward();
			motor::setDutyPB7(0.75 * 255);
			break;

			case 9:
			motor::initBackward();
			motor::setDutyPB7(0.50*255);
			break;

			default:
			break;
		}
	}
}