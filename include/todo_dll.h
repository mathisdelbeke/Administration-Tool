#ifndef TODO_DLL_H
#define TODO_DLL_H

typedef struct TodoDllNode {
    char *todo;
    struct TodoDllNode *nextNode;
    struct TodoDllNode *prevNode;
} TodoDllNode;

void add_back_dll(char *checked_todo);
void add_front_dll(char *checked_todo);
void delete_node_dll(char *todo);
void print_dll();
void free_dll();

#endif