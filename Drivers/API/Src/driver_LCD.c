/*
 * API_LCD.c
 *
 *  Created on: Dec 3, 2023
 *      Author: hollerller
 */

#include "stm32f4xx_hal.h"

#include <stdint.h>
#include "driver_LCD.h"
#include "API_delay.h"
#include "API_i2c.h"

#define INITIALDELAY 20



void LCD_init(){

	HAL_Delay(20);
	LCD_sendCMD(0x30);
	HAL_Delay(10);
	LCD_sendCMD(0x30);
	HAL_Delay(1);
	LCD_sendCMD(0x30);
	LCD_sendCMD(0x20);

}


void LCD_sendCMD(char command){

	uint8_t cmdMSB = (command & 0xF0);
	uint8_t cmdLSB = ((command << 4) & 0xF0);
	uint8_t enableOn = 0x0C;
	uint8_t enableOff = 0x08;

	uint8_t sendCMD[4] = {
			cmdMSB | enableOn,
			cmdMSB | enableOff,
			cmdLSB | enableOn,
			cmdLSB | enableOff};

	i2c_Master_Trasmit(sendCMD, 0x4E, 4);

}

void LCD_sendChar(char caracter){

	uint8_t charMSB = (caracter & 0xF0);
	uint8_t charLSB = ((caracter << 4) & 0xF0);
	uint8_t enableOn = 0x0D;
	uint8_t enableOff = 0x09;

	uint8_t sendChar[4] = {
			charMSB | enableOn,
			charMSB | enableOff,
			charLSB | enableOn,
			charLSB | enableOff};

	i2c_Master_Trasmit(sendChar, 0x4E, 4);


}


//void LCD_sendByte(char data);
