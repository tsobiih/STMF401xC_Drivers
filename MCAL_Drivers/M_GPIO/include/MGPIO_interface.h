/*
 * MGPIO_interface.h
 *
 *  Created on: Feb 14, 2025
 *      Author: elwady
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

typedef enum
{
	PORTA,
	PORTB,
	PORTC
}PORTS;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PINS;

typedef enum
{
	INPUT,
	OUTPUT,
	Alternative_Func,
	Analog
}MODES;

typedef enum
{
	Push_Pull,
	Open_Drain
}OUT_TYPE;

typedef enum
{
	Low_Speed,
	Med_Speed,
	High_Speed,
	VHigh_Speed
}SPEED;

typedef enum
{
	PIN_Low,
	PIN_High
}VALUE;

typedef enum
{
	NOPULLUPORPULLDOWN,
	PULLUP,
	PULLDOWN
}INPUT_MODE;

typedef enum
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}ALT_FUNC;

void MGPIO_voidSetMode(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,MODES Copy_uddtMode);
/*________________________________Output Mode___________________________________________________________________________________*/
void MGPIO_voidSetOutputConfig(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,OUT_TYPE Copy_uddtType , SPEED Copy_uddtSpeed);
void MGPIO_voidSetPinValue(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,VALUE Copy_uddtValue);
void MGPIO_voidSetAtomicPinValue(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,VALUE Copy_uddtValue);
/*________________________________Input Mode____________________________________________________________________________________*/
void MGPIO_voidSetIntputConfig(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,INPUT_MODE Copy_uddtMode);
u8 MGPIO_u8GetPinValue(PORTS Copy_uddtPort ,PINS Copy_uddtPin);
/*________________________________Alternative Mode____________________________________________________________________________________*/
void MGPIO_voidSetAlternativeFunConfig(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,ALT_FUNC Copy_uddtAltFunc);

#endif /* MGPIO_INTERFACE_H_ */
