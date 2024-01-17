#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "LDR_prv.h"
#include "LDR_cfg.h"
#include "LDR_interface.h"


uint16 LDR_u16GetReading(uint8 Copy_u8Channel)
{
	return ADC_u16GetAnalogReading(Copy_u8Channel);
}
