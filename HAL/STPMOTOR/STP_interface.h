#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

typedef struct
{
	uint8 u8Port;
	uint8 u8Blue;
	uint8 u8Pink;
	uint8 u8Yellow;
	uint8 u8Orange;
}STP_Config_t;

uint8 STP_u8RotateCW(const STP_Config_t* Copy_pstConfig);
uint8 STP_u8RotateCCW(const STP_Config_t* Copy_pstConfig);
uint8 STP_u8Stop(const STP_Config_t* Copy_pstConfig);

#endif
