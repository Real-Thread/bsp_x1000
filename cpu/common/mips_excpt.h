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
 * 2016/9/7       Urey         the first version
 */

#ifndef _MIPS_EXCPT_H_
#define _MIPS_EXCPT_H_

#include "mips_regs.h"

#ifndef __ASSEMBLY__
typedef void (* exception_func_t)(mips_reg_ctx *regs);

int rt_hw_exception_init(void);
exception_func_t rt_set_except_vector(int n, exception_func_t func);
void install_default_execpt_handle(void);
#endif /* __ASSEMBLY__ */
#endif /* _MIPS_EXCPT_H_ */
