// Autogenerated with StateSmith
#include "Spec1Sm.h"
#include "../../lang-helpers/c/helper.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

static void ROOT_enter(Spec1Sm* self);
static void ROOT_exit(Spec1Sm* self);

static void S_enter(Spec1Sm* self);
static void S_exit(Spec1Sm* self);

static void S1_enter(Spec1Sm* self);
static void S1_exit(Spec1Sm* self);

static void S11_enter(Spec1Sm* self);
static void S11_exit(Spec1Sm* self);
static void S11_ev1(Spec1Sm* self);

static void T1_enter(Spec1Sm* self);
static void T1_exit(Spec1Sm* self);

static void T11_enter(Spec1Sm* self);
static void T11_exit(Spec1Sm* self);
static void T11_ev2(Spec1Sm* self);

static void T111_enter(Spec1Sm* self);
static void T111_exit(Spec1Sm* self);

void Spec1Sm_ctor(Spec1Sm* self)
{
    memset(self, 0, sizeof(*self));
}

void Spec1Sm_start(Spec1Sm* self)
{
    ROOT_enter(self);
    trace("Transition action `` for Spec1Sm.InitialState to S.");trace("Transition action `` for S.InitialState to S1.");trace("Transition action `` for S1.InitialState to S11.");
    // Transition to target state S11
    {
        // No need exit any states in this handler.
        
        // Enter towards target
        S_enter(self);
        S1_enter(self);
        S11_enter(self);
        
        // update state_id
        self->state_id = Spec1Sm_StateId_S11;
    } // end of transition code
}

void Spec1Sm_dispatch_event(Spec1Sm* self, enum Spec1Sm_EventId event_id)
{
    Spec1Sm_Func behavior_func = self->current_event_handlers[event_id];
    
    while (behavior_func != NULL)
    {
        self->ancestor_event_handler = NULL;
        behavior_func(self);
        behavior_func = self->ancestor_event_handler;
    }
}

const char* Spec1Sm_state_id_to_string(const enum Spec1Sm_StateId id)
{
    switch (id)
    {
        case Spec1Sm_StateId_ROOT: return "ROOT";
        case Spec1Sm_StateId_S: return "S";
        case Spec1Sm_StateId_S1: return "S1";
        case Spec1Sm_StateId_S11: return "S11";
        case Spec1Sm_StateId_T1: return "T1";
        case Spec1Sm_StateId_T11: return "T11";
        case Spec1Sm_StateId_T111: return "T111";
        default: return "?";
    }
}

////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(Spec1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ROOT_exit;
    
    // state behavior:
    {
        // uml action: trace("Enter Spec1Sm.");
        trace("Enter Spec1Sm.");
    } // end of behavior code
}

