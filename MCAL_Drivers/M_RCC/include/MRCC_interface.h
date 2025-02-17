/*
 * MRCC_interface.h
 *
 *  Created on: Feb 7, 2025
 *      Author: elwady
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/******AHB1**********/
#define AHB1_GPIOA 	 0
#define AHB1_GPIOB 	 1
#define AHB1_GPIOC 	 2
#define AHB1_DMA1    21
#define AHB1_DMA2    22

//********APB1**********
#define APB1_SPI2EN   14
#define APB1_SPI3EN   15
#define APB1_USART2   17

//********APB1**********
#define APB2_USART1	  4
#define APB2_USART6   5
#define APB2_SPI1    12
#define APB2_SPI4    13
#define APB2_SYSCFG  14


typedef enum
{
	AHB1_BUS,
	AHB2_BUS,
	APB1_BUS,
	APB2_BUS

}System_Bus;

void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(System_Bus Copy_uddtBus, u8 Copy_u8Peripheral);
void MRCC_voidDisablePeripheralClock(System_Bus Copy_uddtBus, u8 Copy_u8Peripheral);
void MRCC_voidPortAEnable(void);
void MRCC_voidPortBEnable(void);
void MRCC_voidPortCEnable(void);
void MRCC_voidPortADisable(void);
void MRCC_voidPortBDisable(void);
void MRCC_voidPortCDisable(void);

#define HSI_CLOCK  0
#define HSE_CLOCK  1

#define MECHANICAL_CLOCK 0
#define RC_CLOCK		 1

#define SW_MUSK 3

#endif /* MRCC_INTERFACE_H_ */
