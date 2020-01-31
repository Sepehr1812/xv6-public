// A code for testing reader writer problem implementation; P2 Q1.2

#include "types.h"
#include "user.h"

void test_rw(int *pattern, int size)
{
    int pid, i;

    rwinit();
    pid = fork();

    for (i = 1; i < size; i++)
    {
        if (pid < 0)
        {
            printf(1, "fork failed\n");
            exit();
        }
        else if (pid > 0)
        {
            pid = fork();
            sleep(pid * 10); // to avoid get printed texts garbled.
        }
        else
            break;
    }

    if (pid < 0)
    {
        printf(1, "fork failed\n");
        exit();
    }
    else if (pid == 0)
    {
        printf(1, "child adding to shared memory\n");

        int res = rwtest(pattern[i - 1]);
        if (pattern[i - 1] == 0)
            printf(1, "reader read from shared memory: %d\n", res);
        else
            printf(1, "writer wrote to shared memory\n");
    }
    else
    {
        for (i = 0; i < size; i++)
            wait();

        printf(1, "\nuser program finished\n");
        printf(1, "last value of shared memory: %d\n", rwtest(0));
    }
}

int main()
{
    char argv[100];

    printf(1, "enter pattern for readers/writers test:\n");
    int read_size = read(0, argv, sizeof(argv));
    argv[read_size - 1] = '\0';

    int pattern[100], i;
    for (i = 0; argv[i + 1] != '\0'; i++)
    {
        switch (argv[i + 1])
        {
            case '0':
                pattern[i] = 0;
                break;
            case '1':
                pattern[i] = 1;
                break;
            default:
                printf(1, "pattern must consist of only 0 and 1\n");
                exit();
        }
    }

    test_rw(pattern, i);
    exit();
}