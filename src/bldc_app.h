/**
 * @file bldc_app.h
 * @brief BLDC电机应用层头文件
 * @author Rainbow Skyrunner
 * @date 2025-03-17
 */

#ifndef BLDC_APP_H
#define BLDC_APP_H

#include <stdint.h>
#include "bldc_control.h"

/**
 * @brief 故障代码枚举
 */
typedef enum {
    BLDC_FAULT_NONE = 0,          /**< 无故障 */
    BLDC_FAULT_OVERCURRENT = 1,    /**< 过流故障 */
    BLDC_FAULT_OVERVOLTAGE = 2,    /**< 过压故障 */
    BLDC_FAULT_UNDERVOLTAGE = 3,   /**< 欠压故障 */
    BLDC_FAULT_OVERTEMP = 4,       /**< 过温故障 */
    BLDC_FAULT_HALL_ERROR = 5,     /**< 霍尔传感器故障 */
    BLDC_FAULT_STALL = 6           /**< 堵转故障 */
} BLDC_Fault_t;

/**
 * @brief 初始化电机应用
 * @param None
 * @return None
 */
void BLDC_App_Init(void);

/**
 * @brief 电机启动
 * @param None
 * @return None
 */
void BLDC_Start(void);

/**
 * @brief 电机停止
 * @param None
 * @return None
 */
void BLDC_Stop(void);

/**
 * @brief 设置电机速度
 * @param speed 目标速度(RPM)
 * @return None
 */
void BLDC_Set_Speed(float speed);

/**
 * @brief 设置电机转矩
 * @param torque 目标转矩(百分比，0-100)
 * @return None
 */
void BLDC_Set_Torque(float torque);

/**
 * @brief 故障处理
 * @param fault_code 故障代码
 * @return None
 */
void BLDC_Fault_Handler(BLDC_Fault_t fault_code);

/**
 * @brief 获取当前故障代码
 * @param None
 * @return 当前故障代码
 */
BLDC_Fault_t BLDC_Get_Fault(void);

/**
 * @brief 清除故障
 * @param None
 * @return None
 */
void BLDC_Clear_Fault(void);

/**
 * @brief 电机应用主循环
 * @param None
 * @return None
 */
void BLDC_App_Loop(void);

#endif /* BLDC_APP_H */