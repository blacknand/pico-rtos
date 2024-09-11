#include <stdio.h>
#include "queue.h"

int main() {
    printf("Inputting 1, 2, 3, 4 into the quueue\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    printf("Testing queue overflow, entering 5\n");
    enqueue(5);

    output_queue();

    printf("Dequeing first two elements\n");
    dequeue();
    dequeue();

    output_queue();
    
    printf("Testing queue underflow\n");
    dequeue();
    dequeue();
    dequeue();

    return 0;
}