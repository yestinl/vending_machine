/*
 * GPIOConfiguration.c
 *描述：时钟使能GPIO端口，其中PF4为打击电机1的控制管脚
 *      时钟使能GPIO端口，其中PF4为打击电机1的控制管脚
 *      PK1是打击电机2的控制管脚，
 *      PN1、PN0、PF4为旋转电机的控制管脚
 *      PL0、PL1、PL2、PL3读取红外传感器返回的数据
 *  Created on: 2018年6月12日
 *      Author: 18577
 */

#include "GPIOConfiguration.h"

void configure_GPIOF(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, F0|F4);
}

void configure_GPION(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, N0|N1);
}

void configure_GPIOK(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);

    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, K7);
}

void configure_GPIOL(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);

    GPIOPinTypeGPIOInput(GPIO_PORTL_BASE,L0|L1|L2|L3);
}
