#ifndef TODO_H
#define TODO_H

typedef struct TodoNode {
    char *todo;
    struct TodoNode *nextNode;
} TodoNode;

void init_sigint();
void handle_sigint(int sig);

void add_back_list(char *checked_todo);
void add_front_list(char *checked_todo);
void print_list();
void free_list();

#endif