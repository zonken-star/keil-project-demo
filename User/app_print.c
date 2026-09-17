#include "app_print.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"


static uint32_t tick = 0;  // 私有变量，只在本模块内，不暴露到main

void App_Print_Init(void)
{
    // 这里可以放业务初始化，当前例子无额外初始化
    usart_init(115200);
    tick = 0;
}

void App_Print_Run(void)
{
    printf("hello, tick=%d\r\n", tick);
    tick++;
}
