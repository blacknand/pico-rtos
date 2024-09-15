#ifndef SIZE
#define SIZE 4  
#endif

void enqueue(int insert_item);
void dequeue(void);
void output_queue(void);
int peek(void);
extern int inp_arr[4];
extern int rear;
extern int front;              // Front and read queue pointers to keep record of first and last element in the queue