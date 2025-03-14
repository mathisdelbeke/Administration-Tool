#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include "main.h"
#include "todo_sll.h"
#include "todo_dll.h"

static const int MAX_CHARS = 250;

int main() {
	signal(SIGINT, handle_sigint);
	while(true) {
		char selected_option;
		printf("1. Add ssl back\n2. Add ssl front\n3. Print ssl\n4. Delete ssl\n\n5. Add dll back\n6. Add dll front\n7. Print dll\n8. Delete dll\n\n");
		selected_option = getchar();
		while (getchar() != '\n');
		if (selected_option == '1') option_add_sll(true);
		else if (selected_option == '2') option_add_sll(false);
		else if (selected_option == '3') print_sll();
		else if (selected_option == '4') option_delete(true);
		else if (selected_option == '5') option_add_dll(true);
		else if (selected_option == '6') option_add_dll(false);
		else if (selected_option == '7') print_dll();
		else if (selected_option == '8') option_delete(false);
	}
	return 0;
}

void handle_sigint(int sig) {
	printf("\nCaught signal %d (Ctrl + C), cleaning up...\n", sig);
    
    free_sll();  
    free_dll(); 

    exit(0);
}

static void option_add_sll(bool add_back)
{
	char input[MAX_CHARS + 2];
	do read_input(input);
	while (!is_input_correct(input));

	if (add_back)
		add_back_sll(input);
	else
		add_front_sll(input);
}

static void option_add_dll(bool add_back) {
	char input[MAX_CHARS + 2];
	do read_input(input);
	while (!is_input_correct(input));

	if (add_back) 
		add_back_dll(input);
	else 
		add_front_dll(input);
}

static void option_delete(bool del_sll)
{
	char input[MAX_CHARS + 2];
	do read_input(input);
	while (!is_input_correct(input));

	if (del_sll)
		delete_node_sll(input);
	else
		delete_node_dll(input);
}

static void read_input(char *input) {
	printf("Enter a todo, max %d chars: ", MAX_CHARS);
	fgets(input, sizeof(input), stdin);
}

static bool is_input_correct(char *input) {
    bool input_correct = false;
    if (strcmp(input, "\n") != 0) {
        if (!is_only_space(input))
            input_correct = true;
    }
    return input_correct;
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