#include <iostream>
#include <format>

// Remember, f index is on the node which is in front of the leading node, and rear (r) index
// is on the last Node

struct circularQueue
{
    int size;
    int f = 0;
    int r = 0;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        std::cout << "Queue is full!!\n";
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        std::cout << std::format("Added {} to Queue\n", val);
    }
}

void dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        std::cout << "Queue is empty, cannot dequeue!!\n";
    }
    else
    {
        q->f = (q->f + 1) % q->size;
    }
}

void show(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        std::cout << "Queue is empty!!\n";
    }
    else
    {
        std::cout << "Front ->>  ";
        int i = q->f + 1;
        while(true) {
            std::cout << q->arr[i] << " ";
            if (i == q->r){
                break;
            }
            i = (i+1) % q->size;
        }
        std::cout << "<<- Rear\n";
    }
}

int main()
{
    circularQueue *q = new circularQueue;
    q->size = 5;
    q->arr = new int[q->size];

    show(q);
    enqueue(q, 10);
    enqueue(q, 15);
    show(q);
    dequeue(q);
    show(q);
    dequeue(q);
    enqueue(q, 16);
    enqueue(q, 13);
    enqueue(q, 12);
    enqueue(q, 11);
    enqueue(q, 111);
    enqueue(q, 14);
    show(q);
    

    return 0;
}