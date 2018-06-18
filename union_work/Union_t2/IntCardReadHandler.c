/*
 * IntCardReadHandler.c
 * 描述：插卡后发出卡片信息的中断服务程序
 *  Created on: 2018年6月17日
 *      Author: 18577
 */

#include "IntCardReadHandler.h"

void IntCardReadHandler(void)
{
    InfraRed_led_transmit();
    IntDisable(INT_GPIOA);
}
