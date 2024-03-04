#include "stm32f10x.h"                  // Device header


void LED_Init_01(void) {
    // 时钟使能
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    // 定义结构体，设置端口输入输出模式
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_SetBits(GPIOA, GPIO_Pin_0);
    GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

// A0灯亮
void LED_Green_On(void) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_0);
}
// A1灯亮
void LED_Red_On(void) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}
// A0灯灭
void LED_Green_Off(void) {
    GPIO_SetBits(GPIOA, GPIO_Pin_0);
}
// A1灯灭
void LED_Red_Off(void) {
    GPIO_SetBits(GPIOA, GPIO_Pin_1);
}
