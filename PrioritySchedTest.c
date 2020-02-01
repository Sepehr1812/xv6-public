// Test code for priority scheduling Q 3.5.2

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
    changePolicy(2);

    int i = 0;
    int j = 0;
    int k = 0;

    struct timeVariables times[25];
    int pids[25];
    for (j = 1; j <= 25; j++)
    {
        if (fork() == 0)
        {
            if (1 <= j && j <= 5)
                changePriority(5);
            else if (6 <= j && j <= 10)
                changePriority(4);
            else if (11 <= j && j <= 15)
                changePriority(3);
            else if (16 <= j && j <= 20)
                changePriority(2);
            else if (21 <= j && j <= 25)
                changePriority(1);

            for (i = 0; i < 500; i++)
                printf(1, "[%d]:[%d] \n", j, i);
            exit();
        }
    }

    for (k = 0; k < 25; k++)
        pids[k] = waitForChild(&times[k]);

    int sumTurnaroundTime = 0;
    int sumCBT = 0;
    int sumWaitingTime = 0;

    // sorting
    struct timeVariables temp;
    int priority_min_index;
    int pid_min;
    int pid_temp;
    for (i = 0; i < 25; i++)
    {
        // find minimum
        pid_min = 100000;
        priority_min_index = -1;
        for (j = i; j < 25; j++)
        {
            if (pids[j] < pid_min)
            {
                pid_min = pids[j];
                priority_min_index = j;
            }
        }

        // swapping
        temp = times[priority_min_index];
        times[priority_min_index] = times[i];
        times[i] = temp;

        pid_temp = pids[priority_min_index];
        pids[priority_min_index] = pids[i];
        pids[i] = pid_temp;
    }

    int sumTurnaroundTime5 = 0, sumTurnaroundTime4 = 0, sumTurnaroundTime3 = 0, sumTurnaroundTime2 = 0, sumTurnaroundTime1 = 0;
    int sumCBT5 = 0, sumCBT4 = 0, sumCBT3 = 0, sumCBT2 = 0, sumCBT1 = 0;
    int sumWaitingTime5 = 0, sumWaitingTime4 = 0, sumWaitingTime3 = 0, sumWaitingTime2 = 0, sumWaitingTime1 = 0;

    for (k = 0; k < 25; k++)
    {
        if (0 <= k && k < 5)
        {
            sumTurnaroundTime5 += (times[k].terminationTime - times[k].creationTime);
            sumCBT5 += times[k].runningTime;
            sumWaitingTime5 += times[k].readyTime;
        }
        else if (5 <= k && k < 10)
        {
            sumTurnaroundTime4 += (times[k].terminationTime - times[k].creationTime);
            sumCBT4 += times[k].runningTime;
            sumWaitingTime4 += times[k].readyTime;
        }
        else if (10 <= k && k < 15)
        {
            sumTurnaroundTime3 += (times[k].terminationTime - times[k].creationTime);
            sumCBT3 += times[k].runningTime;
            sumWaitingTime3 += times[k].readyTime;
        }
        else if (15 <= k && k < 20)
        {
            sumTurnaroundTime2 += (times[k].terminationTime - times[k].creationTime);
            sumCBT2 += times[k].runningTime;
            sumWaitingTime2 += times[k].readyTime;
        }
        else if (20 <= k && k < 25)
        {
            sumTurnaroundTime1 += (times[k].terminationTime - times[k].creationTime);
            sumCBT1 += times[k].runningTime;
            sumWaitingTime1 += times[k].readyTime;
        }

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
    int childNumber = 25;
    int avgTurnaroundTime = sumTurnaroundTime / childNumber;
    int avgCBT = sumCBT / childNumber;
    int avgWaitingTime = sumWaitingTime / childNumber;

    int eachPriorityNum = 5;
    int avgTurnaroundTime5 = sumTurnaroundTime5 / eachPriorityNum;
    int avgCBT5 = sumCBT5 / eachPriorityNum;
    int avgWaitingTime5 = sumWaitingTime5 / eachPriorityNum;

    int avgTurnaroundTime4 = sumTurnaroundTime4 / eachPriorityNum;
    int avgCBT4 = sumCBT4 / eachPriorityNum;
    int avgWaitingTime4 = sumWaitingTime4 / eachPriorityNum;

    int avgTurnaroundTime3 = sumTurnaroundTime3 / eachPriorityNum;
    int avgCBT3 = sumCBT3 / eachPriorityNum;
    int avgWaitingTime3 = sumWaitingTime3 / eachPriorityNum;

    int avgTurnaroundTime2 = sumTurnaroundTime2 / eachPriorityNum;
    int avgCBT2 = sumCBT2 / eachPriorityNum;
    int avgWaitingTime2 = sumWaitingTime2 / eachPriorityNum;

    int avgTurnaroundTime1 = sumTurnaroundTime1 / eachPriorityNum;
    int avgCBT1 = sumCBT1 / eachPriorityNum;
    int avgWaitingTime1 = sumWaitingTime1 / eachPriorityNum;

    printf(1, "\nPriority 5 : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime5);
    printf(1, "Average CBT : %d  \n", avgCBT5);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime5);

    printf(1, "\nPriority 4 : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime4);
    printf(1, "Average CBT : %d  \n", avgCBT4);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime4);

    printf(1, "\nPriority 3 : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime3);
    printf(1, "Average CBT : %d  \n", avgCBT3);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime3);

    printf(1, "\nPriority 2 : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime2);
    printf(1, "Average CBT : %d  \n", avgCBT2);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime2);

    printf(1, "\nPriority 1 : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime1);
    printf(1, "Average CBT : %d  \n", avgCBT1);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime1);


    printf(1, "\nAll Processes : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime);
    printf(1, "Average CBT : %d  \n", avgCBT);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime);

    exit();
}