static void ROOT_exit(Spec1Sm* self)
{
    
    // state behavior:
    {
        // uml action: trace("Exit Spec1Sm.");
        trace("Exit Spec1Sm.");
    } // end of behavior code
    // State machine root is a special case. It cannot be exited.
    (void)self;  // nothing to see here compiler. move along!
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state S
////////////////////////////////////////////////////////////////////////////////

static void S_enter(Spec1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = S_exit;
    
    // state behavior:
    {
        // uml action: trace("Enter S.");
        trace("Enter S.");
    } // end of behavior code
}

static void S_exit(Spec1Sm* self)
{
    
    // state behavior:
    {
        // uml action: trace("Exit S.");
        trace("Exit S.");
    } // end of behavior code
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state S1
////////////////////////////////////////////////////////////////////////////////

static void S1_enter(Spec1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = S1_exit;
    
    // state behavior:
    {
        // uml action: trace("Enter S1.");
        trace("Enter S1.");
    } // end of behavior code
}

static void S1_exit(Spec1Sm* self)
{
    
    // state behavior:
    {
        // uml action: trace("Exit S1.");
        trace("Exit S1.");
    } // end of behavior code
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = S_exit;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state S11
////////////////////////////////////////////////////////////////////////////////

static void S11_enter(Spec1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = S11_exit;
    self->current_event_handlers[Spec1Sm_EventId_EV1] = S11_ev1;
    
    // state behavior:
    {
        // uml action: trace("Enter S11.");
        trace("Enter S11.");
    } // end of behavior code
}

static void S11_exit(Spec1Sm* self)
{
    
    // state behavior:
    {
        // uml action: trace("Exit S11.");
        trace("Exit S11.");
    } // end of behavior code
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = S1_exit;
    self->current_event_handlers[Spec1Sm_EventId_EV1] = NULL;  // no ancestor listens to this event
}

static void S11_ev1(Spec1Sm* self)
{
    // setup handler for next ancestor that listens to `EV1` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `EV1` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml guard: trace_guard("State S11: check behavior `EV1 TransitionTo(S1.ExitPoint(1))`.", true)
        // uml action: trace("Transition action `` for S11 to S1.ExitPoint(1).");trace("Transition action `` for S1 to T11.");trace("Transition action `` for T11.EntryPoint(1) to T111.");
        // uml transition target: T111
        if (trace_guard("State S11: check behavior `EV1 TransitionTo(S1.ExitPoint(1))`.", true))
        {
            trace("Transition action `` for S11 to S1.ExitPoint(1).");trace("Transition action `` for S1 to T11.");trace("Transition action `` for T11.EntryPoint(1) to T111.");
            
            // Transition to target state T111
            {
                // First, exit up to Least Common Ancestor S.
                while (self->current_state_exit_handler != S_exit)
                {
                    self->current_state_exit_handler(self);
                }
                
                // Enter towards target
                T1_enter(self);
                T11_enter(self);
                T111_enter(self);
                
                // update state_id
                self->state_id = Spec1Sm_StateId_T111;
            } // end of transition code
            
            // Mark event as handled. Required because of transition.
            // self->ancestor_event_handler = NULL; // already done at top of function
            return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
        } // end of guard code
    } // end of behavior code
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state T1
////////////////////////////////////////////////////////////////////////////////

static void T1_enter(Spec1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = T1_exit;
    
    // state behavior:
    {
        // uml action: trace("Enter T1.");
        trace("Enter T1.");
    } // end of behavior code
}

static void T1_exit(Spec1Sm* self)
{
    
    // state behavior:
    {
        // uml action: trace("Exit T1.");
        trace("Exit T1.");
    } // end of behavior code
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = S_exit;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state T11
////////////////////////////////////////////////////////////////////////////////

static void T11_enter(Spec1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = T11_exit;
    self->current_event_handlers[Spec1Sm_EventId_EV2] = T11_ev2;
    
    // state behavior:
    {
        // uml action: trace("Enter T11.");
        trace("Enter T11.");
    } // end of behavior code
}

static void T11_exit(Spec1Sm* self)
{
    
    // state behavior:
    {
        // uml action: trace("Exit T11.");
        trace("Exit T11.");
    } // end of behavior code
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = T1_exit;
    self->current_event_handlers[Spec1Sm_EventId_EV2] = NULL;  // no ancestor listens to this event
}

static void T11_ev2(Spec1Sm* self)
{
    // setup handler for next ancestor that listens to `EV2` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `EV2` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml guard: trace_guard("State T11: check behavior `EV2 TransitionTo(S1)`.", true)
        // uml action: trace("Transition action `` for T11 to S1.");trace("Transition action `` for S1.InitialState to S11.");
        // uml transition target: S11
        if (trace_guard("State T11: check behavior `EV2 TransitionTo(S1)`.", true))
        {
            trace("Transition action `` for T11 to S1.");trace("Transition action `` for S1.InitialState to S11.");
            
            // Transition to target state S11
            {
                // First, exit up to Least Common Ancestor S.
                while (self->current_state_exit_handler != S_exit)
                {
                    self->current_state_exit_handler(self);
                }
                
                // Enter towards target
                S1_enter(self);
                S11_enter(self);
                
                // update state_id
                self->state_id = Spec1Sm_StateId_S11;
            } // end of transition code
            
            // Mark event as handled. Required because of transition.
            // self->ancestor_event_handler = NULL; // already done at top of function
            return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
        } // end of guard code
    } // end of behavior code
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state T111
////////////////////////////////////////////////////////////////////////////////

static void T111_enter(Spec1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = T111_exit;
    
    // state behavior:
    {
        // uml action: trace("Enter T111.");
        trace("Enter T111.");
    } // end of behavior code
}

static void T111_exit(Spec1Sm* self)
{
    
    // state behavior:
    {
        // uml action: trace("Exit T111.");
        trace("Exit T111.");
    } // end of behavior code
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = T11_exit;
}


