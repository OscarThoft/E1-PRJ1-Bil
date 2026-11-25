#include "motor.h"
#include "Sensor.h"
#include "uart.h"
#include "Lyd.h"
#define F_CPU 16000000UL
#include <util/delay.h>

namespace MotorSettinghw {

	void MotorSetting()
	{	
		UART::InitUART(9600,8,1);
		Lyd::startLyd();
		Inter::Sensor();

		switch (Inter::count)
		{
			case 0:
			motor::setDutyPB7(80);
			Inter::delay_ms_long(500);
			break;

			case 1: //(gentager 32 gange)
			Lyd::spilLyd(0x01);
			motor::setDutyPB7(100);
			break;
			
			case 2:
			motor::initForward();
			motor::setDutyPB7(200);
			break;
			
			case 3:
			motor::setDutyPB7(50);
			Inter::delay_ms_long(500);
			
			motor::initBackward();
			motor::setDutyPB7(190);
			Inter::delay_ms_long(500);
			
			motor::initBackward();
			motor::setDutyPB7(190);
			Inter::delay_ms_long(500);
			
			
			break;
			
			case 4:
			Lyd::spilLyd(0x02);
			motor::initForward();
			motor::setDutyPB7(0);
			break;
			
			case 5:
			motor::initBackward();
			motor::setDutyPB7(0.75 * 255);
			break;

			case 6:
			motor::initForward();
			motor::setDutyPB7(0);
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
			Lyd::spilLyd(0x03);
			break;

			default:
			break;
		}
	}
}