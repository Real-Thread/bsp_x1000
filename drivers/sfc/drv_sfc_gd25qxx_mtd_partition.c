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
 * 2017-04-19     Urey         the first version
 */

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <drivers/mtd_nor.h>

#include "board.h"
#include "drv_clock.h"
#include "drv_gpio.h"
#include "drv_sfc.h"
#include "mtd_nor_partition.h"

static struct rt_mtd_nor_partition _sf_gd25_parts[] =
{
    {
        /* sf01 u-boot 512K */
        .name       = "uboot",
        .offset     = 0x0,
        .size       = (0x80000),
        .mask_flags = PART_FLAG_RDONLY | PART_TYPE_BLK,     /* force read-only */
    },

    {
        /* kernel */
        .name       = "kernel",
        .offset     = 0x80000,
        .size       = 0x380000,
        .mask_flags = PART_FLAG_RDONLY | PART_TYPE_BLK,     /* force read-only */
    },

    {
        /* rootfs */
        .name       = "rootfs",
        .offset     = 0x400000,
        .size       = 0x800000,
        .mask_flags = PART_FLAG_RDONLY | PART_TYPE_BLK,     /* force read-only & Block device */
    },

    {
        /* sf04 appfs 2M*/
        .name       = "appfs",
        .offset     = 0xE00000,
        .size       = 0x200000,
        .mask_flags = PART_FLAG_RDWR | PART_TYPE_BLK,     /* force read-only & Block device */
    },

    //end
    {
        .name = (char *)0
    }
};


int rt_hw_gd25qxx_mtd_part_init(const char *mtd_name)
{
    mtd_nor_init_partition(mtd_name,_sf_gd25_parts);

    return 0;
}
