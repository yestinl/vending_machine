/*
 * IntCardReadHandler.c
 * �������忨�󷢳���Ƭ��Ϣ���жϷ������
 *  Created on: 2018��6��17��
 *      Author: 18577
 */

#include "IntCardReadHandler.h"

void IntCardReadHandler(void)
{
    InfraRed_led_transmit();
    IntDisable(INT_GPIOA);
}