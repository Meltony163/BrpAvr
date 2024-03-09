#include"SSD_interface.h"
#include"ErrType.h"
#include"STD_TYPES.h"
#include"SSD_prv.h"
#include"DIO_interface.h"
#include"BIT_MATH.h"
uint8 SSD_u8ON(SSD_CONFIGRATION const* ptr_sConfigration)
{
	uint8 Loc_u8ErrorState=OK;
	if(ptr_sConfigration!=NULL)
	{
		if((ptr_sConfigration->Type==ANODE)||(ptr_sConfigration->Type==ETA_KIT))
		{
			DIO_u8SetPinValue(ptr_sConfigration->EnablePort, ptr_sConfigration->EnablePin, DIO_u8PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(ptr_sConfigration->EnablePort, ptr_sConfigration->EnablePin, DIO_u8PIN_LOW);
		}
	}
	else
	{
		Loc_u8ErrorState=NULL_PTR;
	}
	return Loc_u8ErrorState;
}
uint8 SSD_u8OFF(SSD_CONFIGRATION const* ptr_sConfigration)
{
		uint8 Loc_u8ErrorState=OK;
		if(ptr_sConfigration!=NULL)
		{
			if((ptr_sConfigration->Type==ANODE)||(ptr_sConfigration->Type==ETA_KIT))
			{
				DIO_u8SetPinValue(ptr_sConfigration->EnablePort, ptr_sConfigration->EnablePin, DIO_u8PIN_LOW);
			}
			else
			{
				DIO_u8SetPinValue(ptr_sConfigration->EnablePort, ptr_sConfigration->EnablePin, DIO_u8PIN_HIGH);
			}
		}
		else
		{
			Loc_u8ErrorState=NULL_PTR;
		}
		return Loc_u8ErrorState;
}
uint8 SSD_u8SetNumber(SSD_CONFIGRATION const* ptr_sConfigration,uint8 cpy_nNumber)
{
	uint8 Loc_u8ErrorState=OK;
	static const uint8 Loc_au8Numbers0[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	static const uint8 Loc_au8Numbers1[10]={0b01111110,0b00001100,0b10110110,0b10011110,0b11001100,0b11011010,0b11111010,0b00001110,0b11111110,0b11011110};
	if(ptr_sConfigration!=NULL)
	{
		if(cpy_nNumber>9)
		{
			Loc_u8ErrorState=NOK;
		}
		else
		{
			if(ptr_sConfigration->FirstPin==DIO_u8PIN0)
			{
				uint8 Loc_u8Iterator=0;
				for(Loc_u8Iterator=0;Loc_u8Iterator<7;Loc_u8Iterator++)
				{
					if(ptr_sConfigration->Type==ANODE)
					{
						DIO_u8SetPinValue(ptr_sConfigration->Port,Loc_u8Iterator ,!(GET_BIT(Loc_au8Numbers0[cpy_nNumber],Loc_u8Iterator)));
					}
					else if((ptr_sConfigration->Type==CATHODE)||(ptr_sConfigration->Type==ETA_KIT))
					{
						DIO_u8SetPinValue(ptr_sConfigration->Port,Loc_u8Iterator ,GET_BIT(Loc_au8Numbers0[cpy_nNumber],Loc_u8Iterator));
					}
				}
			}
			else if(ptr_sConfigration->FirstPin==DIO_u8PIN1)
			{
				uint8 Loc_u8Iterator=1;
				for(Loc_u8Iterator=1;Loc_u8Iterator<8;Loc_u8Iterator++)
				{
					if(ptr_sConfigration->Type==ANODE)
					{
						DIO_u8SetPinValue(ptr_sConfigration->Port,Loc_u8Iterator ,!(GET_BIT(Loc_au8Numbers1[cpy_nNumber],Loc_u8Iterator)));
					}
					else if((ptr_sConfigration->Type==CATHODE)||(ptr_sConfigration->Type==ETA_KIT))
					{
						DIO_u8SetPinValue(ptr_sConfigration->Port,Loc_u8Iterator ,GET_BIT(Loc_au8Numbers1[cpy_nNumber],Loc_u8Iterator));
					}
				}
			}
		}
	}
	else
	{
		Loc_u8ErrorState=NULL_PTR;
	}
	return Loc_u8ErrorState;
}
