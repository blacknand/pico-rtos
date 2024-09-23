/*
    - time quantum: the fixed time allocated for each process to execute before the scheduler switches 
        to the next process.
    - burst time: the total amount of time required by a process to complete execution.
    - turn around time: the time difference between completion time and arrival time. It is the total 
        time from when a process enters the queue to when it finishes.
        Formula: turn around time = completion time - arrival time
    - waiting time: the time a process spends waiting in the ready queue before getting the CPU. 
        It is the time spent in the system minus the time spent actually executing.
        Formula: waiting time = turn around time - burst time
    - total time (current): the current time being tracked by the scheduler during the process execution.
        This is incremented as processes are executed (i.e., the global system time).
    - total execution time: the total amount of time it takes for all scheduled processes to finish executing.
*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#include "rrs_test.h"

int main() {
    int n, i, j;
    

    return 0;
}