#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DAC_prv.h"
#include "DAC_cfg.h"
#include "DAC_interface.h"

void DAC_voidSetAnalogVolt(uint16 Copy_u16mVolt)
{
	uint8 Local_u8DigitalValue = (uint8)(((uint32)Copy_u16mVolt * 255UL)/5000UL);

	DIO_u8SetPortValue(DIO_u8PORTC,Local_u8DigitalValue);
}
