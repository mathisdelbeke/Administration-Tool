#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include "main.h"
#include "todo_sll.h"
#include "todo_dll.h"
#include "ring_buffer.h"
#include "queue.h"
#include "hash_map.h"

static const int MAX_CHARS = 250;

int main() {
	signal(SIGINT, handle_sigint);
	while(true) {
		show_menu();
	}
	return 0;
}

static void handle_sigint(int sig) {
	printf("\nCaught signal %d (Ctrl + C), cleaning up...\n", sig);
    free_sll();  
    free_dll(); 
	exit(0);
}

static void show_menu() {
	printf("1. Add ssl back\n2. Add ssl front\n3. Print ssl\n4. Delete ssl\n5. Add dll back\n6. Add dll front\n7. Print dll\n8. Delete dll\n+. Add to buffer\n-. Remove to buffer\n:. Print buffer\ne. Enqueue\nd. Dequeue\n;. Print queue\n0. Add hash\n9. Del hash\n/. Print hashmap\n\n");
	char selected_option = getchar();
	if (selected_option == '\n') return;
	while (getchar() != '\n');
	if      (selected_option == '1') add_todo(SLL, AT_BACK);
	else if (selected_option == '2') add_todo(SLL, AT_FRONT);
	else if (selected_option == '3') print_sll();
	else if (selected_option == '4') delete_todo(SLL);
	else if (selected_option == '5') add_todo(DLL, AT_BACK);
	else if (selected_option == '6') add_todo(DLL, AT_FRONT);
	else if (selected_option == '7') print_dll();
	else if (selected_option == '8') delete_todo(DLL);
	else if (selected_option == '+') add_value_buffer();
	else if (selected_option == '-') remove_value_buffer();
	else if (selected_option == ':') print_buffer();
	else if (selected_option == 'e') enqueue_queue();
	else if (selected_option == 'd') dequeue_queue();
	else if (selected_option == ';') print_queue();
	else if (selected_option == '0') add_hash_entry();
	else if (selected_option == '9') del_hash_entry();
	else if (selected_option == '/') print_hashmap();
}     

static void add_todo(TypeLinkedlist type_linkedlist, InsertionPosition insert_position) {
	char todo[MAX_CHARS + 2];
	read_input_todo(todo);
	if (type_linkedlist == SLL) {
		if (insert_position == AT_BACK)
			add_back_sll(todo);
		else if (insert_position == AT_FRONT)
			add_front_sll(todo);
	} 
	else if (type_linkedlist == DLL) {
		if (insert_position == AT_BACK)
			add_back_dll(todo);
		else if (insert_position == AT_FRONT)
			add_front_dll(todo);
	}
}

static void delete_todo(TypeLinkedlist type_linkedlist) {
	char todo[MAX_CHARS + 2];
	read_input_todo(todo);
	if (type_linkedlist == SLL)
		delete_node_sll(todo);
	else if (type_linkedlist == DLL)
		delete_node_dll(todo);
}

static void add_value_buffer() {
	int8_t value;
	read_input_value(&value);
	buffer_write(value);
}

static void remove_value_buffer() {
	int8_t reading;
	bool read_correct = buffer_read(&reading); 
	if (read_correct)
		printf("Sensor value fetched: %d\n", reading);
	else
		printf("Nothing read\n");
}

static void enqueue_queue() {
	int8_t value;
	read_input_value(&value);
	enqueue(value);
}

static void dequeue_queue() {
	int8_t reading;
	bool read_correct = dequeue(&reading); 
	if (read_correct)
		printf("Sensor value fetched: %d\n", reading);
	else
		printf("Nothing dequeued\n");
}

static void add_hash_entry() {
	int8_t key;
	int8_t value;
	read_input_value(&value);
	read_input_value(&key);
	insert_hash(key, value);
}

static void del_hash_entry() {
	int8_t key;
	read_input_value(&key);
	delete_hash(key);
}

static void read_input_value(int8_t *value) {
	bool read_correct = 0;
	do {
		printf("Enter a senosr reading (-128 to 127): ");
		read_correct = scanf("%hhd", value);
		while (getchar() != '\n');
	} while (read_correct != 1 || (*value < -128 || *value > 127));
}

static void read_input_todo(char *todo) {
	do {
		printf("Enter a todo, max %d chars: ", MAX_CHARS);
		fgets(todo, sizeof(todo), stdin);
	} while(!is_todo_correct(todo));
}

static bool is_todo_correct(char *todo) {
    bool is_correct = false;
    if (strcmp(todo, "\n") != 0) {
        if (!is_only_space(todo))
		is_correct = true;
    }
    return is_correct;
}

static bool is_only_space(char *input) {
    bool only_spaces = true;
    int input_len = strlen(input);
    for (int i = 0; i < input_len; i++) {
        if (input[i] != ' ' && input[i] != '\n' && input[i] != '\t') {
            only_spaces = false;
            break;
        }
    }
    return only_spaces;
}