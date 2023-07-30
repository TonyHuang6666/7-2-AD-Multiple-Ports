#include "stm32f10x.h"
/*
在扫描模式的情况下，每一个单独的通道都会被转换，但是只有第一个通道的转换结果会被保存到DR寄存器中，
在非扫描模式的情况下，只有第一个通道的转换结果会被保存到DR寄存器中。每个通道转换完以后不会产生任何
标志位或者中断，只有当所有通道都转换完以后，才会产生转换完成标志位EOC。如果要用手动转运的方式来处理
每个通道的转换结果，可以使用间断模式，每次转换一个通道，转运完数据以后再触发，转换下一个通道。（不建议）
如果真的要用扫描模式，则应该配合DMA使用，这样每个通道的转换结果都会被保存到DR寄存器中。
*/
void AD_Init(void)
{
    //1.配置时钟及ADCCLK的分频器
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);//使能ADC1时钟
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);//ADCCLK=PCLK2/6=72/6=12MHz
    //2.配置GPIO
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//模拟输入，相当于断开了GPIO
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;//PA0~3
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA
    //3.配置多路开关（选择规则组输入通道）
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);//软件触发转换
    //4.配置ADC
    ADC_InitTypeDef ADC_InitStructure;
    ADC_StructInit(&ADC_InitStructure);//ADC结构体先赋初始值
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐
     ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//软件触发转换（不使用外部触发）
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;//连续转换模式
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;//扫描模式
    ADC_InitStructure.ADC_NbrOfChannel = 1;//通道数（扫描模式才有用，非扫描只用第一个序列）
    ADC_Init(ADC1, &ADC_InitStructure);//初始化ADC1
    //5.开启ADC的电源
    ADC_Cmd(ADC1, ENABLE);//使能ADC1
    //6.校准ADC
    ADC_ResetCalibration(ADC1);
    while(ADC_GetResetCalibrationStatus(ADC1)==SET)
    {
        ;
    }//等待校准完成
    ADC_StartCalibration(ADC1);
    while(ADC_GetCalibrationStatus(ADC1)==SET)
    {
        ;
    }//等待校准完成
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);//软件触发转换
}

uint16_t Get_Outcome(uint8_t ADC_Channel)
{ 
    ADC_RegularChannelConfig(ADC1, ADC_Channel, 1 , ADC_SampleTime_1Cycles5);
    return ADC_GetConversionValue(ADC1);//读取转换结果时，会自动清除转换完成标志位EOC
    //等待时间的计算：采样周期55.5个，转换周期12.5个，总共68个周期，即68个周期/12MHz=5.6us
}
