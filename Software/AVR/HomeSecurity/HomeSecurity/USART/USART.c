#include "USART.h"

//volatile unsigned char usart_state = S_START;
//
//volatile unsigned char remaining_events = 0;
//volatile unsigned char total_events = 0;



//ISR(USART_RXC_vect)
//{
	////define temp value for storing received byte and stor data
	//char data = UDR;
	//
	//switch(usart_state)
	//{
		//case S_START:	if(data == C_CONF)
							//usart_state = S_ID;				
						//break;
		//case S_ID	:	devices[no_devices].id = data; //Set id TODO: check on no of devices
						//usart_state = S_EVENT_NO;
						//break;
		//case S_EVENT_NO:devices[no_devices].no_events = data;
						//total_events = remaining_events = data; //TODO check if remaining events are > 0 and < MAX_EVENTS
						//usart_state = S_TYPE;
						//break;
		//case S_TYPE	:	devices[no_devices].events[total_events-remaining_events].type = data;
						//usart_state = S_HOUR;
						//break;
		//case S_HOUR	:	devices[no_devices].events[total_events-remaining_events].hour = data;
						//usart_state = S_MIN;
						//break;
		//case S_MIN	:	devices[no_devices].events[total_events-remaining_events].minute = data;
						//remaining_events--;
						//if(remaining_events > 0)
							//usart_state = S_TYPE;
						//else
						//{
							//no_devices++;
							//usart_state = S_START;
						//}
						//break;
							//
		//default		:	usart_state = S_START;
						//break;	
	//}
//
//}

void USART_Init()
{
	/* disable interrupts */
	cli();
	
	//Set baud rate
	UBRRL=UBRRVAL;		//low byte

	UBRRH=(UBRRVAL>>8);	//high byte

	//Set data frame format: asynchronous mode,no parity, 1 stop bit, 8 bit size
	UCSRC=(1<<URSEL)|(0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|
		(0<<USBS)|(0<<UCSZ2)|(1<<UCSZ1)|(1<<UCSZ0);	

	//Enable Transmitter and Receiver and Interrupt on receive complete
	UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);

	//enable global interrupts
	sei();
}