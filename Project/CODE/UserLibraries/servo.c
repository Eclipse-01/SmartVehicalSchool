/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣��???�ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32F12K
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"
#include "servo.h"

/*
 * �����ں�Ƶ�ʵ��趨�����Բ鿴board.h�ļ�
 * ��board_init��,�Ѿ���P54��������Ϊ��λ
 * �����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����
 */

// ����ȫ�ֱ���
uint16 ServoAngle;

/**
 *@brief  �����ʼ��
 *@note   Ҫ���ڳ�ʼ����λ�ã������޸�Center��ֵ
 */
void servo_init(void)
{
    uint32 duty = (uint32)(Center * 10000 / 20); // Center = 1 �������1ms��PWM�ź�
    pwm_init(PWMB_CH3_P33, 50, duty);            // PWMƵ����50Hz����20ms��
}

/**
 * @brief ��������õ�ָ���Ƕȡ�
 *
 * �˺�������һ���Զ�Ϊ��λ�ĽǶȣ����������������Ӧ��λ�á�
 * �Ƕ�Ӧ�ڶ��֧�ֵ���Ч��Χ�ڣ���MaxAngle�ĺ궨�塣
 *
 * @param angle Ҫ���õĶ���Ƕȣ��Զ�Ϊ��λ��
 */
void servo_set_position(uint16 angle)
{
    uint32 pulseWide = Center;
    if (angle > MaxAngle)
    {
        angle = MaxAngle;
    }
    if (angle < -MaxAngle)
    {
        angle = -MaxAngle;
    }
    pulseWide += angle * (2 / 180); // �����ʽ�ĺ��壺ÿ1ms��Ӧ�Ƕ���90�㣬���ýǶȳ���(1ms/90��)�õ���Ӧ��ms�����ټ���Center�õ����յ�ms��
    pwm_duty(PWMB_CH3_P33, pulseWide);
    ServoAngle = angle;
}

/**
 * @brief ��ȡ��ǰ����ĽǶȣ��Զ�Ϊ��λ��
 */
uint16 servo_get_angle(void)
{
    return ServoAngle;
}