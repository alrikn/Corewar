/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** print_map
*/

#include "my.h"
#include "op.h"
#include "struct.h"
#include <stdio.h>


char to_hex_char(int value)
{
    if (value < 10)
        return '0' + value;
    return 'A' + (value - 10);
}

void byte_to_hex(unsigned char byte, char *dest)
{
    int high = byte / 16;
    int low = byte % 16;

    dest[0] = to_hex_char(high);
    dest[1] = to_hex_char(low);
}

/*
** every 2 chars is 1 byte (hexadecimal)
** we need to write 32 bytes on each line before skipping a line
** (so 64 chars) the char is a byte, and each byte is 2 hex digits
*/
void print_map(core_t *core)
{
    const unsigned char *array = (const unsigned char *)core->array;
    int array_strlen = MEM_SIZE;
    char line[65];
    int i = 0;
    int pos = 0;

    while (i < array_strlen) {
        for (pos = 0; pos < 32 && i < array_strlen; pos++) {
            byte_to_hex(array[i], &line[pos * 2]);
            i++;
        }
        line[64] = '\0';
        my_cooler_putstr(line);
        my_cooler_putstr("\n");
    }
}
