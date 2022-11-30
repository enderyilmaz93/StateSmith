#include "smtest.h"
#include <stdio.h>
#include <stdlib.h>


static const char* state_string_cooking = 
"gainOven_StateId_COOKING\n";

static const char* state_string_cooldown = 
"gainOven_StateId_COOLDOWN\n";

static const char* state_string_dooropen = 
"gainOven_StateId_DOOROPEN\n";

static const char* state_string_heating = 
"gainOven_StateId_HEATING\n";

static const char* state_string_pause = 
"gainOven_StateId_PAUSE\n";

static const char* state_string_ready = 
"gainOven_StateId_HEATING\n";

static const char* state_string_failure = 
"gainOven_StateId_FAILURE\n";

static const char* state_string_immediate = 
"gainOven_StateId_IMMEDIATE\n";

static const char* state_string_inspection = 
"gainOven_StateId_INSPECTION\n";

static const char* state_string_selftest = 
"gainOven_StateId_SELFTEST\n";

static const char* state_string_standbyoff = 
"gainOven_StateId_STANDBY_OFF\n";

static const char* state_string_standbyon = 
"gainOven_StateId_STANDBY_ON\n";


static void clear_screen(void)
{
    //system("clear");
}

void state_standby_on(void)
{
    clear_screen();
    printf("%s", state_string_standbyon);
}

void state_standby_off(void)
{
    clear_screen();
    printf("%s", state_string_standbyoff);
}

void state_immediate(void)
{
    clear_screen();
    printf("%s", state_string_immediate);
}

void state_inspection(void)
{
    clear_screen();
    printf("%s", state_string_inspection);
}

void state_failure(void)
{
    clear_screen();
    printf("%s", state_string_failure);
}

void state_selfTest(void)
{
    clear_screen();
    printf("%s", state_string_selftest);
}

void state_cooking(void)
{
    clear_screen();
    printf("%s", state_string_cooking);
}

void state_pause(void)
{
    clear_screen();
    printf("%s", state_string_pause);
}

void state_heating(void)
{
    clear_screen();
    printf("%s", state_string_heating);
}

void state_coolDown(void)
{
    clear_screen();
    printf("%s", state_string_cooldown);
}

void state_ready(void)
{
    clear_screen();
    printf("%s", state_string_ready);
}

void state_doorOpen(void)
{
    clear_screen();
    printf("%s", state_string_dooropen);
}

