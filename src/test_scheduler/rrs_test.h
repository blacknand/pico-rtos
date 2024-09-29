struct process {
    int arrival_time;
    int burst_time;
    int start_time[20];
    int wait_time;
    int final_time;
    int turn_around_time;
    int pos;
};

extern int quant;