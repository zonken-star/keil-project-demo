#include "app_led.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"


static uint32_t tick = 0;  // 私有变量，只在本模块内，不暴露到main

void App_LedDemo_Init(void)
{
    // 这里可以放业务初始化，当前例子无额外初始化
    led_init(); 
    tick = 0;
}

void App_LedDemo_Run(void)
{
    LED0(0);         /* LED0亮 */
    LED1(1);         /* LED1灭 */
    delay_ms(500);
    LED0(1);         /* LED0灭 */
    LED1(0);         /* LED1亮 */
    delay_ms(500);
}
