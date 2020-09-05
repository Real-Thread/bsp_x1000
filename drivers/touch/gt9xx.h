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
 * 2017-01-01     Urey      first version
 */
#ifndef _GT9XX_H_
#define _GT9XX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <rtdevice.h>
#include <rtthread.h>

#define GT910_ADDR_BABBH
//#define GT910_ADDR_2829H

#ifdef GT910_ADDR_BABBH
#define GT910_IIC_ADDR         0x14//0x14//0x5D//
//#define GT910_IIC_RADDR         0x29
//#define GT910_IIC_WADDR         0x28
#else
#define GT910_IIC_RADDR         0x29
#define GT910_IIC_WADDR         0x28
#endif

extern uint16_t show_len;
extern uint16_t total_len;
extern uint8_t gtp_rawdiff_mode;

extern int tpd_halt;
extern int gtp_send_cfg(struct rt_i2c_bus_device *i2c);
extern void gtp_reset_guitar(struct rt_i2c_bus_device *i2c, int ms);
extern void gtp_int_sync(int ms);
extern uint8_t gup_init_update_proc(struct rt_i2c_bus_device *i2c);
extern uint8_t gup_init_fw_proc(struct rt_i2c_bus_device *i2c);

extern int gtp_i2c_read(struct rt_i2c_bus_device *i2c, uint8_t *buf, int len);
extern int gtp_i2c_write(struct rt_i2c_bus_device *i2c,uint8_t *buf,int len);
extern int i2c_write_bytes(struct rt_i2c_bus_device *i2c, uint16_t addr, uint8_t *txbuf, int len);
extern int i2c_read_bytes(struct rt_i2c_bus_device *i2c, uint16_t addr, uint8_t *rxbuf, int len);
extern int i2c_read_dbl_check(struct rt_i2c_bus_device *i2c, uint16_t addr, uint8_t *rxbuf, int len);
extern int gtp_i2c_read_dbl_check(struct rt_i2c_bus_device *i2c, uint16_t addr, uint8_t *rxbuf, int len);

extern void mt65xx_eint_unmask(uint32_t line);
extern void mt65xx_eint_mask(uint32_t line);

#ifdef __cplusplus
}
#endif

#endif /* _GT9XX_H_ */
