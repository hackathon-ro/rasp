#ifndef _TIME_H_
#define _TIME_H_

#include "TimerHw.h"

#define TMR2_ISR() {if(TMR2IF){TMR2IF=0;TimerIsr();}}


// fclock in MHz in float format ex: 4.0 means 4 MHz
#define  TimeInit(fclock)  TimerInitialize(PR2_SETTING(2501/3,4,2,fclock), T2_PRESCALER_4 & T2_POSTSCALER_2)

extern void     TimerInitialize(uint8_t pr2_Setting, uint8_t tmr2_Setting);
extern void     TimerIsr(void);

#endif /* _TIME_H_ */
