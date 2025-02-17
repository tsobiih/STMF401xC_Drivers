#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "MRCC_interface.h"
#include "SS_interface.h"
#include "SS_config.h"


const u8 SS_Patterns[10] = {
	0b0111111,  // 0 -> A, B, C, D, E, F
	0b0000110,  // 1 -> B, C
	0b1011011,  // 2 -> A, B, G, E, D
	0b1001111,  // 3 -> A, B, G, C, D
	0b1100110,  // 4 -> B, C, F, G
	0b1101101,  // 5 -> A, C, D, F, G
	0b1111101,  // 6 -> A, C, D, E, F, G
	0b0000111,  // 7 -> A, B, C
	0b1111111,  // 8 -> A, B, C, D, E, F, G
	0b1101111   // 9 -> A, B, C, D, F, G
};

void SS_voidInit(void)
{
	for(SS_PINS i=SS_LED_A ; i <= SS_LED_DP ; i++)
	{
		MGPIO_voidSetMode(SS_PORT, i,  OUTPUT);
		MGPIO_voidSetOutputConfig(SS_PORT, i,  Push_Pull, Low_Speed);
		MGPIO_voidSetAtomicPinValue(SS_PORT, i, PIN_Low);
	}
}

void SS_voidLedsState(u8 Copy_u8State)
{
	switch (Copy_u8State) {
		case PIN_High:
			for(SS_PINS i=SS_LED_A ; i <= SS_LED_DP ; i++)
			{
				MGPIO_voidSetAtomicPinValue(SS_PORT, i, PIN_High);
			}
			break;
		case PIN_Low:
			for(SS_PINS i=SS_LED_A ; i <= SS_LED_DP ; i++)
			{
				MGPIO_voidSetAtomicPinValue(SS_PORT, i, PIN_Low);
			}
			break;
		default:
			break;
	}
}

void SS_voidSetNumber(u8 Copy_u8Num)
{
    if ((Copy_u8Num <= 9) && (Copy_u8Num >= 0))
    {

		for (SS_PINS i = SS_LED_A; i <= SS_LED_DP; i++)
		{

			MGPIO_voidSetAtomicPinValue(SS_PORT, i, (SS_Patterns[Copy_u8Num] >> i) & 1);

		}
    }

}














