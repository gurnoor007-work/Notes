#include <iostream>
#include <format>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->r == q->size - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(struct Queue *q){
    if(q->r == q->f) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(struct Queue *q, int val) {
    if (isFull(q)){
        std::cout << "Queue is Full!!\n";
    }
    else {
        q->r++;
        q->arr[q->r] = val;
        std::cout << std::format("Added {} to Queue\n", val);
    }
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty, cannot dequeue!!\n";
    }
    else {
        q->f++;
        
    }
}

int main()
{
    Queue *q = new Queue;
    q->size = 100;
    q->f = q->r = -1;
    q->arr = new int[q->size];

    enqueue(q, 10);
    enqueue(q, 200);


    return 0;
}