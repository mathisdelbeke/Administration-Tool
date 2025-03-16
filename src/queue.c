#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "queue.h"

Queue queue = {.front = 0, .back = 0, .count = 0};

bool enqueue(int8_t value) {
    if (queue.count == MAX_QUEUE) {
        printf("! QUEUE FULL !\n");
        return false;
    }
    queue.values[queue.back] = value;
    queue.back = ((queue.back + 1) % MAX_QUEUE);
    queue.count++;
    print_queue();
    return true;
}

bool dequeue(int8_t *reading) {
    if (queue.count == 0) {
        printf("! QUEUE EMPTY !\n");
        return false;
    }
    *reading = queue.values[queue.front]; 
    queue.front = ((queue.front + 1) % MAX_QUEUE);
    queue.count--;
    print_queue();
    return true;
}

void print_queue() {
    printf("-------------------\n");
    for (int i = 0; i < MAX_QUEUE; i++) {
        printf("%hhd", queue.values[i]);
        if (i == queue.back) printf("\t<= back");
        if (i == queue.front) printf("\t<= front");
        printf("\n");
    }
    printf("-------------------\n");
}
