/*
 * distance.h
 *
 *  Created on: 2018Äê6ÔÂ10ÈÕ
 *      Author: 18577
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_

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

#include "vl6180x_i2c.h"

#define confirm_distance 0x64
int distance_confirm_flag(void);

#endif /* DISTANCE_H_ */
