/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		common
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32F12K
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-4-14
 ********************************************************************************************************************/

#ifndef __COMMON_H_
#define __COMMON_H_
#include "STC32Gxx.h"
#include <string.h>
#include <stdio.h>
#include "intrins.h"


#define ee_printf printf  
//������������
typedef unsigned char   uint8  ;	//  8 bits 
typedef unsigned int  	uint16 ;	// 16 bits 
typedef unsigned long  	uint32 ;	// 32 bits 
								
								
typedef signed char     int8   ;	//  8 bits 
typedef signed int      int16  ;	// 16 bits 
typedef signed long     int32  ;	// 32 bits 
								
								
typedef volatile int8   vint8  ;	//  8 bits 
typedef volatile int16  vint16 ;	// 16 bits 
typedef volatile int32  vint32 ;	// 32 bits 
								
								
typedef volatile uint8  vuint8 ;	//  8 bits 
typedef volatile uint16 vuint16;	// 16 bits 
typedef volatile uint32 vuint32;	// 32 bits 



typedef enum //����ģ��
{
    NO_WIRELESS_MODE = 0,   // û������ģ��
    WIRELESS_SI24R1 = 1,    // ����ת����
    WIRELESS_CH9141 = 2,    // ����ת����
    WIRELESS_CH573 = 3,     // CH573ģ��
	WIRELESS_BLE6A20 = 4,   // BLE6A20����ģ��
	
}WIRELESS_TYPE_enum;



extern WIRELESS_TYPE_enum wireless_type;

extern void (*wireless_module_uart_handler)(uint8 dat);


//typedef enum
//{
//    SYSTEM_CLOCK_22_1184M        = 22118400,                                         // 24Mhz
//    SYSTEM_CLOCK_48M        = 48000000,                                         // 48Mhz
//    SYSTEM_CLOCK_72M        = 72000000,                                         // 72Mhz
//    SYSTEM_CLOCK_96M        = 96000000,                                         // 96Mhz
//    SYSTEM_CLOCK_120M       = 120000000,                                        // 120Mhz
//    SYSTEM_CLOCK_144M       = 144000000,                                        // 144Mhz
//}system_clock_enum;



#endif