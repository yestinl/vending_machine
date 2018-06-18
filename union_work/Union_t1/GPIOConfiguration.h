/*
 * GPIOConfiguration.h
 *
 *  Created on: 2018Äê6ÔÂ12ÈÕ
 *      Author: 18577
 */

#ifndef GPIOCONFIGURATION_H_
#define GPIOCONFIGURATION_H_
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

#define F0 GPIO_PIN_0
#define F4 GPIO_PIN_4
#define N0 GPIO_PIN_0
#define N1 GPIO_PIN_1
#define L0 GPIO_PIN_0
#define L1 GPIO_PIN_1
#define L2 GPIO_PIN_2
#define L3 GPIO_PIN_3
#define K7 GPIO_PIN_7

void configure_GPIOF(void);
void configure_GPION(void);
void configure_GPIOK(void);
void configure_GPIOL(void);

#endif /* GPIOCONFIGURATION_H_ */
