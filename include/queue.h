#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>
#define MAX_QUEUE 5

typedef struct Queue {
    int8_t values[MAX_QUEUE];
    uint8_t front;
    uint8_t back;
    uint8_t count;
} Queue;

bool enqueue(int8_t value);
bool dequeue(int8_t *reading);
void print_queue();

#endif