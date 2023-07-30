#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t V_Outcome,R_Outcome,L_Outcome,T_Outcome;
int main(void)
{
	OLED_Init();
	AD_Init();
	OLED_ShowString(1,1,"V Outcome:");
	OLED_ShowString(2,1,"R Outcome:");
	OLED_ShowString(3,1,"L Outcome:");
	OLED_ShowString(4,1,"T Outcome:");
	while (1)
	{
		V_Outcome=Get_Outcome(ADC_Channel_0);
		R_Outcome=Get_Outcome(ADC_Channel_1);
		L_Outcome=Get_Outcome(ADC_Channel_2);
		T_Outcome=Get_Outcome(ADC_Channel_3);
	}
}
/*如果要避免由于波动导致AD值在判断阈值附近抖动进而影响输出，可迟滞比较。
例如，当AD值大于阈值时，输出高电平，当AD值小于阈值减去一个迟滞值时，输出低电平。
与GPIO的施密特触发器类似
为了避免抖动还可以使用软件滤波，即对AD值进行多次采样，取平均值作为最终结果。
或者裁剪分辨率，例如将12位的AD值裁剪为8位，去掉数据尾数，这样也可以避免抖动。
*/
