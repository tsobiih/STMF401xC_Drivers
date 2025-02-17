/*
 * MGPIO_program.c
 *
 *  Created on: Feb 14, 2025
 *      Author: elwady
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "MGPIO_private.h"


void MGPIO_voidSetMode(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,MODES Copy_uddtMode)
{
	if((Copy_uddtPort==PORTA)&& (Copy_uddtPin == PIN13)&& (Copy_uddtPin == PIN14) && (Copy_uddtPin == PIN15))
	{
		//Do Noyhing
	}
	else if((Copy_uddtPort==PORTB)&& (Copy_uddtPin == PIN3)&& (Copy_uddtPin == PIN4) && (Copy_uddtPin == PIN5))
	{
		//Do Noyhing
	}
	else {
		switch (Copy_uddtPort) {
			case PORTA:
				GPIOA->MODER &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOA->MODER |=(Copy_uddtMode<<(Copy_uddtPin*2));
				break;
			case PORTB:
				GPIOB->MODER &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOB->MODER |=(Copy_uddtMode<<(Copy_uddtPin*2));
				break;
			case PORTC:
				GPIOC->MODER &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOC->MODER |=(Copy_uddtMode<<(Copy_uddtPin*2));
				break;
			default:
				break;
		}
	}
}

void MGPIO_voidSetOutputConfig(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,OUT_TYPE Copy_uddtType , SPEED Copy_uddtSpeed)
{
	if((Copy_uddtPort==PORTA)&& (Copy_uddtPin == PIN13)&& (Copy_uddtPin == PIN14) && (Copy_uddtPin == PIN15))
	{
		//Do Noyhing
	}
	else if((Copy_uddtPort==PORTB)&& (Copy_uddtPin == PIN3)&& (Copy_uddtPin == PIN4) && (Copy_uddtPin == PIN5))
	{
		//Do Noyhing
	}
	else {
		switch (Copy_uddtPort) {
			case PORTA:
				GPIOA->OTYPER  &=~(1<<Copy_uddtPin);
				GPIOA->OTYPER  |=(Copy_uddtType<<Copy_uddtPin);
				GPIOA->OSPEEDR &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOA->OSPEEDR |=(Copy_uddtSpeed<<(Copy_uddtPin*2));
				break;
			case PORTB:
				GPIOB->OTYPER  &=~(1<<Copy_uddtPin);
				GPIOB->OTYPER  |=(Copy_uddtType<<Copy_uddtPin);
				GPIOB->OSPEEDR &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOB->OSPEEDR |=(Copy_uddtSpeed<<(Copy_uddtPin*2));
				break;
			case PORTC:
				GPIOC->OTYPER  &=~(1<<Copy_uddtPin);
				GPIOC->OTYPER  |=(Copy_uddtType<<Copy_uddtPin);
				GPIOC->OSPEEDR &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOC->OSPEEDR |=(Copy_uddtSpeed<<(Copy_uddtPin*2));
				break;
			default:
				break;
		}
	}
}
void MGPIO_voidSetPinValue(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,VALUE Copy_uddtValue)
{
	if((Copy_uddtPort==PORTA)&& (Copy_uddtPin == PIN13)&& (Copy_uddtPin == PIN14) && (Copy_uddtPin == PIN15))
	{
		//Do Noyhing
	}
	else if((Copy_uddtPort==PORTB)&& (Copy_uddtPin == PIN3)&& (Copy_uddtPin == PIN4) && (Copy_uddtPin == PIN5))
	{
		//Do Noyhing
	}
	else {
		switch (Copy_uddtPort) {
			case PORTA:
				if(Copy_uddtValue==PIN_Low)
				{
					GPIOA->ODR &=~(1<<(Copy_uddtPin));
				}
				else if(Copy_uddtValue==PIN_High)
				{
					GPIOA->ODR |=(1<<(Copy_uddtPin));
				}
				break;
			case PORTB:
				if(Copy_uddtValue==PIN_Low)
				{
					GPIOB->ODR &=~(1<<(Copy_uddtPin));
				}
				else if(Copy_uddtValue==PIN_High)
				{
					GPIOB->ODR |=(1<<(Copy_uddtPin));
				}
				break;
			case PORTC:
				if(Copy_uddtValue==PIN_Low)
				{
					GPIOC->ODR &=~(1<<(Copy_uddtPin));
				}
				else if(Copy_uddtValue==PIN_High)
				{
					GPIOC->ODR |=(1<<(Copy_uddtPin));
				}
				break;
			default:
				break;
		}
	}
}

void MGPIO_voidSetAtomicPinValue(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,VALUE Copy_uddtValue)
{
	if((Copy_uddtPort==PORTA)&& (Copy_uddtPin == PIN13)&& (Copy_uddtPin == PIN14) && (Copy_uddtPin == PIN15))
	{
		//Do Noyhing
	}
	else if((Copy_uddtPort==PORTB)&& (Copy_uddtPin == PIN3)&& (Copy_uddtPin == PIN4) && (Copy_uddtPin == PIN5))
	{
		//Do Noyhing
	}
	else
	{
		switch (Copy_uddtPort) {
			case PORTA:
				if(Copy_uddtValue==PIN_High)
				{
					GPIOA->BSRR =(1<<Copy_uddtPin);
				}
				else if(Copy_uddtValue==PIN_Low)
				{
					GPIOA->BSRR =(1<<(Copy_uddtPin+16));
				}
				break;
			case PORTB:
				if(Copy_uddtValue==PIN_High)
				{
					GPIOB->BSRR =(1<<Copy_uddtPin);
				}
				else if(Copy_uddtValue==PIN_Low)
				{
					GPIOB->BSRR =(1<<(Copy_uddtPin+16));
				}
				break;
			case PORTC:
				if(Copy_uddtValue==PIN_High)
				{
					GPIOC->BSRR =(1<<Copy_uddtPin);
				}
				else if(Copy_uddtValue==PIN_Low)
				{
					GPIOC->BSRR =(1<<(Copy_uddtPin+16));
				}
				break;
			default:
				break;
		}
	}
}

void MGPIO_voidSetIntputConfig(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,INPUT_MODE Copy_uddtMode)
{
	if((Copy_uddtPort==PORTA)&& (Copy_uddtPin == PIN13)&& (Copy_uddtPin == PIN14) && (Copy_uddtPin == PIN15))
	{
		//Do Noyhing
	}
	else if((Copy_uddtPort==PORTB)&& (Copy_uddtPin == PIN3)&& (Copy_uddtPin == PIN4) && (Copy_uddtPin == PIN5))
	{
		//Do Noyhing
	}
	else
	{
		switch (Copy_uddtPort) {
			case PORTA:
				GPIOA->PUPDR &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOA->PUPDR |=(Copy_uddtMode<<(Copy_uddtPin*2));
				break;
			case PORTB:
				GPIOB->PUPDR &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOB->PUPDR |=(Copy_uddtMode<<(Copy_uddtPin*2));
				break;
			case PORTC:
				GPIOC->PUPDR &=~(GPIO_MUSK<<(Copy_uddtPin*2));
				GPIOC->PUPDR |=(Copy_uddtMode<<(Copy_uddtPin*2));
				break;
			default:
				break;
		}
	}
}

u8 MGPIO_u8GetPinValue(PORTS Copy_uddtPort ,PINS Copy_uddtPin)
{
	u8 Local_u8PinValue=3;
	if((Copy_uddtPort==PORTA)&& (Copy_uddtPin == PIN13)&& (Copy_uddtPin == PIN14) && (Copy_uddtPin == PIN15))
	{
		//Do Noyhing
	}
	else if((Copy_uddtPort==PORTB)&& (Copy_uddtPin == PIN3)&& (Copy_uddtPin == PIN4) && (Copy_uddtPin == PIN5))
	{
		//Do Noyhing
	}
	else
	{
		switch (Copy_uddtPort) {
			case PORTA:
				Local_u8PinValue = GET_BIT(GPIOA->IDR, Copy_uddtPin);
				break;
			case PORTB:
				Local_u8PinValue = GET_BIT(GPIOB->IDR, Copy_uddtPin);
				break;
			case PORTC:
				Local_u8PinValue = GET_BIT(GPIOC->IDR, Copy_uddtPin);
				break;
			default:
				break;
		}
	}
		return Local_u8PinValue;
}

void MGPIO_voidSetAlternativeFunConfig(PORTS Copy_uddtPort ,PINS Copy_uddtPin ,ALT_FUNC Copy_uddtAltFunc)
{
	if(Copy_uddtPin<=7)
	{
		switch (Copy_uddtPort) {
			case PORTA:
				GPIOA->ARFL &=~(ALT_FUNC_MUSK<<(Copy_uddtPin*4));
				GPIOA->ARFL |=(Copy_uddtAltFunc<<(Copy_uddtPin*4));
				break;
			case PORTB:
				GPIOB->ARFL &=~(ALT_FUNC_MUSK<<(Copy_uddtPin*4));
				GPIOB->ARFL |=(Copy_uddtAltFunc<<(Copy_uddtPin*4));
				break;
			case PORTC:
				GPIOC->ARFL &=~(ALT_FUNC_MUSK<<(Copy_uddtPin*4));
				GPIOC->ARFL |=(Copy_uddtAltFunc<<(Copy_uddtPin*4));
				break;
			default:
				break;
		}
	}
	else if((Copy_uddtPin<=15)&&(Copy_uddtPin>=8))
	{
		switch (Copy_uddtPort) {
			case PORTA:
				GPIOA->ARFH &=~(ALT_FUNC_MUSK<<((Copy_uddtPin-8)*4));
				GPIOA->ARFH |=(Copy_uddtAltFunc<<((Copy_uddtPin-8)*4));
				break;
			case PORTB:
				GPIOB->ARFH &=~(ALT_FUNC_MUSK<<((Copy_uddtPin-8)*4));
				GPIOB->ARFH |=(Copy_uddtAltFunc<<((Copy_uddtPin-8)*4));
				break;
			case PORTC:
				GPIOC->ARFH &=~(ALT_FUNC_MUSK<<((Copy_uddtPin-8)*4));
				GPIOC->ARFH |=(Copy_uddtAltFunc<<((Copy_uddtPin-8)*4));
				break;
			default:
				break;
		}
	}
}
