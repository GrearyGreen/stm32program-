#ifndef __L29_H
#define __L29_H	 
#include "sys.h"

#define MOT1A PAout(0)// PA1
#define MOT1B PAout(2)// PA2
#define MOT2A PAout(3)// PA3
#define MOT2B PAout(4)// PA4	
#define MOT3A PAout(5)// PA5
#define MOT3B PAout(6)// PA6
#define MOT4A PAout(7)// PA7
#define MOT4B PAout(8)// PA8

void GPIOUT_Init(void);//≥ı ºªØ
void MOTSET_front(void);//uint8_t L291,uint8_t L292,uint8_t L293,uint8_t L294
void MOTSET_back(void);
void MOTSET_left(void);
void MOTSET_right(void);
void MOTSET_stop(void);
#endif
