#ifndef MAP_H
#define MAP_H

#define MAP(start1,end1,start2,end2,value)             (uint32) ((uint32)end2-((uint32)((uint32)end2-(uint32)start2)*((uint32)end1-(uint32)value))/(uint32)(end1-start1))

#endif
