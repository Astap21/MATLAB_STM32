/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LED_13_ADC.h
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

#ifndef RTW_HEADER_LED_13_ADC_h_
#define RTW_HEADER_LED_13_ADC_h_
#include "STM32_Config.h"
#define ADC1_DMA_BUFF_SIZE             0

/**
 * @brief  ADC data information
 */
typedef struct {
  uint16_t* RegularValueBuffer;        /*!< Regular buffer for converted value*/
  uint16_t* InjectedValueBuffer;       /*!< Injected buffer for converted value*/
  uint32_t RegularCurrentRank;         /*!< Regular current rank*/
  uint32_t InjectedCurrentRank;        /*!< Injected current rank*/
  uint32_t nbRegChannel;               /*!< Number of regular channel*/
  uint32_t nbInjChannel;               /*!< Number of injected channel*/
  uint32_t DMABuffSize;                /*!< Buffer size for DMA acquisition*/
  uint8_t useDMA;                      /*!< DMA aquisition mode */
  uint8_t IntEndOfAllConv;             /*!< EOS/JEOS Int at end of all conversions */
  void (* ItEOCFcn)(void);
  void (* ItJEOCFcn)(void);
  void (* ItAWDFcn)(void);
  void (* ItOVRFcn)(void);
  void (* ItDMAFullFcn)(void);
  void (* ItDMAHalfFullFcn)(void);
} ADC_DataLinkTypeDef;

extern ADC_DataLinkTypeDef* G_ADC_Data;/* Pointer to ADC data information*/
extern ADC_HandleTypeDef* G_ADC_Handler;/* Pointer to ADC handler */

/* ADC1 handler */
extern ADC_HandleTypeDef hadc1;

/* ADC1 Regular channel Converted value buffer */
extern uint16_t ADC1_RegularConvertedValue[1];

/* ADC1 data information*/
extern ADC_DataLinkTypeDef ADC1_DataLink;

#endif                                 /* RTW_HEADER_LED_13_ADC_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED_13_ADC.h
 */
