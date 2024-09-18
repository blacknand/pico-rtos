#ifndef QUEUE_H    
#define QUEUE_H

#ifndef SIZE
#define SIZE    4
#endif

extern int inp_arr[SIZE];   
extern int rear;
extern int front;

void enqueue(int insert_item);
void dequeue(void);
void output_queue(void);
int peek(void);

#endif  // QUEUE_H   
