#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"

#include "ADC_reg.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"

void ADC_voidInit(void)
{
	/*Set AVCC as reference voltage*/
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	/*Select left or right adjust according to resolution configuration*/
#if ADC_u8RESOLUTION == EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8RESOLUTION == TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else #error Wrong ADC_u8RESOLUTION configuration option
#endif

	/*Disable Auto trigger mode*/
	CLR_BIT(ADCSRA,ADCSRA_ADATE);

	/*Disable interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	/*Clear the prescaler bits*/
	ADCSRA &= PRESCALER_BIT_MASK;
	/*Configure the prescaler division factor*/
	ADCSRA |= ADC_u8PRESCALER_DIVISON_FACTOR << PRESCALER_BIT_POS;
}

uint16 ADC_u16GetAnalogReading(uint8 Copy_u8Channel)
{
	uint16 Local_u16AnalogReading;

	/*clear input channel bits*/
	ADMUX &= CHANNEL_BIT_MASK;
	/*Set input channel*/
	ADMUX |= Copy_u8Channel << CHANNEL_BIT_POS;

	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Wait for ADC interrupt flag by polling*/
	while(!GET_BIT(ADCSRA,ADCSRA_ADIF));
	/*clear ADC interrupt flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*get the conversion result*/
#if ADC_u8RESOLUTION == EIGHT_BITS
	Local_u16AnalogReading= (uint16)(((uint32)ADCH*REFERENCE_VOLTAGE)/TWO_POW_EIGHT);
#elif ADC_u8RESOLUTION == TEN_BITS
	Local_u16AnalogReading= (uint16)(((uint32)ADC*REFERENCE_VOLTAGE)/TWO_POW_TEN);
#endif

	return Local_u16AnalogReading;
}
