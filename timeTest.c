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
    times.creationTime = 2;
    times.terminationTime = 20000;
    times.readyTime = 15;
    times.runningTime = 20;
    times.sleepingTime = 10;

    waitForChild(&times);

    exit();
}
