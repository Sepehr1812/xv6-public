#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// My project

// return parent process id (ppid)
int
sys_getppid(void)
{
  return myproc()->parent->pid;
}

int
sys_getChildren(void)
{
  int pid;
  argptr(0, (void*) &pid, sizeof(pid));
  return getChildrenFunc(pid);
}

int
sys_getCount(void)
{
  int scn;
  argptr(0, (void*) &scn, sizeof(scn));
  return myproc()->sys_count[scn];
}

int
sys_changePriority(void)
{
  int p;
  argptr(0, (void*) &p, sizeof(p));
  myproc()->priority = p;

  if (myproc()->priority == p)
    return 1;
  return -1;
}

int
sys_changePolicy(void)
{
  int a;
  argptr(0, (void*) &a, sizeof(a));
  whichAlgo = a;
  // cprintf("algo: %d\n", whichAlgo); // for test
  if (whichAlgo == a)
    return 1;
  return -1;
}

int sys_waitForChild(void)
{
  struct timeVariables* t;
  argptr(0, (void*) &t, sizeof(t));
  int r = waitForChild(t);
  return r;
}

void
sys_ticketlockInit(void)
{
    init_tlock();
}

int
sys_ticketlockTest(void)
{
    return inc_sh_mem();
}

void
sys_rwinit(void)
{

}

int
sys_rwtest(void)
{
    int is_write;
    argint(0, (void*) &is_write);

}
