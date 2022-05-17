#ifndef _LCD_HD44780_H
#define _LCD_HD44780_H

#include "main.h"

// LCD com 4 bits de dados

// Definições para os pinos empregados

#define RS_port GPIOA
#define RS_pin  GPIO_PIN_1

#define EN_port  GPIOA
#define EN_pin   GPIO_PIN_0

#define D4_port  GPIOB
#define D4_pin   GPIO_PIN_4
#define D5_port  GPIOB
#define D5_pin   GPIO_PIN_5
#define D6_port  GPIOB
#define D6_pin   GPIO_PIN_6
#define D7_port  GPIOB
#define D7_pin   GPIO_PIN_7

//-------------------------------------------------------------------------------------------------
#define PULSO_ENABLE() 	HAL_Delay(1), HAL_GPIO_WritePin(EN_port, EN_pin, 1); HAL_Delay(1); HAL_GPIO_WritePin(EN_port, EN_pin, 0); HAL_Delay(1)

// macros para simplificação do uso de algumas funções

#define LIMPA_LCD()						cmd_LCD(0x01)
#define DESLOCA_CURSOR(end_posicao)		cmd_LCD(end_posicao)
#define DESLOCA_CURSOR_DIR()			cmd_LCD(0x06)
#define DESLOCA_MSG_DIR_C_CARCT()		cmd_LCD(0x05) //desloca msg para a direita com a entrada de novo caractere
#define DESLOCA_MSG_DIR_S_CARCT()		cmd_LCD(0x1C) //desloca msg para a direita sem a entrada de novo caractere
#define DESLOCA_CURSOR_ESQ()			cmd_LCD(0x04)
#define DESLOCA_MSG_ESQ_C_CARCT()		cmd_LCD(0x07)
#define DESLOCA_MSG_ESQ_S_CARACT()		cmd_LCD(0x18)

#define ESCREVE_CARACTERE_CGRAM0()		write_character_LCD(0x00)				//apresenta primeiro caractere 0x00
#define ESCREVE_CARACTERE_CGRAM1()		write_character_LCD(0x01)
#define ESCREVE_CARACTERE_CGRAM2()		write_character_LCD(0x02)
#define ESCREVE_CARACTERE_CGRAM3()		write_character_LCD(0x03)
#define ESCREVE_CARACTERE_CGRAM4()		write_character_LCD(0x04)
#define ESCREVE_CARACTERE_CGRAM5()		write_character_LCD(0x06)
#define ESCREVE_CARACTERE_CGRAM6()		write_character_LCD(0x06)
#define ESCREVE_CARACTERE_CGRAM7()		write_character_LCD(0x07)

void send_nibble_LCD(uint8_t dado);
void send_byte_LCD(uint8_t dado);
void cmd_LCD(uint32_t comando);
void write_character_LCD(uint8_t caracter);
void init_LCD_4bits();
void write_string_LCD(char *msg);
void write_nr_LCD(uint32_t nr, uint32_t quant);
void write_string_nr_LCD(char *msg,uint32_t nr, uint32_t quant);
void new_character_CGRAM(const uint8_t *caract, uint32_t qual);
void write_time_LCD(uint32_t horas, uint32_t minutos, uint32_t segundos);

#endif

