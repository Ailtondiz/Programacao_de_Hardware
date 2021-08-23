/****************************************************************************
 * Copyright (C) 2020 by Programacao de Hardware Engenharia de computacao   *
 *                                                                          *
 * This file is part of TP02.                                        *
 *                                                                          *
 * TP02 e um software livre: voce pode redistribui-lo e / ou modifica-lo    *
 * sob os termos da GNU Lesser General Public License conforme publicada    *
 * pela Free Software Foundation, seja a versao 3 da Licenca, ou            *
 * (a sua escolha) qualquer versao posterior.                               *
 *                                                                          *
 * O TP02 e distribuido na esperanca de que seja util,                      *
 * mas SEM QUALQUER GARANTIA; sem mesmo a garantia implicita de             *
 * COMERCIALIZACAO ou ADEQUACAO A UM DETERMINADO FIM. Veja o                *
 * GNU Lesser General Public License para obter mais detalhes.              *
 *                                                                          *
 * Voce deve ter recebido uma copia do GNU Lesser General Public            *
 * Licenca junto com TP02. Caso contrario, consulte                         *
 *<http://www.gnu.org/licenses/>.                                           *
 * <https://www.doxygen.nl/manual/index.html>                               *
 ****************************************************************************/

/**
 * @file main.c
 * @author <b>Ailton Fernandes do Rosario Junior RA: 171912, Lucas Sanju Komatsu RA: 170958, Manuel Cassiano Ferreira da Silva RA: 172152, Kevin da Silva Tani Leite RA: 167364</b>
 * @date 21 Aug 2021
 * @brief <b>TP02 da materia Programacao de Hardware do 6 semestre de Engenharia de Computacao.</b>
 *
 * O aluno(a) devera desenvolver um codigo em C, em que ele devera criar as funcoes de manipulacao de IO 
 * (usando os registros DDRx,PINx,PORTx) onde cada devera proporcionar ao usuario poder escolher qualquer 
 * pino e port que ele quiser.  Em seguida, na funcao main, o aluno devera implementar um exemplo usando 
 * as funcoes, e de preferencia para implementar como se fosse um projeto (de sua escolha. EX: Sensor de 
 * janelas).A resposta devera ser implementado cabecalho de acordo com o exemplo deste e descricao de cada
 * comando usando Doxygen. A resposta devera ser enviada para o proprio github do aluno, e postar os 
 * arquivos fonte na tarefa do teams.
 * 
 * O envio dos arquivos deverao ser enviados os codigos fontes puros e a documentacao gerada pelo doxygen 
 * em uma pasta zipada(no teams). No seu github, deve-se colocar da forma mais organizada que o aluno achar
 * (deve-se colocar o link do github dele no codigo fonte principal).
 * 
 * OBJETIVO DO PROJETO: Aplicacao para uma lampada automatica acionada por um sensor de presenca.
 * 
 * O TP FOI FEITO EM GRUPO POIS NAO ESTAVAMOS CONSEGUINDO FAZER SOZINHO, ENTAO NOS REUNIMOS EM GRUPO.
 *
 * @note https://github.com/Ailtondiz/Programacao_de_Hardware.git
 * @see http://inovfablab.unisanta.br
 * @see http://fabmanager.unisanta.br
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>
#include <string.h>

/** Variavel para ler o estado/presenca no sensor. **/
char estadoPino; /** Entrada da porta escolhida pelo usuario, porta padrao como B.  **/
char port = 'B'; /** Entrada do pino escolhido pelo usuario, pino padrao como 1**/
int pin = 1; /** variavel de controle. **/
int x; 

int main(void){ 
	while(1){ /**mantem o programa em loop. **/
		
		printf("Aviso: A porta/Pino B0 está didicada para leitura do sensor !!! \nA porta C só possui 6 pinos \n"); /** Aviso **/
		
		printf("Entre com a letra da porta que a Lampada esta conectada (A, B ou C): "); /** Solicita a entrada do dados para o usuario. **/
		scanf("%c", &port); /** Armazena a entrada da porta do usuario. **/
		
		printf("Entre com o numero do pino que a Lampada esta conectada (de 0 a 7): "); /** Solicita a entrada do dados para o usuario. **/
		scanf("%d", &pin); /** Armazena a entrada do pino do usuario. **/
		
		x=1; 
		while(x) /** Permite a leitura da porta/pino ate que haja uma presenca. **/
		estadoPino = PINB0; /** Le estado do pino B0 que esta ligado ao sensor, 0 para sem leitura de presenca e 1 para leitura de presenca. **/
			if(estadoPino >= 1){	
				x = 0; /** sai do loop de leitura da porta B0 **/
			};	
				
			switch (port){	/** habilita porta selecionada pelo usuario, para que possa ligar a lampada por 10s e desligar apos os 10s. **/
				case 'B' :
					if(pin == 1){
						DDRB |= (1 << DDB1);
					}
					else if(pin == 2){
						DDRB |= (1 << DDB2);
					}
					else if(pin == 3){
						DDRB |= (1 << DDB3);
					}
					else if(pin == 4){
						DDRB |= (1 << DDB4);
					}
					else if(pin == 5){
						DDRB |= (1 << DDB5);
					}
					else if(pin == 6){
						DDRB |= (1 << DDB6);
					}
					else if(pin == 7){
						DDRB |= (1 << DDB7);
					}
					PORTB |= (1 << pin); /** liga lampada. **/
					_delay_ms(10000); /** delay de 10s. **/
					PORTB &= (1 << pin); /** desliga lampada. **/
					break;
			
				case 'C' :
					if(pin == 0){
						DDRC |= (1 << DDC0);
					}
					else if(pin == 1){
						DDRC |= (1 << DDC1);
					}
					else if(pin == 2){
						DDRC |= (1 << DDC2);
					}
					else if(pin == 3){
						DDRC |= (1 << DDC3);
					}
					else if(pin == 4){
						DDRC |= (1 << DDC4);
					}
					else if(pin == 5){
						DDRC |= (1 << DDC5);
					}
					else if(pin == 6){
						DDRC |= (1 << DDC6);
					}
					PORTC |= (0 << pin); /** liga lampada. **/
					_delay_ms(10000); /** delay de 10s. **/
					PORTC &= (0 << pin); /** desliga lampada. **/
					break;
			
				case 'D' :
					if(pin == 0){
						DDRD |= (1 << DDD0);
					}
					else if(pin == 1){
						DDRD |= (1 << DDD1);
					}
					else if(pin == 2){
						DDRD |= (1 << DDD2);
					}
					else if(pin == 3){
						DDRD |= (1 << DDD3);
					}
					else if(pin == 4){
						DDRD |= (1 << DDD4);
					}
					else if(pin == 5){
						DDRD |= (1 << DDD5);
					}
					else if(pin == 6){
						DDRD |= (1 << DDD6);
					}
					else if(pin == 7){
						DDRD |= (1 << DDD7);
					}
					PORTD |= (0 << pin); /** liga lampada. **/
					_delay_ms(10000); /** delay de 10s. **/
					PORTD &= (0 << pin); /** desliga lampada. **/
		}
	};
};