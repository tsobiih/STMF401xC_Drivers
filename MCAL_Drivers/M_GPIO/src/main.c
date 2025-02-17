#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"

void main(void)
{

	MRCC_voidInit();

	MRCC_voidPortAEnable();

	MGPIO_voidSetMode(PORTA,PIN0,OUTPUT);
	MGPIO_voidSetOutputConfig(PORTA,PIN0,Push_Pull,Low_Speed);
	MGPIO_voidSetAtomicPinValue(PORTA,PIN0,PIN_High);


	while(1)
	{



	}
}


