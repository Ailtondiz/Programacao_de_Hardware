#include <avr/io.h>

delay_1s:
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		rcall delay_100ms
		ret

delay_100ms:
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		rcall delay_10ms
		ret

delay_10ms:
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		rcall delay_1ms
		ret

delay_1ms:
		push r16; salva o valor em r16
		ldi r16,99; determina o valor de r16, que seriam quantas vezes ele vai ter que fazer o loop
		delay_1ms1: ;10us/loop
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
			nop; gasta 1 ciclo
		dec r16
		brne delay_1ms1
		pop r16; restore value no r16
		ret
