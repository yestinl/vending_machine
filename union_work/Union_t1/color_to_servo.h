/*
 * InfraRed_led.h
 *
 *  Created on: 2018Äê6ÔÂ10ÈÕ
 *      Author: 18577
 */

#ifndef COLOR_TO_SERVO_H_
#define COLOR_TO_SERVO_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "GPIOConfiguration.h"
#include "color_judge.h"

void color_to_servo(void);

#endif /* COLOR_TO_SERVO_H_ */
