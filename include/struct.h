/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** just a place to hold structs so that my.h is'nt bloated
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include "op.h"
    #include <stdbool.h>
    #include <stdio.h>
    #define NBR_OF_PLAYERS 512
    #define MAX_FUNC 16

/*
 ** label is malloced so watch out
 ** if offset bigger than short than loop
 ** label_initialized is false if index is called before declaring label
 ** label_initialized is true if index is called after declaring label
*/
typedef struct label_list {
    char *label;
    bool label_initialized;
    int offset;
    struct label_list *next;
} list_t;

typedef struct list_of_labels {
    char **label_array;
    list_t *head;
} label_t;

typedef struct files {
    char *input_name;
    FILE *input;
    FILE *output;
} file_t;

typedef enum function_list {
    LIVE = 1,
    LD,
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
    AFF,
} func_list_t;

typedef struct {
    const char *name;
    func_list_t func;
} func_map_t;

typedef enum argument_size {
    S_NONE,
    S_REGISTER = 1,
    S_INDIRECT = 2,
    S_DIRECT = 4,
    S_INDEX_POS = 2,
} type_size_t;

/*
 ** index: format with( %: label name) or (% index_pos)
 ** direct: format with( % number)
 ** register: format (r number)
 ** indirect: format (number)
 ** example: sti r1, %:hi, %1
*/
typedef enum argument_type {
    NONE,
    REGISTER = 1,
    DIRECT = 2,
    INDIRECT = 4,
    INDEX_POS = 8,
} type_t;

/*
 ** label name is not null only if index_label is called
 ** if type is register, then the value is the register index
*/
typedef struct arguments {
    type_t type;
    union value {
        short short_val;
        int int_val;
        char byte;
    } value_type;
} args_t;

/*
 ** num_bytes: how many bytes we are going to need to write
 (+1 for initializer byte)
 ** func_num directly translates to the byte we read
*/
typedef struct function {
    short num_bytes;
    args_t args[MAX_ARGS_NUMBER];
    bool calls_index;
    bool coding_byte;
    char func_num;
    unsigned char orig_coding_byte; //original coding byte for future reference
    struct function *next;
    struct function *prev;
} func_t;

typedef struct champ_heads {
    func_t *func;
    int wait_cycle;
    int register_buf[REG_NUMBER];
    bool dead;
    int pc;
    bool carry;
    struct champ_heads *next;
} finger_t;

typedef struct player {
    int register_buf[REG_NUMBER];
    long current_byte_pos;
    unsigned int id; //this is for -n flag
    header_t header;
    FILE *input;
    long PC; // this is the programcounter(where player head is on the array)
    long cycle_since_live; // how many cicles since we have called live
    long num_of_live; //how may time have we called the live instruction
    bool dead;
    bool special_pc; // this is toggle to true if the user did -a
    finger_t *fing_head; // when all the heads are null then the player is dead
    struct player *next;
} player_t;

typedef struct dump {
    bool dump;
    int dump_num;
} dump_flag_t;

typedef struct core {
    file_t file;
    label_t labels;
    int num_of_players;
    bool error_occured;
    char array[MEM_SIZE];
    player_t *player_head;
    dump_flag_t dump;
} core_t;

extern const func_map_t func_map_index[];

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    type_t type[MAX_ARGS_NUMBER];
    char func_num;
    int nbr_cycles;
    char *comment;
} op_t;

/*
** op_tab
*/
extern const op_t op_tab[];

typedef int (*op_func_t)(core_t *, finger_t *, func_t *);

#endif
