
#ifndef X10_H_
#define X10_H_

/*X10 constants:*/
/*Start code*/
#define START_CODE 0b1110
/*House Codes*/
#define	HOUSE_A	0b0110
#define	HOUSE_B	0b1110	
#define	HOUSE_C	0b0010
#define	HOUSE_D	0b1010
#define	HOUSE_E	0b0001
#define	HOUSE_F	0b1001
#define	HOUSE_G	0b0101
#define	HOUSE_H	0b1101
#define	HOUSE_I	0b0111
#define	HOUSE_J	0b1111
#define	HOUSE_K	0b0011
#define	HOUSE_L	0b1011
#define	HOUSE_M	0b0000
#define	HOUSE_N	0b1000
#define HOUSE_O	0b0100
#define HOUSE_P	0b1100

/*Key codes*/
/*Units:*/
#define UNIT_1	0b01100
#define UNIT_2	0b11100
#define UNIT_3	0b00100
#define UNIT_4	0b10100
#define UNIT_5	0b00010
#define UNIT_6	0b10010
#define UNIT_7	0b01010
#define UNIT_8	0b11010
#define UNIT_9	0b01110
#define UNIT_10	0b11110
#define UNIT_11	0b00110
#define UNIT_12	0b10110
#define UNIT_13	0b00000
#define UNIT_14	0b10000
#define UNIT_15	0b01000
#define UNIT_16	0b11000
/*Functions:*/
#define ALL_UNITS_OFF	0b00001
#define ALL_LIGHTS_ON	0b00011
#define ON				0b00101
#define OFF				0b00111
#define DIM				0b01001
#define BRIGHT			0b01011
#define ALL_LIGHTS_OFF	0b01101
#define EXTENDED_CODE	0b01111
#define HAIL_REQUEST	0b10001
#define HAIL_ACKNOWLEDGE	0b10011
#define PRE_SET_DIM			0b10101
#define EXTENDED_DATA		0b11001
#define STATUS_ON			0b11011
#define STATUS_OFF			0b11101
#define STATUS_REQUEST		0b11111


#include "../HomeSecurity.h"

volatile unsigned char bit_to_send;
volatile unsigned char bit_sent;

void X10_Init(void);

void write_command(unsigned char houseCode, unsigned char numberCode, unsigned char numRepeats);

void send_bits(unsigned char cmd, unsigned char numBits, unsigned char isStartCode);

void start_carrier_signal(void);

void stop_carrier_signal(void);

void send_bit(unsigned char bit);

#endif /* X10_H_ */