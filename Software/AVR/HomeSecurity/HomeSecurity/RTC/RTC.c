
#include "RTC.h"

ISR(TIMER0_COMP_vect)
{
	RTC_step();
	
	//Check if an event is schedule for this moment:
	int i,j;
	for(i = 0; i < no_devices; i++)
	{
		Device* d = &devices[i];
		for(j = 0; j < d->no_events; j++)
		{
			if (d->events[j].hour == t.hour && d->events[j].minute == t.minute )
			{
				if (d->events[j].type == E_ON) // on
				{
					PORTC &= ~( 1 << (d->id+ID_OFFSET) );
				}
				else if (d->events[j].type == E_OFF) // off TODO defines
				{
					PORTC |= 1 << (d->id+ID_OFFSET);
				}
			}
		}
		
	}	
}	

void RTC_init(void)
{
	/* disable interrupts */
	cli();

	/*enable timer compare match interrupt*/
	TIMSK = 1 << OCIE0;

	/*set timer counter initial value*/
	TCNT0=0x00;
	
	/*set compare match value*/
	OCR0 = 30;

	/*start timer with prescaler: 1024 , Clear timer on compare match (CTC) mode*/
	TCCR0 = 1 << CS02 | 1 << CS00 | 1 << WGM01;
	
	/* enable interrupts */
	sei();
}

void RTC_step(void) //called every second
{ 
    if (++t.second==60)        //keep track of time, date, month, and year
    {
        t.second=0;
        if (++t.minute==60) 
        {
            t.minute=0;
            if (++t.hour==24)
            {
                t.hour=0;
                if (++t.date==32)
                {
                    t.month++;
                    t.date=1;
                }
                else if (t.date==31) 
                {                    
                    if ((t.month==4) || (t.month==6) || (t.month==9) || (t.month==11)) 
                    {
                        t.month++;
                        t.date=1;
                    }
                }
                else if (t.date==30)
                {
                    if(t.month==2)
                    {
                       t.month++;
                       t.date=1;
                    }
                }              
                else if (t.date==29) 
                {
                    if((t.month==2) && (not_leap()))
                    {
                        t.month++;
                        t.date=1;
                    }                
                }                          
                if (t.month==13)
                {
                    t.month=1;
                    t.year++;
                }
            }
        }
    }  
}  
 
char not_leap(void)      //check for leap year
{
    if (!(t.year%100))
        return (char)(t.year%400);
    else
        return (char)(t.year%4);
} 