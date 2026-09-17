/**
 ****************************************************************************************************
 * @file        main.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2021-10-14
 * @brief       跑马灯 实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 探索者 F407开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "app_led.h"
#include "app_print.h"
#include "version.h"


int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(336, 8, 2, 7); /* 设置时钟,168Mhz */
    delay_init(168);                    /* 延时初始化 */
    App_LedDemo_Init();                 /* 应用模块初始化 */
    App_Print_Init();

    // 上电串口打印固件版本
    printf("\r\n=====================================\r\n");
    printf("Firmware Version: %s\r\n", FW_APP_VERSION);
    printf("Git Commit Hash:  %s\r\n", FW_GIT_HASH);
    printf("Build Time:       %s\r\n", FW_BUILD_TIME);
    printf("=====================================\r\n");

    while (1)
    {
        App_LedDemo_Run();
        App_Print_Run();
    }
}
