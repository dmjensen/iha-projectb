#ifndef USART_H_
#define USART_H_

#include "../HomeSecurity.h"

#define UBRRVAL ((F_CPU/(BAUDRATE*16UL))-1)

////States:
//#define S_START 0xA0	//Idle
//#define S_ID 0xA1		//Waiting for device ID
//#define S_EVENT_NO 0xA2	//Waiting for number of events
//#define S_TYPE 0xA3		//Waiting for event type
//#define S_HOUR 0xA4		//Waiting for event hour
//#define S_MIN 0xA5		//Waiting for event minute
//
////Commands:
//#define C_Reset 0xB0	//Resets the state machine to S_START
//#define C_CONF 0xB1		//Received when in S_START and PC wants to initiate configuration of a device

void USART_Init(void);

#endif /* USART_H_ */