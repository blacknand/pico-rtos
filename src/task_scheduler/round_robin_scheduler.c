/** 
 * Implementation of the round robin CPU scheduling algorithim in which every process is allocated a fixed amount of time 
 * to finish execution, called a time quantum. Every process within this algorithim is executed cyclically meaning if a 
 * process does not finish execution during it's allocated time quantum then the process is sent back to the ready state
 * at the back of the queue (FIFO data structure) and must await for it's next time quantum to finish the execution. In other
 * words, if a process's time burst is more than the time quantum, then it will go back to the end of the queue and will
 * continue executing when it's time quantum is next up. 
*/


/**
 * Strong chace this needs to be ran like an FPGA program
 * what I am thinking is that you run task_scheduler.c once on the Pico
 * and then you give the input as the setup to ask how many tasks there are to execute
 * and then it just executes using them
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "pico/stdlib.h"
#include "round_robin_scheduler.h"
#include "queue.h"

#ifndef FIXED_INTERVAL
#define FIXED_INTERVAL 4
#endif

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 100
#endif

#define NUM_TASKS 4
#define TIME_QUANT 1000                         // 1000 ms by default 


int max(int a, int b) {
    return (a > b) ? a : b;
}


int round_robin_scheduler(void (*func_ptr1) (void), void (*func_ptr2) (void),
                          void (*func_ptr3) (void), void (*func_ptr4) (void)) {
    // https://www.scaler.com/topics/round-robin-scheduling-in-os/
    int processes = 4;                                                  // The number of processes to execute
    int time_quantum = 4;                                               // The alloted number of seconds during a time quantum
    struct process_struct process[4];              
    float avg_wait, avg_turn;                               
    int total_turn = 0, burst_arr[4], total_waiting = 0;

    void (*tasks_arr[4]) (void) = {func_ptr1, func_ptr2, func_ptr3, func_ptr4};
    for (int i = 0; i < 4; i++)
        printf("func ptr: %d - %p\n", i, (void*)tasks_arr[i]);
    const char *task_names[4] = {"flash_pico_led", "output_task1", "output_task2", "output_task3"};

    int tasks_index = 0;
    while (1) {
        tasks_arr[tasks_index]();                // Execute current function
        sleep_ms(TIME_QUANT);
        tasks_index = (tasks_index + 1) % NUM_TASKS;
    }

    return 0;
}