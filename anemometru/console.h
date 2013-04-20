#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include "Types.h"
#include "uart.h"

#define ConsoleInit(baud,fclock,brgh) ConsoleInitUart((brgh)?BaudCalcH(baud,fclock):BaudCalcL(baud,fclock),brgh)

extern void ConsoleInitUart(uint8_t BaudSetting, bool_t brgh); // returns TRUE if OK
extern void puts(const char *string);

#endif /* _CONSOLE_H_*/

