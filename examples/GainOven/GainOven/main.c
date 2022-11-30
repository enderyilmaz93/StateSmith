#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "app_timer.h"
#include "smtest.h"
#include "gainOven.h"

////////////////////////////////////////////////////////////////////////////////
// global vars
////////////////////////////////////////////////////////////////////////////////

static gainOven g_state_machine;
static enum gainOven_StateId g_sm_last_state_id;

////////////////////////////////////////////////////////////////////////////////
// prototypes
////////////////////////////////////////////////////////////////////////////////

static void read_input_run_state_machine(void);
static char read_char_from_line_and_clear_user_input(void);
static void detect_sm_state_change(void);


////////////////////////////////////////////////////////////////////////////////
// functions
////////////////////////////////////////////////////////////////////////////////


int main(void)
{
    printf("---------------------------------------\n\n");
    printf("gainOven C Code Running!\n\n");
    printf("USAGE:\n");
    printf("  type o <enter> to send gainOven_EventId_BUTTON_ON_OFF_PRESS event to state machine\n");
    printf("  type p <enter> to send gainOven_EventId_BUTTON_START_PAUSE_PRESS event to state machine\n");
    printf("  type s <enter> to send gainOven_EventId_BUTTON_STOP_PRESSED event to state machine\n");
    printf("  type c <enter> to send gainOven_EventId_COOKING_COMPLETE event to state machine\n");
    printf("  type d <enter> to send gainOven_EventId_DOOR_CLOSE event to state machine\n");
    printf("  type D <enter> to send gainOven_EventId_DOOR_OPEN event to state machine\n");
    printf("  type i <enter> to send gainOven_EventId_IMMEDIATE_ACTION event to state machine\n");
    printf("  type f <enter> to send gainOven_EventId_INSPECTION_OFF_COMMAND event to state machine\n");
    printf("  type I <enter> to send gainOven_EventId_INSPECTION_ON_COMMAND event to state machine\n");
    printf("  type F <enter> to send gainOven_EventId_SELF_TEST_FAIL event to state machine\n");
    printf("  type P <enter> to send gainOven_EventId_SELF_TEST_PASS event to state machine\n");
    printf("  type S <enter> to send gainOven_EventId_SELF_TEST_REQUIRE event to state machine\n");
    printf("  type t <enter> to send gainOven_EventId_TIME_UP event to state machine\n");
    printf("  type . <enter> to send gainOven_EventId_DO event to state machine\n");
    printf("\n");
    printf("hit <enter> to start\n");
    read_char_from_line_and_clear_user_input();

    // setup and start state machine
    gainOven_ctor(&g_state_machine);
    gainOven_start(&g_state_machine);

    while (true)
    {
        read_input_run_state_machine();
    }
}


static void read_input_run_state_machine(void)
{
    bool valid_input = true;
    enum gainOven_EventId event_id = gainOven_EventId_DO;

    char c = read_char_from_line_and_clear_user_input();
    switch (c)
    {
        case 'o': event_id = gainOven_EventId_BUTTON_ON_OFF_PRESS; break;
        case 'p': event_id = gainOven_EventId_BUTTON_START_PAUSE_PRESS; break;
        case 's': event_id = gainOven_EventId_BUTTON_STOP_PRESSED; break;
        case 'c': event_id = gainOven_EventId_COOKING_COMPLETE; break;
        case 'd': event_id = gainOven_EventId_DOOR_CLOSE; break;
        case 'D': event_id = gainOven_EventId_DOOR_OPEN; break;
        case 'i': event_id = gainOven_EventId_IMMEDIATE_ACTION; break;
        case 'f': event_id = gainOven_EventId_INSPECTION_OFF_COMMAND; break;
        case 'I': event_id = gainOven_EventId_INSPECTION_ON_COMMAND; break;
        case 'F': event_id = gainOven_EventId_SELF_TEST_FAIL; break;
        case 'P': event_id = gainOven_EventId_SELF_TEST_PASS; break;
        case 'S': event_id = gainOven_EventId_SELF_TEST_REQUIRE; break;
        case 't': event_id = gainOven_EventId_TIME_UP; break;
        case '.': event_id = gainOven_EventId_DO; break;
        default: valid_input = false; break;
    }

    if (valid_input)
    {
        gainOven_dispatch_event(&g_state_machine, event_id);
        detect_sm_state_change();
        // app_timer_sleep_ms(1000);
    }
}


// blocks while waiting for input
static char read_char_from_line_and_clear_user_input(void)
{
    char buf[100];
    char* c_ptr = fgets(buf, sizeof(buf), stdin);

    // erase user input from command line so that lightbulb animation stays at top
    // https://stackoverflow.com/a/35190285/7331858
    printf("\033[A");   // VT100 - move cursor up one line
    printf("\33[2K\r"); // VT100 - erase line cursor is on
    fflush(stdout);

    if (c_ptr == NULL)
    {
        return '\0';
    }

    return *c_ptr;
}

static void detect_sm_state_change(void)
{
    const enum gainOven_StateId current_state = g_state_machine.state_id;
    if (current_state != g_sm_last_state_id)
    {
        printf("State changed from %s to %s\n", 
            gainOven_state_id_to_string(g_sm_last_state_id),
            gainOven_state_id_to_string(current_state));
        g_sm_last_state_id = current_state;
    }
}
