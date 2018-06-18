/*
 * distance.c
 *描述：
 *       距离传感器sda接pb3 scl接pb2，完成距离小于10cm后改变FLAG的功能
 *  Created on: 2018年6月10日
 *      Author: 18577
 */


#include "distance.h"

uint8_t data_staus=0, data_id;
//距离传感器距离
uint8_t distance=0;

int distance_confirm_flag(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);                 //设置系统时钟源

    IIC_Init();
    VL6180X_Init();
    data_id = VL6180X_CheckID();  // 0x03
    distance = RangePollingRead();

    if(distance <= confirm_distance)
        return 1;
    else
        return 0;
}
