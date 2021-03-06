#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/StructAsState.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class StructAsState
// *********** From the preamble, verbatim:
#line 5 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
typedef struct hello_t {
    char* name;
    int value;
} hello_t;
    

// *********** End of preamble.
typedef struct {
    int bank_index;
    #line 10 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    hello_t s;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} structasstate_self_t;
void structasstatereaction_function_0(void* instance_args) {
    structasstate_self_t* self = (structasstate_self_t*)instance_args;
    #line 12 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    printf("State s.name=\"%s\", value=%d.\n", self->s.name, self->s.value);
    if (self->s.value != 42) {
        fprintf(stderr, "FAILED: Expected 42.\n");
        exit(1);
    }
        
}
structasstate_self_t* new_StructAsState() {
    structasstate_self_t* self = (structasstate_self_t*)calloc(1, sizeof(structasstate_self_t));
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    self->___reaction_0.number = 0;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    self->___reaction_0.function = structasstatereaction_function_0;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    self->___reaction_0.self = self;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 11 "file:/lf-flexpret-scripts/tests/StructAsState.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    return self;
}
void delete_StructAsState(structasstate_self_t* self) {
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
// =============== END reactor class StructAsState

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t** __timer_triggers = NULL;
int __timer_triggers_size = 0;
// Array of pointers to timer triggers to be scheduled in __trigger_startup_reactions().
reaction_t* __startup_reactions[1];
int __startup_reactions_size = 1;
// Empty array of pointers to shutdown triggers.
reaction_t** __shutdown_reactions = NULL;
int __shutdown_reactions_size = 0;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    // ************* Instance StructAsState of class StructAsState
    structasstate_self_t* structasstate_self = new_StructAsState();
    //***** Start initializing StructAsState
    __startup_reactions[0] = &structasstate_self->___reaction_0;
    static hello_t structasstate_initial_s = {"Earth", 42};
    structasstate_self->s = structasstate_initial_s;
    //***** End initializing StructAsState
    // Populate arrays of trigger pointers.
    structasstate_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    structasstate_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (structasstate_self->___reaction_0.num_outputs > 0) {
        structasstate_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * structasstate_self->___reaction_0.num_outputs);
        structasstate_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * structasstate_self->___reaction_0.num_outputs);
        structasstate_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * structasstate_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of StructAsState does not depend on one maximal upstream reaction.
    structasstate_self->___reaction_0.last_enabling_reaction = NULL;
    // doDeferredInitialize
    // Connect inputs and outputs for reactor StructAsState.
    // END Connect inputs and outputs for reactor StructAsState.
    
    structasstate_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    structasstate_self->___reaction_0.index = 0x7fffffffffff0000LL;
}
void __trigger_startup_reactions() {
    
    for (int i = 0; i < __startup_reactions_size; i++) {
        if (__startup_reactions[i] != NULL) {
            _lf_enqueue_reaction(__startup_reactions[i]);
        }
    }
}
void __initialize_timers() {
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
