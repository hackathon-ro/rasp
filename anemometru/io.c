/******************************************************
*                                                     *
*    IO interface for PIC16 MCU                       *
*                                                     *
*     Author : Virgil Capel                           *
*                                                     *
******************************************************/
#include "types.h"
#include "interrupts.h"
#include <pic.h>

extern void SensorInt(void);

/*****************************************************/
void IoInit(void)
{
  INTE = 1;
  IntGlobalEnable();
}

/*****************************************************/

void  IoIsr(void)
{
  SensorInt();
}

/*****************************************************/

