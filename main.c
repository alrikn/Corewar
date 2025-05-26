/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** main
*/

// 0101100
// 88
// indexes
// 1 byte, 1 byte, 2 byte


// U 65535
// NU 32767
//11111111 11111111
// 4294967295 MSB
// 65535
// 255 -> 256

#include "my.h"
#include "struct.h"
#include <stdio.h>

static int print_help(void)
{
    my_cooler_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_cooler_putstr
    (" [-a load_address] prog_name] ...\nDESCRIPTION\n");
    my_cooler_putstr
    ("-dump nbr_cycle dumps the memory after the nbr_cycle execution ");
    my_cooler_putstr
    ("(if the round isn't already over) with the following format: ");
    my_cooler_putstr("32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n");
    my_cooler_putstr
    ("-n prog_number sets the next program's number. \n");
    my_cooler_putstr
    ("By default, the first free number in the parameter order\n");
    return 0;
}

/*
** GENERAL ->
** -dump n -> we change core.dump = true;
** FOR PLAYER->
** -n num -> we change the player.id = num
** -a num -> we change player.pc = num
*/
int main(int argc, char **argv)
{
    core_t core = {0};
    int i = 1;

    if (argc < 2)
        return 84;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return print_help();
    deal_with_flags(argc, argv, &core, &i);
    parse_players(argc, argv, &core, &i);
    if (core.error_occured) {
        free_everything(&core);
        return 84;
    }
    initialize_players(&core);
    main_loop(&core);
    if (core.dump.dump_num)
        print_map(&core);
    free_everything(&core);
    return 0;
}
