/*
 * maintenance_distance.c
 *
 *  Created on: 2018��6��12��
 *  ���������봫������ά��ģ��
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

    if(distance_confirm_flag()) //�жϾ����Ƿ�С��10cm�������͡�1���������͡�0��
        UARTCharPutNonBlocking(UART0_BASE, 1);
//    GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_2, GPIO_PIN_2);
    else
        UARTCharPutNonBlocking(UART0_BASE, 0);
//    GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_2, 0);
}


