#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/DelayString.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Test
#line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
typedef struct {
#line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    string value;
#line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    bool is_present;
#line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    int num_destinations;
#line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
} test_in_t;
typedef struct {
    int bank_index;
    #line 18 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    interval_t start_time;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    test_in_t* __in;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // width of -2 indicates that it is not a multiport.
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    int __in__width;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // Default input (in case it does not get connected)
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    test_in_t __default__in;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    reaction_t ___reaction_0;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    trigger_t ___in;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    reaction_t* ___in_reactions[1];
} test_self_t;
void testreaction_function_0(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    test_in_t* in = self->__in;
    int in_width = self->__in__width;
    #line 20 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    printf("Received: %s.\n", in->value);
    // Check the time of the input.
    interval_t elapsed = get_elapsed_logical_time();
    printf("After %lld nsec of logical time.\n", elapsed);
    if (elapsed != 100000000LL) {
        printf("ERROR: Expected elapsed time to be 100000000. It was %lld.\n", elapsed);
        exit(1);
    }
    if (strcmp(in->value, "Hello") != 0) {
        printf("ERROR: Expected input value to be \"Hello\". It was \"%s\".\n", in->value);
        exit(2);            
    }
        
}
test_self_t* new_Test() {
    test_self_t* self = (test_self_t*)calloc(1, sizeof(test_self_t));
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // Set input by default to an always absent default input.
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->__in = &self->__default__in;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.number = 0;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.function = testreaction_function_0;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.self = self;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in.last = NULL;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 17 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(string);
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

// =============== START reactor class DelayString
#line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
typedef struct {
#line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    string value;
#line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    bool is_present;
#line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    int num_destinations;
#line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
} delaystring_in_t;
#line 6 "file:/lf-flexpret-scripts/tests/DelayString.lf"
typedef struct {
#line 6 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    string value;
#line 6 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    bool is_present;
#line 6 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    int num_destinations;
#line 6 "file:/lf-flexpret-scripts/tests/DelayString.lf"
} delaystring_out_t;
#line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
typedef struct {
#line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    trigger_t* trigger;
#line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    string value;
#line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    bool is_present;
#line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    bool has_value;
#line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    lf_token_t* token;
#line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
} delaystring_a_t;
typedef struct {
    int bank_index;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    interval_t delay;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    delaystring_a_t __a;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    delaystring_in_t* __in;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // width of -2 indicates that it is not a multiport.
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    int __in__width;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // Default input (in case it does not get connected)
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    delaystring_in_t __default__in;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    delaystring_out_t __out;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    int __out__width;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    reaction_t ___reaction_0;
    #line 11 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    reaction_t ___reaction_1;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    trigger_t ___a;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    reaction_t* ___a_reactions[1];
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    trigger_t ___in;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    reaction_t* ___in_reactions[1];
} delaystring_self_t;
void delaystringreaction_function_0(void* instance_args) {
    delaystring_self_t* self = (delaystring_self_t*)instance_args;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // Expose the action struct as a local variable whose name matches the action name.
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    delaystring_a_t* a = &self->__a;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // Set the fields of the action struct to match the current trigger.
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    a->is_present = self->___a.is_present;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    a->has_value = ((self->___a.token) != NULL && (self->___a.token)->value != NULL);
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    a->token = (self->___a.token);
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    if (a->has_value) {
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
        a->value = *(string*)(self->___a.token)->value;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    }
    delaystring_out_t* out = &self->__out;
    #line 9 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    SET(out, a->value);
        
}
void delaystringreaction_function_1(void* instance_args) {
    delaystring_self_t* self = (delaystring_self_t*)instance_args;
    delaystring_in_t* in = self->__in;
    int in_width = self->__in__width;
    delaystring_a_t* a = &self->__a;
    #line 12 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // The following copies the char*, not the string.
    schedule_copy(a, self->delay, &(in->value), 1);
        
}
delaystring_self_t* new_DelayString() {
    delaystring_self_t* self = (delaystring_self_t*)calloc(1, sizeof(delaystring_self_t));
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->__a.trigger = &self->___a;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    // Set input by default to an always absent default input.
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->__in = &self->__default__in;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.number = 0;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.function = delaystringreaction_function_0;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.self = self;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 11 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_1.number = 1;
    #line 11 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_1.function = delaystringreaction_function_1;
    #line 11 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_1.self = self;
    #line 11 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 11 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_1.tardy_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___a.last = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___a_reactions[0] = &self->___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___a.reactions = &self->___a_reactions[0];
    #line 7 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___a.number_of_reactions = 1;
    self->___a.is_physical = false;
    self->___a.element_size = sizeof(string);
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in.last = NULL;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in_reactions[0] = &self->___reaction_1;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(string);
    return self;
}
void delete_DelayString(delaystring_self_t* self) {
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
// =============== END reactor class DelayString

// =============== START reactor class DelayStringTest
typedef struct {
    int bank_index;
    struct {
        #line 5 "file:/lf-flexpret-scripts/tests/DelayString.lf"
        delaystring_in_t in;
    } __d;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} delaystringtest_self_t;
void delaystringtestreaction_function_0(void* instance_args) {
    struct d{
        delaystring_in_t* in;
    } d;
    delaystringtest_self_t* self = (delaystringtest_self_t*)instance_args;
    d.in = &(self->__d.in);
    #line 40 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    SET(d.in, "Hello");
        
}
delaystringtest_self_t* new_DelayStringTest() {
    delaystringtest_self_t* self = (delaystringtest_self_t*)calloc(1, sizeof(delaystringtest_self_t));
    #line 39 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.number = 0;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.function = delaystringtestreaction_function_0;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.self = self;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 39 "file:/lf-flexpret-scripts/tests/DelayString.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    return self;
}
void delete_DelayStringTest(delaystringtest_self_t* self) {
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
// =============== END reactor class DelayStringTest

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
    __tokens_with_ref_count_size = 1;
    __tokens_with_ref_count = (token_present_t*)malloc(1 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 3;
    __is_present_fields = (bool**)malloc(3 * sizeof(bool*));
    // ************* Instance DelayStringTest of class DelayStringTest
    delaystringtest_self_t* delaystringtest_self = new_DelayStringTest();
    //***** Start initializing DelayStringTest
    __startup_reactions[0] = &delaystringtest_self->___reaction_0;
    // ************* Instance DelayStringTest.d of class DelayString
    delaystring_self_t* delaystringtest_d_self = new_DelayString();
    //***** Start initializing DelayStringTest.d
    delaystringtest_d_self->delay = MSEC(100); 
    // width of -2 indicates that it is not a multiport.
    delaystringtest_d_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    delaystringtest_d_self->__in__width = -2;
    delaystringtest_d_self->___a.offset = 0;
    delaystringtest_d_self->___a.period = -1;
    delaystringtest_d_self->___a.token = __create_token(sizeof(string));
    delaystringtest_d_self->___a.is_present = false;
    __tokens_with_ref_count[0].token
            = &delaystringtest_d_self->___a.token;
    __tokens_with_ref_count[0].is_present
            = &delaystringtest_d_self->___a.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    //***** End initializing DelayStringTest.d
    // ************* Instance DelayStringTest.t of class Test
    test_self_t* delaystringtest_t_self = new_Test();
    //***** Start initializing DelayStringTest.t
    // width of -2 indicates that it is not a multiport.
    delaystringtest_t_self->__in__width = -2;
    delaystringtest_t_self->start_time = 0;
    //***** End initializing DelayStringTest.t
    //***** End initializing DelayStringTest
    // Populate arrays of trigger pointers.
    delaystringtest_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delaystringtest_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delaystringtest_self->___reaction_0.num_outputs > 0) {
        delaystringtest_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delaystringtest_self->___reaction_0.num_outputs);
        delaystringtest_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaystringtest_self->___reaction_0.num_outputs);
        delaystringtest_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delaystringtest_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delaystringtest_self->___reaction_0.output_produced[0]
    = &delaystringtest_self->__d.in.is_present
    ;
    // Reaction 0 of DelayStringTest does not depend on one maximal upstream reaction.
    delaystringtest_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayStringTest triggers 1 downstream reactions through port DelayStringTest.d.in.
    delaystringtest_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayStringTest, allocate an
    // array of trigger pointers for downstream reactions through port DelayStringTest.d.in
    trigger_t** delaystringtest_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delaystringtest_self->___reaction_0.triggers[0] = delaystringtest_0_0;
    // Point to destination port DelayStringTest.d.in's trigger struct.
    delaystringtest_0_0[0] = &delaystringtest_d_self->___in;
    delaystringtest_self->__d.in.
    num_destinations = 1;
    delaystringtest_d_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delaystringtest_d_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delaystringtest_d_self->___reaction_0.num_outputs > 0) {
        delaystringtest_d_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delaystringtest_d_self->___reaction_0.num_outputs);
        delaystringtest_d_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaystringtest_d_self->___reaction_0.num_outputs);
        delaystringtest_d_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delaystringtest_d_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delaystringtest_d_self->___reaction_0.output_produced[0]
    = &delaystringtest_d_self->__out.is_present
    ;
    // Total number of outputs produced by the reaction.
    delaystringtest_d_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delaystringtest_d_self->___reaction_1.num_outputs > 0) {
        delaystringtest_d_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * delaystringtest_d_self->___reaction_1.num_outputs);
        delaystringtest_d_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaystringtest_d_self->___reaction_1.num_outputs);
        delaystringtest_d_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * delaystringtest_d_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayStringTest.d does not depend on one maximal upstream reaction.
    delaystringtest_d_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayStringTest.d triggers 1 downstream reactions through port DelayStringTest.d.out.
    delaystringtest_d_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayStringTest.d, allocate an
    // array of trigger pointers for downstream reactions through port DelayStringTest.d.out
    trigger_t** delaystringtest_d_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delaystringtest_d_self->___reaction_0.triggers[0] = delaystringtest_d_0_0;
    // Point to destination port DelayStringTest.t.in's trigger struct.
    delaystringtest_d_0_0[0] = &delaystringtest_t_self->___in;
    // Reaction 1 of DelayStringTest.d does not depend on one maximal upstream reaction.
    delaystringtest_d_self->___reaction_1.last_enabling_reaction = NULL;
    delaystringtest_d_self->__out.num_destinations
    = 1;
    delaystringtest_t_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delaystringtest_t_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delaystringtest_t_self->___reaction_0.num_outputs > 0) {
        delaystringtest_t_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delaystringtest_t_self->___reaction_0.num_outputs);
        delaystringtest_t_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaystringtest_t_self->___reaction_0.num_outputs);
        delaystringtest_t_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delaystringtest_t_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayStringTest.t depends on one maximal upstream reaction.
    delaystringtest_t_self->___reaction_0.last_enabling_reaction = &(delaystringtest_d_self->___reaction_0);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor DelayStringTest.
    // Connect DelayStringTest.d.out to input port DelayStringTest.t.in
    delaystringtest_t_self->__in = (test_in_t*)&delaystringtest_d_self->__out;
    // Connect inputs and outputs for reactor DelayStringTest.d.
    // END Connect inputs and outputs for reactor DelayStringTest.d.
    // Connect inputs and outputs for reactor DelayStringTest.t.
    // END Connect inputs and outputs for reactor DelayStringTest.t.
    // Connect PortInstance DelayStringTest.d.in, which gets data from reaction 0
    // of DelayStringTest, to DelayStringTest.d.in.
    delaystringtest_d_self->__in = (delaystring_in_t*)&delaystringtest_self->__d.in;
    // END Connect inputs and outputs for reactor DelayStringTest.
    // Add action DelayStringTest.d.a to array of is_present fields.
    __is_present_fields[0] 
            = &delaystringtest_d_self->__a.is_present;
    // Add port DelayStringTest.d.in to array of is_present fields.
    __is_present_fields[1] 
            = &delaystringtest_self->__d.in.
            is_present;
    // Add port DelayStringTest.d.out to array of is_present fields.
    __is_present_fields[2] = &delaystringtest_d_self->__out.is_present
    ;
    delaystringtest_self->___reaction_0.chain_id = 2;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaystringtest_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delaystringtest_d_self->___reaction_0.chain_id = 5;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaystringtest_d_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delaystringtest_d_self->___reaction_1.chain_id = 3;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaystringtest_d_self->___reaction_1.index = 0x7fffffffffff0001LL;
    delaystringtest_t_self->___reaction_0.chain_id = 4;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaystringtest_t_self->___reaction_0.index = 0x7fffffffffff0001LL;
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