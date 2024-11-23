/*
 * Copyright (c) 2017 Jari Saukkonen, Samuli Vuorinen
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Arduino pin mappings */
#define PIN_M0 6
#define PIN_M1 5
#define PIN_M2 4
#define PIN_DIR 2
#define PIN_STEP 3
#define PIN_ENABLE 7

/* Microstepping for Moonlite "half" mode */
#define MICROSTEPS_HALF 16
/* Microstepping for Moonlite "full" mode */
#define MICROSTEPS_FULL 8

#define MANUAL_BUTTONS

#ifdef MANUAL_BUTTONS
/* Arduino pin mapping for manual button and speed control */
#define PIN_UP_IN 12
#define PIN_DOWN_OUT 11
#define BTN_POTI_SPEED A0
#define BTN_MIN_SPEED 32
#define BTN_MAX_SPEED 2
#define BTN_ACCEL_FACTOR 1.05f
#define NB_STEPS 10
#endif

#define TEMP_SENSOR

#ifdef TEMP_SENSOR
/* Arduino pin mapping for DS18B20 Temeratur sensor */
#define ONE_WIRE_BUS 10
#endif

#endif
