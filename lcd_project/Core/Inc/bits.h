/*
 * bits.h
 *
 *  Created on: 10 de mai de 2022
 *      Author: Matheus Cunha
 */

#define FCPU 84000000				//define a frequencia da CPU - 84 MHz - ALTERAR TB NA LINHA DE BAIXO!

asm (".equ fcpu, 84000000  \n\t");	//diretiva para usar fcpu em assembly



#define	set_bit(y,bit)	(y|=(1<<bit))	//coloca em 1 o bit x da variï¿½vel Y
#define	clr_bit(y,bit)	(y&=~(1<<bit))	//coloca em 0 o bit x da variï¿½vel Y
#define cpl_bit(y,bit) 	(y^=(1<<bit))	//troca o estado lï¿½gico do bit x da variï¿½vel Y
#define tst_bit(y,bit) 	(y&(1<<bit))	//retorna 0 ou 1 conforme leitura do bit

//----------------------------------------------------------------------------------


/* INC_BITS_H_ */
