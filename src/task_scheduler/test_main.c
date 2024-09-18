#include <stdio.h>
#include "round_robin_scheduler.h"

void output_task0(void) {
    printf("Hello from output_task2\n");
}

void output_task1(void) {
    printf("Hello from output_task1\n");
}


void output_task2(void) {
    printf("Hello from output_task2\n");
}


void output_task3(void) {
    printf("Hello from output_task3\n");
}


int main() {
    void (*output_task0_func_ptr) (void);
    void (*output_task1_func_ptr) (void);
    void (*output_task2_func_ptr) (void);
    void (*output_task3_func_ptr) (void);
    output_task0_func_ptr = &output_task0;
    output_task1_func_ptr = &output_task1;
    output_task2_func_ptr = &output_task2;
    output_task3_func_ptr = &output_task3;
    round_robin_scheduler(output_task0_func_ptr, output_task1_func_ptr,
                          output_task2_func_ptr, output_task3_func_ptr);
}