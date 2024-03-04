#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Buzzer_Init(void) {
    // 时钟使能
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    // 定义结构体，设置端口输入输出模式
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

// 蜂鸣器响
void Buzzer_On(void) {
    GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

// 蜂鸣器关
void Buzzer_Off(void) {
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

// 蜂鸣器指定毫秒时间响
void Buzzer_On_ms(int ms) {
    Buzzer_On();
    Delay_ms(ms);
    Buzzer_Off();
}