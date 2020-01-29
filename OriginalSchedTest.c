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
    int i[1000000];
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

    for (i[getpid() % 1000] = 0; i[getpid() % 1000] < 1000; i[getpid() % 1000]++)
        printf(1, "[%d]: [%d]\n", getpid(), i[getpid()] + 1);

    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    waitForChild(&times[getpid() % 1000]);
    // printf(1, "times in order: %d, %d, %d, %d, %d\n", times[getpid() % 1000].creationTime,
    //  times[getpid() % 1000].terminationTime,
    //           times[getpid() % 1000].readyTime, times[getpid() % 1000].runningTime,
    //            times[getpid() % 1000].sleepingTime);

    int tt = times[getpid() % 1000].terminationTime - times[getpid() % 1000].creationTime;
    int cbt = times[getpid() % 1000].runningTime;
    int wt = tt - cbt;

    printf(1, "[[%d]]: TT = %d, CBT = %d, WT = %d\n", getpid() % 1000, tt, cbt, wt);

    // printf(1, "\n\n\nTimes for children:\n\n");
    // int j;
    // int stt = 0;
    // int scbt = 0;
    // int swt = 0;
    // for (j = 0; j < 1000; j++)    
    // {
    //     int tt = times[j].terminationTime - times[j].creationTime;
    //     int cbt = times[j].runningTime;
    //     int wt = tt - cbt;
    //     stt += tt;
    //     scbt += cbt;
    //     swt += wt;

    //     printf(1, "[[%d]]: TT = %d, CBT = %d, WT = %d\n", j + 1, tt, cbt, wt);
    // }

    // printf(1, "\n\n***********************************************ATT = %d, ACBT = %d, AWT = %d\n", stt / 1000.0, scbt / 1000.0, swt / 1000.0);

    exit();
}
