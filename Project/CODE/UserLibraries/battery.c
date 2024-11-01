/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company			�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32F12K
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2023-11-18
 * @note		    ��AI���� By JNU-FLY
 ********************************************************************************************************************/

#include "headfile.h"

#define BAT_VOL_PIN ADC_P05

uint16 ad_result = 0;           // ���ŵ�ѹ
uint16 battery_voltage = 0;     // ��ص�ѹ
uint32 temp;

/**
 * @brief ��ʼ����ص�ѹ���ģ��
 * 
 * �ú�����ʼ�����ڵ�ص�ѹ����ADCģ�顣
 */
void battery_init(void){
    adc_init(BAT_VOL_PIN, ADC_SYSclk_DIV_32);
}

/**
 * @brief ��ȡ��ص�ѹ
 * 
 * �ú���ͨ��ADC��ȡ��ص�ѹ�������ݷ�ѹ�������ʵ�ʵ�ص�ѹ��
 * �����ص�ѹ����6.5V������ʾ��LOW BATTERY����ֹͣ�����������battery.h���޸�LOW_BATTERY_VOLTAGE��ֵΪ-1���ô˹���
 * 
 * @return uint16 ���ص�ص�ѹ����λΪ����
 */
uint16 get_battery_voltage(void){
    ad_result = adc_once(BAT_VOL_PIN, ADC_12BIT);
    temp = (((uint32)ad_result * 3300) / 4095);  //�������ǰadc���ŵĵ�ѹ ���㹫ʽΪ ad_result*VCC/ADC�ֱ���    VCC��λΪmv
    battery_voltage =  temp * 11; //�������ŵ�ѹ  �ͷ�ѹ�������ֵ�����ص�ѹ ���㹫˾Ϊ   ���ŵ�ѹ*(R2+R3)/R3   R3Ϊ�ӵض˵���
    while (battery_voltage < LOW_BATTERY_VOLTAGE){
        ips200_show_string(120,200,"LOW BATTERY");
        drv8701_stop(MOTOR_BOTH); //ֹͣ�����ֹ��ع���
        while(ENABLE_LOW_BATTERY_PROTECTION)
        delay_ms(10000); // ���������ֹ��������
    }
    
    return battery_voltage;
}

uint16 get_battery_percentage(void){
    int max_voltage = 4200 * BATTERY_GROUP_NUM;
    int min_voltage = LOW_BATTERY_VOLTAGE * BATTERY_GROUP_NUM;
    int current_voltage = get_battery_voltage();
    int percentage = (current_voltage - min_voltage) * 100 / (max_voltage - min_voltage);
    if (percentage > 100){
        percentage = 100;
    }
    if (percentage < 0){
        percentage = 0;
    }
    return percentage;
}

