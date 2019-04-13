/*
** EPITECH PROJECT, 2018
** tools_bsq
** File description:
** tools_bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int compar_min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return (a + 1);
    if (b <= a && b <= c)
        return (b + 1);
    if (c <= a && c <= b)
        return (c + 1);
    return (0);
}

int *scan_max(int **nvmaps, int len, int cols, int *max)
{
    int max_len = 0;
    int max_cols = 0;
    int max_square = 0;

    for (int c = 0; c <= cols; c++) {
        for (int k = 0; k <= len; k++) {
            if (nvmaps[k][c] > max_square) {
                max_square = nvmaps[k][c];
                max_len = k;
                max_cols = c;
            }
        }
    }
    max[0] = max_square;
    max[1] = max_len;
    max[2] = max_cols;
    return (max);
}
