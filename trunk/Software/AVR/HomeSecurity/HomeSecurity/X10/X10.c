#include "X10.h"

/*Zero crossing interrupt*/
ISR(INT0_vect)
{
	/*Start carrier signal if 1 is to be sent*/
	if (bit_to_send != 0)
	{
		start_carrier_signal();
	}
	
	/*Disable zero crossing interrupt*/
	GICR &= ~(1 << INT0);

	/*Wait 1 ms: */	
	/*Reset timer 2 value*/
	TCNT2=0x00;
	/*Start timer 2 with prescaler: 8 */
	TCCR2 |= 1 << CS21 | 1 << CS20;

}

/*1 ms timer 2 interrupt*/
ISR(TIMER2_COMP_vect)
{
	/*Stop carrier signal after 1 ms */
	stop_carrier_signal();
	bit_sent = TRUE;
	/*Stop timer 2*/
	TCCR2 &= ~(1 << CS22 | 1 << CS21 | 1 << CS20);
}

/*Initialize timer1 timer2 and external interrupt*/
void X10_Init(void)
{
	/* disable interrupts */
	cli();
	
	/*Configure zero crossing interrupt on external interrupt 0*/
	/*Interrupt on INT0 pin both rising and falling edge*/
	MCUCR = (1<<ISC00);	
	
	/*Configure Timer2 to wait 1 ms. Used to set carrier signal for 1 ms*/
	/*Set compare match value*/
	OCR2 = 115;
	/*Clear timer on compare match (CTC) mode*/
	TCCR2 = 1 << WGM21;
	/*Enable timer compare match interrupt*/
	TIMSK |= (1 << OCIE2);	
	
	/*Configure Timer1 to generate ~120kHz square wave*/
	/* Set on match, clear on TOP */
	TCCR1A  = ((1 << COM1A1) | (1 << COM1A0));

	/* Phase + Frequency Correct PWM, CLK Source: CLK I/O with no prescaler */
	TCCR1B  = (1 << CS10) | (1 << WGM13);

	/* TOP is 15. 1.843 MHz / 15 = ~122 kHz */
	ICR1    = 0x0F;
   
	/* Dutycycle 53 / 47 */
	OCR1A = 0x0008;
	
	/* Enable interrupts */
	sei();
}

void start_carrier_signal(void)
{
	/*Set OC1A as output*/
	 DDRD   |= (1 << PD5);
}

void stop_carrier_signal(void)
{
	/*Set OC1A as input, thus stopping the signal*/
	DDRD   &= ~(1 << PD5);
}

/*Sends one bit and only returns after the bit has been sent.*/
void send_bit(unsigned char bit)
{
	bit_to_send = bit;
	bit_sent = FALSE;
	/*Enable zero crossing interrupt*/
	GICR |= (1 << INT0);
	
	while (bit_sent == FALSE);
}

/*Writes a X10 command/address "repeats" times*/
void write_command(unsigned char house_code, unsigned char number_code, unsigned char repeats) {
	
	unsigned char i;
	send_bit(0); // sync
	/*Repeat command as requested*/
 	for (i = 0; i < repeats; i++)
	{
		/*Send the start code all commands begin with*/
 		send_bits(START_CODE, 4, TRUE);
		/*Send the house code*/
  		send_bits(house_code, 4, FALSE);
		/*Send the number code*/
  		send_bits(number_code, 5, FALSE);
  	}
	  
  	/*
	 *If this isn't a bright or dim command,
	 *it should be followed by a delay of 6 zero crossings:
	 */
  	if ((number_code != BRIGHT) && (number_code != DIM))
	{
		for (i = 0; i < 6; i++)
 			send_bit(0);
  	}
}

/*Writes a number of bits, if these bits are start code then their complementary bits are not written*/
void send_bits(unsigned char bits, unsigned char num_bits, unsigned char is_start_code)
{
	unsigned char i;
	unsigned char current_bit;
  
	/*Iterate through the number of bits */
	for(i=1; i<=num_bits; i++)
	{
		/*Extract current bit*/
		current_bit = bits & (1 << (num_bits - i));
		/*Send current bit*/
		send_bit(current_bit);
		
		/* if this is a start code then do
		 * not send its complement. Otherwise do:
		 */
		if(is_start_code != TRUE)
		{
			if (current_bit != 0)
				send_bit(0);
			else
				send_bit(1);
		}
			
	}
}