#include "stm32f10x.h"
#include "Delay.h"

#define BUZZER_RCC_APB2Periph    RCC_APB2Periph_GPIOB
#define BUZZER_GPIO_PIN          GPIO_Pin_12
#define BUZZER_GPIOx             GPIOB

void Buzzer_Init(void) {
    // 时钟使能
    RCC_APB2PeriphClockCmd(BUZZER_RCC_APB2Periph, ENABLE);
    // 定义结构体，设置端口输入输出模式
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = BUZZER_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BUZZER_GPIOx, &GPIO_InitStructure);
    
    GPIO_SetBits(BUZZER_GPIOx, BUZZER_GPIO_PIN);
}

// 蜂鸣器响
void Buzzer_On(void) {
    GPIO_ResetBits(BUZZER_GPIOx, BUZZER_GPIO_PIN);
}

// 蜂鸣器关
void Buzzer_Off(void) {
    GPIO_SetBits(BUZZER_GPIOx, BUZZER_GPIO_PIN);
}

// 蜂鸣器指定毫秒时间响
void Buzzer_On_ms(int ms) {
    Buzzer_On();
    Delay_ms(ms);
    Buzzer_Off();
}