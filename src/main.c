#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "todo.h"

static const int MAX_CHARS = 250;

static bool is_only_space(char *input) {
    bool only_spaces = true;
    int input_len = strlen(input);
    for (int i = 0; i < input_len; i++) {
        if (input[i] != ' ' && input[i] != '\n') {
            only_spaces = false;
            break;
        }
    }
    return only_spaces;
}

static bool is_input_correct(char *input) {
    bool input_correct = false;
    if (strcmp(input, "\n") != 0) {
        if (!is_only_space(input)) {
            input_correct = true;
        }
    }
    return input_correct;
}

char * read_input(char *todo) {
	fgets(todo, sizeof(todo), stdin);

	if (todo[strcspn(todo, "\n")] != '\n') {
		printf("Error: Input exceeds %d characters!\n", MAX_CHARS);
		int ch; 
		while ((ch = getchar()) != '\n' && ch != EOF) continue;
	}
	return todo;
}

void option_add_back() {
	printf("Enter a todo, max %d chars: ", MAX_CHARS);
	char todo[MAX_CHARS + 2];
	read_input(todo);
	if (is_input_correct(todo)) add_back_list(todo);
}

void option_add_front() {
	printf("Enter a todo, max %d chars: ", MAX_CHARS);
	char todo[MAX_CHARS + 2];
	read_input(todo);
	if (is_input_correct(todo)) add_front_list(todo);
}

void option_print() {
	print_list();
}	

int main() {
	init_sigint();
	while(true) {
		char selected_option;
		printf("1. Add to back   2. Add to front   3. print: ");
		selected_option = getchar();
		while (getchar() != '\n');
		if (selected_option == '1') option_add_back();
		else if (selected_option == '2') option_add_front();
		else if (selected_option == '3') option_print();
	}
	return 0;
}