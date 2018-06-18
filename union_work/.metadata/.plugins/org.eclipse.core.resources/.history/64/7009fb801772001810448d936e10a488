/*
 * UARTSend.c
 * 描述：
 * UART配置函数、多字符发送函数、中断服务函数
 *  Created on: 2018年6月10日
 *      Author: 18577
 */

#include <UARTConfiguration.h>


uint32_t g_ui32SysClock;
//串口初始化配置
void ConfigureUART(void)
{
    //
        // Set the clocking to run directly from the crystal at 120MHz.1g
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

        //
        // Enable the peripherals used by this example.
        //
        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

        //
        // Enable processor interrupts.
        //
        IntMasterEnable();

        //
        // Set GPIO A0 and A1 as UART pins.
        //
        GPIOPinConfigure(GPIO_PA0_U0RX);
        GPIOPinConfigure(GPIO_PA1_U0TX);
        GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

        //
        // Configure the UART for 115,200, 8-N-1 operation.
        //
        UARTConfigSetExpClk(UART0_BASE, g_ui32SysClock, 115200,
                                (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                 UART_CONFIG_PAR_NONE));

        //
        // Enable the UART interrupt.
        //
        IntEnable(INT_UART0);
        UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);

}
//串口发送多字符函数
void UARTSend(const uint8_t *pui8Buffer, uint32_t ui32Count)
{
    //
    // Loop while there are more characters to send.
    //
    while(ui32Count--)
    {
        //
        // Write the next character to the UART.
        //
        UARTCharPutNonBlocking(UART0_BASE, *pui8Buffer++);
    }
}

//*****************************************************************************
//
// The UART interrupt handler.
//
//*****************************************************************************
void UARTIntHandler(void)
{
    uint32_t ui32Status;

    int16_t rec_num;

    //
    // Get the interrrupt status.
    //
    ui32Status = UARTIntStatus(UART0_BASE, true);
    //GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
    //
    // Clear the asserted interrupts.
    //
    UARTIntClear(UART0_BASE, ui32Status);

    //
    // Loop while there are characters in the receive FIFO.
    //
    while(UARTCharsAvail(UART0_BASE))
    {
        //
        // Read the next character from the UART and write it back to the UART.
        //
        UARTCharPutNonBlocking(UART0_BASE,
                                   UARTCharGetNonBlocking(UART0_BASE));

        rec_num=(UARTCharGetNonBlocking(UART0_BASE));

        switch (rec_num)
        {

            case 0x02://执行距离传感器维护模块
                maintenance_distance();
                break;
            case 0x03://执行旋转电机维护模块
                maintenance_rotate_servo();
                break;
            case 0x04://执行打击电机1维护模块
                maintenance_push_servo1();
                break;
            case 0x05://执行打击电机2维护模块
                maintenance_push_servo2();
                break;
            case 0x11://取出一个蓝色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);

                break;
            case 0x21://取出两个蓝色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x12://取出一个红色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x22://取出两个红色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x13://取出一个绿色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x23://取出两个绿色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x14://取出一个紫色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x24://取出两个紫色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x15://取出一个黄色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
            case 0x25://取出两个黄色木块
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
                DelayMS(30000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
                DelayMS(10000);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
                DelayMS(20000);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
                break;
//            case 0x16:
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
//                DelayMS(30000);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
//                DelayMS(10000);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
//                DelayMS(20000);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
//                break;
//            case 0x26://取出两个蓝色木块
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
//                DelayMS(30000);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
//                DelayMS(10000);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
//                DelayMS(20000);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
//                DelayMS(20000);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
//                DelayMS(30000);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
//                DelayMS(10000);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
//                DelayMS(20000);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
//                GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
//                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
//                break;
            default:
                break;
        }
    }
}
