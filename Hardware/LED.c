#include "stm32f10x.h"                  // Device header
#define LED_RCC_APB2Periph RCC_APB2Periph_GPIOA
#define LED_0_GPIO_PIN GPIO_Pin_0
#define LED_1_GPIO_PIN GPIO_Pin_1
#define LED_GPIOx GPIOA

void LED_Init_01(void) {
    // 时钟使能 
    RCC_APB2PeriphClockCmd(LED_RCC_APB2Periph, ENABLE);
    // 定义结构体，设置端口输入输出模式
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = LED_0_GPIO_PIN | LED_1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_GPIOx, &GPIO_InitStructure);
    
    GPIO_SetBits(LED_GPIOx, LED_0_GPIO_PIN);
    GPIO_SetBits(LED_GPIOx, LED_1_GPIO_PIN);
}

// A0灯亮
void LED_Green_On(void) {
    GPIO_ResetBits(LED_GPIOx, LED_0_GPIO_PIN);
}
// A1灯亮
void LED_Red_On(void) {
    GPIO_ResetBits(LED_GPIOx, LED_1_GPIO_PIN);
}
// A0灯灭
void LED_Green_Off(void) {
    GPIO_SetBits(LED_GPIOx, LED_0_GPIO_PIN);
}
// A1灯灭
void LED_Red_Off(void) {
    GPIO_SetBits(LED_GPIOx, LED_1_GPIO_PIN);
}
