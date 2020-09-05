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
 * 2015-11-19     Urey         the first version
 */

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>

#include <stdint.h>

#include "board.h"
#include "drv_clock.h"
#include "drv_ost.h"

/**
 * This is the OST timer interrupt service routine.
 */
void rt_hw_ost_handler(void)
{
    /* increase a OS tick */
    rt_tick_increase();

    /* clear flag */
    REG_OSTFR = 0;
}

int rt_hw_ost_init(void)
{
    rt_uint32_t cnt, div;
    struct clk  *clk;

    div = OST_DIV16;
    cnt = BOARD_EXTAL_CLK / 16;

    /* enable OST clock */
    clk = clk_get("sys_ost");
    clk_enable(clk);

    /* Disable OST (channel 1/2) */
    REG_OSTECR = 0x3;

    /* clear counter */
    REG_OSTCR = 0x01;
    REG_OST1CNT = 0;

    /* set timer data (channel 1) */
    REG_OST1DFR   = (cnt / RT_TICK_PER_SECOND - 1);

    /* set prescale ext clk */
    REG_OSTCCR = div;

    /* unmask interrupt */
    REG_OSTMR = 0;

    /* enable OST (channel 1) */
    REG_OSTESR = 0x01;

    clk_put(clk);

    return 0;
}

#include <finsh.h>
int ost(int argc, char** argv)
{
    rt_kprintf("OSTCCR = 0x%08x\n", REG_OSTCCR);
    rt_kprintf("OSTER = 0x%08x\n", REG_OSTER);
    rt_kprintf("count = 0x%08x\n", REG_OST1CNT);

    rt_kprintf("TCU_TER = 0x%08x\n", REG_TCU_TER);

    return 0;
}
MSH_CMD_EXPORT(ost, ost debug);
