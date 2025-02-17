#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "SS_interface.h"

void main(void)
{
	u8 Local_u8Switch=3;
	u8 Local_u8Last=2;
	u8 Local_u8Counter=0;

	MRCC_voidInit();

	MRCC_voidPortAEnable();
	MRCC_voidPortBEnable();

	SS_voidInit();
	MGPIO_voidSetMode(PORTB, PIN0, INPUT);
	MGPIO_voidSetIntputConfig(PORTB, PIN0, PULLUP);

	while(1)
	{
		Local_u8Switch = MGPIO_u8GetPinValue(PORTB, PIN0);

		if((Local_u8Switch==PIN_High) && (Local_u8Last == PIN_Low))
		{
			if(Local_u8Counter < 10)
			{
				SS_voidSetNumber(Local_u8Counter);
				Local_u8Counter++;
			}
			else
			{
				Local_u8Counter=0;
				SS_voidLedsState(PIN_High);
			}
			Local_u8Last=Local_u8Switch;

//			for (int i = 0; i < 1000; i++);
		}
		else if(Local_u8Switch == PIN_Low)
		{
			Local_u8Last=Local_u8Switch;
		}
	}
}


