#include "funcation.h"
#include "led.h"

void fun1()
{
	LED0 = 0;
}

void fun2()
{
	LED0 = 1;
}

void fun3()
{
	LED1 = ~LED1;
}
