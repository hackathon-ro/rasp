#ifndef _IO_H_
#define _IO_H_


#define INT_ISR() {if(INTF){INTF=0;IoIsr();}}


extern void     IoInit(void);
extern void     IoIsr(void);

#endif /* _IO_H_ */
