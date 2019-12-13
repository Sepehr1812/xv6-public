// Test code for Q 2.1

#include "types.h"
#include "user.h"

int main(int argc, char const *argv[])
{
    fork();
    fork();
    // wait();
    printf(1, "PID: %d, PPID: %d, getChildren: %d\n", getpid(), getppid(), getChildren(getppid()));
    wait();

    exit();
}
