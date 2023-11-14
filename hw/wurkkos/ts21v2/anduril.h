// Wurkkos TS21 config options for Anduril using the Attiny1616
// avrdude -c jtag2updi -P /dev/ttyUSB0 -p t1616 -v -u -Uflash:w:anduril.wurkkos-ts21v2.hex
// Copyright (C) 2021-2023 (FIXME)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// same as  the  BLF Q8, mostly
#include "sofirn/blf-q8-t1616/anduril.h"

#ifdef VOLTAGE_LOW
#undef VOLTAGE_LOW
#endif
#define VOLTAGE_LOW 30 // 3.0V is low enough for li-ion

#define HOLD_TIMEOUT 20
#define RELEASE_TIMEOUT 18

#undef B_TIMING_ON
#define B_TIMING_ON B_PRESS_T // turn on when button is pressed, don't wait for release

#undef MOON_TIMING_HINT // hint is unnecessary

// voltage readings were a little high with the Q8 value
#undef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 5  // add 0.25V, not 0.35V

// Button LED Indicator

// off mode: high (2)
// lockout: high (2)
#ifdef INDICATOR_LED_DEFAULT_MODE
#undef INDICATOR_LED_DEFAULT_MODE
#endif
#define INDICATOR_LED_DEFAULT_MODE ((2<<2) + 2) // always high

// DEFAULT_LEVEL is when Indicator LED turns on, so it should be = 1x7135 ramp ceiling (MAX_1x7135)
#ifdef DEFAULT_LEVEL
#undef DEFAULT_LEVEL
#endif
#define DEFAULT_LEVEL MAX_1x7135

// don't blink during the ramp; the button LED brightness is sufficient
// to indicate which power channel(s) are being used
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif
#ifdef BLINK_AT_RAMP_CEIL
#undef BLINK_AT_RAMP_CEIL
#endif

// stop panicking at ~60% power
#ifdef THERM_FASTER_LEVEL
#undef THERM_FASTER_LEVEL
#endif
#define THERM_FASTER_LEVEL 105

// Don't go too high in simple ui mode
#undef SIMPLE_UI_FLOOR
#undef SIMPLE_UI_CEIL
#undef SIMPLE_UI_STEPS
#define SIMPLE_UI_FLOOR  10
#define SIMPLE_UI_CEIL   120
#define SIMPLE_UI_STEPS  5

#undef HALFSPEED_LEVEL
#define HALFSPEED_LEVEL 30
#undef QUARTERSPEED_LEVEL
#define QUARTERSPEED_LEVEL 10