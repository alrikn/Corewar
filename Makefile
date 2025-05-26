##
## EPITECH PROJECT, 2024
## My_printf
## File description:
## Makefile
##

LIB_NAME = libmy.a
NAME = corewar
TEST_BIN = unit_tests

SRC = ./main.c \
	./src/big_endian/read_char.c \
	./src/big_endian/read_int_array.c \
	./src/big_endian/read_int.c \
	./src/big_endian/read_reverse_int.c \
	./src/big_endian/read_reverse_short.c \
	./src/big_endian/read_short.c \
	./src/big_endian/reverse_int.c \
	./src/big_endian/read_short_array.c \
	./src/big_endian/reverse_short.c \
	./src/big_endian/write_specific.c \
	./src/free_everything/free_everything.c \
	./src/func_list/func_list.c \
	./src/function_operation/add.c \
	./src/function_operation/aff.c \
	./src/function_operation/and.c \
	./src/function_operation/fork.c \
	./src/function_operation/ld.c \
	./src/function_operation/ldi.c \
	./src/function_operation/lfork.c \
	./src/function_operation/live.c \
	./src/function_operation/lld.c \
	./src/function_operation/lldi.c \
	./src/function_operation/or.c \
	./src/function_operation/st.c \
	./src/function_operation/sti.c \
	./src/function_operation/sub.c \
	./src/function_operation/xor.c \
	./src/function_operation/zjmp.c \
	./src/game_loop/main_loop.c \
	./src/game_loop/pc_update.c \
	./src/given_struct/op.c \
	./src/map_handle/print_map.c \
	./src/map_handle/read_func.c \
	./src/map_handle/write_map.c \
	./src/parse_binary/binary_to_array.c \
	./src/parse_binary/coding_byte_parser.c \
	./src/parse_binary/parse_binary.c \
	./src/parse_binary/parse_header.c \
	./src/player_handle/initialize_players/initialize.c \
	./src/player_handle/initialize_players/flag_hunting.c \
	./src/player_handle/kill_player.c \
	./src/utils/first_char.c \
	./src/utils/contain.c \
	./src/utils/my_cooler_putstr.c \
	./src/utils/my_put_nbr.c \
	./src/utils/str_to_word_array.c \
	./src/utils/last_char.c \
	./src/utils/my_num_to_str.c \
	./src/utils/my_numlen.c \
	./src/utils/my_revstr.c \
	./src/utils/my_strcat.c \
	./src/utils/my_strcpy.c \
	./src/utils/my_str_to_int.c \
	./src/utils/my_strlen.c \
	./src/utils/my_strncpy.c \
	./src/utils/my_str_to_float.c \
	./src/utils/my_strncmp.c \
	./src/utils/my_move_to_char.c \
	./src/utils/my_strtok.c \
	./src/utils/my_int_to_str.c \
	./src/utils/ascii_to_sum.c \
	./src/utils/my_strcmp.c \
	./src/utils/my_strdup.c \
	./src/utils/free_array.c \
	./src/utils/my_arraydup.c \
	./src/utils/my_is_num.c \
	./src/utils/my_memset.c \

TEST_SRC = $(SRC) \
	./tests/test_my_printf.c

CC = gcc
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -g
INCLUDE_PATH = ./include/
LDFLAGS = -I$(INCLUDE_PATH)
TEST_LDFLAGS = $(LDFLAGS) --coverage -lcriterion
DESTINATION = -I$(INCLUDE_PATH) -L. -lmy



all: $(LIB_NAME) $(NAME)

$(NAME): $(LIB_NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(DESTINATION)

$(LIB_NAME): $(OBJ)
	ar -rc $(LIB_NAME) $(OBJ)

$(TEST_BIN):
	$(CC) $(CFLAGS) -o $(TEST_BIN) $(TEST_SRC) $(TEST_LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

test:
	cp $(NAME) tests_for_me/

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(LIB_NAME)
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re: fclean $(LIB_NAME) $(NAME)

compile:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS)

coverage: tests_run
	gcovr -r .
	gcovr -r . --branches

.PHONY: all re compile coverage fclean clean test
