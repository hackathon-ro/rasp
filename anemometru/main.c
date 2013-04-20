/******************************************************
*                                                     *
*    Anemometer                                       *
*    Serial out 4800 8N1    4.9152 Mhz Xtall          *
*    MCU  PIC16F628A                                  *
*                                                     *
*     Author : Capel Virgil                           *
*                                                     *
******************************************************/

// avem trei evenimente: un timer la o secunda, unul la 833us si intreruperea de pe rb0

#include <stdio.h>
#include <pic.h>
#include "console.h"
#include "time.h"
#include "io.h"

typedef unsigned char freq_t;
typedef unsigned int  time_t;

#define DEBOUNCING_TIME 10  // 8-9 ms
#define MAX_TIME     6000 //  x*1200     12000  la  10 sec     sau 36000 la 30 sec
#define MIN_TIME        12  //  100 ms cit de des se apeleaza measure... initial era 10ms
#define TRS_TIME        60  //  50 ms
#define Com_msg       0x01
#define Measure_msg   0x02
#define MeanCoeffT     0.2
#define MeanCoeffF     0.005
#define MEAN_START    1.0

#define MsgGet(x)   (mMsg & x)
#define MsgClean(x)  mMsg&=~x
#define MsgPut(x)    mMsg|=x
#define GetFreq()    mFreq
#define GetTime()    mTime
#define SaveFreq(x)  mFreq=x
#define SaveTime(x)  mTime=x


bank1 static unsigned char mMsg;
bank1 static freq_t mFreq, counterFreq;
static time_t mTime, counterTime;
static unsigned char mDebouncingTime;

static char flagstop;

char* Measure(freq_t, time_t);

/**************************************************************/

void main(void)
{
  char * pStr;
  IoInit();
  TimeInit(4.9152);
  ConsoleInit(4800,4915200,1);
	
	flagstop=0;

  //puts("\n\r Anemometer v0.1\n\r");
  for(;;)
  {
    if(MsgGet(Measure_msg))
    {
      MsgClean(Measure_msg);
      pStr = Measure(GetFreq(), GetTime());
    }

    if(MsgGet(Com_msg))
    {
      MsgClean(Com_msg);
      puts(pStr);

		
    }
  }
}

/**************************************************************/




//fara medie
char* Measure(freq_t freq, time_t time)
{
  bank1 static char string[20];
  float fTemp1, fTemp2;
 // fTemp1 = (float)freq;
  	fTemp1= 1200.0/(float)time;
	fTemp2 = 0.8333333*(float)time;
//	fTemp1= 1000.0/(float)fTemp2;

 // sprintf(string, "%2.1f Hz %5.1f ms\n\r", fTemp1, fTemp2);


if (fTemp2>0)
{   if(fTemp2<5000) 
		{
		if(flagstop<5)
			{
  				sprintf(string, "%2.2f Hz ,%5.2f ms \n\r",fTemp1,fTemp2);
 			}
		else sprintf(string, "No wind \n\r" );
		}
	else sprintf(string, "No wind \n\r" );

}
else sprintf(string, "No wind \n\r" ); 

 

return &string[0];
}


/*


// cu medie
char* Measure(freq_t freq, time_t time)
{
  bank1 static char string[30];
  float fTemp, MeanCoeff;
  static float fMean = MEAN_START;
  if(time < TRS_TIME)
  {
    fTemp = (float)freq;
    MeanCoeff = MeanCoeffF;
  }
  else
  {
    fTemp = 1200.0/(float)time;
    MeanCoeff = MeanCoeffT;
  }
  fMean = MeanCoeff*fTemp + (1.0-MeanCoeff)*fMean;
 // sprintf(string, "%2.1f Hz\n\r", fMean);

//if (time>0)   if(time<MAX_TIME) if (fMean!=0)
{
  sprintf(string, "%2.1f Hz ,%5.1f ms \n\r",fMean,time*0.83333);
 }

//else sprintf(string, "No wind \n\r" );
 
  return &string[0];
}
*/
/**************************************************************/

// Aici intru la fiecare intrerupere de la senzor
void SensorInt(void)
{
  if(mDebouncingTime == 0)
  {
    mDebouncingTime = DEBOUNCING_TIME;
    counterFreq++;
    SaveTime(counterTime);
    counterTime = 0;
	flagstop=0;
    if(GetTime() > MIN_TIME) // minimum time interval pentru apelare Measure()
      MsgPut(Measure_msg); // send message to main to process time info

	
  }
}

/**************************************************************/

// Aici intru de la timer interrupt la 833 us time interval
void Time833us(void)
{
  if(mDebouncingTime != 0)
    mDebouncingTime--;
  if(counterTime <= MAX_TIME)
    counterTime++; 
}

/**************************************************************/

// sint apelat de timer interrupt la 1 s time interval
void Time1s(void)
{
  SaveFreq(counterFreq);
  counterFreq = 0;
  flagstop++;	
  MsgPut(Measure_msg); // send message to main (sa proceseze masuratoarea)
  MsgPut(Com_msg);  // send message to main (sa trimita info)
}

/**************************************************************/


