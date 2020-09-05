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
 * 2016/9/19      Urey         the first version
 */

#ifndef _X1000_CACHE_H_
#define _X1000_CACHE_H_

#include "../common/mips.h"
#include "../common/mips_cache.h"


void rt_hw_icache_invalidate_all(void);
void rt_hw_icache_flush_all(void);

void rt_hw_dcache_flush_all(void);
void rt_hw_dcache_flush_range(rt_uint32_t addr, rt_uint32_t size);
void rt_hw_dcache_invalidate_all(void);
void rt_hw_dcache_invalidate_range(rt_uint32_t addr,rt_uint32_t size);

void rt_hw_flush_cache_all(void);
#endif /* _X1000_CACHE_H_ */
