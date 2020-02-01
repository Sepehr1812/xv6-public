// Test code for quantum modified Q 3.5.1

#include "types.h"
#include "user.h"

struct timeVariables {
    int creationTime;
    int terminationTime;
    int sleepingTime;
    int readyTime;
    int runningTime;
};

int main(void)
{
    changePolicy(1);

    int i = 0;
    int j = 0;
    int k = 0;

    struct timeVariables times[10];
    for (j = 0; j < 10; j++)
    {
        if (fork() == 0)
        {
            for (i = 0; i < 1000; i++)
                printf(1, "[%d]: [%d] \n", getpid(), i);
            exit();
        }
    }

    for (k = 0; k < 10; k++)
        waitForChild(&times[k]);

    int sumTurnaroundTime = 0;
    int sumCBT = 0;
    int sumWaitingTime = 0;

    for (k = 0; k < 10; k++)
    {
        sumTurnaroundTime += (times[k].terminationTime - times[k].creationTime);
        sumCBT += times[k].runningTime;
        sumWaitingTime += times[k].readyTime;
        printf(1, "Child number : %d \n", (k + 1));
        printf(1, "Turnaround time : %d  \n", (times[k].terminationTime - times[k].creationTime));
        printf(1, "CBT : %d  \n", times[k].runningTime);
        printf(1, "Waiting time : %d  \n", times[k].readyTime);
        printf(1, "\n");
    }

    // calculating parameters
    int childNumber = 10;
    int avgTurnaroundTime = sumTurnaroundTime / childNumber;
    int avgCBT = sumCBT / childNumber;
    int avgWaitingTime = sumWaitingTime / childNumber;

    printf(1, "All Processes : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime);
    printf(1, "Average CBT : %d  \n", avgCBT);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime);

    exit();
}
