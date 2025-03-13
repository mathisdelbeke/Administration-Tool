#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include "todo.h"

TodoNode *head;

void init_sigint() {
    signal(SIGINT, handle_sigint);
}

void handle_sigint(int sig) {
    printf("\nCaught signal %d (Ctrl + c), cleaning up...\n", sig);
    free_list();
    exit(0);
}

void add_back_list(char *checked_todo) {
    char *todo = strdup(checked_todo);
    TodoNode *newNode = (TodoNode *)malloc(sizeof(TodoNode));
    if (newNode == NULL) {
        printf("Memory allocation todo failed\n");
        return;
    }
    newNode->todo = todo;
    newNode->nextNode = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    TodoNode *temp = head;
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
}

void add_front_list(char *checked_todo) {
    char *todo = strdup(checked_todo);
    TodoNode *newNode = (TodoNode *)malloc(sizeof(TodoNode));
    if (newNode == NULL) {
        printf("Memory allocation todo failed\n");
        return;
    }
    newNode->todo = todo;
    newNode->nextNode = head;
    head = newNode;
}

void delete_node(char *todo) {
    TodoNode *temp = head;
    TodoNode *prev = NULL;

    if (temp != NULL && strcmp(temp->todo, todo) == 0) {
        head = temp->nextNode;
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

void print_list() {
    TodoNode *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->todo);
        temp = temp->nextNode;
    }
}

void free_list() {
    TodoNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->nextNode;
        free(temp->todo);
        free(temp);
    }
}