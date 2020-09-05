/*
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co.,Ltd
 *
 * This software is dual-licensed: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation. For the terms of this
 * license, see <http://www.gnu.org/licenses/>.
 *
 * You are free to use this software under the terms of the GNU General
 * Public License, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * Alternatively for commercial application, you can contact us
 * by email <business@rt-thread.com> for commercial license.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-11-8      Tangyuxin    first version
 */

#include <rtthread.h>

#include <board.h>
#include <drv_gpio.h>

void blink_task(void* param)
{
    rt_uint8_t cnt = 0;
    
    while(1)
    {
        rt_thread_delay(RT_TICK_PER_SECOND / 4);

        if(cnt & 0x01)
            gpio_set_value(BLINK_LED0_PORT,BLINK_LED0_PIN,0);
        else
            gpio_set_value(BLINK_LED0_PORT,BLINK_LED0_PIN,1);

        if(cnt & 0x02)
            gpio_set_value(BLINK_LED1_PORT,BLINK_LED1_PIN,0);
        else
            gpio_set_value(BLINK_LED1_PORT,BLINK_LED1_PIN,1);

        if(cnt & 0x04)
            gpio_set_value(BLINK_LED2_PORT,BLINK_LED2_PIN,0);
        else
            gpio_set_value(BLINK_LED2_PORT,BLINK_LED2_PIN,1);

        if(cnt & 0x08)
            gpio_set_value(BLINK_LED3_PORT,BLINK_LED3_PIN,0);
        else
            gpio_set_value(BLINK_LED3_PORT,BLINK_LED3_PIN,1);

        cnt ++;
    }
}

int blink_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("blink",
                           blink_task, RT_NULL,
                           512,
                           RT_THREAD_PRIORITY_MAX - 2,
                           10);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
}
INIT_APP_EXPORT(blink_init);
