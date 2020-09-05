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
 * 2015-11-19     RealThread   the first version
 */

#ifndef BOARD_KEY_H__
#define BOARD_KEY_H__

#ifndef RT_USING_AUDIO_PLAYER
enum KEY_VALUE
{
    KEY_VOLINC,
    KEY_VOLDEC,
    KEY_NEXT,
    KEY_PREV,

    KEY_PAUSE,
    KEY_PLAY,
    KEY_PLAY_PAUSE,

    KEY_MUTE,

    KEY_MIC,
    KEY_EQ,
    KEY_MENU,
    KEY_CHANNEL,
    KEY_FAVORITE,

    //system shutdown, wifi config...
    KEY_PWROFF,
    KEY_CONFIG,
    KEY_NETWORK_MODE,

    KEY_SOURCE,
    KEY_UNKNOWN,
};
#endif

struct keyboard_io_def
{
    enum gpio_port  port;
    enum gpio_pin   pin;

    int  longKey;
    int  shortKey;
};

typedef void (*keyboard_event_handler_t)(uint32_t event);

void rt_hw_keyboard_init(void);
void rt_hw_keyboard_set_handler(keyboard_event_handler_t handler);

#endif
