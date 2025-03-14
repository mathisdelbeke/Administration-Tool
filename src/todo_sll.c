#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "todo_sll.h"

TodoSllNode *sll_head;

void add_back_sll(char *checked_todo) {
    char *todo = strdup(checked_todo);
    TodoSllNode *newNode = (TodoSllNode *)malloc(sizeof(TodoSllNode));
    if (newNode == NULL) {
        printf("Memory allocation todo failed\n");
        return;
    }
    newNode->todo = todo;
    newNode->nextNode = NULL;

    if (sll_head == NULL) {
        sll_head = newNode;
        return;
    }

    TodoSllNode *temp = sll_head;
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
}

void add_front_sll(char *checked_todo) {
    char *todo = strdup(checked_todo);
    TodoSllNode *newNode = (TodoSllNode *)malloc(sizeof(TodoSllNode));
    if (newNode == NULL) {
        printf("Memory allocation todo failed\n");
        return;
    }
    newNode->todo = todo;
    newNode->nextNode = sll_head;
    sll_head = newNode;
}

void delete_node_sll(char *todo) {
    TodoSllNode *temp = sll_head;
    TodoSllNode *prev = NULL;

    if (temp != NULL && strcmp(temp->todo, todo) == 0) {
        sll_head = temp->nextNode;
        free(temp->todo);
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->todo, todo) != 0) {
        prev = temp;
        temp = temp->nextNode;
    }
    if (temp == NULL) return;

    prev->nextNode = temp->nextNode;
    free(temp->todo);
    free(temp);    
}

void print_sll() {
    printf("\n-------------------\n");
    TodoSllNode *temp = sll_head;
    while (temp != NULL) {
        printf("%s\n", temp->todo);
        temp = temp->nextNode;
    }
    printf("-------------------\n");
}

void free_sll() {
    TodoSllNode *temp;
    while (sll_head != NULL) {
        temp = sll_head;
        sll_head = sll_head->nextNode;
        free(temp->todo);
        free(temp);
    }
}