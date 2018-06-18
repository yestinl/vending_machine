/*
 * InfraRed_led.c
 * 描述：
 *      红外头向自己为0、1、2、3，对管0、1、2、3分别接PL3、PL2、PL1、PL0，实现卡片编号通过串口传输到GUI
 *  Created on: 2018年6月10日
 *      Author: 18577
 */
#include "InfraRed_led.h"

//****************************************************************************
//
// System clock rate in Hz.
//
//****************************************************************************
uint32_t g_ui32SysClock;

int tran_code;
int infra_code[4];

void InfraRed_led_read(void)
{
    configure_GPIOL();
    if(GPIOPinRead(GPIO_PORTL_BASE,L0))
    {
             infra_code[0] = 0;
    }
    else
    {
            infra_code[0] = 1;
    }
    if(GPIOPinRead(GPIO_PORTL_BASE,L1))
    {
            infra_code[1] = 0;
    }
    else
    {
            infra_code[1] = 1;
    }
    if(GPIOPinRead(GPIO_PORTL_BASE,L2))
    {
            infra_code[2] = 0;
    }
    else
    {
            infra_code[2] = 1;
    }
    if(GPIOPinRead(GPIO_PORTL_BASE,L3))
    {
            infra_code[3] = 0;
    }
    else
    {
            infra_code[3] = 1;
    }
    tran_code = infra_code[0]*8+infra_code[1]*4+infra_code[2]*2+infra_code[3]*1;
}
void InfraRed_led_transmit(void)
 {
    //
    // Set the clocking to run directly from the crystal at 120MHz.
    //
    g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                         SYSCTL_OSC_MAIN |
                                         SYSCTL_USE_PLL |
                                         SYSCTL_CFG_VCO_480), 120000000);

    //
    // Enable the peripherals used by this example.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

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

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);

    GPIOPinTypeGPIOInput(GPIO_PORTL_BASE,L0|L1|L2|L3);
    if(GPIOPinRead(GPIO_PORTL_BASE,L0))
    {
         infra_code[0] = 0;
    }
    else
    {
         infra_code[0] = 1;
    }
    if(GPIOPinRead(GPIO_PORTL_BASE,L1))
    {
         infra_code[1] = 0;
    }
    else
    {
         infra_code[1] = 1;
    }
    if(GPIOPinRead(GPIO_PORTL_BASE,L2))
    {
         infra_code[2] = 0;
    }
    else
    {
         infra_code[2] = 1;
    }
    if(GPIOPinRead(GPIO_PORTL_BASE,L3))
    {
         infra_code[3] = 0;
    }
    else
    {
         infra_code[3] = 1;
    }
    tran_code = infra_code[0]*8+infra_code[1]*4+infra_code[2]*2+infra_code[3]*1;
    switch(tran_code)
    {
        case 0:
            UARTCharPutNonBlocking(UART0_BASE, 0);
//            UARTSend((uint8_t *)"Blank", 5);
            break;
        case 1:
            UARTCharPutNonBlocking(UART0_BASE, 1);
//            UARTSend((uint8_t *)"Red", 3);
            break;
        case 2:
            UARTCharPutNonBlocking(UART0_BASE, 2);
//            UARTSend((uint8_t *)"Green", 5);
            break;
        case 4:
            UARTCharPutNonBlocking(UART0_BASE, 4);
//            UARTSend((uint8_t *)"Blue", 4);
            break;
        case 8:
            UARTCharPutNonBlocking(UART0_BASE, 8);
//            UARTSend((uint8_t *)"Yellow", 6);
            break;
        case 3:
            UARTCharPutNonBlocking(UART0_BASE, 3);
//            UARTSend((uint8_t *)"Purple", 6);
            break;
        case 5:
            UARTCharPutNonBlocking(UART0_BASE, 5);
//            UARTSend((uint8_t *)"White", 5);
            break;
        case 9:
            UARTCharPutNonBlocking(UART0_BASE, 9);
//            UARTSend((uint8_t *)"Black", 5);
            break;
        default:
            UARTCharPutNonBlocking(UART0_BASE, 10);
//            UARTSend((uint8_t *)"Error", 5);
            break;
    }
    DelayMS(50);
}



