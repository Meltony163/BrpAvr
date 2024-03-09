#include"STD_TYPES.h"
#include"ErrType.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"SSD_interface.h"
#include"util/delay.h"

#define STOP_NUMBER      15
void main(void)
{
	PORT_vInitDirection();
	SSD_CONFIGRATION Local_stSsd1,Local_stSsd2;
	Local_stSsd1.EnablePin=DIO_u8PIN7;
	Local_stSsd1.EnablePort=DIO_u8PORTC;
	Local_stSsd1.FirstPin=DIO_u8PIN1;
	Local_stSsd1.Port=DIO_u8PORTA;
	Local_stSsd1.Type=CATHODE;

	Local_stSsd2.EnablePin=DIO_u8PIN6;
	Local_stSsd2.EnablePort=DIO_u8PORTC;
	Local_stSsd2.FirstPin=DIO_u8PIN1;
	Local_stSsd2.Port=DIO_u8PORTA;
	Local_stSsd2.Type=CATHODE;

	SSD_u8OFF(&Local_stSsd1);
	SSD_u8OFF(&Local_stSsd2);

	uint8 Local_u8Counter=0u,Local_u8DelayCounter,Local_u8Reset=DIO_u8PIN_HIGH,Local_u8Continue=DIO_u8PIN_HIGH;

	while(1)
	{
		DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN0, &Local_u8Reset);

		if(Local_u8Reset==DIO_u8PIN_LOW)
		{
			Local_u8Counter=0u;
		}

		for(Local_u8DelayCounter=0;Local_u8DelayCounter<10;Local_u8DelayCounter++)
		{
			SSD_u8ON(&Local_stSsd1);
			SSD_u8SetNumber(&Local_stSsd1, (Local_u8Counter%10));
			_delay_ms(10);
			SSD_u8OFF(&Local_stSsd1);
			SSD_u8ON(&Local_stSsd2);
			SSD_u8SetNumber(&Local_stSsd2, (Local_u8Counter/10));
			_delay_ms(10);
			SSD_u8OFF(&Local_stSsd2);
		}

		DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN0, &Local_u8Reset);
		if(Local_u8Reset==DIO_u8PIN_LOW)
		{
			Local_u8Counter=0u;
		}

		if(Local_u8Counter==STOP_NUMBER)
		{
			while(1)
			{
				SSD_u8ON(&Local_stSsd1);
				SSD_u8SetNumber(&Local_stSsd1, (Local_u8Counter%10));
				_delay_ms(10);
				SSD_u8OFF(&Local_stSsd1);
				SSD_u8ON(&Local_stSsd2);
				SSD_u8SetNumber(&Local_stSsd2, (Local_u8Counter/10));
				_delay_ms(10);
				SSD_u8OFF(&Local_stSsd2);

				DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN0, &Local_u8Reset);
				if(Local_u8Reset==DIO_u8PIN_LOW)
				{
					Local_u8Counter=0u;
					break;
				}

				DIO_u8ReadPinValue(DIO_u8PORTB, DIO_u8PIN1, &Local_u8Continue);
				if(Local_u8Continue==DIO_u8PIN_LOW)
				{
					break;
				}

			}
		}
		if(Local_u8Counter<100)
		{
			Local_u8Counter++;
		}
	}
}
