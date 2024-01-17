#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

enum
{
	A0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	A0_A0_G10,
	A1_A0_G10,
	A0_A0_G200,
	A1_A0_G200,
	A2_A2_G10,
	A3_A2_G10,
	A2_A2_G200,
	A3_A2_G200,
	A0_A1_G1,
	A1_A1_G1,
	A2_A1_G1,
	A3_A1_G1,
	A4_A1_G1,
	A5_A1_G1,
	A6_A1_G1,
	A7_A1_G1,
	A0_A2_G1,
	A1_A2_G1,
	A2_A2_G1,
	A3_A2_G1,
	A4_A2_G1,
}ADC_enChannels;

void ADC_voidInit(void);
uint16 ADC_u16GetAnalogReading(uint8 Copy_u8Channel);

#endif /* ADC_INTERFACE_H_ */
