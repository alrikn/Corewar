/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H
    #include <stdlib.h>
    #include "struct.h"
    #include "op.h"
    #include <unistd.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <string.h>
    #include <string.h>
    #include <sys/types.h>
    #include <time.h>
    #include <sys/wait.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdint.h>

    #define PATH "/etc/passwd"
    #define MAX_PATH_LEN 64
    #define MAX_LOOP_INPUT 2048

//utils

char *num_to_str(int num);
int num_len(int nb);
char *my_revstr(char *str);
int my_cooler_putstr(char const *str);
char *my_strcat(char *dest, char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_move_to_char(const char *str, int c);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(char const *str);
int my_str_to_int(const char *str);
int my_strcmp(const char *str1, const char *str2);
char *my_strdup(char const *src);
char *my_get_time(void);
double my_str_to_float(const char *str, char **endptr);
char *my_strtok(char *str, const char *delim);
char *my_int_to_str(long int num);
int ascci_to_sum(const char *str);
char **my_str_to_word_array(char const *str);
char *last_char(const char *str, char character);
bool contains(const char *big, const char *small);
long my_put_nbr(long nb);
char **my_str_to_word_array_specific(char const *str, char spec_letter);
char *first_char(const char *str, const char c);
char **my_arraydup(const char **array);
bool my_is_num(const char *str);
void *my_memset(void *ptr, int value, size_t num);

//bytes parsing

int16_t read_short(uint8_t one, uint8_t two);
int32_t read_int(uint8_t one, uint8_t two, uint8_t three, uint8_t four);
int read_rev_int(FILE *input);
int read_short_array(char *array, int index);
int read_int_array(char *array, int index);

//file parsing

void update_bytecount(core_t *core, func_t *node, player_t *player);
void coding_byte_handle(core_t *core, func_t *node, player_t *player);
int no_coding_byte_handle(core_t *core, func_t *node);
bool is_func_with_coding_byte(func_t *node);
int parse_header(core_t *core, player_t *player);
int function_list_maker(core_t *core, player_t *player);
short read_rev_short(FILE *input);
char read_char(FILE *input);
int binary_to_array(core_t *core, player_t *player);

//array handling

int write_map(core_t *core, long pos, int size, unsigned int value);
void print_map(core_t *core);
int pc_update(int pc);
void write_short_array(char *array, unsigned int index, short value);
void write_int_array(char *array, unsigned int index, int value);

//functions

int op_live(core_t *core, finger_t *champ, func_t *func);
int op_ld(core_t *core, finger_t *champ, func_t *node);
int op_st(core_t *core, finger_t *champ, func_t *func);
int op_sti(core_t *core, finger_t *champ, func_t *func);
int op_zjmp(core_t *core, finger_t *champ, func_t *func);
int op_aff(core_t *core, finger_t *champ, func_t *node);
int op_add(core_t *core, finger_t *champ, func_t *node);
int op_sub(core_t *core, finger_t *champ, func_t *node);
int op_fork(core_t *core, finger_t *champ, func_t *func);
int op_lfork(core_t *core, finger_t *champ, func_t *func);
int op_lld(core_t *core, finger_t *champ, func_t *node);
int op_and(core_t *core, finger_t *champ, func_t *node);
int op_or(core_t *core, finger_t *champ, func_t *node);
int op_xor(core_t *core, finger_t *champ, func_t *node);
int op_ldi(core_t *core, finger_t *champ, func_t *node);
int op_lldi(core_t *core, finger_t *champ, func_t *node);

//freeing

void free_everything(core_t *core);
void kill_player(core_t *core, player_t **player);
void free_all_heads(finger_t *finger);

//initializing

void parse_players(int argc, char **argv, core_t *core, int *i);
void deal_with_flags(int argc, char **argv, core_t *core, int *i);

//game loop

void initialize_players(core_t *core);
int main_loop(core_t *core);
func_t *read_map_func(core_t *core, int *pc);

//miscellaneous

void free_list(list_t *head);
int delete_node(list_t **head, const char *label);
void add_to_list(list_t **head, const char *label, char **label_array);
int update_offset(list_t **head, int written_bytes);
int verify_everything(core_t *core);
void free_inst_list(func_t *head);
func_t *add_to_inst_list(func_t **head, const char *line);
int write_2byt(FILE *file, short value);
int write_4byt(FILE *file, int value);
int parse_line(core_t *core);
func_t *create_inst_node(const char *line);
int write_coding_byte(FILE *file, short pairs[4]);
int parse_output(core_t *core);
int print_arguments(core_t *core, func_t *current);
int write_header(core_t *core);
int my_reverse_int(int num);
short my_reverse_short(short num);
int write_label(core_t *core, func_t *current, char *label);
func_t *handle_direct(func_t *new_node, int i, char *argument);
func_t *modify_inst_node(char *line, func_t *new_node);
bool is_index_func(func_t *node);

#endif
