#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H
#include"STD_TYPES.h"

#define ANODE       1u
#define CATHODE     2u
#define ETA_KIT     3u


typedef struct SSD_CONFIGRATION
{
    uint8 Type;
    uint8 Port;
    uint8 EnablePort;
    uint8 EnablePin;
    uint8 FirstPin;
}SSD_CONFIGRATION;

uint8 SSD_u8ON(SSD_CONFIGRATION const* ptr_sConfigration);
uint8 SSD_u8OFF(SSD_CONFIGRATION const* ptr_sConfigration);
uint8 SSD_u8SetNumber(SSD_CONFIGRATION const* ptr_sConfigration,uint8 cpy_nNumber);

#endif
