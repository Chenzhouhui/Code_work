#include <stdio.h>

int main() {
    printf("Welcome to the Smart Home System!\n");
    /* 器件选型 
    主控：STM32F103C8T6
    HC-SR501/人体红外传感器
    BH1750/光照传感器
    MQ7/一氧化碳传感器
    MQ4/甲烷传感器
    1.44 TFT 彩屏
    AHT20/温湿度传感器
    esp8266—01sWifi模块

     外设与引脚分配（建议方案）
     1) I2C1 总线（共用）
         PB6 -> I2C1_SCL -> BH1750 SCL、AHT20 SCL
         PB7 -> I2C1_SDA -> BH1750 SDA、AHT20 SDA

     2) ADC 采样
         PA0 -> ADC1_IN0 -> MQ7 AO（CO 浓度模拟量）
         PA1 -> ADC1_IN1 -> MQ4 AO（甲烷浓度模拟量）

     3) 人体红外（数字输入）
         PB0 -> GPIO/EXTI0 -> HC-SR501 OUT

     4) TFT 1.44 SPI 屏（以 ST7735 常见接口为例）
         PA5 -> SPI1_SCK  -> TFT SCK
         PA7 -> SPI1_MOSI -> TFT SDA/MOSI
         PA4 -> GPIO      -> TFT CS
         PA6 -> GPIO      -> TFT DC/RS
         PA8 -> GPIO      -> TFT RST
         PB1 -> TIM3_CH4  -> TFT BL（背光 PWM，可选）

     5) WiFi 模块 ESP8266-01S（USART2）
         PA2 -> USART2_TX -> ESP8266 RX
         PA3 -> USART2_RX -> ESP8266 TX
         PB10 -> GPIO     -> ESP8266 EN/CH_PD（拉高使能）
         PB11 -> GPIO     -> ESP8266 RST（低电平复位，可选）

     6) 供电与电平注意
         - STM32、BH1750、AHT20、ESP8266 使用 3.3V。
         - MQ7/MQ4 常见模块多为 5V 供电，AO 进入 PA0/PA1 前需分压到 0~3.3V。
         - TFT 若是 3.3V 逻辑版本可直连；若为 5V 逻辑需电平转换。
    */
    return 0;
}