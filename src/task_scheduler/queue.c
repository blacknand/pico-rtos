#include <stdio.h>
#include "queue.h"

void enqueue(int insert_item) {
    // Inserts items into the end of the queue
    // https://www.digitalocean.com/community/tutorials/queue-in-c
    int insert_item;

    if (rear == SIZE - 1)
        printf("Queue overflow when trying to enter %d\n", insert_item);
    else {
        if (front == -1) {
            front = 0;
        rear++;
        inp_arr[read] = insert_item;
        }
    }
}


void dequeue(void) {
    if (front == -1 || front > rear) {
        // If queue is already empty
        printf("Queue underflow\n");
        return;
    } else {
        front++;
    }
}


void output_queue(void) {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue:\n");
        for (int i = front; i <= rear; i++)
            printf("%d\n", inp_arr[i]);
    }
}