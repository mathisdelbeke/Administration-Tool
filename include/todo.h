#ifndef TODO_H
#define TODO_H

typedef struct {
    char *task;
    struct TodoNode *next;
} TodoNode;

void add_todo(char *string);

#endif