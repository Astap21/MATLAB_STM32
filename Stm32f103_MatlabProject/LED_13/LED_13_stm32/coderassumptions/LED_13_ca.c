/*
 * File: LED_13_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "LED_13_ca.h"

CA_HWImpl_TestResults CA_LED_13_HWRes;
CA_PWS_TestResults CA_LED_13_PWSRes;
const CA_HWImpl CA_LED_13_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "STMicroelectronics->STM32 32-bit Cortex-M",/* HWDeviceType */
  0                                    /* MemoryAtStartup */
};

CA_HWImpl CA_LED_13_ActHW;
void LED_13_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_LED_13_ActHW, &CA_LED_13_ExpHW,
    &CA_LED_13_PWSRes);
  caVerifyHWImpl(&CA_LED_13_ActHW, &CA_LED_13_ExpHW, &CA_LED_13_HWRes);
}
