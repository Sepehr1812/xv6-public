// Test code for Q 2.1

#include "types.h"
#include "user.h"

int main(int argc, char const *argv[])
{
    int a = fork();
    int b = fork();

    if (a > 0)
        sleep(20);
    if (b > 0)
        sleep(10);

    printf(1, "PID: %d, PPID: %d, getChildren: %d\n", getpid(), getppid(), getChildren(getppid()));
    
    wait();
    wait();

    exit();
}
