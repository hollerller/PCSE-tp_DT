/*
 * API_LCDhandler.c
 *
 *  Created on: Dec 5, 2023
 *      Author: hollerller
 */

#include "stm32f4xx_hal.h"
#include "API_LCDhandler.h"
#include "driver_BME280.h"
#include "driver_LCD.h"
#include <stdio.h>
#include "main.h"


typedef enum {
	TH_CURRENT,	// State for normal values for Temperature and Humidity
	TH_MAX,	// State for temperature outside thresholds
	TH_MIN,	// State for humidity outside thresholds

} LCDstate_t;

static LCDstate_t LCDstate;

static float maxTemp = -40;
static float minTemp = 85;

static float maxHum = 0;
static float minHum = 100;

char messageTemp[16] = "";
char messageHum[16] = "";


void LCDhandlerInit(){

	LCDstate = TH_CURRENT;

}


void LCDhandlerFSM(){

	tempMax();
	tempMin();
	humMax();
	humMin();
	uint8_t buttonState = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin); // Read the button state (pressed or released)

	switch (LCDstate) {

		case TH_CURRENT:	// State when temperature and humidity are within thresholds


			if (buttonState){
			LCD_clear();
			LCD_sendCMD(0x80);
			sprintf(messageTemp, "Temp: %.2f", temp);
			LCD_sendString(messageTemp);

			LCD_sendCMD(0xC0);
			sprintf(messageHum, "Hum:  %.2f", hum);
			LCD_sendString(messageHum);
		} else {
			LCDstate = TH_MAX;
		}


			break;

		case TH_MAX:// State when temperature is outside thresholds but humidity is ok

			if (buttonState){
			LCD_clear();
			LCD_sendCMD(0x80);
			sprintf(messageTemp, "Max Temp: %.2f", maxTemp);
			LCD_sendString(messageTemp);

			LCD_sendCMD(0xC0);
			sprintf(messageHum, "Max Hum:  %.2f", maxHum);
			LCD_sendString(messageHum);

			} else {
						LCDstate = TH_MIN;
					}

			break;

		case TH_MIN:// State when humidity is outside thresholds but temperature is ok

			if (buttonState){
				LCD_clear();
			LCD_sendCMD(0x80);
			sprintf(messageTemp, "Min Temp: %.2f", minTemp);
			LCD_sendString(messageTemp);

			LCD_sendCMD(0xC0);
			sprintf(messageHum, "Min Hum:  %.2f", minHum);
			LCD_sendString(messageHum);

			} else {
									LCDstate = TH_CURRENT;
								}

			break;

		default:
			// default state for the FSM
			LCDstate = TH_CURRENT;

			break;

		}


}

void tempMax(){

	if (temp > maxTemp){
		maxTemp = temp;
	}

}

void tempMin(){

	if (temp < minTemp){
		minTemp = temp;
	}

}

void humMax(){

	if (hum > maxHum){
		maxHum = hum;
	}

}

void humMin(){

	if (hum < minHum){
		minHum = hum;
	}

}

