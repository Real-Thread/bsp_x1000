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
 * 2016-08-08     Urey         the first version
 */

#ifndef DRIVER_DRV_PMU_H_
#define DRIVER_DRV_PMU_H_

int drv_pmu_init(void);
void drv_pmu_power_up(void);
void drv_pmu_power_down(void);
int drv_pmu_get_keypwr(void);
#endif /* DRIVER_DRV_PMU_H_ */
