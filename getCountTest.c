// Test for Q 2.2

#include "types.h"
#include "user.h"

int main(int argc, char const *argv[])
{
    int scn = atoi(argv[1]);

    // sys call number 22 has repeated for 5 times to test.
    // It prints a doubled number after each time we call "getCountTest 22" : 7, 14, 21, ... .
    getppid();
    getppid();
    getppid();
    getppid();
    getppid();
    getppid();
    getppid();

    printf(1, "System Call Count: %d\n", getCount(scn));
    
    exit();
}
