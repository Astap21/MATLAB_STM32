/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.c
 *
 * Code generated for Simulink model :LED_13.
 *
 * Model version      : 1.5
 * Simulink Coder version    : 8.14 (R2018a) 06-Feb-2018
 * TLC version       : 8.14 (Feb 22 2018)
 * C/C++ source code generated on  : Fri Jul 13 14:20:11 2018
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

/* USER CODE BEGIN 0 */
#include <stdio.h>
#include "LED_13.h"                    /* Model's header file */
#include "rtwtypes.h"                  /* MathWorks types */

/* Real-time model */
extern RT_MODEL_LED_13 *const LED_13_M;

/* Set which subrates need to run this base step (base rate always runs).*/
/* Defined in LED_13.c file */
extern void LED_13_SetEventsForThisBaseStep(boolean_T*);

/* Flags for taskOverrun */
static boolean_T OverrunFlags[2];

/* Number of auto reload timer rotation computed */
static volatile uint32_t autoReloadTimerLoopVal_S = 1;

/* Remaining number of auto reload timer rotation to do */
static volatile uint32_t remainAutoReloadTimerLoopVal_S = 1;

/* USER CODE END 0 */

/****************************************************
   main function
   Example of main :
   - Clock configuration
   - call Initialize
   - Wait for systick (infinite loop)
 *****************************************************/
int main (void)
{
  /* USER CODE BEGIN 1 */
  /* Data initialization */
  int_T i;
  boolean_T eventFlags[2];             /* Model has 2 rates */

  /* USER CODE END 1 */

  /* USER CODE BEGIN 2 */
  /* Systick configuration and enable SysTickHandler interrupt */
  if (SysTick_Config((uint32_t)(SystemCoreClock * 0.01))) {
    autoReloadTimerLoopVal_S = 1;
    do {
      autoReloadTimerLoopVal_S++;
    } while ((uint32_t)(SystemCoreClock * 0.01)/autoReloadTimerLoopVal_S >
             SysTick_LOAD_RELOAD_Msk);

    SysTick_Config((uint32_t)(SystemCoreClock * 0.01)/autoReloadTimerLoopVal_S);
  }

  remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S;//Set nb of loop to do

  /* USER CODE END 2 */

  /* USER CODE BEGIN WHILE */
  for (i=0;i<2;i++) {
    OverrunFlags[i] = 0;
  }

  /* Model initialization call */
  LED_13_initialize();

  /* Infinite loop */
  /* Real time from systickHandler */
  while (1) {
    /*Process tasks every solver time*/
    if (remainAutoReloadTimerLoopVal_S == 0) {
      remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S;

      /* Check base rate for overrun */
      if (OverrunFlags[0]) {
        rtmSetErrorStatus(LED_13_M, "Overrun");
      }

      OverrunFlags[0] = true;

      /*
       * For a bare-board target (i.e., no operating system), the rates
       * that execute this base step are buffered locally to allow for
       * overlapping preemption.  The generated code includes function
       * writeCodeInfoFcn() which sets the rates
       * that need to run this time step.  The return values are 1 and 0
       * for true and false, respectively.
       */
      LED_13_SetEventsForThisBaseStep(eventFlags);

      /* Step the model for base rate */
      LED_13_step(0);

      /* Get model outputs here */

      /* Indicate task for base rate complete */
      OverrunFlags[0] = false;

      /* Step the model for any subrate */
      for (i = 1; i < 2; i++) {
        if (eventFlags[i]) {
          if (OverrunFlags[i]) {
            rtmSetErrorStatus(LED_13_M, "Overrun");
          }

          OverrunFlags[i] = true;

          /* Step the model for subrate "i" */
          LED_13_step(i);

          /* Indicate task complete for sample time "i" */
          OverrunFlags[i] = false;
        }
      }
    }
  }

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */
/****************************************************
   SysTick_Handler callback function
   This handler is called every tick and schedules tasks
 *****************************************************/
void HAL_SYSTICK_Callback(void)
{
  /* For TIME OUT processing */
  HAL_IncTick();

  /* Manage nb of loop before interrupt has to be processed */
  if (remainAutoReloadTimerLoopVal_S) {
    remainAutoReloadTimerLoopVal_S--;
  }
}

/* USER CODE END 4 */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] main.c
 */
