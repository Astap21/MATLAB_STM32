/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LED_13.h
 *
 * Code generated for Simulink model :LED_13.
 *
 * Model version      : 1.7
 * Simulink Coder version    : 8.14 (R2018a) 06-Feb-2018
 * TLC version       : 8.14 (Feb 22 2018)
 * C/C++ source code generated on  : Fri Jul 13 17:26:57 2018
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

#ifndef RTW_HEADER_LED_13_h_
#define RTW_HEADER_LED_13_h_
#include <string.h>
#include "STM32_Config.h"
#include "LED_13_External_Functions.h"
#ifndef LED_13_COMMON_INCLUDES_
# define LED_13_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LED_13_COMMON_INCLUDES_ */

#include "LED_13_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T Output_DSTATE;               /* '<S1>/Output' */
} DW_LED_13;

/* Real-time Model Data Structure */
struct tag_RTM_LED_13 {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block states (default storage) */
extern DW_LED_13 LED_13_DW;

/* External function called from main */
extern void LED_13_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void LED_13_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void LED_13_initialize(void);
extern void LED_13_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_LED_13 *const LED_13_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LED_13'
 * '<S1>'   : 'LED_13/Counter Limited'
 * '<S2>'   : 'LED_13/If Action Subsystem'
 * '<S3>'   : 'LED_13/Counter Limited/Increment Real World'
 * '<S4>'   : 'LED_13/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_LED_13_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED_13.h
 */
