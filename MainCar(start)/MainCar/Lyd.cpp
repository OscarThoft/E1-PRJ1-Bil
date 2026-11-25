
#include <avr/io.h>
#include <stdlib.h>
#include "Lyd.h"
#include "uart.h"
#pragma once

namespace Lyd{
void startLyd(){
	UART::SendChar(0x7E);
	UART::SendChar(0x06);
	UART::SendChar(0x00); 
	UART::SendChar(0x00);
	UART::SendChar(0x1E); 
	UART::SendChar(0xFF); 
	UART::SendChar(0xDC); 
	UART::SendChar(0xEF);
	
};

void spilLyd(uint8_t lyd){
		UART::SendChar(0x7E);     
		UART::SendChar(0x03);     
		UART::SendChar(0x00);     
		UART::SendChar(0x00);  
		UART::SendChar(lyd);  
		uint16_t test = 0xFFFF - (0x03 + 0x00 + 0x00 + lyd) + 1;
		UART::SendChar(0xFF);
		UART::SendChar(test & 0xFF);    
		UART::SendChar(0xEF);
}
}