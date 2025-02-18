// Autogenerated with StateSmith
#include "gainOven.h"
            
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

static void ROOT_enter(gainOven* self);
static void ROOT_exit(gainOven* self);

static void STATE_1_enter(gainOven* self);
static void STATE_1_exit(gainOven* self);
static void STATE_1_do(gainOven* self);
static void STATE_1_transitionright(gainOven* self);

static void STATE_2_enter(gainOven* self);
static void STATE_2_exit(gainOven* self);
static void STATE_2_transitionleft(gainOven* self);

void gainOven_ctor(gainOven* self)
{
    memset(self, 0, sizeof(*self));
}

void gainOven_start(gainOven* self)
{
    ROOT_enter(self);
    // Transition to target state STATE_1
    {
        // No need exit any states in this handler.
        
        // Enter towards target
        STATE_1_enter(self);
        
        // update state_id
        self->state_id = gainOven_StateId_STATE_1;
    } // end of transition code
}

void gainOven_dispatch_event(gainOven* self, enum gainOven_EventId event_id)
{
    gainOven_Func behavior_func = self->current_event_handlers[event_id];
    
    while (behavior_func != NULL)
    {
        self->ancestor_event_handler = NULL;
        behavior_func(self);
        behavior_func = self->ancestor_event_handler;
    }
}

const char* gainOven_state_id_to_string(const enum gainOven_StateId id)
{
    switch (id)
    {
        case gainOven_StateId_ROOT: return "ROOT";
        case gainOven_StateId_STATE_1: return "STATE_1";
        case gainOven_StateId_STATE_2: return "STATE_2";
        default: return "?";
    }
}

////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(gainOven* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ROOT_exit;
}

static void ROOT_exit(gainOven* self)
{
    // State machine root is a special case. It cannot be exited.
    (void)self;  // nothing to see here compiler. move along!
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state STATE_1
////////////////////////////////////////////////////////////////////////////////

static void STATE_1_enter(gainOven* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = STATE_1_exit;
    self->current_event_handlers[gainOven_EventId_DO] = STATE_1_do;
    self->current_event_handlers[gainOven_EventId_TRANSITIONRIGHT] = STATE_1_transitionright;
    
    // state behavior:
    {
        // uml action: // Comment from enter of the State 1
        // Comment from enter of the State 1<EOF>
    } // end of behavior code
}

static void STATE_1_exit(gainOven* self)
{
    
    // state behavior:
    {
        // uml action: // Comment from exit of the State 1
        // Comment from exit of the State 1<EOF>
    } // end of behavior code
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[gainOven_EventId_DO] = NULL;  // no ancestor listens to this event
    self->current_event_handlers[gainOven_EventId_TRANSITIONRIGHT] = NULL;  // no ancestor listens to this event
}

static void STATE_1_do(gainOven* self)
{
    // setup handler for next ancestor that listens to `do` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `do` event
    
    // state behavior:
    {
        bool consume_event = false; // the `do` event is special in that it normally is not consumed.
        (void)consume_event; // avoid un-used variable compiler warning. StateSmith cannot (yet) detect if behavior action code sets `consume_event`.
        // note: no ancestor consumes this event, but we output `bool consume_event` anyway because a user's design might rely on it.
        
        // uml action: // Comment from do of the State 1
        // Comment from do of the State 1<EOF>
        
        if (consume_event)
        {
            // Mark event as handled.
            // self->ancestor_event_handler = NULL; // already done at top of function
        }
    } // end of behavior code
}

static void STATE_1_transitionright(gainOven* self)
{
    // setup handler for next ancestor that listens to `transitionRight` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `transitionRight` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: STATE_2
        // Transition to target state STATE_2
        {
            // First, exit up to Least Common Ancestor ROOT.
            while (self->current_state_exit_handler != ROOT_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            STATE_2_enter(self);
            
            // update state_id
            self->state_id = gainOven_StateId_STATE_2;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state STATE_2
////////////////////////////////////////////////////////////////////////////////

static void STATE_2_enter(gainOven* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = STATE_2_exit;
    self->current_event_handlers[gainOven_EventId_TRANSITIONLEFT] = STATE_2_transitionleft;
}

static void STATE_2_exit(gainOven* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[gainOven_EventId_TRANSITIONLEFT] = NULL;  // no ancestor listens to this event
}

static void STATE_2_transitionleft(gainOven* self)
{
    // setup handler for next ancestor that listens to `transitionLeft` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `transitionLeft` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: STATE_1
        // Transition to target state STATE_1
        {
            // First, exit up to Least Common Ancestor ROOT.
            while (self->current_state_exit_handler != ROOT_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            STATE_1_enter(self);
            
            // update state_id
            self->state_id = gainOven_StateId_STATE_1;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}


