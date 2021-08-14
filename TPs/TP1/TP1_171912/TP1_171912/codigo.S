
/*
 * codigo.S
 *
 * Created: 13/08/2021 20:10:35
 *  Author: ailton
 *	Adaptação do TP5
 */ 

#include <avr/io.h>
#include "delay.S"

.global INICIO
	INICIO:
		ldi r17, 0b00001111
		ldi r18, 0b11110000 
		out DDRD, r17
	LOOP:
		out PORTD, r17
		rcall delay_1s
		out PORTD, r18
		rcall delay_1s
		ret
