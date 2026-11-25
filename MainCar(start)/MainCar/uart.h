#include <avr/io.h>
#include <util/delay.h>
namespace UART{
void InitUART(unsigned long Baudrate, unsigned char Databit, unsigned char Rx_Int);
void SendChar(char Tegn);
}
