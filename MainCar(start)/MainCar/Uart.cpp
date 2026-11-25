#define XTAL 16000000
#pragma once
#include <avr/io.h>
#include <stdlib.h>
#include "uart.h"

namespace UART{	
	
void InitUART(unsigned long Baudrate, unsigned char Databit, unsigned char Rx_Int)
{
	UCSR0B = 0b00011000;
	if(Databit==5){
		UCSR0C = 0b00000000;
		} else if (Databit==6){
		UCSR0C = 0b00000010;
		} else if (Databit==7){
		UCSR0C = 0b00000100;
		} else if (Databit==8){
		UCSR0C = 0b00000110;
		} else {
		UCSR0C = 0b00000110;
	}
	UBRR0 = (XTAL/(16*Baudrate))-1;
	
	if(Rx_Int!=0){
		UCSR0B = 0b10011000;
	}
}

void SendChar(char Tegn)
{
	while(!(UCSR0A & 0b00100000)==1){
	}
	UDR0 = Tegn;
}
}