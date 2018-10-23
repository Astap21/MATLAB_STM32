/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "LED_13_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_LED_13_ExpHW
#define CA_Actual_HWImpl               CA_LED_13_ActHW
#define CA_HWImpl_Results              CA_LED_13_HWRes
#define CA_PortableWordSizes_Results   CA_LED_13_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   LED_13_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
