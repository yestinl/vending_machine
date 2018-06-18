/*
 * GPIOConfiguration.c
 *������ʱ��ʹ��GPIO�˿ڣ�����PF4Ϊ������1�Ŀ��ƹܽ�
 *      ʱ��ʹ��GPIO�˿ڣ�����PF4Ϊ������1�Ŀ��ƹܽ�
 *      PK1�Ǵ�����2�Ŀ��ƹܽţ�
 *      PN1��PN0��PF4Ϊ��ת����Ŀ��ƹܽ�
 *      PL0��PL1��PL2��PL3��ȡ���⴫�������ص�����
 *  Created on: 2018��6��12��
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
