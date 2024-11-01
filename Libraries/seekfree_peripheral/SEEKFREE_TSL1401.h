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

#ifndef _TSL1401_c
#define _TSL1401_c

#include "common.h"
#include "zf_uart.h"
#include "board.h"

#define CCD_CLK_PIN   	P07               	//CCD CLK���Ŷ���
#define CCD_SI_PIN    	P02               	//CCD SI ���Ŷ���
#define AD_CHANNEL_CH1 	ADC_P03             //����AD�ɼ�ͨ�� ADC_P03
#define AD_CHANNEL_CH2  ADC_P05             //����AD�ɼ�ͨ��2 ADC_P05
#define EXPOSURE_TIME  	10                  //����CCD�ع�ʱ�� ��λMS
#define PIT_TIMER_CH	TIM_4				//ʹ�������ж϶�ʱ��4
#define AD_RESOLUTION	ADC_12BIT			//ADת��12λ
	


#define CCD_CLK(x)      CCD_CLK_PIN = x 
#define CCD_SI(x)       CCD_SI_PIN  = x


#define CCD_CLK(x)      CCD_CLK_PIN = x 
#define CCD_SI(x)       CCD_SI_PIN  = x


extern uint16 ccd_data_ch1[128];  			//CCD����ͨ��1
extern uint16 ccd_data_ch2[128];        	//CCD����ͨ��2
extern uint8 tsl1401_finish_flag;

void ccd_init(void);
void ccd_collect(void);
void ccd_send_data(UARTN_enum uart_n ,uint16 *dat);

#endif