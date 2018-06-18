/*
 * color_judge.h
 *
 *  Created on: 2018Äê6ÔÂ10ÈÕ
 *      Author: 18577
 */

#ifndef COLOR_JUDGE_H_
#define COLOR_JUDGE_H_

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"
#include "inc/hw_nvic.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pwm.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/i2c.h"
#include "driverlib/systick.h"
#include "driverlib/rom.h"
#include "driverlib/fpu.h"
#include "utils/uartstdio.h"
#include "utils/softi2c.h"

#include "TCS34725_file.h"
#include "softi2c.h"
#include "UARTConfiguration.h"

#define blue_r 0x19
#define blue_g 0x2E
#define blue_b 0x27
#define red_r 0x4B
#define red_g 0x0E
#define red_b 0x0D
#define green_r 0x35
#define green_g 0x30
#define green_b 0x16
#define purple_r 0x21
#define purple_g 0x19
#define purple_b 0x1D


//#define blue_r 0x24
//#define blue_g 0x4A
//#define blue_b 0x3E
//#define red_r 0x65
//#define red_g 0x16
//#define red_b 0x13
//#define green_r 0x4D
//#define green_g 0x62
//#define green_b 0x22
//#define purple_r 0x28
//#define purple_g 0x20
//#define purple_b 0x25
#define yellow_r 0x93
#define yellow_g 0x71
#define yellow_b 0x24
//#define pink_r 0x78
//#define pink_g 0x37
//#define pink_b 0x34
#define pink_r 0x5A
#define pink_g 0x26
#define pink_b 0x24
int color_judge(void);

#endif /* COLOR_JUDGE_H_ */
