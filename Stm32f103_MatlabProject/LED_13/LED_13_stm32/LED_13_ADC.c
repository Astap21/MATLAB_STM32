/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LED_13_ADC.c
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
#include "LED_13_ADC.h"

ADC_DataLinkTypeDef* G_ADC_Data;       /* Pointer to ADC data information*/
ADC_HandleTypeDef* G_ADC_Handler;      /* Pointer to ADC handler */

/* ADC1 Regular channel Converted value buffer */
uint16_t ADC1_RegularConvertedValue[1];

/* ADC1 data information*/
ADC_DataLinkTypeDef ADC1_DataLink;

/*******************************************************************************
 * Function Name  : HAL_ADC_ConvCpltCallback
 * Description    : Regular interrupt conversion complete callback
 * Input          : ADC_HandleTypeDef*
 *******************************************************************************/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
{
  ADC_DataLinkTypeDef* pL_ADC_Data = G_ADC_Data;/* Pt to ADC data information */
  ADC_HandleTypeDef* pL_ADC_Handler = G_ADC_Handler;/* Pt to ADC handler */
  if (pL_ADC_Handler == AdcHandle) {
    if (pL_ADC_Data->useDMA == false) {
      /* Process It for current received channel */
      /* Store converted value of current regular channel */
      pL_ADC_Data->RegularValueBuffer[pL_ADC_Data->RegularCurrentRank] =
        HAL_ADC_GetValue(AdcHandle);

      /*Increment rank for next conversion*/
      pL_ADC_Data->RegularCurrentRank++;

      /* Test for max conversion channel number */
      if (pL_ADC_Data->RegularCurrentRank >= pL_ADC_Data->nbRegChannel) {
        pL_ADC_Data->RegularCurrentRank = 0;
      }
    }

    if (pL_ADC_Data->ItEOCFcn != NULL) {
      /* Call End Of Conversion function */
      pL_ADC_Data->ItEOCFcn();
    }

    if (pL_ADC_Data->useDMA == true) {
      if (pL_ADC_Data->ItDMAFullFcn != NULL) {
        /* Call DMA transfer complete function */
        pL_ADC_Data->ItDMAFullFcn();
      }

      /* Re-start DMA acqusition */
      HAL_ADC_Start_DMA(AdcHandle, (uint32_t*)pL_ADC_Data->RegularValueBuffer,
                        pL_ADC_Data->DMABuffSize);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED_13_ADC.c
 */
