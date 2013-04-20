#ifndef _TIMER_HW_H_
#define _TIMER_HW_H_

#include "Types.h"
#include <pic.h>

/*  TIMER0
  Parametri:
  FOSC  - frecventa procesorului in MHz, de tip float (ex. 10.0 )
  PERIOD  - perioada generarii intreruperilor de la timer0 in microsecunde
  PRESCALER - poate lua valorile 1, 2, 4, 8, 16, 32, 64, 128 sau 256
        valoarea 1 se foloseste in cazul in care prescalerul este asignat la WDT
*/
#define TMR0_SETTING(PERIOD,PRESCALER,FOSC,NR_INSTR)  (unsigned char)(256.0-((PERIOD-NR_INSTR*4/FOSC)*FOSC)/(PRESCALER*4.0))

#define  T0_CS_EXTERNAL    0x3F
#define  T0_CS_INTERNAL    0x1F
#define  T0_EDGE_HL        0x3F
#define  T0_EDGE_LH        0x2F
#define  T0_PS_WDT         0x3F
#define  T0_PS_TMR0        0x37
#define  T0_PRESCALER_2    0x38
#define  T0_PRESCALER_4    0x39
#define  T0_PRESCALER_8    0x3A
#define  T0_PRESCALER_16   0x3B
#define  T0_PRESCALER_32   0x3C
#define  T0_PRESCALER_64   0x3D
#define  T0_PRESCALER_128  0x3E
#define  T0_PRESCALER_256  0x3F

#define  config_int_timer0()  T0IF=0;T0IE=1
#define  stop_int_timer0()    T0IE=0;T0IF=0
#define  open_timer0(x)       TMR0=0;{unsigned char __TMR0_TMP;__TMR0_TMP=0xC0&OPTION;OPTION=__TMR0_TMP|(x);}
#define  close_timer0()       (TMR0=0,T0IE=0,T0IF=0)
#define  read_timer0()        TMR0
#define  write_timer0(x)      TMR0=(x)
#define  overflow_timer0      T0IF


/*  TIMER1
  Parametri:
  FOSC  - frecventa procesorului in MHz, de tip float (ex. 10.0 )
  PERIOD  - perioada generarii intreruperilor de la timer1 in usecunde
  PRESCALER - poate lua valorile 1, 2, 4 sau 8
*/
#define TMR1H_SETTING(PER,PRESC,FOSC,NR_INSTR)  (unsigned char)(((unsigned int)(TMR1_SETTING(PER,PRESC,FOSC,NR_INSTR)))>>8)
#define TMR1L_SETTING(PER,PRESC,FOSC,NR_INSTR)  (unsigned char)(((unsigned int)(TMR1_SETTING(PER,PRESC,FOSC,NR_INSTR)))&0xFF)
#define TMR1_SETTING(PERIOD,PRESCALER,FOSC,NR_INSTR)  (unsigned int)(65536.0-((PERIOD-4.0*NR_INSTR/FOSC)*FOSC)/(PRESCALER*4.0))

#define  TIMER1_ON         0xFF
#define  TIMER1_OFF        0xFE
#define  T1_PRESCALER_1    0xCF
#define  T1_PRESCALER_2    0xDF
#define  T1_PRESCALER_4    0xEF
#define  T1_PRESCALER_8    0xFF
#define T1_OSC_EN          0xFF
#define T1_OSC_DIS         0xF7
#define  T1_CK_ASYNC       0xFF
#define  T1_CK_SYNC        0xFB
#define  T1_CS_EXTERNAL    0xFF
#define  T1_CS_INTERNAL    0xFD

#define  config_int_timer1()  TMR1IF=0;TMR1IE=1
#define  stop_int_timer1()    TMR1IE=0;TMR1IF=0
#define  stop_timer1()        (T1CON&=TIMER1_OFF)
#define  start_timer1()       (T1CON|=(~TIMER1_OFF))
#define  open_timer1(x)       TMR1L=0;TMR1H=0;T1CON=(x)
#define  close_timer1()       T1CON=0;TMR1IE=0;TMR1IF=0
#define read_timer1h()        TMR1H
#define read_timer1l()        TMR1L
//#define read_timer1()        ((unsigned int)((TMR1H<<8)|TMR1L))
#define write_timer1(x)       ((TMR1L=(unsigned char)(((unsigned int)(x))&0xFF)),(TMR1H=(unsigned char)(((unsigned int)(x))>>8)))
#define write_timer1h(x)      TMR1H=(x)
#define write_timer1l(x)      TMR1L=(x)
#define  overflow_timer1      TMR1IF
/*
#pragma inline read_timer1
unsigned int read_timer1(void)
{
  unsigned char temp_H, temp_L;
  temp_H = TMR1H;
  temp_L = TMR1L;
  if(temp_H != TMR1H)
    temp_H = TMR1H;
  return ((unsigned int)( (temp_H<<8)|temp_L)  );
}*/

//extern unsigned int read_timer1(void);

/*  TIMER2
  Parametri:
  FOSC  - frecventa procesorului in MHz, de tip float (ex. 10.0 )
  PERIOD  - perioada generarii intreruperilor de la timer2 in usecunde
  PRESCALER - poate lua valorile 1, 4 sau 16
  POSTSCALER- poate lua valori de la 1 la 16
*/
#define PR2_SETTING(PER,PRESCALER,POSTSCALER,FOSC)  (unsigned char)(((FOSC*PER)/(4.0*PRESCALER*POSTSCALER))-1)

#define  TIMER2_ON          0xFF
#define  TIMER2_OFF         0xFB

#define  T2_PRESCALER_1     0xFC
#define  T2_PRESCALER_4     0xFD
#define  T2_PRESCALER_16    0xFE

#define  T2_POSTSCALER_1    0x87
#define  T2_POSTSCALER_2    0x8F
#define  T2_POSTSCALER_3    0x97
#define  T2_POSTSCALER_4    0x9F
#define  T2_POSTSCALER_5    0xA7
#define  T2_POSTSCALER_6    0xAF
#define  T2_POSTSCALER_7    0xB7
#define  T2_POSTSCALER_8    0xBF
#define  T2_POSTSCALER_9    0xC7
#define  T2_POSTSCALER_10   0xCF
#define  T2_POSTSCALER_11   0xD7
#define  T2_POSTSCALER_12   0xDF
#define  T2_POSTSCALER_13   0xE7
#define  T2_POSTSCALER_14   0xEF
#define  T2_POSTSCALER_15   0xF7
#define  T2_POSTSCALER_16   0xFF

#define  config_int_timer2()  TMR2IF=0;TMR2IE=1
#define  stop_int_timer2()    TMR2IE=0;TMR2IF=0
#define  open_timer2(period,settings)  PR2=(period);T2CON=(settings)
#define  close_timer2()       PR2=0xFF;T2CON=0;TMR2IE=0;TMR2IF=0
#define read_timer2()         TMR2
#define write_timer2(x)       TMR2=(x)
#define  stop_timer2()        T2CON&=TIMER2_OFF
#define  start_timer2()       T2CON|=(~TIMER2_OFF)
#define  set_pr2_timer2(x)    PR2=(x)

#endif//  _TIMER_HW_H_

