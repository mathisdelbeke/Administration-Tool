#ifndef MAIN_H
#define MAIN_H

typedef enum {
	AT_BACK,
	AT_FRONT
} InsertionPosition;

typedef enum {
    SLL,
    DLL
} TypeLinkedlist;

static void handle_sigint(int sig);
static void show_menu();

static void add_todo(TypeLinkedlist type_linkedlist, InsertionPosition insert_position);
static void delete_todo(TypeLinkedlist type_linkedlist);

static void add_value_buffer();
static void remove_value_buffer();
static void enqueue_queue();
static void dequeue_queue();

static void read_input_value(int8_t *value);
static void read_input_todo(char *todo);
static bool is_todo_correct(char *todo);
static bool is_only_space(char *input);

#endif