/******************************************************
*                                                     *
*    Timer driver for PIC16 MCU                       *
*                                                     *
*     Author : Virgil Capel                           *
*                                                     *
******************************************************/
#include "types.h"
#include "time.h"
#include "TimerHw.h"
#include "interrupts.h"

extern void Time833us(void);
extern void Time1s(void);

/*****************************************************/
void TimerInitialize(uint8_t pr2_Setting, uint8_t tmr2_Setting)
{
  open_timer2(pr2_Setting, tmr2_Setting & TIMER2_ON);
  config_int_timer2();
  IntGlobalEnable();
}

/*****************************************************/
// get here every 833.3333 us
void     TimerIsr(void)
{
  static  uint8_t counter = 12, counter2 = 100;
  counter--;
  Time833us();
  if(counter == 0)
  {
    counter = 12;
    counter2--;
    if(counter2 == 0)
    {
      counter2 = 100;
      Time1s();
    }
  }
}

/*****************************************************/

