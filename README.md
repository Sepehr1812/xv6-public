# XV6
This project is a modified XV6 Operation System.

**Added System Calls**
* ```getChildren```: This system call gets PID of a process and returns process ids of its children.
* ```getCount```: This system call gets a valid system call number (listed in the file "syscall.h") as an input and returns the
number of times the referenced system call was invoked by the calling process.
* ```getPPID```: Returns PID of the parent of the current process.

**Modified Schedualing Algorithms**
* One added algorithm changes CPU turn every 10 CPU ticks (instead of 1).
* Another one considers a priority of 1 to 5 to every process and implements priority schedualing algorithm.
* ```changePolicy``` system call added to change schedualing algorithm between three policies.
* ```changePriority``` system call added to change the priority of processes.
* Test codes could be used for measuring execution times for each priority and comparing with another priorities.
* ```waitForChild``` system call added. It is the same ```wait``` system call plus measuring times will be explained below.

**Ability to Measure Important Times**
* This ability implemented by a struct contains below times:
```creationTime, terminationTime, sleepingTime, readyTime, runningTime```
Struct fields have been added to each process.

**Ticket Lock**
* Implementation of ticket lock and test files for it.
* implemetation of readers writers problem with ticket lock (uses a shared integer variable).


! Numbers in my commit notes are numbers of questions in the project description.
!! my changes to source codes are below ```// My project``` lines.
!!! You can find the source code here: https://github.com/mit-pdos/xv6-public
