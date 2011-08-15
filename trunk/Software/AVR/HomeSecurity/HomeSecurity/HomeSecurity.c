#include "HomeSecurity.h"


int main(void)
{
	/* use PortC for output (LED) */
	DDRC = 0xFF;
	
	no_devices = 0;
	
	//RTC_init();
	USART_Init();
	X10_Init();
	
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
	
	
	/*Set Frame Format
   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit
   >> char size 8
   */

   UCSRC=(1<<URSEL)|(3<<UCSZ0);


   //Enable The receiver and transmitter
   UCSRB=(1<<RXEN)|(1<<TXEN);
	
	while(1)
	{
		unsigned char data;
		//Wait until a data is available
		while(!(UCSRA & (1<<RXC)));
		data = UDR;
		
		if(data == 0xAA)
		{
			//Turn on Unit 2 in House A
			write_command(HOUSE_A, UNIT_2, 2);
			write_command(HOUSE_A, ON, 2);
			
			//Debug turn on LED0
			PORTC &= ~(0x01);
		}
		else if(data == 0xFF)
		{
			//Turn off Unit 2 in House A
			write_command(HOUSE_A, UNIT_2, 2);
			write_command(HOUSE_A, OFF, 2);
			
			//Debug turn off LED0
			PORTC |= 0x01;
		}
		//else ignore data

	
		
	}; //loop forever
}