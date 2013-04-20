/******************************************************
*                                                     *
* Communication console driver over UART for PIC16    *
*                                                     *
*     Author : Virgil Capel                           *
*                                                     *
******************************************************/

#include "console.h"
#include "uart.h"

#define putch(c) UartWriteByte((uint8_t)c)

/*****************************************************/
void ConsoleInitUart(uint8_t BaudSetting, bool_t brgh)
{
	UartConfig_t Config;
	UartOpen();
	Config.Baud = BaudSetting;
	Config.Brgh = brgh;
	UartSetConfig(&Config);
}

/*****************************************************/
void puts(const char *string)
{
    while(*string!='\0')
		putch(*string++);
}

/*****************************************************/

