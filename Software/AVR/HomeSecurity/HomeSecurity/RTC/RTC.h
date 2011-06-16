#ifndef RTC_H_
#define RTC_H_

#include "../HomeSecurity.h"

void RTC_step(void);
void RTC_init(void);

char not_leap(void);

typedef struct
{ 
	unsigned char second;   //enter the current time, date, month, and year
	unsigned char minute;
	unsigned char hour;                                     
	unsigned char date;       
	unsigned char month;
	unsigned int year;      
} RTC_time;

volatile RTC_time t;



#endif /* RTC_H_ */