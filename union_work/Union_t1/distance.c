/*
 * distance.c
 *������
 *       ���봫����sda��pb3 scl��pb2����ɾ���С��10cm��ı�FLAG�Ĺ���
 *  Created on: 2018��6��10��
 *      Author: 18577
 */


#include "distance.h"

uint8_t data_staus=0, data_id;
//���봫��������
uint8_t distance=0;

int distance_confirm_flag(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);                 //����ϵͳʱ��Դ

    IIC_Init();
    VL6180X_Init();
    data_id = VL6180X_CheckID();  // 0x03
    distance = RangePollingRead();

    if(distance <= confirm_distance)
        return 1;
    else
        return 0;
}
