/*
 * maintenance_servo.h
 *
 *  Created on: 2018Äê6ÔÂ12ÈÕ
 *      Author: 18577
 */

#ifndef MAINTENANCE_SERVO_H_
#define MAINTENANCE_SERVO_H_
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
#include "GPIOConfiguration.h"
#include "softi2c.h"
void maintenance_rotate_servo(void);
void maintenance_push_servo1(void);
void maintenance_push_servo2(void);
#endif /* MAINTENANCE_SERVO_H_ */
