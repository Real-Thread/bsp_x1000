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
#include <rtdevice.h>

#ifdef RT_USING_DFS
#include <dfs_fs.h>

int mnt_init(void)
{
    rt_kprintf("init filesystem...\n");
#ifdef RT_USING_MTD_NOR
    //mount rootfs
    if (dfs_mount("rootfs", "/", "elm", 0, 0) == 0)
    {
        rt_kprintf("File System on root initialized!\n");
    }
    else
    {
        rt_kprintf("File System on root initialization failed!\n");
    }

    //mount appfs
    if (dfs_mount("appfs", "/appfs", "elm", 0, 0) == 0)
    {
        rt_kprintf("File System on appfs initialized!\n");
    }
    else
    {
        rt_kprintf("File System on appfs initialization failed!\n");
    }
#endif

#if (defined(RT_USING_SDIO) && defined(RT_USING_MSC0))
    rt_thread_delay(RT_TICK_PER_SECOND/5);
    if (dfs_mount("sd0", "/sd", "elm", 0, 0) == 0)
    {
        rt_kprintf("File System on TF initialized!\n");
    }
    else
    {
        rt_kprintf("File System on TF fail!\n");
    }
#endif

    return 0;
}
INIT_ENV_EXPORT(mnt_init);

#endif
