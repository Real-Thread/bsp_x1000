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
 * 2016/9/10      Urey         the first version
 */

#ifndef _MIPS_CFG_H_
#define _MIPS_CFG_H_

#ifndef __ASSEMBLY__
#include <stdint.h>
typedef struct mips32_core_cfg
{
    uint16_t icache_line_size;
    uint16_t icache_size;
    uint16_t dcache_line_size;
    uint16_t dcache_size;

    uint16_t max_tlb_entries;   /* number of tlb entry */
} mips32_core_cfg_t;

extern mips32_core_cfg_t g_mips_core;

#endif /* __ASSEMBLY__ */

#endif /* _MIPS_CFG_H_ */
