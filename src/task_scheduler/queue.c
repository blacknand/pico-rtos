#include <stdio.h>
#include "queue.h"

int inp_arr[4];
int rear = -1;
int front = -1;

void enqueue(int insert_item) {
    // Inserts items into the end of the queue
    // https://www.digitalocean.com/community/tutorials/queue-in-c

    if (rear == SIZE - 1)
        printf("Queue overflow when trying to enter %d\n", insert_item);
    else {
        if (front == -1)
            front = 0;
        rear++;
        inp_arr[rear] = insert_item;
        printf("Added %d into the queue\n", insert_item);
    }
}


void dequeue(void) {
    if (front == -1 || front > rear) {
        // If queue is already empty
        printf("Queue underflow\n");
        return;
    } else {
        printf("Removing %d from the queue\n", inp_arr[front]);
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