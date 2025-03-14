#ifndef MAIN_H
#define MAIN_H

void handle_sigint(int sig);

static void option_add_sll(bool add_back);
static void option_add_dll(bool add_back);
static void option_delete(bool del_sll);

static void read_input(char *input);
static bool is_input_correct(char *input);
static bool is_only_space(char *input);

#endif