#ifndef __BSP_MOTOR_TIM_H
#define	__BSP_MOTOR_TIM_H

#include "stm32h7xx.h"
#include ".\bldcm_control\bsp_bldcm_control.h"

/* �������תʵ�ֽṹ�� */

#define SPEED_FILTER_NUM      30    // �ٶ��˲�����

typedef struct
{
  int32_t timeout;            // ��ʱ�����¼���
  float speed;                // ����ٶ� rps��ת/���ӣ�
  int32_t enable_flag;        // ���ʹ�ܱ�־
  int32_t speed_group[SPEED_FILTER_NUM];
  int32_t location;
}motor_rotate_t;

/* ������ƶ�ʱ�� */
#define MOTOR_TIM           				      TIM1
#define MOTOR_TIM_CLK_ENABLE()  			    __TIM1_CLK_ENABLE()
extern TIM_HandleTypeDef  htimx_bldcm;

/* �ۼ� TIM_Period�������һ�����»����ж�		
	����ʱ����0������5599����Ϊ5600�Σ�Ϊһ����ʱ���� */
#define PWM_PERIOD_COUNT     (5600)

#define PWM_MAX_PERIOD_COUNT    (PWM_PERIOD_COUNT - 100)

/* ��ʱ��ʱ��ԴTIMxCLK = 2 * PCLK1  
					PCLK1 = HCLK / 4 
					=> TIMxCLK=HCLK/2=SystemCoreClock/2=240MHz
	 �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT)/PWM_PERIOD_COUNT = 14.28KHz*/
#define PWM_PRESCALER_COUNT     (3)

/* TIM8ͨ��1������� */
#define MOTOR_OCPWM1_PIN           		    GPIO_PIN_9
#define MOTOR_OCPWM1_GPIO_PORT     		    GPIOE
#define MOTOR_OCPWM1_GPIO_CLK_ENABLE() 	  __GPIOE_CLK_ENABLE()
#define MOTOR_OCPWM1_AF					          GPIO_AF1_TIM1

/* TIM8ͨ��2������� */
#define MOTOR_OCPWM2_PIN           		    GPIO_PIN_11
#define MOTOR_OCPWM2_GPIO_PORT     		    GPIOE
#define MOTOR_OCPWM2_GPIO_CLK_ENABLE() 	  __GPIOE_CLK_ENABLE()
#define MOTOR_OCPWM2_AF					          GPIO_AF1_TIM1

/* TIM8ͨ��3������� */
#define MOTOR_OCPWM3_PIN           		    GPIO_PIN_13
#define MOTOR_OCPWM3_GPIO_PORT     		    GPIOE
#define MOTOR_OCPWM3_GPIO_CLK_ENABLE() 	  __GPIOE_CLK_ENABLE()
#define MOTOR_OCPWM3_AF					          GPIO_AF1_TIM1

/* TIM8ͨ��1����������� */
#define MOTOR_OCNPWM1_PIN            		  GPIO_PIN_13
#define MOTOR_OCNPWM1_GPIO_PORT      		  GPIOB
#define MOTOR_OCNPWM1_GPIO_CLK_ENABLE()	  __GPIOB_CLK_ENABLE()
#define MOTOR_OCNPWM1_AF					        GPIO_AF1_TIM1

/* TIM8ͨ��2����������� */
#define MOTOR_OCNPWM2_PIN            		  GPIO_PIN_14
#define MOTOR_OCNPWM2_GPIO_PORT      		  GPIOB
#define MOTOR_OCNPWM2_GPIO_CLK_ENABLE()	  __GPIOB_CLK_ENABLE()
#define MOTOR_OCNPWM2_AF					        GPIO_AF1_TIM1

/* TIM8ͨ��3����������� */
#define MOTOR_OCNPWM3_PIN            		  GPIO_PIN_15
#define MOTOR_OCNPWM3_GPIO_PORT      		  GPIOB
#define MOTOR_OCNPWM3_GPIO_CLK_ENABLE()	  __GPIOB_CLK_ENABLE()
#define MOTOR_OCNPWM3_AF					        GPIO_AF1_TIM1

#define TIM_COM_TS_ITRx                   TIM_TS_ITR2    // �ڲ���������(TIM8->ITR3->TIM5)

/* ������������ʱ�� */
#define HALL_TIM           				      TIM3
#define HALL_TIM_CLK_ENABLE()  			    __TIM3_CLK_ENABLE()

extern TIM_HandleTypeDef htimx_hall;

/* �ۼ� TIM_Period�������һ�����»����ж�		
	����ʱ����0������4999����Ϊ5000�Σ�Ϊһ����ʱ���� */
#define HALL_PERIOD_COUNT     (10000)

/* ��ʱ��ʱ��ԴTIMxCLK = 2 * PCLK1  
					PCLK1 = HCLK / 4 
					=> TIMxCLK=HCLK/2=SystemCoreClock/2=240MHz
	 �趨��ʱ��Ƶ��Ϊ = TIMxCLK / (PWM_PRESCALER_COUNT + 1) / PWM_PERIOD_COUNT = 10Hz
   ���� T = 100ms */
#define HALL_PRESCALER_COUNT     (2400)

/* TIM5 ͨ�� 1 ���� */
#define HALL_INPUT1_PIN           		    GPIO_PIN_6
#define HALL_INPUT1_GPIO_PORT     		    GPIOC
#define HALL_INPUT1_GPIO_CLK_ENABLE() 	  __GPIOC_CLK_ENABLE()
#define HALL_INPUT1_AF					          GPIO_AF2_TIM3

/* TIM5 ͨ�� 2 ���� */
#define HALL_INPUT2_PIN           		    GPIO_PIN_7
#define HALL_INPUT2_GPIO_PORT     		    GPIOC
#define HALL_INPUT2_GPIO_CLK_ENABLE() 	  __GPIOC_CLK_ENABLE()
#define HALL_INPUT2_AF					          GPIO_AF2_TIM3

/* TIM5 ͨ�� 3 ���� */
#define HALL_INPUT3_PIN           		    GPIO_PIN_8
#define HALL_INPUT3_GPIO_PORT     		    GPIOC
#define HALL_INPUT3_GPIO_CLK_ENABLE() 	  __GPIOC_CLK_ENABLE()
#define HALL_INPUT3_AF					          GPIO_AF2_TIM3

#define HALL_TIM_IRQn                    TIM3_IRQn
#define HALL_TIM_IRQHandler              TIM3_IRQHandler

extern TIM_HandleTypeDef TIM_TimeBaseStructure;

void PWM_TIMx_Configuration(void);
void stop_pwm_output(void);
void set_pwm_pulse(uint16_t pulse);
float get_motor_speed(void);
float get_motor_location(void);

void hall_enable(void);
void hall_disable(void);
void hall_tim_config(void);

#endif /* __BSP_MOTOR_TIM_H */

