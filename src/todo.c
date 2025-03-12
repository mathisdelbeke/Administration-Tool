#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include "todo.h"

TodoNode *head = NULL;

bool is_only_spaces(char *input_string) {
    int len_string = strlen(input_string);
    for (int i = 0; i < len_string; i++) {
        if (input_string[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool is_input_correct(char *input_string) {
    bool input_correct = false;
    if (strcmp(input_string, "") != 0) {
        if (!is_only_spaces(input_string)) {
            input_correct = true;
        }
	}
    return input_correct;
}   

void add_todo(char *input_string) {
    if (is_input_correct(input_string)) {
        printf("%s\n", input_string);
        printf("good\n");
    }
}
