#ifndef HOMESECURITY_H_
#define HOMESECURITY_H_

#define F_CPU 3686400
#define BAUDRATE 115200
#define MAX_DEVICES 10
#define MAX_EVENTS 4

//Event types
#define E_ON 10
#define E_OFF 15

//Device id offset
#define ID_OFFSET -100

#include <avr/io.h>
#include <avr/interrupt.h>
#include "RTC/RTC.h" //Real Time Clock
#include "USART/USART.h"

typedef struct
{ 
	volatile unsigned char type;
	volatile unsigned char hour;
	volatile unsigned char minute;
} Event;

typedef struct
{ 
	volatile unsigned char id;
	volatile unsigned char no_events;
	volatile Event events[MAX_EVENTS];  
} Device;

volatile Device devices[MAX_DEVICES];
volatile unsigned char no_devices;


#endif /* HOMESECURITY_H_ */