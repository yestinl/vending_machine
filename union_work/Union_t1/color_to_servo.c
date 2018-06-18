/*
 * servo_to_signal.c
 * 描述：通过颜色传感器返回的颜色编号输出6个不同信号至io口，进行分拣，可以通过四个小灯演示
 *
 *  Created on: 2018年6月10日
 *      Author: 18577
 */


#include <color_to_servo.h>
#include "color_judge.h"

uint32_t g_ui32SysClock;

void color_to_servo(void)
{
    int color_num;

        //
        // Set the clocking to run directly from the crystal at 120MHz.
        //
        g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                 SYSCTL_OSC_MAIN |
                                                 SYSCTL_USE_PLL |
                                                 SYSCTL_CFG_VCO_480), 120000000);
        //
        // Enable the GPIO port that is used for the on-board LED.
        //
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);


        //
        // Enable the GPIO pins for the LED (PN0).
        //
        GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
        GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);
        GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0);
        GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4);
        configure_GPIOK();
    color_num = color_judge();
    switch (color_num)
    {
                case 0x01:
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                    DelayMS(10000);
                    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, K7);
                    DelayMS(1000);
                    break;
                case 0x02:
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                    DelayMS(10000);
                    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, K7);
                    DelayMS(1000);
                    break;
                case 0x03:
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                    DelayMS(10000);
                    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, K7);
                    DelayMS(1000);
                    break;
                case 0x04:
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                    DelayMS(10000);
                    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, K7);
                    DelayMS(1000);
                    break;
                case 0x05:
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                    DelayMS(10000);
                    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, K7);
                    DelayMS(1000);
                    break;
                case 0x06:
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                    DelayMS(10000);
                    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, K7);
                    DelayMS(1000);
                    break;
                default:
                    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, 0);
                    DelayMS(20000);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                    break;
     }
//    DelayMS(10000);
}
