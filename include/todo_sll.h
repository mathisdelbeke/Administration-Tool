#ifndef TODO_SLL_H
#define TODO_SLL_H

typedef struct TodoSllNode {
    char *todo;
    struct TodoSllNode *nextNode;
} TodoSllNode;

void add_back_sll(char *checked_todo);
void add_front_sll(char *checked_todo);
void delete_node_sll(char *todo);
void print_sll();
void free_sll();

#endif