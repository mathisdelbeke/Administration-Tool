#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "ring_buffer.h"

RingBuffer rb = { .head = 0, .tail = 0};

bool buffer_write(int8_t value) {
    if (is_buffer_full()) {
        printf("! BUFFER FULL !\n");
        return false;
    }
    rb.values[rb.head] = value;
    rb.head = (rb.head + 1) % BUFFER_SIZE;
    print_buffer();
    return true;
}

bool buffer_read(int8_t *reading) {
    if (is_buffer_empty()) {
        printf("! BUFFER EMPTY !\n");
        return false;
    }
    *reading = rb.values[rb.tail];
    rb.tail = (rb.tail + 1) % BUFFER_SIZE;
    print_buffer();
    return true;
}

void print_buffer() {
    printf("-------------------\n");
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        printf("%hhd", rb.values[i]);
        if (i == rb.head) printf("\t<= head");
        if (i == rb.tail) printf("\t<= tail");
        printf("\n");
    }
    printf("-------------------\n");
}

bool is_buffer_full() {
    return ((rb.head + 1) % BUFFER_SIZE) == rb.tail;
}

bool is_buffer_empty() {
    return rb.head == rb.tail; 
}