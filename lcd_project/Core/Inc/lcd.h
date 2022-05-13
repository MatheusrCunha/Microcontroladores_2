#ifndef _LCD_H
#define _LCD_H

#include "bits.h"
#include "stm32f1xx_hal.h"

//--------------------------------------------------------------------------------------------------------
//	Defini��es para facilitar a troca dos pinos do hardware e facilitar a re-programa��o
//
//	Configura��o Default conforme LCT_KEY_ETC Shield
//
//--------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------

#define tam_vetor	5	// n�mero de digitos individuais para a convers�o por ident_num()
#define conv_ascii	48	// 48 se ident_num() deve retornar um n�mero no formato ASCII (0 para formato decimal)

//--------------------------------------------------------------------------------------------------------

//	sinal de habilita��o para o LCD
#define pulso_enable() HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1); HAL_Delay(1); HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0); HAL_Delay(1);
/*
#define pulso_enable() 	atraso_us(1); SET_CONTRL_E=E; atraso_us(1); CLR_CONTRL_E=E; atraso_us(45)
*/
//--------------------------------------------------------------------------------------------------------

#define RS_Pin GPIO_PIN_1
#define RS_GPIO_Port GPIOA
#define E_Pin GPIO_PIN_2
#define E_GPIO_Port GPIOA
#define D4_Pin GPIO_PIN_3
#define D4_GPIO_Port GPIOA
#define D5_Pin GPIO_PIN_4
#define D5_GPIO_Port GPIOA
#define D6_Pin GPIO_PIN_5
#define D6_GPIO_Port GPIOA
#define D7_Pin GPIO_PIN_6
#define D7_GPIO_Port GPIOA

//	prot�tipo das fun��es

void cmd_LCD(uint32_t c);
void caract_LCD(uint32_t c);
void inic_LCD_4bits();
void escreve_LCD(char *c);
void escreve_LCD_Flash(const char *c);

void ident_num(uint32_t valor, uint32_t *disp);

#endif
