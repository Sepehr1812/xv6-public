#include "ticketlock.h"
#include "types.h"
#include "defs.h"
#include "param.h"
#include "x86.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

// initialize the lock
void
t_initlock(struct ticketlock *lk, char *name)
{
    lk->name = name;
    lk->cpu = 0;
    lk->ticket = 0;
    lk->turn = 0;
}

// acquire the lock
void
t_acquire(struct ticketlock *lk)
{
    pushcli();
    if (t_holding(lk))
        panic("acquire");

    int my_ticket = fetch_and_add(&lk->ticket, 1);
    while (my_ticket != lk->turn); // locking

    __sync_synchronize();

    lk->cpu = mycpu();
    getcallerpcs(&lk, lk->pcs);
}

// release the lock
void
t_release(struct ticketlock *lk)
{
    if (!t_holding(lk))
        panic("release");

    lk->pcs[0] = 0;
    lk->cpu = 0;

    fetch_and_add(&lk->turn, 1); // giving turn to another process

    __sync_synchronize();

    popcli();
}

// Check whether this cpu is holding the lock.
int
t_holding(struct ticketlock *lk)
{
    int r;
    pushcli();
    r = (lk->ticket != lk->turn) && lk->cpu == mycpu();
    popcli();
    return r;
}
