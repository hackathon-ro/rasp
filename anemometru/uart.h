#ifndef _UART_H_
#define _UART_H_

/********************************************************************
                Header for UART module library functions
********************************************************************/
#include "types.h"

#define BaudCalcL(baud, fclock)	(uint8_t)(fclock/(baud*64UL)-1)
#define BaudCalcH(baud, fclock)	(uint8_t)(fclock/(baud*16UL)-1)

typedef struct
{
	uint8_t Baud;
  bool_t  Brgh;
} UartConfig_t;

extern void UartOpen(void);
extern void UartWriteByte(uint8_t Data);
extern void UartSetConfig(UartConfig_t *pUartConfig);

#endif /*_UART_H_ */
