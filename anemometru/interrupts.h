#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <pic.h>

#define IntGlobalEnable()  {PEIE=1;GIE=1;}
#define IntGlobalDisable() {GIE=0;GIE=0;}

#endif //_INTERRUPTS_H_
