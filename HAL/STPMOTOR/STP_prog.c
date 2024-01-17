#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"
#include "../../Library/ErrType.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_interface.h"
#include "STP_cfg.h"
#include "STP_interface.h"
#include "STP_prv.h"


uint8 STP_u8RotateCW(const STP_Config_t* Copy_pstConfig)
{
	uint8 Local_ErrorState = OK;

	if(Copy_pstConfig != NULL)
	{
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_LOW);
		_delay_ms(2);
	}
	else
	{
		Local_ErrorState = NULL_PTR_ERR;
	}

	return Local_ErrorState;
}
uint8 STP_u8RotateCCW(const STP_Config_t* Copy_pstConfig)
{
	uint8 Local_ErrorState = OK;

	if(Copy_pstConfig != NULL)
	{
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_LOW);
		_delay_ms(2);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_HIGH);
		_delay_ms(2);
	}
	else
	{
		Local_ErrorState = NULL_PTR_ERR;
	}

	return Local_ErrorState;
}
uint8 STP_u8Stop(const STP_Config_t* Copy_pstConfig)
{
	uint8 Local_ErrorState = OK;
	if(Copy_pstConfig != NULL)
	{
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Blue,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pink,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Yellow,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Orange,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_ErrorState = NULL_PTR_ERR;
	}
	return Local_ErrorState;
}
