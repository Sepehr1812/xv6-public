#include "types.h"
#include "user.h"

struct timeVariables {
  uint creationTime;
  uint terminationTime;
  uint sleepingTime;
  uint readyTime;
  uint runningTime;
} times;

int main(int argc, char const *argv[])
{
    fork();
    waitForChild(&times);
    printf(1, "times in order: %d, %d, %d, %d, %d\n", times.creationTime, times.terminationTime,
              times.readyTime, times.runningTime, times.sleepingTime);

    exit();
}
