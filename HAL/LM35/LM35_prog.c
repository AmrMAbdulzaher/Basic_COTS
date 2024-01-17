#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "LM35_prv.h"
#include "LM35_cfg.h"
#include "LM35_interface.h"


uint8 LM35_u8GetTempReading(uint8 Copy_u8Channel)
{
	uint8 Local_u8TempReading= (uint8) (ADC_u16GetAnalogReading(Copy_u8Channel) / DIVISION_FACTOR);

	return Local_u8TempReading;
}
