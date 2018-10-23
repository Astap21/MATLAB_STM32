/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LED_13.c
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

#include "LED_13.h"
#include "LED_13_private.h"

/* Block signals (default storage) */
B_LED_13 LED_13_B;

/* Block states (default storage) */
DW_LED_13 LED_13_DW;

/* Real-time model */
RT_MODEL_LED_13 LED_13_M_;
RT_MODEL_LED_13 *const LED_13_M = &LED_13_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void LED_13_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(LED_13_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (LED_13_M->Timing.TaskCounters.TID[1])++;
  if ((LED_13_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    LED_13_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void LED_13_step0(void)                /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void LED_13_step1(void)                /* Sample time: [0.1s, 0.0s] */
{
  uint8_T rtb_Output;

  /* S-Function (ADC_Read): '<Root>/ADC_Read' */
  /* S-Function Block: <Root>/ADC_Read */

  /* Get regular rank1 output value from ADC1 regular value buffer */
  LED_13_B.ADC_Read = (uint16_t)ADC1_RegularConvertedValue[0];

  /* Re-Start interrupt conversion for ADC1 regular channel*/
  HAL_ADC_Start_IT(&hadc1);

  /* UnitDelay: '<S1>/Output' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  Sum: '<S3>/FixPt Sum1'
   */
  rtb_Output = (uint8_T)(LED_13_DW.Output_DSTATE + 1U);

  /* If: '<Root>/If' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  if (LED_13_DW.Output_DSTATE > 5) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */

    /* S-Function (GPIO_Write): '<S2>/GPIO_Write1' */
    /* S-Function Block: <S2>/GPIO_Write1 */

    //
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  }

  /* End of If: '<Root>/If' */

  /* Switch: '<S4>/FixPt Switch' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (rtb_Output > 10) {
    rtb_Output = 0U;
  }

  /* End of Switch: '<S4>/FixPt Switch' */

  /* S-Function (STM32_Config): '<Root>/STM32_Config' */
  /* S-Function Block: <Root>/STM32_Config */

  /* Update for UnitDelay: '<S1>/Output' */
  LED_13_DW.Output_DSTATE = rtb_Output;
}

/* Model step wrapper function for compatibility with a static main program */
void LED_13_step(int_T tid)
{
  switch (tid) {
   case 0 :
    LED_13_step0();
    break;

   case 1 :
    LED_13_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void LED_13_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LED_13_M, 0,
                sizeof(RT_MODEL_LED_13));

  /* block I/O */
  (void) memset(((void *) &LED_13_B), 0,
                sizeof(B_LED_13));

  /* states (dwork) */
  (void) memset((void *)&LED_13_DW, 0,
                sizeof(DW_LED_13));

  /* user code (Start function Body) */

  /* ADC1 initialization */
  /*Store ADC1 data information and its handler */
  G_ADC_Data = &ADC1_DataLink;
  G_ADC_Handler = &hadc1;
  ADC1_DataLink.RegularValueBuffer = ADC1_RegularConvertedValue;
  ADC1_DataLink.RegularCurrentRank = 0;
  ADC1_DataLink.nbRegChannel = 1;
  ADC1_DataLink.InjectedValueBuffer = NULL;
  ADC1_DataLink.InjectedCurrentRank = ADC_INJECTED_RANK_1;
  ADC1_DataLink.nbInjChannel = 0;

  /* Interrupt vector initialization */
  ADC1_DataLink.ItEOCFcn = NULL;
  ADC1_DataLink.ItJEOCFcn = NULL;
  ADC1_DataLink.ItAWDFcn = NULL;
  ADC1_DataLink.ItOVRFcn = NULL;
  ADC1_DataLink.ItDMAFullFcn = NULL;
  ADC1_DataLink.ItDMAHalfFullFcn = NULL;

  /* Force data alignment to Right */
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;

  /* DMA not used */
  ADC1_DataLink.useDMA = false;

  /* EOC/JEOC at end of single channel conversion */
  ADC1_DataLink.IntEndOfAllConv = false;

  /* Start interrupt conversion for ADC1 regular channel*/
  HAL_ADC_Start_IT(&hadc1);

  /* Start for S-Function (ADC_Read): '<Root>/ADC_Read' */
  ;
  ;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED_13.c
 */
