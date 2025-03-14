#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "todo_dll.h"

TodoDllNode *dll_head;
TodoDllNode *dll_tail;

void add_back_dll(char *checked_todo) {
    TodoDllNode *newNode = (TodoDllNode *)malloc(sizeof(TodoDllNode));
    if (newNode == NULL) {
        printf("Memory allocation todo failed\n");
        return;
    }
    newNode->todo = strdup(checked_todo);;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;

    if (dll_tail == NULL) {
        dll_head = newNode;
        dll_tail = newNode;
    } else {
        dll_tail->nextNode = newNode;
        newNode->prevNode = dll_tail;
        dll_tail = newNode;
    }
}

void add_front_dll(char *checked_todo) {
    TodoDllNode *newNode = (TodoDllNode *)malloc(sizeof(TodoDllNode));
    if (newNode == NULL) {
        printf("Memory allocation todo failed\n");
        return;
    }
    newNode->todo = strdup(checked_todo);
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if (dll_head == NULL) {
        dll_head = newNode;
        dll_tail = newNode;
    } else {
        newNode->nextNode = dll_head;
        dll_head->prevNode = newNode;
        dll_head = newNode;
    }
}

void delete_node_dll(char *todo) {
    if (dll_head == NULL) return; 
    TodoDllNode *temp = dll_head;

    while (temp != NULL && strcmp(temp->todo, todo) != 0) {
        temp = temp->nextNode;
    }
    if (temp == NULL) return;

    if (temp == dll_head) {
        dll_head = temp->nextNode;
        if (dll_head != NULL) {
            dll_head->prevNode = NULL;
        } else {
            dll_tail = NULL; 
        }
    } 
    else if (temp == dll_tail) {
        dll_tail = temp->prevNode;
        dll_tail->nextNode = NULL;
    } 
    else {
        temp->prevNode->nextNode = temp->nextNode;
        temp->nextNode->prevNode = temp->prevNode;
    }

    free(temp->todo);
    free(temp);
}

void print_dll() {
    printf("\n-------------------\n");
    TodoDllNode *temp = dll_head;
    while (temp != NULL) {
        printf("%s\n", temp->todo);
        temp = temp->nextNode;
    }
    printf("-------------------\n");
}

void free_dll() {
    TodoDllNode *temp;
    while (dll_head != NULL) {
        temp = dll_head;
        dll_head = dll_head->nextNode;
        free(temp->todo);
        free(temp);
    }
}