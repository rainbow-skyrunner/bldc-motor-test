/**
 * @file bldc_driver.h
 * @brief BLDC电机驱动层头文件
 * @author Rainbow Skyrunner
 * @date 2025-03-17
 */

#ifndef BLDC_DRIVER_H
#define BLDC_DRIVER_H

#include <stdint.h>

/**
 * @brief 初始化GPIO引脚
 * @param None
 * @return None
 */
void BLDC_GPIO_Init(void);

/**
 * @brief 初始化定时器PWM
 * @param None
 * @return None
 */
void BLDC_PWM_Init(void);

/**
 * @brief 初始化霍尔传感器接口
 * @param None
 * @return None
 */
void BLDC_Hall_Init(void);

/**
 * @brief 初始化ADC
 * @param None
 * @return None
 */
void BLDC_ADC_Init(void);

/**
 * @brief 设置PWM占空比
 * @param duty PWM占空比值(0-1000)
 * @return None
 */
void BLDC_Set_PWM_Duty(uint16_t duty);

/**
 * @brief 获取霍尔传感器状态
 * @param None
 * @return 霍尔传感器状态(0-7)
 */
uint8_t BLDC_Get_Hall_State(void);

/**
 * @brief 获取电机电流
 * @param None
 * @return 电机电流值(mA)
 */
float BLDC_Get_Current(void);

/**
 * @brief 获取电机电压
 * @param None
 * @return 电机电压值(V)
 */
float BLDC_Get_Voltage(void);

/**
 * @brief 使能电机驱动
 * @param None
 * @return None
 */
void BLDC_Enable(void);

/**
 * @brief 禁用电机驱动
 * @param None
 * @return None
 */
void BLDC_Disable(void);

#endif /* BLDC_DRIVER_H */