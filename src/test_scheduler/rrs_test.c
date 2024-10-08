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

// https://www.geeksforgeeks.org/program-for-round-robin-scheduling-for-the-same-arrival-time/ (this source is terrible)

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#include "rrs_test.h"

int main() {
    int processes_num;
    int quant = 0;

    printf("Enter number of processes: ");
    scanf("%d", &processes_num);
    struct process processes[processes_num];

    printf("Enter the time quantum: ");
    scanf("%d", &quant);

    printf("Enter the process numbers: ");
    for (int i = 0; i < processes_num; i++)
        scanf("%d", &(processes[i].pos));                                 // For position in queue?

    printf("Enter the arrival time of processes: ");
    for (int i = 0; i < processes_num; i++)
        scanf("%d", &(processes[i].arrival_time));

    printf("Enter the burst time of processes: ");
    for (int i = 0; i < processes_num; i++)
        scanf("%d", &(processes[i].burst_time));

    int unfinished_processes = processes_num;
    int start_times[processes_num][20];                                 // The start times of processses during different quantum executions
    float time = 0, min_time = INT_MAX;
    float remaining_burst_times[processes_num];
    float next_start_times[processes_num];

    // Initialisaing burst and arrival time arrays
    int index = -1;
    for (int i = 0; i < processes_num; i++) {
        remaining_burst_times[i] = processes[i].burst_time;
        next_start_times[i] = processes[i].arrival_time;
        for (int j = 0; j < 20; j++)
            start_times[i][j] = -1;
    }

    int total_wait_time = 0, total_turn_around_time = 0;
    bool flag = false;

    while (unfinished_processes != 0) {
        min_time = INT_MAX;
        flag = false;

        
        for (int i = 0; i < processes_num; i++) {
            float process_time = time + 0.1;                                    // To enable any processes that arrive exactly at time to still be considered
            // Ready to execute and still has burst time, process with the smallest arrival time is chosen
            if (next_start_times[i] <= process_time && min_time > next_start_times[i] && remaining_burst_times[i] > 0) {
                index = i;
                min_time = next_start_times[i];
                flag = true;
            }
        }

        // If no process is ready
        if (!flag) {
            time++;
            continue;
        }

        // Calculate the starting time
        int j = 0;
        while (start_times[index][j] != -1)
            j++;                                                                // Find first available index in start_times                                                               

        if (start_times[index][j] == -1) {
            start_times[index][j] = time;                                       // Record start time of process
            processes[index].start_time[j] = time;
        }

        // Determines if the process finishes within the quantum
        if (remaining_burst_times[index] <= quant) {
            time += remaining_burst_times[index];
            remaining_burst_times[index] = 0;
        } else {
            time += quant;
            remaining_burst_times[index] -= quant;                                // Process is paused until next cycle
        }

        if (remaining_burst_times[index] > 0)
            next_start_times[index] = time + 0.1;

        // Calculate the arrival time, burst time and final times
        if (remaining_burst_times[index] == 0) {
            unfinished_processes--;
            processes[index].final_time = time;
            processes[index].wait_time = processes[index].final_time - processes[index].arrival_time - processes[index].burst_time;
            total_wait_time += processes[index].wait_time;
            processes[index].turn_around_time = processes[index].burst_time + processes[index].wait_time;
            total_turn_around_time += processes[index].turn_around_time;
        }
    }

    printf("%-15s %-15s %-15s %-25s %-15s %-15s %-15s\n", 
           "Process number", "Arrival time", "Burst time", "Start times", 
           "Final time", "Wait time", "Turn around time");

    for (int i = 0; i < processes_num; i++) {
        // Print the process details with the same fixed column widths
        printf("%-15d %-15d %-15d ", 
               processes[i].pos, 
               processes[i].arrival_time, 
               processes[i].burst_time);

        // Print all start times for the process
        int j = 0;
        while (start_times[i][j] != -1) {
            printf("%d ", start_times[i][j]);
            j++;
        }

        // Ensure enough padding after start times
        printf("%*s", 25 - (j * 3), "");

        // Print the final time, wait time, and turn-around time in the corresponding columns
        printf("%-15d %-15d %-15d\n", 
               processes[i].final_time, 
               processes[i].wait_time, 
               processes[i].turn_around_time);
    }

    // Calculate average wait time and turn around time
    double avg_wait_time, avg_turn_around_time;
    avg_wait_time = total_wait_time / (float) processes_num;
    avg_turn_around_time = total_turn_around_time / (float) processes_num;

    printf("\n");
    printf("Average wait time:              %lf\n", avg_wait_time);
    printf("Average turn around time:       %lf\n", avg_turn_around_time);

    return 0;
}