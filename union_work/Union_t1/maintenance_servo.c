/*
 * maintenance_servo.c
 * 描述：电机维护模块执行程序
 *  Created on: 2018年6月12日
 *      Author: 18577
 */
#include "maintenance_servo.h"

void maintenance_rotate_servo(void)
{
    configure_GPION();
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
    DelayMS(20000);
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
}

void maintenance_push_servo1(void)
{
    configure_GPIOF();
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, F0);
    DelayMS(20000);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
}

void maintenance_push_servo2(void)
{
    configure_GPIOK();
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, K7);
    DelayMS(20000);
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, 0);
}
