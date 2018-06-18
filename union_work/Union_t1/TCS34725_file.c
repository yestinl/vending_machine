/*
 * TCS34725_file.c
 *
 *  Created on: 2018��5��14��
 *      Author: wzh
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pwm.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "inc/hw_i2c.h"
#include "driverlib/i2c.h"
#include "utils/uartstdio.h"
#include "utils/softi2c.h"
#include "driverlib/systick.h"
#include "driverlib/rom.h"
#include "inc/hw_nvic.h"
#include "driverlib/fpu.h"
#include "TCS34725_file.h"
void Delay_ms(uint32_t ui32Seconds)
{
    ui32Seconds = ui32Seconds/400;

    while(ui32Seconds--)
    {
        while(SysTickValueGet()>1000)
        {

        }

        while(SysTickValueGet()<1000)
        {

        }
    }
}


void I2CMasterWriteTCS34725(uint8_t *pui8data,			//д��Ĵ��������� ����
                        uint8_t ui8SlaveAddress,		//�ӻ���ַ
                        uint8_t ui8TCSAddress,			//�Ĵ�����ַ
                        uint32_t ui32Count)				//�������ݴ���
{
    uint32_t DataNumber;								//��ȡ��������

    uint32_t MsterCMD;									//���ͷ�ʽ

    I2CMasterSlaveAddrSet(I2C2_BASE,ui8SlaveAddress,false);

    I2CMasterDataPut(I2C2_BASE,ui8TCSAddress);

    I2CMasterControl(I2C2_BASE,I2C_MASTER_CMD_BURST_SEND_START);

    while(I2CMasterBusy(I2C2_BASE));
    while(!(I2CMasterErr(I2C2_BASE)==I2C_MASTER_ERR_NONE));
    Delay_ms(500);

    for(DataNumber=0;DataNumber<ui32Count;DataNumber++)
    {
        if(DataNumber==(ui32Count -1))
        {
            MsterCMD=I2C_MASTER_CMD_BURST_SEND_FINISH;
        }
        else
        {
            MsterCMD=I2C_MASTER_CMD_BURST_SEND_CONT;
        }

        I2CMasterDataPut(I2C2_BASE,*pui8data);

        I2CMasterControl(I2C2_BASE,MsterCMD);

        while(I2CMasterBusy(I2C2_BASE));
        while(!(I2CMasterErr(I2C2_BASE)==I2C_MASTER_ERR_NONE));

        pui8data ++;

    }
}



void I2CMasterReadTCS34725(uint8_t *pui8data,				//��ȡ���� ����
                        uint8_t ui8SlaveAddress,			//�ӻ���ַ
                        uint8_t ui8TCSAddress,				//�Ĵ�����ַ
                        uint32_t ui32Count)					//��ȡ���ݴ���
{
    uint32_t DataNumber;									//��ȡ��������

    uint32_t MsterCMD;										//���ͷ�ʽ

    I2CMasterSlaveAddrSet(I2C2_BASE,ui8SlaveAddress,false);

    I2CMasterDataPut(I2C2_BASE,ui8TCSAddress);

    I2CMasterControl(I2C2_BASE,I2C_MASTER_CMD_BURST_SEND_START);	//��ʼ���ʹӻ���ַ

    while(I2CMasterBusy(I2C2_BASE));
    while(!(I2CMasterErr(I2C2_BASE)==I2C_MASTER_ERR_NONE));

    I2CMasterSlaveAddrSet(I2C2_BASE,ui8SlaveAddress,true);			//��
    Delay_ms(500);
    for(DataNumber=0;DataNumber<ui32Count;DataNumber++)
    {
        if(ui32Count == 1)
        {
            MsterCMD=I2C_MASTER_CMD_SINGLE_RECEIVE;					//���ζ�ȡ
        }
        else
        {
            if(DataNumber==0)
            {
                MsterCMD=I2C_MASTER_CMD_BURST_RECEIVE_START;		//��ʼ��ȡ
            }
            else if(DataNumber==(ui32Count -1))
            {
                MsterCMD=I2C_MASTER_CMD_BURST_RECEIVE_FINISH;		//������ȡ
            }
            else
            {
                MsterCMD=I2C_MASTER_CMD_BURST_RECEIVE_CONT;			//������ȡ
            }
        }

        I2CMasterControl(I2C2_BASE,MsterCMD);

        while(I2CMasterBusy(I2C2_BASE));
        while(!(I2CMasterErr(I2C2_BASE)==I2C_MASTER_ERR_NONE));
        //Delay_ms(50);
        *pui8data =I2CMasterDataGet(I2C2_BASE);						//�����ȡ

        pui8data ++;

    }
}


void TCS34725_Enable(void)											//����
{

        uint8_t cmd = TCS34725_ENABLE_PON;					//0x01

    I2CMasterWriteTCS34725(&cmd, SLAVE_ADDRESS,TCS34725_ENABLE, 1);

    Delay_ms(500);

    cmd = TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN;

    I2CMasterWriteTCS34725(&cmd, SLAVE_ADDRESS,0xa0,1);
}




void TCS34725_SetIntegrationTime(uint8_t time)				//PMT�ӵ硢�ع��ʱ�䣬������ʽ�����ǹ��Ӽ�����Ҳ�����ǹ����������
{
    uint8_t cmd = time;
    I2CMasterWriteTCS34725(&cmd,SLAVE_ADDRESS,TCS34725_ATIME, 1);
    Delay_ms(500);
}


void TCS34725_SetGain(uint8_t ui8gain)
{
    uint8_t cmd = ui8gain;
    I2CMasterWriteTCS34725(&cmd,SLAVE_ADDRESS,TCS34725_CONTROL, 1);
    Delay_ms(500);
}



