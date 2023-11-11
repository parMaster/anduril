// Wurkkos TS21 config options for Anduril
// Copyright (C) 2018-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// using BLF Q8 (SP36) as a base
#include "sofirn/blf-q8/anduril.h"

// TODO: calibrate voltage readings !!!
#undef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 5  // add 0.25V (5*0.05), not 0.35V (7*0.05)

// don't blink during the ramp; the button LED brightness is sufficient
// to indicate which power channel(s) are being used
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif
#ifdef BLINK_AT_RAMP_CEIL
#undef BLINK_AT_RAMP_CEIL
#endif

// stop panicking at ~60% power or ~3000 lm
#ifdef THERM_FASTER_LEVEL
#undef THERM_FASTER_LEVEL
#endif
#define THERM_FASTER_LEVEL 105

// save extra memory for USE_SMOOTH_STEPS
#ifdef USE_VERSION_CHECK
// #undef USE_VERSION_CHECK
#endif

// this one needs more memory
#define USE_SMOOTH_STEPS

// TODO: calibrate this !!!
#define THERM_CAL_OFFSET 99

// off mode: high (2)
// lockout: high (2)
#ifdef INDICATOR_LED_DEFAULT_MODE
#undef INDICATOR_LED_DEFAULT_MODE
#endif
#define INDICATOR_LED_DEFAULT_MODE ((2<<2) + 2)

// too big, turn off extra features
#undef USE_TACTICAL_MODE
