#include "HomeSecurity.h"


int main(void)
{
	/* use PortC for output (LED) */
	DDRC = 0xFF;
	
	no_devices = 0;
	
	RTC_init();
	USART_Init();
	
	//devices[0].id = 100;
	//devices[0].no_events = 2;
	//devices[0].events[0].type = 10;
	//devices[0].events[0].hour = 2;
	//devices[0].events[0].minute = 0;
	//devices[0].events[1].type = 15;
	//devices[0].events[1].hour = 4;
	//devices[0].events[1].minute = 30;
	//no_devices = 1;
	
	PORTC = 0xFF; //turn LEDs off
	
	while(1)
	{
		if(t.hour%2 != 0 )
		{
			PORTC &= ~(1<<7);
		}
		else
		{
			PORTC |= 1<<7;
		}			

			
	}; //loop forever
}