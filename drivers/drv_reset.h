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
 * 2016/7/29      Urey         the first version
 */

#ifndef _DRV_RESET_H_
#define _DRV_RESET_H_

/* WDT */
void wdt_start_count(int msecs);
void wdt_stop_count(void);
void wdt_clear(void);

/* hibernate */
void x1000_hibernate(void);


/* Reset */
/* reset_cmd[] = "wdt","hibernate","recovery" */
int x1000_reset(const char *reset_cmd);


#define RESET_HR_BIT	(0x01 << 3)
#define RESET_P0R_BIT	(0x01 << 2)
#define RESET_WR_BIT	(0x01 << 1)
#define RESET_PR_BIT	(0x01 << 0)
uint32_t x1000_get_last_reset(void);


#endif /* _DRV_RESET_H_ */
