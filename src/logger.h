#pragma once

/**
 * Library containing the logging functions of the framework.
 */

#include <stdio.h>
#include "ll_constants.h"
#include "string_manipulation.h"

/**
 * Function that flushes the console output in debug mode.
 * 
 * See logger modes for the last parameter (1 = LL_DEBUG, 0 = LL_PROD).
 * 
 * Examples:
 * ```c
 * flushOutput(LL_DEBUG);
 * flushOutput(LL_PROD);
 * ```
 */
extern void flushOutput(int mode);

/**
 * Function that handles errors.
 * If the debug mode is enabled, these will be displayed in the terminal, otherwise they will be
 * written to a log file.
 * 
 * See logger modes for the last parameter (1 = LL_DEBUG, 0 = LL_PROD).
 * 
 * This function is not supposed to be called by itself. It has been thought as an embedded function
 * allowing you to create different level errors that will have their own function. It's pretty much
 * the Exception base class of all exceptions in its own way.
 * 
 * Examples:
 * ```c
 * void handleIllegalArgumentError(char *message, char *charTime, int mode) {
 *     handleError("[ILLEGAL_ARGUMENT]", message, charTime, mode);
 * }
 * ```
 */
extern void handleError(char *errorTag, char *message, char *charTime, int mode);

/**
 * Function that handles runtime errors.
 * These errors takes the `[ERROR]` tag.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * Example:
 * ```c
 * if (actual != expected) handleRuntimeError("Wrong value!\n", getTime(), LL_DEBUG);
 * ```
 * 
 * => output:
 * ```txt
 * [ERROR] Wed Nov 15 13:36:47 2023: Wrong value!
 * ```
 */
extern void handleRuntimeError(char *message, char *charTime, int mode);

/**
 * Function that handles critical errors.
 * These errors takes the `[CRITICAL]` tag and causes the program to stop.
 * 
 * See logger modes for the last parameter (1 = LL_DEBUG, 0 = LL_PROD).
 * 
 * Example:
 * ```c
 * if (required_value == NULL) handleCriticalError("Can't continue the execution!\n", getTime(), LL_DEBUG);
 * ```
 * 
 * => output:
 * ```txt
 * [CRITICAL] Wed Nov 15 13:37:26 2023: Can't continue the execution!
 * ```
 */
extern void handleCriticalError(char *message, char *charTime, int mode);

/**
 * Function that handles standard debug display.
 * If the debug mode is enabled, it will display the informations in the terminal, otherwise it
 * won't display anything.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * Example:
 * ```c
 * debug("[DEBUG] %s: currently debugging => val=%s\n", getTime(), val, LL_DEBUG);
 * ```
 * 
 * => output:
 * ```txt
 * [DEBUG] Wed Nov 15 13:42:34 2023: currently debugging => val=example
 * ```
 */
extern void debug(const char *messageTemplate, char *charTime, char *content, int mode);
