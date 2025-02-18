// Autogenerated with StateSmith
#pragma once
#include <stdint.h>

enum Spec1Sm_EventId
{
    Spec1Sm_EventId_EV1 = 0,
    Spec1Sm_EventId_EV2 = 1,
};

enum
{
    Spec1Sm_EventIdCount = 2
};

enum Spec1Sm_StateId
{
    Spec1Sm_StateId_ROOT = 0,
    Spec1Sm_StateId_S = 1,
    Spec1Sm_StateId_S1 = 2,
    Spec1Sm_StateId_S11 = 3,
    Spec1Sm_StateId_T1 = 4,
    Spec1Sm_StateId_T11 = 5,
    Spec1Sm_StateId_T111 = 6,
};

enum
{
    Spec1Sm_StateIdCount = 7
};

typedef struct Spec1Sm Spec1Sm;
typedef void (*Spec1Sm_Func)(Spec1Sm* sm);

struct Spec1Sm
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    enum Spec1Sm_StateId state_id;
    
    // Used internally by state machine. Don't modify.
    Spec1Sm_Func ancestor_event_handler;
    
    // Used internally by state machine. Don't modify.
    Spec1Sm_Func current_event_handlers[Spec1Sm_EventIdCount];
    
    // Used internally by state machine. Don't modify.
    Spec1Sm_Func current_state_exit_handler;
    
    // User variables. Can be used for inputs, outputs, user variables...
    struct
    {
        uint8_t count;
    } vars;
};

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void Spec1Sm_ctor(Spec1Sm* self);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void Spec1Sm_start(Spec1Sm* self);

// Dispatches an event to the state machine. Not thread safe.
void Spec1Sm_dispatch_event(Spec1Sm* self, enum Spec1Sm_EventId event_id);

// Converts a state id to a string. Thread safe.
const char* Spec1Sm_state_id_to_string(const enum Spec1Sm_StateId id);

