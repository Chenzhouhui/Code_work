#include <stdio.h>

int main() {
    printf("Welcome to the Smart Home System!\n");
    /* 器件选型 
    主控：STM32F103C8T6
    HC-SR501/人体红外传感器 5V
    BH1750/光照传感器 3.3V
    MQ7/一氧化碳传感器 5V
    MQ4/甲烷传感器 5V
    1.44 TFT 彩屏 3.3V
    AHT20/温湿度传感器 3.3V
    esp8266—01sWifi模块 3.3V

    外设与引脚分配(保留调试串口:USART1 PA9/PA10)
    1)MQ-4甲烷传感器：
    VCC --> 5V
    GND --> GND
    DO --> PB0(GPIO输入/可EXTI,需3.3V)
    AO --> PA0(ADC1_IN0,需分压)
    ------------------------------------------------
    2)MQ-7一氧化碳传感器：
    VCC --> 5V
    GND --> GND
    DO --> PB1(GPIO输入/可EXTI,需3.3V)
    AO --> PA1(ADC1_IN1,需分压)
    ------------------------------------------------
    3)BH1750光照传感器：
    VCC --> 3.3V
    GND --> GND
    SCL --> PB6(I2C1_SCL)
    SDA --> PB7(I2C1_SDA)
    ADDR --> GND(0x23)
    --------------------------------------------------
    4)AHT20温湿度传感器：
    3V3 --> 3.3V
    SDA --> PB7(与BH1750共线)
    SCL --> PB6(与BH1750共线)
    GND --> GND
    --------------------------------------------------
     5)HC-SR501人体红外传感器：
    VCC --> 5V
    GND --> GND
    OUT --> PB10(GPIO输入/可EXTI)
    ----------------------------------------------------
    6)1.44 TFT 彩屏：
    VCC --> 3.3V(建议)
    GND --> GND
    CS --> PA4
    RESET --> PB13(GPIO输出)
    RS(DC) --> PB12(GPIO输出)
    SDI(MOSI) --> PA7(SPI1_MOSI)
    SCK --> PA5(SPI1_SCK)
    LED --> PB14(TIM1_CH2 PWM调光)
    ----------------------------------------------------
    7)ESP8266-01S WiFi模块：
    VCC --> 3.3V(>=500mA)
    GND --> GND
    TX --> PA3(USART2_RX,3.3V)
    RX --> PA2(USART2_TX,3.3V)
    */
    return 0;
}