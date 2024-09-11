/*
Implementation of the round robin CPU scheduling algorithim in which every process is allocated a fixed amount of time
to finish execution, called a time quantum. Every process within this algorithim is executed cyclically meaning if a 
process does not finish execution during it's allocated time quantum then the process is sent back to the ready state
at the back of the queue (FIFO data structure) and must await for it's next time quantum to finish the execution. In other
words, if a process's time burst is more than the time quantum, then it will go back to the end of the queue and will
continue executing when it's time quantum is next up. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "round_robin_scheduler.c"

#ifndef FIXED_INTERVAL
#define FIXED_INTERVAL  4
#endif

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 100
#endif


int init(void) {
    int processes = 4
    int time_quantum = 4;
    struct process_struct process;
    float avg_wait, avg_turn;
    int total_turn = 0, burst_arr[50];

    /* Set arrival time and burst time */
    // flash_pico_led
    processes[0].arrival_time = 0;
    processes[0].burst_time = 10 * (2 * LED_DELAY_MS);
    // output_task1
    processes[1].arrival_time = 1;
    processes[1].arrival_time = 1000;
    // output_task2
    processes[2].arrival_time = 2;
    processes[2].arrival_time = 1000;
    // output_task3
    processes[3].arrival_time = 3;
    processes[3].arrival_time = 1000;
}