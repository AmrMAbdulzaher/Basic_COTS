#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

typedef enum
{
	PULL_DOWN=0u,
	PULL_UP=1u
}PULL_TYPE_t;

typedef enum
{
	RELEASED=0u,
	PRESSED=1u
}SW_STATE_t;

typedef struct
{
	uint8 u8Port;
	uint8 u8Pin;
	PULL_TYPE_t u8Pull_Type;
}SW_Config_t;

uint8 SW_u8GetState(const SW_Config_t* Copy_pstConfig, uint8* Copy_pu8State);

#endif
