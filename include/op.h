/*
** EPITECH PROJECT, 2024
** Robot Factory
** File description:
** i don't want to erase te other one, but code compliance is complaining
** cus old file header not up to current standard
*/
/*
** op.h for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

#ifndef _OP_H_
    #define _OP_H_
    #define MEM_SIZE (6 * 1024)
    /*how big the array is
    its printed on lines of 64*/
    #define IDX_MOD 512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"
    /*
    ** regs
    */
    /* r1 <--> rx */
    #define REG_NUMBER 16
     /* register */
    #define T_REG 1
    /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_DIR 2
    /* indirect always relative
    (ld 1,r1 put what's in the address (1+pc) into r1 (4 bytes )) */
    #define T_IND 4
    /* LABEL */
    #define T_LAB 8
    /*
    ** size (in bytes)
    */
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE
    /*
    ** header
    */
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3
    /*
    ** live
    */
    #define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40


typedef char args_type_t;


typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

#endif
