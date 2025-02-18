// Autogenerated with StateSmith
#include "Tutorial1Sm.h"
// Some user .c file comment...
#include "light.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

static void ROOT_enter(Tutorial1Sm* self);
static void ROOT_exit(Tutorial1Sm* self);

static void BOOM_enter(Tutorial1Sm* self);
static void BOOM_exit(Tutorial1Sm* self);

static void OFF_enter(Tutorial1Sm* self);
static void OFF_exit(Tutorial1Sm* self);
static void OFF_increase(Tutorial1Sm* self);

static void ON_GROUP_enter(Tutorial1Sm* self);
static void ON_GROUP_exit(Tutorial1Sm* self);
static void ON_GROUP_off(Tutorial1Sm* self);

static void ON1_enter(Tutorial1Sm* self);
static void ON1_exit(Tutorial1Sm* self);
static void ON1_dim(Tutorial1Sm* self);
static void ON1_increase(Tutorial1Sm* self);

static void ON2_enter(Tutorial1Sm* self);
static void ON2_exit(Tutorial1Sm* self);
static void ON2_dim(Tutorial1Sm* self);
static void ON2_increase(Tutorial1Sm* self);

static void ON3_enter(Tutorial1Sm* self);
static void ON3_exit(Tutorial1Sm* self);
static void ON3_dim(Tutorial1Sm* self);
static void ON3_increase(Tutorial1Sm* self);

void Tutorial1Sm_ctor(Tutorial1Sm* self)
{
    memset(self, 0, sizeof(*self));
}

void Tutorial1Sm_start(Tutorial1Sm* self)
{
    ROOT_enter(self);
    // Transition to target state OFF
    {
        // No need exit any states in this handler.
        
        // Enter towards target
        OFF_enter(self);
        
        // update state_id
        self->state_id = Tutorial1Sm_StateId_OFF;
    } // end of transition code
}

void Tutorial1Sm_dispatch_event(Tutorial1Sm* self, enum Tutorial1Sm_EventId event_id)
{
    Tutorial1Sm_Func behavior_func = self->current_event_handlers[event_id];
    
    while (behavior_func != NULL)
    {
        self->ancestor_event_handler = NULL;
        behavior_func(self);
        behavior_func = self->ancestor_event_handler;
    }
}

const char* Tutorial1Sm_state_id_to_string(const enum Tutorial1Sm_StateId id)
{
    switch (id)
    {
        case Tutorial1Sm_StateId_ROOT: return "ROOT";
        case Tutorial1Sm_StateId_BOOM: return "BOOM";
        case Tutorial1Sm_StateId_OFF: return "OFF";
        case Tutorial1Sm_StateId_ON_GROUP: return "ON_GROUP";
        case Tutorial1Sm_StateId_ON1: return "ON1";
        case Tutorial1Sm_StateId_ON2: return "ON2";
        case Tutorial1Sm_StateId_ON3: return "ON3";
        default: return "?";
    }
}

////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ROOT_exit;
}

static void ROOT_exit(Tutorial1Sm* self)
{
    // State machine root is a special case. It cannot be exited.
    (void)self;  // nothing to see here compiler. move along!
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state BOOM
////////////////////////////////////////////////////////////////////////////////

static void BOOM_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = BOOM_exit;
    
    // state behavior:
    {
        // uml action: light_boom();
        light_boom();
    } // end of behavior code
}

static void BOOM_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state OFF
////////////////////////////////////////////////////////////////////////////////

static void OFF_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = OFF_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = OFF_increase;
    
    // state behavior:
    {
        // uml action: light_off();
        light_off();
    } // end of behavior code
}

static void OFF_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void OFF_increase(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `INCREASE` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `INCREASE` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: ON1
        // Transition to target state ON1
        {
            // First, exit up to Least Common Ancestor ROOT.
            while (self->current_state_exit_handler != ROOT_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            ON_GROUP_enter(self);
            ON1_enter(self);
            
            // update state_id
            self->state_id = Tutorial1Sm_StateId_ON1;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON_GROUP
////////////////////////////////////////////////////////////////////////////////

static void ON_GROUP_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_OFF] = ON_GROUP_off;
}

static void ON_GROUP_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_OFF] = NULL;  // no ancestor listens to this event
}

