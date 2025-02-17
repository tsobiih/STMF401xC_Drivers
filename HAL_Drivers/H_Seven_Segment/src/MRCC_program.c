#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_config.h"
#include "MRCC_interface.h"
#include "MRCC_private.h"


void MRCC_voidInit(void)
{
#if(SYS_CLOCK == HSI_CLOCK)
		//HSI ON
		RCC->CR |=(1<<HSI_ON);
		//SET_BIT(RCC->CR, HSI_ON);

		//Wait till ready
		while(GET_BIT(RCC->CR,HSI_RDY)==0);

		//Switch to HSI
		RCC->CFGR &=~(SW_MUSK<<SW0);
		RCC->CFGR |=(HSI_Oscillator<<SW0);

#elif(SYS_CLOCK == HSE_CLOCK)

	#if(HSE_OSC == MECHANICAL_CLOCK)
		RCC->CR &=~(1<<HSEBYP);
	#elif(HSE_OSC == RC_CLOCK)
		RCC->CR |=(1<<HSEBYP);
	#endif

	//HSE ON
	RCC->CR |=(1<<HSE_ON);

	//Wait Till Ready
	while(GET_BIT(RCC->CR,HSE_RDY)==0);

	//Switch
	RCC->CFGR &=~(SW_MUSK<<SW0);
	RCC->CFGR |=(HSE_Oscillator<<SW0);

	//Disable HSI_CLOCK
	RCC->CR &=~(1<<HSI_ON);
#endif
}

void MRCC_voidEnablePeripheralClock(System_Bus Copy_uddtBus, u8 Copy_u8Peripheral)
{
	switch (Copy_uddtBus) {
		case AHB1_BUS:
			RCC->AHB1ENR |=(1<<Copy_u8Peripheral);
			break;
		case AHB2_BUS:
			RCC->AHB2ENR |=(1<<Copy_u8Peripheral);
			break;
		case APB1_BUS:
			RCC->APB1ENR |=(1<<Copy_u8Peripheral);
			break;
		case APB2_BUS:
			RCC->APB2ENR |=(1<<Copy_u8Peripheral);
			break;
		default:
			break;
	}
}
void MRCC_voidDisablePeripheralClock(System_Bus Copy_uddtBus, u8 Copy_u8Peripheral)
{
	switch (Copy_uddtBus) {
		case AHB1_BUS:
			RCC->AHB1ENR &=~(1<<Copy_u8Peripheral);
			break;
		case AHB2_BUS:
			RCC->AHB2ENR &=~(1<<Copy_u8Peripheral);
			break;
		case APB1_BUS:
			RCC->APB1ENR &=~(1<<Copy_u8Peripheral);
			break;
		case APB2_BUS:
			RCC->APB2ENR &=~(1<<Copy_u8Peripheral);
			break;
		default:
			break;
	}
}

void MRCC_voidPortAEnable(void)
{
	MRCC_voidEnablePeripheralClock(AHB1_BUS,AHB1_GPIOA);
}

void MRCC_voidPortBEnable(void)
{
	MRCC_voidEnablePeripheralClock(AHB1_BUS ,AHB1_GPIOB);
}

void MRCC_voidPortCEnable(void)
{
	MRCC_voidEnablePeripheralClock(AHB1_BUS ,AHB1_GPIOC);
}

void MRCC_voidPortADisable(void)
{
	MRCC_voidDisablePeripheralClock(AHB1_BUS,AHB1_GPIOA);
}

void MRCC_voidPortBDisable(void)
{
	MRCC_voidDisablePeripheralClock(AHB1_BUS,AHB1_GPIOB);
}

void MRCC_voidPortCDisable(void)
{
	MRCC_voidDisablePeripheralClock(AHB1_BUS,AHB1_GPIOC);
}




















