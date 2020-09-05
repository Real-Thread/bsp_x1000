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
 * 2017-02-19     RealThread   the first version
 */

#ifndef BOARD_HALLEY2_IDELAN_H__
#define BOARD_HALLEY2_IDELAN_H__

#define AUDIO_SHUTDOWN_PORT     GPIO_PORT_B
#define AUDIO_SHUTDOWN_PIN      GPIO_Pin_7
#define AUDIO_SHUTDOWN_MUTE     1

/*
 * IO LCD
 */
#define LCD_PWEN_PORT           GPIO_PORT_B
#define LCD_PWEN_PIN            GPIO_Pin_19 //原理图不对，实际连接到LCD_TE

#define LCD_RST_PORT            GPIO_PORT_B
#define LCD_RST_PIN             GPIO_Pin_14

#define LCD_BL_PORT             GPIO_PORT_B
#define LCD_BL_PIN              GPIO_Pin_9

/*
 * IO Touch
 */
#define TP_INT_PORT             GPIO_PORT_B
#define TP_INT_PIN              GPIO_Pin_11

#define TP_RST_PORT             GPIO_PORT_B
#define TP_RST_PIN              GPIO_Pin_12

#define TP_PWEN_PORT            GPIO_PORT_B
#define TP_PWEN_PIN             GPIO_Pin_15


/*
 * IO KeyBoard:
 */
#define KEY_WIFI_PORT           GPIO_PORT_A
#define KEY_WIFI_PIN            GPIO_Pin_20

#define KEY_BT_PORT             GPIO_PORT_A
#define KEY_BT_PIN              GPIO_Pin_21

#define KEY_VOLD_PORT           GPIO_PORT_A
#define KEY_VOLD_PIN            GPIO_Pin_22

#define KEY_VOLU_PORT           GPIO_PORT_B
#define KEY_VOLU_PIN            GPIO_Pin_28

#define KEY_WKUP_PORT           GPIO_PORT_B
#define KEY_WKUP_PIN            GPIO_Pin_31

/*
 * IO Camera
 */
#define CIM_PWDN_PORT           GPIO_PORT_A
#define CIM_PWDN_PIN            GPIO_Pin_25
#define CIM_RST_PORT            GPIO_PORT_A
#define CIM_RST_PIN             GPIO_Pin_24
#define CIM_PWEN_PORT           GPIO_PORT_A
#define CIM_PWEN_PIN            GPIO_Pin_23
/*
 * IO LED Config
 */
#define LED_BT_PORT             GPIO_PORT_B
#define LED_BT_PIN              GPIO_Pin_6

#define LED_WIFI_PORT           GPIO_PORT_B
#define LED_WIFI_PIN            GPIO_Pin_24

#define LED_ZB_PORT             GPIO_PORT_C
#define LED_ZB_PIN              GPIO_Pin_27

/*
 * Others
 */

#define IO_IRQ_FG_PORT          GPIO_PORT_B
#define IO_IRQ_FG_PIN           GPIO_Pin_13


#endif
