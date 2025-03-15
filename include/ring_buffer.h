#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#define BUFFER_SIZE 5

typedef struct RingBuffer {
    int8_t values[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
}RingBuffer;

bool buffer_write(int8_t value);
bool buffer_read(int8_t *reading);
void print_buffer();
bool is_buffer_full();
bool is_buffer_empty();

#endif