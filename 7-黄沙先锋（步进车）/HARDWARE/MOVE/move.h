#ifndef __MOVE_H
#define __MOVE_H


#define DIRL PCout(8) 
#define DIRR PCout(9)

#define PULL PCout(6)
#define PULR PCout(7)


//#define SKI PFout(12)

void MOVE_Init(void);
void goForward(void);
void goBack(void);
void turnLeft(void);
void turnRight(void);
void stop(void);
void speedUp(void);
void speedDown(void);
//void skill(void);

#endif

