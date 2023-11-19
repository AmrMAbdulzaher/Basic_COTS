#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "SW_cfg.h"
#include "SW_interface.h"
#include "SW_prv.h"


uint8 SW_u8GetState(const SW_Config_t* Copy_pstConfig, uint8* Copy_pu8State)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstConfig != NULL && Copy_pu8State != NULL)
	{
		if(Copy_pstConfig->u8Pull_Type == PULL_UP)
		{
			uint8 Local_u8ButtonState;
			DIO_u8ReadPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pin,&Local_u8ButtonState);

			if(Local_u8ButtonState == DIO_u8PIN_LOW)
			{
				*Copy_pu8State = PRESSED;
			}
			else
			{
				*Copy_pu8State = RELEASED;
			}
		}
		else if(Copy_pstConfig->u8Pull_Type == PULL_DOWN)
		{
			uint8 Local_u8ButtonState;
			DIO_u8ReadPinValue(Copy_pstConfig->u8Port,Copy_pstConfig->u8Pin,&Local_u8ButtonState);

			if(Local_u8ButtonState == DIO_u8PIN_LOW)
			{
				*Copy_pu8State = RELEASED;
			}
			else
			{
				*Copy_pu8State = PRESSED;
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}
