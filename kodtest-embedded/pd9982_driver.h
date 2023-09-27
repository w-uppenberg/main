/// @file pd9982_driver.h
#ifndef _WIN32
#ifndef PD9982_DRIVER_H
#define PD9982_DRIVER_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/** ------------------------------------------ Defines ------------------------------------------------------ **/

/** ------------------------------------------ Typedef ----------------------------------------------------- **/

/** -------------------------------------- Global Variables ------------------------------------------------ **/

/** -------------------------------------- Global Functions ------------------------------------------------ **/
/**
 * initialize memory and variables for usage and returns a pointer to the memory location
 * of the simulated control register.
 * @param fp [in] Path to file where the output will be written. If set to NULL, stdout will be used.
**/
volatile void *initModule(const char *output);

/**
 * start the display simulator thread
 **/
void startModule(void);

/**
* stop the display simulator thread
**/
void stopModule(void);

#ifdef __cplusplus
}
#endif

#endif
#endif
