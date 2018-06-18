/*
 * get_number_cubic.h
 *
 *  Created on: 2018Äê6ÔÂ17ÈÕ
 *      Author: 18577
 */

#ifndef GET_NUMBER_CUBIC_H_
#define GET_NUMBER_CUBIC_H_

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <UARTConfiguration.h>
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

void GetOneBlue(void);
void GetTwoBlue(void);
void GetOneRed(void);
void GetTwoRed(void);
void GetOneGreen(void);
void GetTwoGreen(void);
void GetOnePurple(void);
void GetTwoPurple(void);
void GetOneYellow(void);
void GetTwoYellow(void);
void GetOnePink(void);
void GetTwoPink(void);


#endif /* GET_NUMBER_CUBIC_H_ */
