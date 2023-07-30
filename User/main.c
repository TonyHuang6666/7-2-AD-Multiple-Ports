#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
int main(void)
{
	OLED_Init();
	AD_Init();
	OLED_ShowString(1,1,"AD Outcome:");
	while (1)
	{
		OLED_ShowNum(1,12,Get_Outcome(),4);
	}
}
