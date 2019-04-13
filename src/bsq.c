/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** find the square
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int compar_min(int a, int b, int c);
int *scan_max(int **nvmaps, int len, int cols, int *max);

void display_maps(int cols, int len, int **nvmaps)
{
    for (int c = 1; c <= cols; c++) {
        for (int k = 1; k <= len; k++) {
            if (nvmaps[k][c] == -1)
                my_putstr("\e[35mx\e[m");
            else if (nvmaps[k][c] == 0) {
                my_putchar('o');
            } else {
                my_putchar('.');
            }
        }
        my_putchar('\n');
    }
    for (int d = 0; d < len; d++)
        free(nvmaps[d]);
}

void biggest(int **nvmaps, int len, int cols)
{
    int *max = malloc(3 * sizeof(int));

    max = scan_max(nvmaps, len, cols, max);
    int mA = max[1];
    int mB = max[2];
    for (int g = 0; g < max[0]; g++) {
        for (int d = 0; d < max[0]; d++)
            nvmaps[mA - d][mB - g] = -1;
    }
    display_maps(cols, len, nvmaps);
    free(max);
}

void minesweeper(int i, int len, int cols, char *buffer)
{
    int **nvmaps = malloc(len * sizeof(int *));

    for (int b = 0; b < len; b++)
        nvmaps[b] = malloc(sizeof(int) * (cols + 1));
    for (int y = 0; y < (len); y++)
        nvmaps[y][0] = 0;
    for (int c = 1; c <= (cols); c++) {
        nvmaps[0][c] = 0;
        for (int k = 1; k <= (len); k++) {
            if (buffer[i] == 'o') {
                nvmaps[k][c] = 0;
            } else if (buffer[i] != '\n') {
                int m = compar_min(nvmaps[k - 1][c], nvmaps[k][c - 1],
                                   nvmaps[k - 1][c - 1]);
                nvmaps[k][c] = m;
            }
            i++;
        }
    }
    biggest(nvmaps, (len - 1), cols);
}

void maps_bsq(int fd, char *buffer, int size)
{
    int i = 0;
    int len = 0;
    int cols = 0;

    read(fd, buffer, size);
    while (buffer[i] != '\n')
        i++;
    char *str =	malloc((i + 1) * sizeof(char));
    for (int p = 0; p <= i; p++)
        str[p] = buffer[p];
    str[i] = '\0';
    cols = my_getnbr(str);
    i = i + 1;
    for (int d = i; buffer[d] != '\n'; d++)
        len++;
    len = len + 1;
    minesweeper(i, len, cols, buffer);
    free(str);
}

int main(int ac, char **av)
{
    struct stat s;
    char *buffer;

    stat(av[1], &s);
    buffer = malloc(sizeof(char) * s.st_size);
    if (ac == 2) {
        int fd = open(av[1], O_RDONLY);
        if (fd == -1 || s.st_size == 0) {
            write(2, "error\n", 6);
            return (84);
        }
        maps_bsq(fd, buffer, s.st_size);
    } else {
        write(2, "error\n", 6);
        return (84);
    }
    free(buffer);
    return (0);
}
