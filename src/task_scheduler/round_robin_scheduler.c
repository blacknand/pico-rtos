/** 
 * Implementation of the round robin CPU scheduling algorithim in which every process is allocated a fixed amount of time 
 * to finish execution, called a time quantum. Every process within this algorithim is executed cyclically meaning if a 
 * process does not finish execution during it's allocated time quantum then the process is sent back to the ready state
 * at the back of the queue (FIFO data structure) and must await for it's next time quantum to finish the execution. In other
 * words, if a process's time burst is more than the time quantum, then it will go back to the end of the queue and will
 * continue executing when it's time quantum is next up. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "round_robin_scheduler.h"
#include "queue.h"

#ifndef FIXED_INTERVAL
#define FIXED_INTERVAL  4
#endif

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 100
#endif


int round_robin_scheduler(void (*func_ptr1) (void), void (*func_ptr2) (void),
                          void (*func_ptr3) (void), void (*func_ptr4) (void)) {
    // https://www.scaler.com/topics/round-robin-scheduling-in-os/
    int processes = 4;
    int time_quantum = 4;
    struct process_struct process;
    float avg_wait, avg_turn;
    int total_turn = 0, burst_arr[50];

    void (*tasks_arr[4]) (void) = {func_ptr1, func_ptr2, func_ptr3, func_ptr4};

    /* Set arrival time and burst time */
    // flash_pico_led
    process[0].arrival_time = 0;
    process[0].burst_time = 10 * (2 * LED_DELAY_MS);
    burst_arr[0] = prcoess[0].burst_time;
    // output_task1
    process[1].arrival_time = 1;
    process[1].arrival_time = 1000;
    burst_arr[1] = process[1].burst_time;
    // output_task2
    process[2].arrival_time = 2;
    process[2].arrival_time = 1000;
    burst_arr[2] = process[2].burst_time;
    // output_task3
    process[3].arrival_time = 3;
    process[3].arrival_time = 1000;
    burst_arr[3] = process[3].burst_time;

    int current_time = 0;
    enqueue(0);
    int completed = 0;
    int mark[4];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;

    while (completed != n) {
        // Give quantum time to process that is at front of the queue and pop this process from the queue
        index = peek();
        dequeue();

        // If process is being executed for first time, set its start time
        if (burst_arr[index] == process[index].burst_time) {
            process[index].start_time = max(current_time, process[index].arrival_time);  
            current_time = process[index].start_time;
        }

        // Check if remaning burst time is > quantum time
        if (0 < burst_arr[index] - time_quantum) {
            burst_arr[index] -= time_quantum;                           // Reduce burst time by quantum time already exectued
            current_time += time_quantum;                             
        } else {
            // Process completes during quantum time
            tasks_arr[index]();                                                 // Execute task via function pointer
            current_time += burst_arr[index];
            process[index].completion_time = current_time;
            process[index].turn_time = process[index].completion_time - process[index].arrival_time;
            process[index].waiting_time = process[index].turn_time - process[index].burst_time;
            total_waiting += process[index].waiting_time;
            total_turn += process[index].turn_time;
            completed++;
            burst_arr[index] = 0;
        }

        // Check if an additional process has arrived during exectuion of current process and enque it
        for (int i = 1; i < n; i++) {
            if (burst_arr[i] > 0 && process[i].arrival_time <= current_time && mark[i] == 0) {
                mark[i] = 1;
                enqueue(i);
                break;
            }
        }
    }

    avg_waiting = (float) total_waiting / n;
    avg_turn = (float) total_turn / n;

    // Get data of each process
    printf("Process ID: \t");
    printf("Arrival Time: \t");
    printf("Burst Time: \t");
    printf("Completion Time: \t");
    printf("Turn Around Time: \t");
    printf("Waiting Time: \t");
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", i + 1);
        printf("%d\t", process[i].arrival_time);
        printf("%d\t", process[i].burst_time);
        printf("%d\t", process[i].completion_time);
        printf("%d\t", process[i].turn_time);
        printf("%d\t", process[i].waiting_time);
        printf("\n");
    }

    printf("Average waiting time: %.2f\n", avg_waiting);
    printf("Average turnaround time: %.2f\n", avg_turn);
    return 0;
}