#ifndef ROUND_ROBIN_SCHEDULER_H
#define ROUND_ROBIN_SCHEDULER_H

void round_robin_scheduler(void (*func_ptr1)(void), void (*func_ptr2)(void),
                           void (*func_ptr3)(void), void (*func_ptr4)(void));

#endif

struct process_struct {
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_time;
    int waiting_time;
    int start_time;
}