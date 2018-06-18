/*
 * maintenance_distance.c
 *
 *  Created on: 2018年6月12日
 *  描述：距离传感器的维护模块
 *      Author: SKY
 */

#include "maintenance_distance.h"
#include "distance.h"


void maintenance_distance(void)
{

    //
        // Enable the GPIO port that is used for the on-board LED.
        //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);

        //
        // Enable the GPIO pins for the LED (PN0).
        //
    GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_2);

    if(distance_confirm_flag()) //判断距离是否小于10cm，是则发送“1”，否则发送“0”
        UARTCharPutNonBlocking(UART0_BASE, 1);
//    GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_2, GPIO_PIN_2);
    else
        UARTCharPutNonBlocking(UART0_BASE, 0);
//    GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_2, 0);
}


