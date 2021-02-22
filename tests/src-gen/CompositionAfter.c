#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/CompositionAfter.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class __GenDelay_197ef
typedef struct {
    int value;
    bool is_present;
    int num_destinations;
} __gendelay_197ef_inp_t;
typedef struct {
    int value;
    bool is_present;
    int num_destinations;
} __gendelay_197ef_out_t;
typedef struct {
    trigger_t* trigger;
    int value;
    bool is_present;
    bool has_value;
    lf_token_t* token;
} __gendelay_197ef_act_t;
typedef struct {
    int bank_index;
    interval_t delay;
    __gendelay_197ef_act_t __act;
    __gendelay_197ef_inp_t* __inp;
    // width of -2 indicates that it is not a multiport.
    int __inp__width;
    // Default input (in case it does not get connected)
    __gendelay_197ef_inp_t __default__inp;
    __gendelay_197ef_out_t __out;
    int __out__width;
    reaction_t ___reaction_0;
    reaction_t ___reaction_1;
    trigger_t ___act;
    reaction_t* ___act_reactions[1];
    trigger_t ___inp;
    reaction_t* ___inp_reactions[1];
} __gendelay_197ef_self_t;
void __gendelay_197efreaction_function_0(void* instance_args) {
    __gendelay_197ef_self_t* self = (__gendelay_197ef_self_t*)instance_args;
    // Expose the action struct as a local variable whose name matches the action name.
    __gendelay_197ef_act_t* act = &self->__act;
    // Set the fields of the action struct to match the current trigger.
    act->is_present = self->___act.is_present;
    act->has_value = ((self->___act.token) != NULL && (self->___act.token)->value != NULL);
    act->token = (self->___act.token);
    if (act->has_value) {
        act->value = *(int*)(self->___act.token)->value;
    }
    __gendelay_197ef_out_t* out = &self->__out;
    SET(out, act->value);
}
void __gendelay_197efreaction_function_1(void* instance_args) {
    __gendelay_197ef_self_t* self = (__gendelay_197ef_self_t*)instance_args;
    __gendelay_197ef_inp_t* inp = self->__inp;
    int inp_width = self->__inp__width;
    __gendelay_197ef_act_t* act = &self->__act;
    schedule_copy(act, 0, &inp->value, 1);  // Length is 1.
}
__gendelay_197ef_self_t* new___GenDelay_197ef() {
    __gendelay_197ef_self_t* self = (__gendelay_197ef_self_t*)calloc(1, sizeof(__gendelay_197ef_self_t));
    self->__act.trigger = &self->___act;
    // Set input by default to an always absent default input.
    self->__inp = &self->__default__inp;
    self->___reaction_0.number = 0;
    self->___reaction_0.function = __gendelay_197efreaction_function_0;
    self->___reaction_0.self = self;
    self->___reaction_0.deadline_violation_handler = NULL;
    self->___reaction_0.tardy_handler = NULL;
    self->___reaction_1.number = 1;
    self->___reaction_1.function = __gendelay_197efreaction_function_1;
    self->___reaction_1.self = self;
    self->___reaction_1.deadline_violation_handler = NULL;
    self->___reaction_1.tardy_handler = NULL;
    self->___act.last = NULL;
    self->___act_reactions[0] = &self->___reaction_0;
    self->___act.reactions = &self->___act_reactions[0];
    self->___act.number_of_reactions = 1;
    self->___act.is_physical = false;
    self->___act.element_size = sizeof(int);
    self->___inp.last = NULL;
    self->___inp_reactions[0] = &self->___reaction_1;
    self->___inp.reactions = &self->___inp_reactions[0];
    self->___inp.number_of_reactions = 1;
    self->___inp.element_size = sizeof(int);
    return self;
}
void delete___GenDelay_197ef(__gendelay_197ef_self_t* self) {
    if (self->___reaction_0.output_produced != NULL) {
        free(self->___reaction_0.output_produced);
    }
    if (self->___reaction_0.triggers != NULL) {
        free(self->___reaction_0.triggers);
    }
    if (self->___reaction_0.triggered_sizes != NULL) {
        free(self->___reaction_0.triggered_sizes);
    }
    if (self->___reaction_1.output_produced != NULL) {
        free(self->___reaction_1.output_produced);
    }
    if (self->___reaction_1.triggers != NULL) {
        free(self->___reaction_1.triggers);
    }
    if (self->___reaction_1.triggered_sizes != NULL) {
        free(self->___reaction_1.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    for(int i = 0; i < self->___reaction_1.num_outputs; i++) {
        free(self->___reaction_1.triggers[i]);
    }
    free(self);
}
// =============== END reactor class __GenDelay_197ef

// =============== START reactor class Test
#line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
typedef struct {
#line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int value;
#line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    bool is_present;
#line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int num_destinations;
#line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
} test_x_t;
typedef struct {
    int bank_index;
    #line 20 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int count;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    test_x_t* __x;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    // width of -2 indicates that it is not a multiport.
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int __x__width;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    // Default input (in case it does not get connected)
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    test_x_t __default__x;
    #line 21 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    reaction_t ___reaction_0;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    trigger_t ___x;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    reaction_t* ___x_reactions[1];
} test_self_t;
void testreaction_function_0(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    test_x_t* x = self->__x;
    int x_width = self->__x__width;
    #line 22 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    (self->count)++;
    printf("Received %d\n", x->value);
    if (x->value != self->count) { 
        printf("FAILURE: Expected %d\n", self->count);
        exit(1); 
    }
        
}
test_self_t* new_Test() {
    test_self_t* self = (test_self_t*)calloc(1, sizeof(test_self_t));
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    // Set input by default to an always absent default input.
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->__x = &self->__default__x;
    #line 21 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.number = 0;
    #line 21 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.function = testreaction_function_0;
    #line 21 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.self = self;
    #line 21 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 21 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___x.last = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 19 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_Test(test_self_t* self) {
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
// =============== END reactor class Test

// =============== START reactor class Source
#line 9 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
typedef struct {
#line 9 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int value;
#line 9 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    bool is_present;
#line 9 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int num_destinations;
#line 9 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
} source_y_t;
typedef struct {
    int bank_index;
    #line 8 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    interval_t period;
    #line 11 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int count;
    #line 9 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    source_y_t __y;
    #line 9 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    int __y__width;
    #line 12 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    reaction_t ___reaction_0;
    #line 10 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    trigger_t ___t;
    #line 10 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    reaction_t* ___t_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    source_y_t* y = &self->__y;
    #line 13 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    (self->count)++;
    SET(y, self->count);
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    #line 12 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.number = 0;
    #line 12 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.function = sourcereaction_function_0;
    #line 12 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.self = self;
    #line 12 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 12 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 10 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___t.last = NULL;
    #line 10 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    #line 10 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 10 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 10 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    self->___t.number_of_reactions = 1;
    self->___t.is_timer = true;
    return self;
}
void delete_Source(source_self_t* self) {
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
// =============== END reactor class Source

// =============== START reactor class Composition
typedef struct {
    int bank_index;
    #line 30 "file:/lf-flexpret-scripts/tests/CompositionAfter.lf"
    interval_t delay;
} composition_self_t;
composition_self_t* new_Composition() {
    composition_self_t* self = (composition_self_t*)calloc(1, sizeof(composition_self_t));
    return self;
}
void delete_Composition(composition_self_t* self) {
    free(self);
}
// =============== END reactor class Composition

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
    __tokens_with_ref_count_size = 1;
    __tokens_with_ref_count = (token_present_t*)malloc(1 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 3;
    __is_present_fields = (bool**)malloc(3 * sizeof(bool*));
    // ************* Instance Composition of class Composition
    composition_self_t* composition_self = new_Composition();
    //***** Start initializing Composition
    composition_self->delay = SEC(5); 
    // ************* Instance Composition.s of class Source
    source_self_t* composition_s_self = new_Source();
    //***** Start initializing Composition.s
    composition_s_self->period = SEC(2); 
    // width of -2 indicates that it is not a multiport.
    composition_s_self->__y__width = -2;
    static int composition_s_initial_count = 0;
    composition_s_self->count = composition_s_initial_count;
    composition_s_self->___t.offset = SEC(1);
    composition_s_self->___t.period = SEC(2);
    __timer_triggers[0] = &composition_s_self->___t;
    //***** End initializing Composition.s
    // ************* Instance Composition.d of class Test
    test_self_t* composition_d_self = new_Test();
    //***** Start initializing Composition.d
    // width of -2 indicates that it is not a multiport.
    composition_d_self->__x__width = -2;
    static int composition_d_initial_count = 0;
    composition_d_self->count = composition_d_initial_count;
    //***** End initializing Composition.d
    // ************* Instance Composition.delay_0 of class __GenDelay_197ef
    __gendelay_197ef_self_t* composition_delay_0_self = new___GenDelay_197ef();
    //***** Start initializing Composition.delay_0
    composition_delay_0_self->delay = SEC(5); 
    // width of -2 indicates that it is not a multiport.
    composition_delay_0_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    composition_delay_0_self->__inp__width = -2;
    composition_delay_0_self->___act.offset = SEC(5);
    composition_delay_0_self->___act.period = -1;
    composition_delay_0_self->___act.token = __create_token(sizeof(int));
    composition_delay_0_self->___act.is_present = false;
    __tokens_with_ref_count[0].token
            = &composition_delay_0_self->___act.token;
    __tokens_with_ref_count[0].is_present
            = &composition_delay_0_self->___act.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    //***** End initializing Composition.delay_0
    //***** End initializing Composition
    // Populate arrays of trigger pointers.
    composition_self->bank_index = 0;
    composition_s_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    composition_s_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (composition_s_self->___reaction_0.num_outputs > 0) {
        composition_s_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * composition_s_self->___reaction_0.num_outputs);
        composition_s_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * composition_s_self->___reaction_0.num_outputs);
        composition_s_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * composition_s_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    composition_s_self->___reaction_0.output_produced[0]
    = &composition_s_self->__y.is_present
    ;
    // Reaction 0 of Composition.s does not depend on one maximal upstream reaction.
    composition_s_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of Composition.s triggers 1 downstream reactions through port Composition.s.y.
    composition_s_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Composition.s, allocate an
    // array of trigger pointers for downstream reactions through port Composition.s.y
    trigger_t** composition_s_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    composition_s_self->___reaction_0.triggers[0] = composition_s_0_0;
    // Point to destination port Composition.delay_0.inp's trigger struct.
    composition_s_0_0[0] = &composition_delay_0_self->___inp;
    composition_s_self->__y.num_destinations
    = 1;
    composition_d_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    composition_d_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (composition_d_self->___reaction_0.num_outputs > 0) {
        composition_d_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * composition_d_self->___reaction_0.num_outputs);
        composition_d_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * composition_d_self->___reaction_0.num_outputs);
        composition_d_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * composition_d_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Composition.d depends on one maximal upstream reaction.
    composition_d_self->___reaction_0.last_enabling_reaction = &(composition_delay_0_self->___reaction_0);
    composition_delay_0_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    composition_delay_0_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (composition_delay_0_self->___reaction_0.num_outputs > 0) {
        composition_delay_0_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * composition_delay_0_self->___reaction_0.num_outputs);
        composition_delay_0_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * composition_delay_0_self->___reaction_0.num_outputs);
        composition_delay_0_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * composition_delay_0_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    composition_delay_0_self->___reaction_0.output_produced[0]
    = &composition_delay_0_self->__out.is_present
    ;
    // Total number of outputs produced by the reaction.
    composition_delay_0_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (composition_delay_0_self->___reaction_1.num_outputs > 0) {
        composition_delay_0_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * composition_delay_0_self->___reaction_1.num_outputs);
        composition_delay_0_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * composition_delay_0_self->___reaction_1.num_outputs);
        composition_delay_0_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * composition_delay_0_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Composition.delay_0 does not depend on one maximal upstream reaction.
    composition_delay_0_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of Composition.delay_0 triggers 1 downstream reactions through port Composition.delay_0.out.
    composition_delay_0_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Composition.delay_0, allocate an
    // array of trigger pointers for downstream reactions through port Composition.delay_0.out
    trigger_t** composition_delay_0_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    composition_delay_0_self->___reaction_0.triggers[0] = composition_delay_0_0_0;
    // Point to destination port Composition.d.x's trigger struct.
    composition_delay_0_0_0[0] = &composition_d_self->___x;
    // Reaction 1 of Composition.delay_0 does not depend on one maximal upstream reaction.
    composition_delay_0_self->___reaction_1.last_enabling_reaction = NULL;
    composition_delay_0_self->__out.num_destinations
    = 1;
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Composition.
    // Connect Composition.s.y to input port Composition.delay_0.inp
    composition_delay_0_self->__inp = (__gendelay_197ef_inp_t*)&composition_s_self->__y;
    // Connect Composition.delay_0.out to input port Composition.d.x
    composition_d_self->__x = (test_x_t*)&composition_delay_0_self->__out;
    // Connect inputs and outputs for reactor Composition.s.
    // END Connect inputs and outputs for reactor Composition.s.
    // Connect inputs and outputs for reactor Composition.d.
    // END Connect inputs and outputs for reactor Composition.d.
    // Connect inputs and outputs for reactor Composition.delay_0.
    // END Connect inputs and outputs for reactor Composition.delay_0.
    // END Connect inputs and outputs for reactor Composition.
    // Add action Composition.delay_0.act to array of is_present fields.
    __is_present_fields[0] 
            = &composition_delay_0_self->__act.is_present;
    // Add port Composition.s.y to array of is_present fields.
    __is_present_fields[1] = &composition_s_self->__y.is_present
    ;
    // Add port Composition.delay_0.out to array of is_present fields.
    __is_present_fields[2] = &composition_delay_0_self->__out.is_present
    ;
    composition_s_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    composition_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    composition_d_self->___reaction_0.chain_id = 4;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    composition_d_self->___reaction_0.index = 0x7fffffffffff0001LL;
    composition_delay_0_self->___reaction_0.chain_id = 6;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    composition_delay_0_self->___reaction_0.index = 0x7fffffffffff0000LL;
    composition_delay_0_self->___reaction_1.chain_id = 3;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    composition_delay_0_self->___reaction_1.index = 0x7fffffffffff0001LL;
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