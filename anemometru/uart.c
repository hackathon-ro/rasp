/******************************************************
*                                                     *
*    UART driver for PIC16 MCU                        *
*                                                     *
*     Author : Virgil Capel                           *
*                                                     *
******************************************************/

#include <pic.h>
#include "uart.h"

/*****************************************************/
void UartOpen(void)
{
	TXSTA = 0x20;
	RCSTA = 0x90;
	SPBRG = 0;
}

/*****************************************************/

void UartWriteByte(uint8_t Data)
{
	while(!TXIF);
	TXREG = Data;
}

/*****************************************************/

void UartSetConfig(UartConfig_t *pUartConfig)
{
	SPBRG = pUartConfig->Baud;
	BRGH =  pUartConfig->Brgh;
}

/*****************************************************/

