#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/Imported.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class ImportedAgain
#line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
typedef struct {
#line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    int value;
#line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    bool is_present;
#line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    int num_destinations;
#line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
} importedagain_x_t;
typedef struct {
    int bank_index;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    importedagain_x_t* __x;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    // width of -2 indicates that it is not a multiport.
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    int __x__width;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    // Default input (in case it does not get connected)
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    importedagain_x_t __default__x;
    #line 8 "file:/lf-flexpret-scripts/tests/Imported.lf"
    reaction_t ___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    trigger_t ___x;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    reaction_t* ___x_reactions[1];
} importedagain_self_t;
void importedagainreaction_function_0(void* instance_args) {
    importedagain_self_t* self = (importedagain_self_t*)instance_args;
    importedagain_x_t* x = self->__x;
    int x_width = self->__x__width;
    #line 9 "file:/lf-flexpret-scripts/tests/Imported.lf"
    printf("Received: %d.\n", x->value);
            if (x->value != 42) {
                printf("ERROR: Expected input to be 42. Got: %d.\n", x->value);
                exit(1);
            }
        
}
importedagain_self_t* new_ImportedAgain() {
    importedagain_self_t* self = (importedagain_self_t*)calloc(1, sizeof(importedagain_self_t));
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    // Set input by default to an always absent default input.
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->__x = &self->__default__x;
    #line 8 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___reaction_0.number = 0;
    #line 8 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___reaction_0.function = importedagainreaction_function_0;
    #line 8 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___reaction_0.self = self;
    #line 8 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 8 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___x.last = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 7 "file:/lf-flexpret-scripts/tests/Imported.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_ImportedAgain(importedagain_self_t* self) {
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
// =============== END reactor class ImportedAgain

