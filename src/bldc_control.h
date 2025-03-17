/**
 * @file bldc_control.h
 * @brief BLDC电机控制层头文件
 * @author Rainbow Skyrunner
 * @date 2025-03-17
 */

#ifndef BLDC_CONTROL_H
#define BLDC_CONTROL_H

#include <stdint.h>
#include "bldc_driver.h"

/**
 * @brief 电机旋转方向枚举
 */
typedef enum {
    BLDC_DIR_CW = 0,    /**< 顺时针方向 */
    BLDC_DIR_CCW = 1     /**< 逆时针方向 */
} BLDC_Direction_t;

/**
 * @brief 电机控制模式枚举
 */
typedef enum {
    BLDC_MODE_OPEN_LOOP = 0,    /**< 开环控制模式 */
    BLDC_MODE_SPEED = 1,         /**< 速度控制模式 */
    BLDC_MODE_TORQUE = 2         /**< 转矩控制模式 */
} BLDC_Mode_t;

/**
 * @brief 电机状态枚举
 */
typedef enum {
    BLDC_STATE_STOP = 0,         /**< 停止状态 */
    BLDC_STATE_STARTING = 1,      /**< 启动中状态 */
    BLDC_STATE_RUNNING = 2,       /**< 运行状态 */
    BLDC_STATE_FAULT = 3          /**< 故障状态 */
} BLDC_State_t;

/**
 * @brief 初始化电机控制
 * @param None
 * @return None
 */
void BLDC_Control_Init(void);

/**
 * @brief 执行六步换向
 * @param hall_state 霍尔传感器状态(0-7)
 * @return None
 */
void BLDC_Six_Step_Commutation(uint8_t hall_state);

/**
 * @brief 计算电机速度
 * @param None
 * @return 电机速度(RPM)
 */
float BLDC_Calculate_Speed(void);

/**
 * @brief 速度PID控制器
 * @param target_speed 目标速度(RPM)
 * @param current_speed 当前速度(RPM)
 * @return PID控制器输出值
 */
float BLDC_Speed_PID_Controller(float target_speed, float current_speed);

/**
 * @brief 电流限制
 * @param current 当前电流值(mA)
 * @return None
 */
void BLDC_Current_Limitation(float current);

/**
 * @brief 设置电机方向
 * @param direction 电机方向(BLDC_DIR_CW/BLDC_DIR_CCW)
 * @return None
 */
void BLDC_Set_Direction(BLDC_Direction_t direction);

/**
 * @brief 设置电机控制模式
 * @param mode 控制模式
 * @return None
 */
void BLDC_Set_Mode(BLDC_Mode_t mode);

/**
 * @brief 获取电机状态
 * @param None
 * @return 电机状态
 */
BLDC_State_t BLDC_Get_State(void);

#endif /* BLDC_CONTROL_H */