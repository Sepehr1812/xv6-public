#include "types.h"
#include "user.h"

struct timeVariables {
    uint creationTime;
    uint terminationTime;
    uint sleepingTime;
    uint readyTime;
    uint runningTime;
} times[1000];

int main(int argc, char const *argv[])
{
    int i[500000000];
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();

    int pid = getpid();
    if (pid >= 1 && pid <= 5)
        changePriority(5);
    else if (pid >= 6 && pid <= 10)
        changePriority(4);
    else if (pid >= 11 && pid <= 15)
        changePriority(3);
    else if (pid >= 16 && pid <= 20)
        changePriority(2);
    else if (pid >= 25 && pid <= 30)
        changePriority(1);

    for (i[getpid() % 500000000] = 0; i[getpid() % 500000000] < 500000000; i[getpid() % 500000000]++)
        printf(1, "[%d]: [%d]\n", getpid() % 25, i[getpid()] + 1);

    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    waitForChild(&times[getpid() % 500000000]);
    // printf(1, "times in order: %d, %d, %d, %d, %d\n", times[getpid() % 500000000].creationTime,
    //  times[getpid() % 500000000].terminationTime,
    //           times[getpid() % 500000000].readyTime, times[getpid() % 500000000].runningTime,
    //            times[getpid() % 500000000].sleepingTime);

    int tt = times[getpid() % 500000000].terminationTime - times[getpid() % 500000000].creationTime;
    int cbt = times[getpid() % 500000000].runningTime;
    int wt = tt - cbt;

    printf(1, "[[%d]]: TT = %d, CBT = %d, WT = %d\n", getpid() % 500000000, tt, cbt, wt);


    exit();
}
