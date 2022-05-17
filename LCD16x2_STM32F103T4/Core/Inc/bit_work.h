#ifndef _BIT_WORK_H
#define _BIT_WORK_H

#define SET(bit)		(1<<bit)
#define	SET_BIT(y,bit)	(y|=(1<<bit))	//coloca em 1 o bit x da variavel Y
#define	CLR_BIT(y,bit)	(y&=~(1<<bit))	//coloca em 0 o bit x da variavel Y
#define CPL_BIT(y,bit) 	(y^=(1<<bit))	//troca o estado logico do bit x da variavel Y
#define TST_BIT(y,bit) 	(y&(1<<bit))	//retorna 0 ou 1 conforme leitura do bit

#endif
