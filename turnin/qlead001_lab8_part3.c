/*	Author: Quinn Leader qlead001@ucr.edu
 *  Partner(s) Name: NA
 *	Lab Section: 026
 *	Assignment: Lab 8  Exercise 3
 *	Exercise Description: Turn on LED when ADC >= MAX/2
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

const unsigned short MIN = 0x3C, MAX = 0x8E;

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

void Tick() {
    unsigned short signal = ADC;
    PORTB = (signal >= MAX/2);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    ADC_init();
    while (1) {
        Tick();
    }
    return 1;
}
