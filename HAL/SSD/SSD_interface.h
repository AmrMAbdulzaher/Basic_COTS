#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

typedef enum
{
	COM_ANODE = 1u,
	COM_CATHODE = 2u,
	ETAKIT = 3u
}SSD_EN_Type_t;

typedef struct
{
	uint8 u8Port;
	uint8 u8LEDA_Pin;
	uint8 u8EN_Port;
	uint8 u8EN_Pin;
	SSD_EN_Type_t u8EN_Type;
}SSD_Config_t;

uint8 SSD_u8ON(const SSD_Config_t* Copy_pstConfig);
uint8 SSD_u8OFF(const SSD_Config_t* Copy_pstConfig);
uint8 SSD_u8SetNumber(const SSD_Config_t* Copy_pstConfig,uint8 Copy_u8Number);

#endif
