#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/SendingInside.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Printer
#line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
typedef struct {
#line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    int value;
#line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    bool is_present;
#line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    int num_destinations;
#line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
} printer_x_t;
typedef struct {
    int bank_index;
    #line 9 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    int count;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    printer_x_t* __x;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    // width of -2 indicates that it is not a multiport.
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    int __x__width;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    // Default input (in case it does not get connected)
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    printer_x_t __default__x;
    #line 10 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    reaction_t ___reaction_0;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    trigger_t ___x;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    reaction_t* ___x_reactions[1];
} printer_self_t;
void printerreaction_function_0(void* instance_args) {
    printer_self_t* self = (printer_self_t*)instance_args;
    printer_x_t* x = self->__x;
    int x_width = self->__x__width;
    #line 11 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    printf("Inside reactor received: %d\n", x->value);
    if (x->value != self->count) {
        printf("FAILURE: Expected %d.\n", self->count);
        exit(1);
    }
    self->count++;
        
}
printer_self_t* new_Printer() {
    printer_self_t* self = (printer_self_t*)calloc(1, sizeof(printer_self_t));
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    // Set input by default to an always absent default input.
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->__x = &self->__default__x;
    #line 10 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.number = 0;
    #line 10 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.function = printerreaction_function_0;
    #line 10 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.self = self;
    #line 10 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 10 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___x.last = NULL;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_Printer(printer_self_t* self) {
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
// =============== END reactor class Printer

// =============== START reactor class SendingInside
typedef struct {
    int bank_index;
    #line 20 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    int count;
    struct {
        #line 8 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
        printer_x_t x;
    } __p;
    #line 23 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    reaction_t ___reaction_0;
    #line 21 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    trigger_t ___t;
    #line 21 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    reaction_t* ___t_reactions[1];
} sendinginside_self_t;
void sendinginsidereaction_function_0(void* instance_args) {
    struct p{
        printer_x_t* x;
    } p;
    sendinginside_self_t* self = (sendinginside_self_t*)instance_args;
    p.x = &(self->__p.x);
    #line 24 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    (self->count)++;
    SET(p.x, self->count);
        
}
sendinginside_self_t* new_SendingInside() {
    sendinginside_self_t* self = (sendinginside_self_t*)calloc(1, sizeof(sendinginside_self_t));
    #line 23 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.number = 0;
    #line 23 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.function = sendinginsidereaction_function_0;
    #line 23 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.self = self;
    #line 23 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 23 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 21 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___t.last = NULL;
    #line 21 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    #line 21 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 21 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 21 "file:/lf-flexpret-scripts/tests/SendingInside.lf"
    self->___t.number_of_reactions = 1;
    self->___t.is_timer = true;
    return self;
}
void delete_SendingInside(sendinginside_self_t* self) {
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
// =============== END reactor class SendingInside

char* __default_argv[] = {"X", "-f", "true", "-o", "10", "sec"};
void __set_default_command_line_options() {
    default_argc = 6;
    default_argv = __default_argv;
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
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 1;
    __is_present_fields = (bool**)malloc(1 * sizeof(bool*));
    // ************* Instance SendingInside of class SendingInside
    sendinginside_self_t* sendinginside_self = new_SendingInside();
    //***** Start initializing SendingInside
    static int sendinginside_initial_count = 0;
    sendinginside_self->count = sendinginside_initial_count;
    sendinginside_self->___t.offset = 0;
    sendinginside_self->___t.period = SEC(1);
    __timer_triggers[0] = &sendinginside_self->___t;
    // ************* Instance SendingInside.p of class Printer
    printer_self_t* sendinginside_p_self = new_Printer();
    //***** Start initializing SendingInside.p
    // width of -2 indicates that it is not a multiport.
    sendinginside_p_self->__x__width = -2;
    static int sendinginside_p_initial_count = 1;
    sendinginside_p_self->count = sendinginside_p_initial_count;
    //***** End initializing SendingInside.p
    //***** End initializing SendingInside
    // Populate arrays of trigger pointers.
    sendinginside_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    sendinginside_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (sendinginside_self->___reaction_0.num_outputs > 0) {
        sendinginside_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * sendinginside_self->___reaction_0.num_outputs);
        sendinginside_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * sendinginside_self->___reaction_0.num_outputs);
        sendinginside_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * sendinginside_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    sendinginside_self->___reaction_0.output_produced[0]
    = &sendinginside_self->__p.x.is_present
    ;
    // Reaction 0 of SendingInside does not depend on one maximal upstream reaction.
    sendinginside_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of SendingInside triggers 1 downstream reactions through port SendingInside.p.x.
    sendinginside_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of SendingInside, allocate an
    // array of trigger pointers for downstream reactions through port SendingInside.p.x
    trigger_t** sendinginside_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    sendinginside_self->___reaction_0.triggers[0] = sendinginside_0_0;
    // Point to destination port SendingInside.p.x's trigger struct.
    sendinginside_0_0[0] = &sendinginside_p_self->___x;
    sendinginside_self->__p.x.
    num_destinations = 1;
    sendinginside_p_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    sendinginside_p_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (sendinginside_p_self->___reaction_0.num_outputs > 0) {
        sendinginside_p_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * sendinginside_p_self->___reaction_0.num_outputs);
        sendinginside_p_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * sendinginside_p_self->___reaction_0.num_outputs);
        sendinginside_p_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * sendinginside_p_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of SendingInside.p depends on one maximal upstream reaction.
    sendinginside_p_self->___reaction_0.last_enabling_reaction = &(sendinginside_self->___reaction_0);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor SendingInside.
    // Connect inputs and outputs for reactor SendingInside.p.
    // END Connect inputs and outputs for reactor SendingInside.p.
    // Connect PortInstance SendingInside.p.x, which gets data from reaction 0
    // of SendingInside, to SendingInside.p.x.
    sendinginside_p_self->__x = (printer_x_t*)&sendinginside_self->__p.x;
    // END Connect inputs and outputs for reactor SendingInside.
    // Add port SendingInside.p.x to array of is_present fields.
    __is_present_fields[0] 
            = &sendinginside_self->__p.x.
            is_present;
    sendinginside_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    sendinginside_self->___reaction_0.index = 0x7fffffffffff0000LL;
    sendinginside_p_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    sendinginside_p_self->___reaction_0.index = 0x7fffffffffff0001LL;
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