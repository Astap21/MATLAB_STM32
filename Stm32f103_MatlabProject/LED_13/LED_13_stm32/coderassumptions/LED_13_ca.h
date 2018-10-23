/*
 * File: LED_13_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef LED_13_CA_H
#define LED_13_CA_H

/* preprocessor validation checks */
#include "LED_13_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_LED_13_HWRes;
extern CA_PWS_TestResults CA_LED_13_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_LED_13_ExpHW;
extern CA_HWImpl CA_LED_13_ActHW;

/* entry point function to run tests */
void LED_13_caRunTests(void);

#endif                                 /* LED_13_CA_H */
