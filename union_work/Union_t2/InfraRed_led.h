/*
 * InfraRed_led.h
 *
 *  Created on: 2018Äê6ÔÂ10ÈÕ
 *      Author: 18577
 */

#ifndef INFRARED_LED_H_
#define INFRARED_LED_H_


#include<stdint.h>
#include<stdbool.h>
#include"inc/hw_types.h"
#include"inc/hw_ints.h"
#include"inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

#include "softi2c.h"
#include "UARTConfiguration.h"
#include "GPIOConfiguration.h"

#define D1 GPIO_PIN_1
#define D2 GPIO_PIN_0
#define D3 GPIO_PIN_4
#define D4 GPIO_PIN_0
#define L0 GPIO_PIN_0
#define L1 GPIO_PIN_1
#define L2 GPIO_PIN_2
#define L3 GPIO_PIN_3
#define J1 GPIO_PIN_1
void InfraRed_led_transmit(void);
void InfraRed_led_read(void);

#endif /* INFRARED_LED_H_ */
