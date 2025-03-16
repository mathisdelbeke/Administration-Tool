#include <stdio.h>
#include "hash_map.h"

HashEntry hashmap[HASHMAP_SIZE];

uint8_t hash_function(uint8_t key) {
    return key % HASHMAP_SIZE;
}

void insert_hash(uint8_t key, uint8_t value) {
    uint8_t index = hash_function(key);
    while (hashmap[index].used) {
        if (hashmap[index].key == key) {
            hashmap[index].value = value;
            return;
        }
        index = (index + 1) % HASHMAP_SIZE;
    }
    hashmap[index].key = key;
    hashmap[index].value = value;
    hashmap[index].used = 1;
}

void delete_hash(uint8_t key) {
    uint8_t index = hash_function(key);
    while (hashmap[index].used) {
        if (hashmap[index].key == key) {
            hashmap[index].used = 0;
            return;
        }
        index = (index + 1) % HASHMAP_SIZE;
    }
}

uint8_t search_hash(uint8_t key, uint8_t *value) {
    uint8_t index = hash_function(key);
    while (hashmap[index].used) {
        if (hashmap->key == key) {
            *value = hashmap[index].value;
            return 1;
        }
        index = (index + 1) % HASHMAP_SIZE;
    }
    return 0;
}

void print_hashmap() {
    printf("-------------------\n");
    for (int i = 0; i < HASHMAP_SIZE; i++)
        printf("Index %d: Key = %u, Value = %d\n", i, hashmap[i].key, hashmap[i].value);

    printf("-------------------\n");
}