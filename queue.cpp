#include <iostream>
#include "Queue.h" 

//a function to initialize the queue
//input: q - pointer to the queue, size - size of the queue
// output: none
void initQueue(Queue* q, unsigned int size)
{
    q->size = size;
    q->arr = new int[size];
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

//a function to clean the queue
//input: q - pointer to the queue
//output: none
void cleanQueue(Queue* q)
{
    if (q->arr != nullptr)
    {
        delete[] q->arr;
        q->arr = nullptr;
    }
    q->size = 0;
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

//a function to add a new value to the queue
//input: q - pointer to the queue, newValue - value to be add
//output: none
void enqueue(Queue* q, unsigned int newValue)
{
    if (isFull(q)) 
    {
        return; 
    }
    q->arr[q->tail] = newValue;
    q->tail = (q->tail + 1) % q->size;
    q->count++;
}

//a function to remove the value from the head of the queue and return it
//  input: q - pointer to the queue
//  output: value of the removed node, or -1 if the queue is empty
int dequeue(Queue* q)
{
    if (isEmpty(q)) {
        return -1;
    }
    unsigned int value = q->arr[q->head];
    q->head = (q->head + 1) % q->size; 
    q->count--;
    return (int)value;
}

bool isEmpty(Queue* s)
{
    return s->count == 0;
}

bool isFull(Queue* s)
{
    return s->count == s->size;
}