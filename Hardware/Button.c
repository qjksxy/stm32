#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"

// 引脚初始化
void Button_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

// 按键按下检测
uint8_t Button_GetNum(void) {
    uint8_t ButtonNum = 0;
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 0) {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 0);
        Delay_ms(20);
        ButtonNum = 1;
    }
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == 0) {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == 0);
        Delay_ms(20);
        ButtonNum = 2;
    }
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7) == 0) {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7) == 0);
        Delay_ms(20);
        ButtonNum = 3;
    }
    if(ButtonNum != 0) {
        OLED_Show_Int_Info(ButtonNum);
    }
    return ButtonNum;
}