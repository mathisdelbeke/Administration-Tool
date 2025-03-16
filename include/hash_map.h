#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdint.h>
#define HASHMAP_SIZE 5

typedef struct HashEntry {
    uint8_t key;
    int8_t value;
    uint8_t used;
} HashEntry;

uint8_t hash_function(uint8_t key);
void insert_hash(uint8_t key, uint8_t value);
void delete_hash(uint8_t key);
uint8_t search_hash(uint8_t key, uint8_t *value);
void print_hashmap();

#endif