/*	Author: Benjamin Shu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #7  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 * Link to Demo: https://www.youtube.com/watch?v=-bV1R1ms8_o
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
    /* Insert your solution below */
    while (1) {
		unsigned short x = ADC;
		unsigned short MAX = 700;
		if(x <= MAX/8) {
			PORTB = 0x01;
		}
		else if(x <= MAX/4) {
			PORTB = 0x03;
		}
		else if(x <= (3*MAX/8)) {
			PORTB = 0x07;
		}
		else if(x <= MAX/2) {
			PORTB = 0x0F;
		}
		else if(x <= (5 * MAX/8)) {
			PORTB = 0x1F;
		}
		else if(x <= (3 * MAX/4)) {
			PORTB = 0x3F;
		}
		else if(x <= (7 * MAX/8)) {
			PORTB = 0x7F;
		}
		else if(x <= (MAX)) {
			PORTB = 0xFF;
		}
		//max value is 15 + 256 + 512 = 783
    }
    return 1;
}
