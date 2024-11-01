/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2016,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		SEEKFREE_TSL1401.c
 * @brief      		�캢��(����CCD)������
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		Go For It(1325536866)
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32F12K
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2016-02-25
 * @note	
					TSL1401���߶��壺
					------------------------------------ 
					ģ��ܽ�       	��Ƭ���ܽ�
					CCD_AO	   		�鿴SEEKFREE_TSL1401.h�ļ��е�AD_CHANNEL �궨��
					CCD_CLK	   		�鿴SEEKFREE_TSL1401.h�ļ��е�CCD_CLK_PIN�궨��
					CCD_SI	   		�鿴SEEKFREE_TSL1401.h�ļ��е�CCD_SI_PIN �궨��
					------------------------------------ 
 ********************************************************************************************************************/



#include "SEEKFREE_TSL1401.h"
#include "zf_adc.h"
#include "zf_uart.h"
#include "board.h"



uint8 tsl1401_finish_flag;
uint16 ccd_data_ch1[128];                           //CCD����
uint16 ccd_data_ch2[128];                       //CCD����ͨ��2

//-------------------------------------------------------------------------------------------------------------------
//  @brief      TSL1401����CCD��ʼ��
//  @param      NULL
//  @return     void
//  @since      v1.0
//  Sample usage:			
//-------------------------------------------------------------------------------------------------------------------
void ccd_init(void)     
{       
    adc_init(AD_CHANNEL_CH1,0X01);
    adc_init(AD_CHANNEL_CH2,0X01);     
	pit_timer_ms(TIM_4,10);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      TSL1401����CCDͼ��������λ���鿴ͼ��
//  @param      uart_n			���ں�
//  @param      uart_n			����CCD����ָ��
//  @return     void			
//  @since      v1.0
//  Sample usage:				���øú���ǰ���ȳ�ʼ������
//-------------------------------------------------------------------------------------------------------------------
void ccd_send_data(UARTN_enum uart_n ,uint16 *dat)
{
   uint8 i = 0;
   uart_putchar(uart_n,0x00); 
   uart_putchar(uart_n,0xff);
   uart_putchar(uart_n,0x01);
   uart_putchar(uart_n,0x00);
   
	for(i=0; i<128; i++)        
	{
		uart_putchar(uart_n, (uint8)(dat[i]>>8));   //���͸�8λ
		uart_putchar(uart_n, (uint8)(dat[i]&0XFF)); //���͸ߵ�8λ	 	
	}
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      TSL1401����CCD���ݲɼ�
//  @param      NULL
//  @return     void
//  @since      v1.0
//  Sample usage:				��isr.c�����ȴ�����Ӧ���жϺ�����Ȼ����øú���(֮�����������жϱ�־λ)
//-------------------------------------------------------------------------------------------------------------------
void ccd_collect(void)
{
    uint8 i = 0;

    CCD_CLK(1);
    CCD_SI(0);
	CCD_CLK(0);
    CCD_SI(1);
    CCD_CLK(1);
    CCD_SI(0);
	
    for(i=0;i<128;i++)
    {
		CCD_CLK(0);  
		ccd_data_ch1[i] = adc_once(AD_CHANNEL_CH1, AD_RESOLUTION); 
        ccd_data_ch2[i] = adc_once(AD_CHANNEL_CH2, AD_RESOLUTION);
		CCD_CLK(1); 
    }
	tsl1401_finish_flag = 1;
}
