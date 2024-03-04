#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Button.h"


int main(void) {
    // 定义变量
    uint8_t LightNum = 0;
    // 初始化
    OLED_Init();
    LED_Init_01();
    Button_Init();
    
    OLED_ShowChar(1, 1, '~' + 5);
    OLED_ShowChar(1, 2, '~' + 6);
    OLED_ShowString(1, 4, "HELLO,WORLD!");
    OLED_ShowNum(2, 1, 12345, 5);
    OLED_ShowSignedNum(2, 7, -66, 2);
    OLED_ShowHexNum(3, 1, 0xAA55, 4);
    OLED_ShowBinNum(4, 1, 0xAA55, 16);
    while(1) {
        uint8_t ButtonNum = Button_GetNum();
        if(ButtonNum == 1) {
            OLED_ShowNum(2, 1, ButtonNum, 5);
            if(LightNum == 0) {
                LED_Red_On();
                LED_Green_Off();
            } else {
                LED_Red_Off();
                LED_Green_On();
            }
            LightNum = 1 - LightNum;
        }
        if(ButtonNum == 2) {
            LED_Red_Off();
            LED_Green_Off();
        }
    }
}
