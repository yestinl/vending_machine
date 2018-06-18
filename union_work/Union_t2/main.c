#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <UARTConfiguration.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"
#include "inc/hw_nvic.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pwm.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/i2c.h"
#include "driverlib/systick.h"
#include "driverlib/rom.h"
#include "driverlib/fpu.h"
#include "utils/uartstdio.h"
#include "utils/softi2c.h"

#include "TCS34725_file.h"
#include "softi2c.h"
#include "vl6180x_i2c.h"
#include "distance.h"
#include "InfraRed_led.h"
#include "color_judge.h"
#include "GPIOConfiguration.h"
#include "color_to_servo.h"
#include "CardTranOnce.h"

extern int tran_code;
int prev_code = 0;

void IntConfiguration(void)
{
    IntMasterEnable();
    IntEnable(INT_GPIOA);
    IntPrioritySet(INT_GPIOA, 0x00);
}

void Configuration(void)
{
    ConfigureUART();
    configure_GPIOF();
    configure_GPION();
    configure_GPIOK();
    configure_GPIOL();
    IntConfiguration();
}

int main(void)
{
    Configuration();
    while(1)
    {
        color_to_servo();     //ͨ����鲻ͬ��ɫʹ���ת������ͬλ��
        InfraRed_led_read();  //��ȡ��Ƭ��Ϣ
        distance_confirm_flag();//���ж�ȡ���봫��������
        if(prev_code==0)      //ÿ�ζ���ֻ��һ�ο�Ƭ��Ϣ
        {
            prev_code = tran_code;
            if(tran_code!=0)
            {
                   HWREG(NVIC_SW_TRIG) = INT_GPIOA - 16;
            }
        }
        else
        {
            if(prev_code==tran_code)
                   continue;
            else
            {
                prev_code = tran_code;
                IntEnable(INT_GPIOA);
                if(tran_code!=0)
                {
                    HWREG(NVIC_SW_TRIG) = INT_GPIOA - 16;
                }
            }
        }
    }
}
