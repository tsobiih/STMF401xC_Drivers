/*
 * SS_config.h
 *
 *  Created on: Feb 17, 2025
 *      Author: elwady
 */

#ifndef SS_CONFIG_H_
#define SS_CONFIG_H_

typedef enum
{
	zero,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine
}NUMBERS;

typedef enum
{
    SS_LED_A  = PIN0,
    SS_LED_B  = PIN1,
    SS_LED_C  = PIN2,
    SS_LED_D  = PIN3,
    SS_LED_E  = PIN4,
    SS_LED_F  = PIN5,
    SS_LED_G  = PIN6,
    SS_LED_DP = PIN7
}SS_PINS;

typedef enum
{
	SS_PORT = PORTA
}SS_PORTS;

#endif /* SS_CONFIG_H_ */
