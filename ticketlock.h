#include "types.h"

struct ticketlock {
    uint ticket; // the last ticket number
    uint turn; // ticket number of the process that is serving now.

    // For debugging:
    char *name;        // Name of lock.
    struct cpu *cpu;   // The cpu holding the lock.
    uint pcs[10];      // The call stack (an array of program counters) that locked the lock.
};