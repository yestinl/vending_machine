/*
 * color_judge.c
 *  描述：颜色传感器pn5-scl pn4-sda，实现颜色判断并返回颜色编号
 *  Created on: 2018年6月10日
 *      Author: 18577
 */
#include "color_judge.h"

//三个颜色的距离
uint32_t blue_distance=0;
uint32_t red_distance=0;
uint32_t green_distance=0;
uint32_t purple_distance=0;
uint32_t yellow_distance=0;
uint32_t pink_distance=0;

//当前检测距离各个颜色中心的最小距离
uint16_t color_min_distance;
//最终颜色编号
uint8_t result_color=0x01;

uint16_t light;

uint32_t g_ui32SysClock;


int color_judge(void)
{

    //读三个通道颜色信息，分别取其高八位至同一数组中存储
        uint8_t readdata1[2];  //red channel
        uint8_t readdata2[2];  //green channel
        uint8_t readdata3[2];  //blue channel
        uint32_t readdata[3];
    //
    // Set the clocking to run directly from the crystal at 120MHz.
    //
    g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL |
                                             SYSCTL_CFG_VCO_480), 120000000);

    SysTickPeriodSet(SysCtlClockGet());
    SysTickEnable();
    //
    // Enable the GPIO port
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C2);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    GPIOPinConfigure(GPIO_PN5_I2C2SCL);
    GPIOPinConfigure(GPIO_PN4_I2C2SDA);

    //
    // Enable the GPIO
    //
    GPIOPinTypeI2C(GPIO_PORTN_BASE,GPIO_PIN_4);
    GPIOPinTypeI2CSCL(GPIO_PORTN_BASE,GPIO_PIN_5);

    I2CMasterInitExpClk(I2C2_BASE,SysCtlClockGet(),false);

    //TCS34725_Disable();
    TCS34725_Enable();
    TCS34725_SetIntegrationTime(TCS34725_INTEGRATIONTIME_700MS);
    TCS34725_SetGain(TCS34725_GAIN_4X);
    Delay_ms(50);

//    while(1)
//    {

        I2CMasterReadTCS34725(readdata1,SLAVE_ADDRESS,RED_ADDR,2);//RED_ADDR BLUE_ADDR GREEN_ADDR
        Delay_ms(50);
        I2CMasterReadTCS34725(readdata2,SLAVE_ADDRESS,GREEN_ADDR,2);//RED_ADDR BLUE_ADDR GREEN_ADDR
        Delay_ms(50);
        I2CMasterReadTCS34725(readdata3,SLAVE_ADDRESS,BLUE_ADDR,2);//RED_ADDR BLUE_ADDR GREEN_ADDR
        Delay_ms(50);
        readdata[0] = readdata1[1];
        readdata[1] = readdata2[1];
        readdata[2] = readdata3[1];
        //利用曼哈顿距离算法计算和物体颜色和六个颜色中心的距离值，通过比较最小值得出物块颜色
        blue_distance=(fabs(readdata[0]-blue_r)+fabs(readdata[1]-blue_g)+fabs(readdata[2]-blue_b))/3;
        red_distance=(fabs(readdata[0]-red_r)+fabs(readdata[1]-red_g)+fabs(readdata[2]-red_b))/3;
        green_distance=(fabs(readdata[0]-green_r)+fabs(readdata[1]-green_g)+fabs(readdata[2]-green_b))/3;
        purple_distance=(fabs(readdata[0]-purple_r)+fabs(readdata[1]-purple_g)+fabs(readdata[2]-purple_b))/3;
        yellow_distance=(fabs(readdata[0]-yellow_r)+fabs(readdata[1]-yellow_g)+fabs(readdata[2]-yellow_b))/3;
        pink_distance=(fabs(readdata[0]-pink_r)+fabs(readdata[1]-pink_g)+fabs(readdata[2]-pink_b))/3;

        color_min_distance=blue_distance;
        result_color=0x01;
        if(red_distance<color_min_distance)
        {
            color_min_distance=red_distance;
            result_color=0x02;
        }
        if(green_distance<color_min_distance)
        {
            color_min_distance=green_distance;
            result_color=0x03;
        }
        if(purple_distance<color_min_distance)
        {
            color_min_distance=purple_distance;
            result_color=0x04;
        }
        if(yellow_distance<color_min_distance)
        {
            color_min_distance=yellow_distance;
            result_color=0x05;
        }
        if(pink_distance<color_min_distance)
        {
            color_min_distance=pink_distance;
            result_color=0x06;
        }
        //在与颜色中心距离小于0x23的前提下，进行颜色的返回
        if(color_min_distance<=0x55)
        {
            return result_color;
        }
        else
            return 0;
     //}
}





