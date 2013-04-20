#include <pic.h>
#include "time.h"
#include "io.h"

#define ISR_Header static void interrupt ISR_function(void){
#define ISR_Footer }

ISR_Header
#ifdef CCP1_ISR
CCP1_ISR();
#endif // CCP1_ISR
#ifdef CCP2_ISR
CCP2_ISR();
#endif // CCP2_ISR
#ifdef TMR0_ISR
TMR0_ISR();
#endif // TMR0_ISR
#ifdef TMR1_ISR
TMR1_ISR();
#endif // TMR1_ISR
#ifdef TMR2_ISR
TMR2_ISR();
#endif // TMR2_ISR
#ifdef RBI_ISR
RBI_ISR();
#endif // RBI_ISR
#ifdef INT_ISR
INT_ISR();
#endif // INT_ISR
#ifdef UART_ISR
UART_ISR();
#endif // UART_ISR
#ifdef I2C_ISR
I2C_ISR();
#endif // I2C_ISR
#ifdef ADC_ISR
ADC_ISR();
#endif // ADC_ISR
#ifdef EEF_ISR
EEF_ISR();
#endif // EEF_ISR
ISR_Footer

