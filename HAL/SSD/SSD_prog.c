#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_prv.h"
#include "SSD_cfg.h"

uint8 SSD_u8ON(const SSD_Config_t* Copy_pstConfig)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstConfig != NULL)
	{
		if((Copy_pstConfig->u8EN_Type == COM_ANODE) || (Copy_pstConfig->u8EN_Type == ETAKIT))
		{
			DIO_u8SetPinValue(Copy_pstConfig->u8EN_Port,Copy_pstConfig->u8EN_Pin,DIO_u8PIN_HIGH);
		}
		else if(Copy_pstConfig->u8EN_Type == COM_CATHODE)
		{
			DIO_u8SetPinValue(Copy_pstConfig->u8EN_Port,Copy_pstConfig->u8EN_Pin,DIO_u8PIN_LOW);
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
uint8 SSD_u8OFF(const SSD_Config_t* Copy_pstConfig)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstConfig != NULL)
	{
		if((Copy_pstConfig->u8EN_Type == COM_ANODE) || (Copy_pstConfig->u8EN_Type == ETAKIT))
		{
			DIO_u8SetPinValue(Copy_pstConfig->u8EN_Port,Copy_pstConfig->u8EN_Pin,DIO_u8PIN_LOW);
		}
		else if(Copy_pstConfig->u8EN_Type == COM_CATHODE)
		{
			DIO_u8SetPinValue(Copy_pstConfig->u8EN_Port,Copy_pstConfig->u8EN_Pin,DIO_u8PIN_HIGH);
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
uint8 SSD_u8SetNumber(const SSD_Config_t* Copy_pstConfig, uint8 Copy_u8Number)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstConfig != NULL)
	{
		static uint8 Local_au8SSD_BCD[10]=
		{
				0b00111111, // 0
				0b00000110, // 1
				0b01011011, // 2
				0b01001111, // 3
				0b01100110, // 4
				0b01101101, // 5
				0b01111101, // 6
				0b00000111, // 7
				0b01111111, // 8
				0b01101111  // 9
		};

		if((Copy_pstConfig->u8EN_Type == COM_CATHODE) || (Copy_pstConfig->u8EN_Type == ETAKIT))
		{
			uint8 Local_u8Display_Num = Local_au8SSD_BCD[Copy_u8Number];
			if(Copy_pstConfig->u8LEDA_Pin == DIO_u8PIN0)
			{
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN0,GET_BIT(Local_u8Display_Num,0u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN1,GET_BIT(Local_u8Display_Num,1u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN2,GET_BIT(Local_u8Display_Num,2u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN3,GET_BIT(Local_u8Display_Num,3u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN4,GET_BIT(Local_u8Display_Num,4u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN5,GET_BIT(Local_u8Display_Num,5u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN6,GET_BIT(Local_u8Display_Num,6u));
			}
			else if(Copy_pstConfig->u8LEDA_Pin == DIO_u8PIN1)
			{

				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN1,GET_BIT(Local_u8Display_Num,0u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN2,GET_BIT(Local_u8Display_Num,1u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN3,GET_BIT(Local_u8Display_Num,2u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN4,GET_BIT(Local_u8Display_Num,3u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN5,GET_BIT(Local_u8Display_Num,4u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN6,GET_BIT(Local_u8Display_Num,5u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN7,GET_BIT(Local_u8Display_Num,6u));
			}
			else
			{
				Local_u8ErrorState = NOK;
			}
		}
		else if(Copy_pstConfig->u8EN_Type == COM_ANODE)
		{
			uint8 Local_u8Display_Num = ~(Local_au8SSD_BCD[Copy_u8Number]);
			if(Copy_pstConfig->u8LEDA_Pin == DIO_u8PIN0)
			{
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN0,GET_BIT(Local_u8Display_Num,0u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN1,GET_BIT(Local_u8Display_Num,1u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN2,GET_BIT(Local_u8Display_Num,2u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN3,GET_BIT(Local_u8Display_Num,3u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN4,GET_BIT(Local_u8Display_Num,4u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN5,GET_BIT(Local_u8Display_Num,5u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN6,GET_BIT(Local_u8Display_Num,6u));
			}
			else if(Copy_pstConfig->u8LEDA_Pin == DIO_u8PIN1)
			{

				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN1,GET_BIT(Local_u8Display_Num,0u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN2,GET_BIT(Local_u8Display_Num,1u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN3,GET_BIT(Local_u8Display_Num,2u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN4,GET_BIT(Local_u8Display_Num,3u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN5,GET_BIT(Local_u8Display_Num,4u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN6,GET_BIT(Local_u8Display_Num,5u));
				DIO_u8SetPinValue(Copy_pstConfig->u8Port,DIO_u8PIN7,GET_BIT(Local_u8Display_Num,6u));
			}
			else
			{
				Local_u8ErrorState = NOK;
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
