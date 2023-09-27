/// @file pd9982_driver_w32.h
#ifdef _WIN32
#ifndef PD9982_DRIVER_W32_H
#define PD9982_DRIVER_W32_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/** ------------------------------------------ Defines ------------------------------------------------------ **/

/** ------------------------------------------ Typedef ----------------------------------------------------- **/

/** -------------------------------------- Global Variables ------------------------------------------------ **/

/** -------------------------------------- Global Functions ------------------------------------------------ **/
/**
 * initialize memory and variables for usage and returns a pointer to the memory location
 * of the simulated control register
 * @param fp [in] Path to file where the output will be written. If set to NULL, stdout will be used.
**/
__declspec(dllimport) volatile void *__cdecl initModule(const char *output);

/**
 * start the display simulator thread
 **/
__declspec(dllimport) void __cdecl startModule(void);

/**
* stop the display simulator thread
**/
__declspec(dllimport) void __cdecl stopModule(void);

#ifdef __cplusplus
}
#endif

#endif
#endif
