#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/NativeListsAndTimes.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Foo
typedef struct {
    int bank_index;
    #line 5 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    int x;
    #line 6 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t y;
    #line 7 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t z;
    #line 8 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    int* p;
    #line 9 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t* q;
    #line 10 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t r;
    #line 11 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t* g;
    #line 13 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t s;
    #line 14 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t t;
    #line 15 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    bool v;
    #line 16 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t w;
    #line 20 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    int* baz;
    #line 21 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    interval_t period;
    #line 22 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    reaction_t ___reaction_0;
    #line 17 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    trigger_t ___tick;
    #line 17 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    reaction_t* ___tick_reactions[1];
    #line 18 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    trigger_t ___tock;
    #line 19 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    trigger_t ___toe;
} foo_self_t;
void fooreaction_function_0(void* instance_args) {
    foo_self_t* self = (foo_self_t*)instance_args;
    #line 23 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    // Target code    
        
}
foo_self_t* new_Foo() {
    foo_self_t* self = (foo_self_t*)calloc(1, sizeof(foo_self_t));
    #line 22 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___reaction_0.number = 0;
    #line 22 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___reaction_0.function = fooreaction_function_0;
    #line 22 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___reaction_0.self = self;
    #line 22 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 22 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 17 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___tick.last = NULL;
    #line 17 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    #line 17 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___tick_reactions[0] = &self->___reaction_0;
    #line 17 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___tick.reactions = &self->___tick_reactions[0];
    #line 17 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___tick.number_of_reactions = 1;
    self->___tick.is_timer = true;
    #line 18 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___tock.last = NULL;
    self->___tock.is_timer = true;
    #line 19 "file:/lf-flexpret-scripts/tests/NativeListsAndTimes.lf"
    self->___toe.last = NULL;
    self->___toe.is_timer = true;
    return self;
}
void delete_Foo(foo_self_t* self) {
    if (self->___reaction_0.output_produced != NULL) {
        free(self->___reaction_0.output_produced);
    }
    if (self->___reaction_0.triggers != NULL) {
        free(self->___reaction_0.triggers);
    }
    if (self->___reaction_0.triggered_sizes != NULL) {
        free(self->___reaction_0.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    free(self);
}
// =============== END reactor class Foo

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t* __timer_triggers[1];
int __timer_triggers_size = 1;
// Array of pointers to reactions to be scheduled in __trigger_startup_reactions().
reaction_t** __startup_reactions = NULL;
int __startup_reactions_size = 0;
// Empty array of pointers to shutdown triggers.
reaction_t** __shutdown_reactions = NULL;
int __shutdown_reactions_size = 0;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    // ************* Instance Foo of class Foo
    foo_self_t* foo_self = new_Foo();
    //***** Start initializing Foo
    foo_self->x = 0; 
    foo_self->y = 0; 
    foo_self->z = MSEC(1); 
    static int foo_p[] = {1, 2, 3, 4};
    foo_self->p = foo_p;
    static interval_t foo_q[] = {MSEC(1), MSEC(2), MSEC(3)};
    foo_self->q = foo_q;
    foo_self->r = 0; 
    static interval_t foo_g[] = {MSEC(1), MSEC(2)};
    foo_self->g = foo_g;
    foo_self->s = foo_self->y;
    foo_self->t = foo_self->z;
    foo_self->baz = foo_self->p;
    foo_self->period = foo_self->z;
    foo_self->___tick.offset = 0;
    foo_self->___tick.period = 0;
    __timer_triggers[0] = &foo_self->___tick;
    //***** End initializing Foo
    // Populate arrays of trigger pointers.
    foo_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    foo_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (foo_self->___reaction_0.num_outputs > 0) {
        foo_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * foo_self->___reaction_0.num_outputs);
        foo_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * foo_self->___reaction_0.num_outputs);
        foo_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * foo_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Foo does not depend on one maximal upstream reaction.
    foo_self->___reaction_0.last_enabling_reaction = NULL;
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Foo.
    // END Connect inputs and outputs for reactor Foo.
    
    foo_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    foo_self->___reaction_0.index = 0x7fffffffffff0000LL;
}
void __trigger_startup_reactions() {
    
}
void __initialize_timers() {
    for (int i = 0; i < __timer_triggers_size; i++) {
        if (__timer_triggers[i] != NULL) {
            _lf_initialize_timer(__timer_triggers[i]);
        }
    }
}
void logical_time_complete(instant_t timestep, microstep_t microstep) {
}
tag_t next_event_tag(instant_t time, microstep_t microstep) {
    return (tag_t) {  .time = time, .microstep = microstep };
}
bool __trigger_shutdown_reactions() {                          
    for (int i = 0; i < __shutdown_reactions_size; i++) {
        if (__shutdown_reactions[i] != NULL) {
            _lf_enqueue_reaction(__shutdown_reactions[i]);
        }
    }
    // Return true if there are shutdown reactions.
    return (__shutdown_reactions_size > 0);
}
void __termination() {stop_trace();}