#include "LCD_HD44780.h"

//---------------------------------------------------------------------------------------------
// Envio de dados em uma partes para o LCD, 1 nibble (D7 - bit3, D6 - bit2, D5 - bit1, D4 - bit0
//---------------------------------------------------------------------------------------------
void send_nibble_LCD(uint8_t dado) // dado so tem os 4 bits menos significativos válidos
{
	HAL_GPIO_WritePin(D7_port, D7_pin, (dado>>3) & 0x01);
	HAL_GPIO_WritePin(D6_port, D6_pin, (dado>>2) & 0x01);
	HAL_GPIO_WritePin(D5_port, D5_pin, (dado>>1) & 0x01);
	HAL_GPIO_WritePin(D4_port, D4_pin, (dado>>0) & 0x01);

	PULSO_ENABLE();
}
void send_byte_LCD(uint8_t dado)	// envia dois nibbles, 1o o mais significativo
{
	send_nibble_LCD(dado>>4);
	send_nibble_LCD(dado);

}
//---------------------------------------------------------------------------------------------
// Envio de comando ao LCD
//---------------------------------------------------------------------------------------------
void cmd_LCD(uint32_t comando)
{

	HAL_GPIO_WritePin(RS_port,RS_pin,0);
	send_byte_LCD(comando);

	if(comando<4)				//se for instrucao de retorno ou limpeza espera LCD estar pronto
		HAL_Delay(2);
}

//---------------------------------------------------------------------------------------------
// Envio de caracter ao LCD
//---------------------------------------------------------------------------------------------
void write_character_LCD(uint8_t caracter)
{
	HAL_GPIO_WritePin(RS_port,RS_pin,1);
	send_byte_LCD(caracter);
}
//---------------------------------------------------------------------------------------------
// Inicializacaoo do LCD com via de dados de 4 bits
//---------------------------------------------------------------------------------------------
void init_LCD_4bits()		//sequencia ditada pelo fabricando do circuito integrado HD44780
{							//o LCD sera so escrito. Entao, R/W é sempre zero.

	HAL_GPIO_WritePin(RS_port,RS_pin,0);//RS em zero indicando que o dado para o LCD sera uma instrução
	HAL_GPIO_WritePin(EN_port,EN_pin,0);//pino de habilitado em zero

	HAL_Delay(20);	 		//tempo para estabilizar a tensao do LCD, apos VCC ultrapassar 4.5 V (na pratica pode
							//ser maior).
	send_nibble_LCD(0x03);

	HAL_Delay(5);

	PULSO_ENABLE();

	send_nibble_LCD(0x02);

   	cmd_LCD(0x28); 		//interface de 4 bits 2 linhas (aqui se habilita as 2 linhas)
						//sao enviados os 2 nibbles (0x2 e 0x8)
   	cmd_LCD(0x08);		//desliga o display
   	cmd_LCD(0x01);		//limpa todo o display
   	cmd_LCD(0x0C);		//mensagem aparente cursor inativo nao piscando
   	cmd_LCD(0x80);		//inicializa cursor na primeira posicao a esquerda - 1a linha
}
//---------------------------------------------------------------------------------------------
// Escrita de uma string  -  dados armazenados na RAM
//---------------------------------------------------------------------------------------------
void write_string_LCD(char *msg)
{
   for (; *msg!=0;msg++) write_character_LCD(*msg);
}
//---------------------------------------------------------------------------------------------
// Escrita de um n�mero inteiro com magnitude m�xima de 65535
//---------------------------------------------------------------------------------------------
void write_nr_LCD(uint32_t nr, uint32_t quant) // quant é o nr de digitos a serem impressos, entre 1 e 10
{
	uint32_t i;
	uint8_t digito[10];

	i=10;
	do
	{
		i--;
		digito[i] = '0';		//inicializa vetor com '0'
	} while (i!=0);

	do
	{
		digito[i] = (nr%10) + 48;	//pega o resto da divisao por 10 e já converte para ASCII (+48)
		nr /=10;
		i++;						//pega o inteiro da divisão por 10

	}while (nr!=0);

	do
	{	quant--;
		write_character_LCD(digito[quant]); //impressao a partir do digito mais significativo

	} while (quant!=0);
}
//---------------------------------------------------------------------------------------------
void write_string_nr_LCD(char *msg, uint32_t nr, uint32_t quant) //a mensagem, o nr e a quantidade de digitos para impressao
{
	write_string_LCD(msg);
	write_nr_LCD(nr,quant);
}
//---------------------------------------------------------------------------------------------
// Cria caracter novo na CGRAM
//---------------------------------------------------------------------------------------------
void new_character_CGRAM(const uint8_t *caract, uint32_t qual)
/*
  qual vai de 0 até 7 (se pode criar no máximo 8 caracteres)

  O caracter novo deve ser declarado como no exemplo:

  const uint8_t caract[]  = {	0b00100,//Delta
										0b00100,
										0b01010,
										0b01010,
										0b10001,
										0b11111,
										0b00000	};

*/

{
	uint32_t i;

	cmd_LCD(0x40 + (qual*8));				//endereço base para gravar novo segmento

	for(i=0; i<7; i++)
		write_character_LCD(caract[i]);	//grava 8 bytes na CGRAM começando no end. 0x40
	write_character_LCD(0x00);			//apaga última posiçãoo do end. da CGRAM para evitar algum dado espúrio
}
//---------------------------------------------------------------------------------------------
void write_time_LCD(uint32_t horas, uint32_t minutos, uint32_t segundos)
{
	write_nr_LCD(horas,2);
	write_character_LCD(':');
	write_nr_LCD(minutos,2);
	write_character_LCD(':');
	write_nr_LCD(segundos,2);
}
//---------------------------------------------------------------------------------------------


