/*
 * stateFailure.c
 *
 *  Created on: Nov 25, 2022
 *      Author: e_yilmaz8
 */

#define DEBUG_STATEFAILURE 1
#if DEBUG_STATEFAILURE
#include <stdio.h>
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#include "stateFailure.h"

static const char* state_string_failure = "FAILURE";

void stateFailureEntry(void)
{
    #if DEBUG_STATEFAILURE
        DEBUG_PRINT("%s of %s STATE\n", "EVENT_ENTRY", state_string_failure);
    #endif
}

void stateFailureDo(void)
{
    #if DEBUG_STATEFAILURE
        DEBUG_PRINT("%s of %s STATE\n", "EVENT_DO", state_string_failure);
    #endif
}

void stateFailureExit(void)
{
    #if DEBUG_STATEFAILURE
        DEBUG_PRINT("%s of %s STATE\n", "EVENT_EXIT", state_string_failure);
    #endif
}