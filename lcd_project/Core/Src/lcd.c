//=============================================================================================	//
//		Sub-rotinas para o trabalho com um LCD 16x2 com via de dados de 4 bits					//
//		Controlador HD44780	- Pino R/W aterrado													//
//=============================================================================================	//

#include "lcd.h"

//---------------------------------------------------------------------------------------------
// Sub-rotina para enviar comandos ao LCD com via de dados de 4 bits
//---------------------------------------------------------------------------------------------
void cmd_LCD(uint32_t c)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 0);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (c>>7)&0x01);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (c>>6)&0x01);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (c>>5)&0x01);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (c>>4)&0x01);

	pulso_enable();

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (c>>3)&0x01);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (c>>2)&0x01);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (c>>1)&0x01);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, c&0x01);

	pulso_enable();

	if(c<4)
	{
		HAL_Delay(4);
	}

	/*
	CLR_CONTRL_RS=RS;

	//primeiro nibble de dados - 4 MSB

	if(tst_bit(c,7)) SET_D7 = D7; else CLR_D7=D7;
	if(tst_bit(c,6)) SET_D6 = D6; else CLR_D6=D6;
	if(tst_bit(c,5)) SET_D5 = D5; else CLR_D5=D5;
	if(tst_bit(c,4)) SET_D4 = D4; else CLR_D4=D4;

	pulso_enable();

	//segundo nibble de dados - 4 LSB

	if(tst_bit(c,3)) SET_D7 = D7; else CLR_D7=D7;
	if(tst_bit(c,2)) SET_D6 = D6; else CLR_D6=D6;
	if(tst_bit(c,1)) SET_D5 = D5; else CLR_D5=D5;
	if(tst_bit(c,0)) SET_D4 = D4; else CLR_D4=D4;

	pulso_enable();

	if(c<4)				//se for instruï¿½ï¿½o de retorno ou limpeza espera LCD estar pronto
		atraso_ms(2);
		*/
}
//---------------------------------------------------------------------------------------------
void caract_LCD(uint32_t c)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 1);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (c>>7)&0x01);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (c>>6)&0x01);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (c>>5)&0x01);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (c>>4)&0x01);

	pulso_enable();

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (c>>3)&0x01);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (c>>2)&0x01);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (c>>1)&0x01);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, c&0x01);

	pulso_enable();

	/*
	SET_CONTRL_RS=RS;

	//primeiro nibble de dados - 4 MSB

	if(tst_bit(c,7)) SET_D7 = D7; else CLR_D7=D7;
	if(tst_bit(c,6)) SET_D6 = D6; else CLR_D6=D6;
	if(tst_bit(c,5)) SET_D5 = D5; else CLR_D5=D5;
	if(tst_bit(c,4)) SET_D4 = D4; else CLR_D4=D4;

	pulso_enable();

	//segundo nibble de dados - 4 LSB

	if(tst_bit(c,3)) SET_D7 = D7; else CLR_D7=D7;
	if(tst_bit(c,2)) SET_D6 = D6; else CLR_D6=D6;
	if(tst_bit(c,1)) SET_D5 = D5; else CLR_D5=D5;
	if(tst_bit(c,0)) SET_D4 = D4; else CLR_D4=D4;

	pulso_enable();
	*/
}
//---------------------------------------------------------------------------------------------
//Sub-rotina para inicializaï¿½ï¿½o do LCD com via de dados de 4 bits
//---------------------------------------------------------------------------------------------
void inic_LCD_4bits()		//sequï¿½ncia ditada pelo fabricando do circuito integrado HD44780
{							//o LCD serï¿½ sï¿½ escrito. Entï¿½o, R/W ï¿½ sempre zero.

	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 0);
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);

	HAL_Delay(20);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 1);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);

	pulso_enable();
	HAL_Delay(5);
	pulso_enable();
	HAL_Delay(1);
	pulso_enable();

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 1);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0);

	pulso_enable();

	cmd_LCD(0x28);
	cmd_LCD(0x08);
	cmd_LCD(0x01);
	cmd_LCD(0x0C);

	/*
	CLR_CONTRL_RS=RS;		//RS em zero indicando que o dado para o LCD serï¿½ uma instruï¿½ï¿½o
	CLR_CONTRL_E=E;			//pino de habilitaï¿½ï¿½o em zero

	atraso_ms(20);	 		//tempo para estabilizar a tensï¿½o do LCD, apï¿½s VCC ultrapassar 4.5 V (na prï¿½tica pode
							//ser maior).
	// interface de 8 bits
	// 0x3_
	CLR_D7 = D7;
	CLR_D6 = D6;
	SET_D5 = D5;
	SET_D4 = D4;

	pulso_enable();			//habilitaï¿½ï¿½o respeitando os tempos de resposta do LCD
	atraso_ms(5);
	pulso_enable();
	atraso_us(200);
	pulso_enable();			//atï¿½ aqui ainda ï¿½ uma interface de 8 bits.
							//Muitos programadores desprezam os comandos acima, respeitando apenas o tempo de
							//estabilizaï¿½ï¿½o da tensï¿½o (geralmente funciona). Se o LCD nï¿½o for inicializado primeiro no
							//modo de 8 bits, haverï¿½ problemas se o microcontrolador for inicializado e o display jï¿½ o tiver sido.

	// interface de 4 bits, deve ser enviado duas vezes (a outra estï¿½ abaixo)
	// 0x2_
	CLR_D7 = D7;
	CLR_D6 = D6;
	SET_D5 = D5;
	CLR_D4 = D4;

	pulso_enable();
   	cmd_LCD(0x28); 		//interface de 4 bits 2 linhas (aqui se habilita as 2 linhas)
						//sï¿½o enviados os 2 nibbles (0x2 e 0x8)
   	cmd_LCD(0x08);		//desliga o display
   	cmd_LCD(0x01);		//limpa todo o display
   	cmd_LCD(0x0C);		//mensagem aparente cursor inativo nï¿½o piscando
   	cmd_LCD(0x80);		//inicializa cursor na primeira posiï¿½ï¿½o a esquerda - 1a linha
   	*/
}
//---------------------------------------------------------------------------------------------
//Sub-rotina de escrita no LCD -  dados armazenados na RAM
//---------------------------------------------------------------------------------------------
void escreve_LCD(char *c)
{
   for (; *c!=0;c++) caract_LCD(*c);
}
//---------------------------------------------------------------------------------------------
//Sub-rotina de escrita no LCD - dados armazenados na FLASH
//---------------------------------------------------------------------------------------------
void escreve_LCD_Flash(const char *c)
{
   for (; *c!=0;c++) caract_LCD(*c);
}
//---------------------------------------------------------------------------------------------
//Conversï¿½o de um nï¿½mero em seus digitos individuais
//---------------------------------------------------------------------------------------------
void ident_num(uint32_t valor, uint32_t *disp)
{
 	uint32_t n;

	for(n=0; n<tam_vetor; n++)
		disp[n] = 0 + conv_ascii;		//limpa vetor para armazenagem do digitos

	do
	{
       *disp = (valor%10) + conv_ascii;	//pega o resto da divisao por 10
	   valor /=10;						//pega o inteiro da divisï¿½o por 10
	   disp++;

	}while (valor!=0);
}
//---------------------------------------------------------------------------------------------