static void ON_GROUP_off(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `OFF` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `OFF` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: OFF
        // Transition to target state OFF
        {
            // First, exit up to Least Common Ancestor ROOT.
            while (self->current_state_exit_handler != ROOT_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            OFF_enter(self);
            
            // update state_id
            self->state_id = Tutorial1Sm_StateId_OFF;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON1
////////////////////////////////////////////////////////////////////////////////

static void ON1_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON1_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = ON1_dim;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = ON1_increase;
    
    // state behavior:
    {
        // uml action: light_on1();
        light_on1();
    } // end of behavior code
}

static void ON1_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = NULL;  // no ancestor listens to this event
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void ON1_dim(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `DIM` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `DIM` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: OFF
        // Transition to target state OFF
        {
            // First, exit up to Least Common Ancestor ROOT.
            while (self->current_state_exit_handler != ROOT_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            OFF_enter(self);
            
            // update state_id
            self->state_id = Tutorial1Sm_StateId_OFF;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}

static void ON1_increase(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `INCREASE` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `INCREASE` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: ON2
        // Transition to target state ON2
        {
            // First, exit up to Least Common Ancestor ON_GROUP.
            while (self->current_state_exit_handler != ON_GROUP_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            ON2_enter(self);
            
            // update state_id
            self->state_id = Tutorial1Sm_StateId_ON2;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON2
////////////////////////////////////////////////////////////////////////////////

static void ON2_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON2_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = ON2_dim;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = ON2_increase;
    
    // state behavior:
    {
        // uml action: light_on2();
        light_on2();
    } // end of behavior code
}

static void ON2_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = NULL;  // no ancestor listens to this event
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void ON2_dim(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `DIM` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `DIM` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: ON1
        // Transition to target state ON1
        {
            // First, exit up to Least Common Ancestor ON_GROUP.
            while (self->current_state_exit_handler != ON_GROUP_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            ON1_enter(self);
            
            // update state_id
            self->state_id = Tutorial1Sm_StateId_ON1;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}

static void ON2_increase(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `INCREASE` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `INCREASE` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: ON3
        // Transition to target state ON3
        {
            // First, exit up to Least Common Ancestor ON_GROUP.
            while (self->current_state_exit_handler != ON_GROUP_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            ON3_enter(self);
            
            // update state_id
            self->state_id = Tutorial1Sm_StateId_ON3;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON3
////////////////////////////////////////////////////////////////////////////////

static void ON3_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON3_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = ON3_dim;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = ON3_increase;
    
    // state behavior:
    {
        // uml action: count = 0;
        //             light_on3();
        self->vars.count = 0;
        light_on3();
    } // end of behavior code
}

static void ON3_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = NULL;  // no ancestor listens to this event
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void ON3_dim(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `DIM` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `DIM` event
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml transition target: ON2
        // Transition to target state ON2
        {
            // First, exit up to Least Common Ancestor ON_GROUP.
            while (self->current_state_exit_handler != ON_GROUP_exit)
            {
                self->current_state_exit_handler(self);
            }
            
            // Enter towards target
            ON2_enter(self);
            
            // update state_id
            self->state_id = Tutorial1Sm_StateId_ON2;
        } // end of transition code
        
        // Mark event as handled. Required because of transition.
        // self->ancestor_event_handler = NULL; // already done at top of function
        return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
    } // end of behavior code
}

static void ON3_increase(Tutorial1Sm* self)
{
    // setup handler for next ancestor that listens to `INCREASE` event
    self->ancestor_event_handler = NULL; // no ancestor state handles `INCREASE` event
    
    // state behavior:
    {
        bool consume_event = true; // events other than `do` are normally consumed by any event handler. Other event handlers in *this* state may still handle the event though.
        (void)consume_event; // avoid un-used variable compiler warning. StateSmith cannot (yet) detect if behavior action code sets `consume_event`.
        // note: no ancestor consumes this event, but we output `bool consume_event` anyway because a user's design might rely on it.
        
        // uml action: count++;
        self->vars.count++;
        
        if (consume_event)
        {
            // Mark event as handled.
            // self->ancestor_event_handler = NULL; // already done at top of function
        }
    } // end of behavior code
    
    // state behavior:
    {
        // Note: no `consume_event` variable possible here because of state transition. The event must be consumed.
        // uml guard: count >= 3
        // uml transition target: BOOM
        if (self->vars.count >= 3)
        {
            // Transition to target state BOOM
            {
                // First, exit up to Least Common Ancestor ROOT.
                while (self->current_state_exit_handler != ROOT_exit)
                {
                    self->current_state_exit_handler(self);
                }
                
                // Enter towards target
                BOOM_enter(self);
                
                // update state_id
                self->state_id = Tutorial1Sm_StateId_BOOM;
            } // end of transition code
            
            // Mark event as handled. Required because of transition.
            // self->ancestor_event_handler = NULL; // already done at top of function
            return; // event processing immediately stops when a transition occurs. No other behaviors for this state are checked.
        } // end of guard code
    } // end of behavior code
}


