/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2021,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		��ɿƼ�����ת����ģ��
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32F12K
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2021-08-27
 * @note		
					���߶��壺
					------------------------------------ 
					����ת����      ��Ƭ��                        
					RX              �鿴SEEKFREE_BLUETOOTH_CH9141.h�ļ��е�BLUETOOTH_CH9141_UART_TX�궨��
					TX              �鿴SEEKFREE_BLUETOOTH_CH9141.h�ļ��е�BLUETOOTH_CH9141_UART_RX�궨��
					RTS             �鿴SEEKFREE_BLUETOOTH_CH9141.h�ļ��е�BLUETOOTH_CH9141_RTS_PIN�궨��
					CTS             ����
					CMD             ���ջ�������
					------------------------------------ 
 ********************************************************************************************************************/
 
#ifndef SEEKFREE_BLUETOOTH_CH9141_H
#define SEEKFREE_BLUETOOTH_CH9141_H

#include "common.h"






#define BLUETOOTH_CH9141_INDEX              UART_2                              // ����ģ���Ӧʹ�õĴ��ں�
#define BLUETOOTH_CH9141_TIMER              TIM_2                               // ����ģ���Ӧʹ�õĶ�ʱ��
#define BLUETOOTH_CH9141_BUAD_RATE          115200                              // ����ģ���Ӧʹ�õĴ��ڲ�����
#define BLUETOOTH_CH9141_TX_PIN             UART2_TX_P47                        // ����ģ���Ӧģ��� TX Ҫ�ӵ���Ƭ���� RX
#define BLUETOOTH_CH9141_RX_PIN             UART2_RX_P46                        // ����ģ���Ӧģ��� RX Ҫ�ӵ���Ƭ���� TX
#define BLUETOOTH_CH9141_RTS_PIN            P07                                 // ����ģ���Ӧģ��� RTS ����

#define BLUETOOTH_CH9141_DATA_BUF       	S2BUF

#define BLUETOOTH_CH9141_BUFFER_SIZE        64
#define BLUETOOTH_CH9141_TIMEOUT_COUNT      500


uint8       bluetooth_ch9141_init               (void);
void 		bluetooth_ch9141_uart_callback 		(uint8 dat);

uint8 		bluetooth_ch9141send_byte			(uint8 dat);
uint32      bluetooth_ch9141_send_buff          (uint8 *buff, uint32 len);
uint32      bluetooth_ch9141_read_buff          (uint8 *buff, uint32 len);



#endif