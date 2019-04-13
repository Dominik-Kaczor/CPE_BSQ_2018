/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** clear of all character
*/

int my_getnbr(char const *str)
{
    long i = 0;
    long b = 0;
    long negative = 1;

    while (str[i] > '9' || str[i] < '0'){
        if (str[i] == '-')
            negative = negative * -1;
        i = i + 1;
    }
    while (str[i] <= '9' && str[i] >= '0'){
        b = b + (str[i] - 48);
        b = b * 10;
        if (b > 2147483647 || b < -2147483648)
            b = 0;
        i = i + 1;
    }
    b = b / 10;
    return (b * negative);
}
