#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
int main(void)
{
	OLED_Init();
	OLED_ShowString(1, 3, "Hello VS Code!");
	
	while (1)
	{
		
	}
}
