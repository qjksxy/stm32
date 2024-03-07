#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#define BUTTON_RCC_APB2Periph    RCC_APB2Periph_GPIOA
#define BUTTON_1_GPIO_PIN        GPIO_Pin_3
#define BUTTON_2_GPIO_PIN        GPIO_Pin_5
#define BUTTON_3_GPIO_PIN        GPIO_Pin_7
#define BUTTON_GPIOx             GPIOA


// 引脚初始化
void Button_Init(void) {
    RCC_APB2PeriphClockCmd(BUTTON_RCC_APB2Periph, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = BUTTON_1_GPIO_PIN | BUTTON_2_GPIO_PIN | BUTTON_3_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BUTTON_GPIOx, &GPIO_InitStructure);
}

// 按键按下检测
uint8_t Button_GetNum(void) {
    uint8_t ButtonNum = 0;
    if (GPIO_ReadInputDataBit(BUTTON_GPIOx, BUTTON_1_GPIO_PIN) == 0) {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(BUTTON_GPIOx, BUTTON_1_GPIO_PIN) == 0);
        Delay_ms(20);
        ButtonNum = 1;
    }
    if (GPIO_ReadInputDataBit(BUTTON_GPIOx, BUTTON_2_GPIO_PIN) == 0) {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(BUTTON_GPIOx, BUTTON_2_GPIO_PIN) == 0);
        Delay_ms(20);
        ButtonNum = 2;
    }
    if (GPIO_ReadInputDataBit(BUTTON_GPIOx, BUTTON_3_GPIO_PIN) == 0) {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(BUTTON_GPIOx, BUTTON_3_GPIO_PIN) == 0);
        Delay_ms(20);
        ButtonNum = 3;
    }
    if(ButtonNum != 0) {
        OLED_Show_Int_Info(ButtonNum);
    }
    return ButtonNum;
}