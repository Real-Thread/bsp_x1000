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
 * 2017-02-11     Urey         the first version
 */

#ifndef _SPI_FLASH_MTD_PARTITION_H_
#define _SPI_FLASH_MTD_PARTITION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <drivers/mtd_nor.h>

#define PART_FLAG_RDONLY    0x0001
#define PART_FLAG_WRONLY    0x0002
#define PART_FLAG_RDWR      0x0003

#define PART_TYPE_BLK       0x0010
#define PART_TYPE_MTD       0x0020

struct rt_mtd_nor_partition
{
    union
    {
        struct rt_mtd_nor_device    mtd;
        struct rt_device            blk;
    };

    const char *name;
    rt_uint32_t offset;             /* offset within the master MTD space */
    rt_uint32_t size;               /* partition size */
    rt_uint32_t mask_flags;         /* master MTD flags to mask out for this partition */
    void*       user_data;          /* hold parent device */
};

/*
 * functions
 */
extern rt_err_t mtd_nor_init_partition(const char *mtd_name,struct rt_mtd_nor_partition *parts);


#ifdef __cplusplus
}
#endif

#endif /* _SPI_FLASH_MTD_PARTITION_H_ */
