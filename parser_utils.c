#include "push_swap.h"


int check_args(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(!ft_isdigit(str[i]) && str[i] != ' ')
            return 0;
        i++;
    }
   return 1;
}

int count_args(int ac, char **av)
{
    int i;
    int count;

    i = 1;
    count = 0;
    while (i < ac)
    {
        count+= ft_count_words(av[i], ' ');
        i++;
    }
    return (count);
}

void fill_numbers(int ac, char **av, char **numbers)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if(ft_is_empty(av[i]))
        {
            free_all(numbers);
            printf("Error: Empty argument\n");
            exit(1);
        }
        ft_split(av[i], ' ', numbers);
        i++;
    }
}

int check_numbers(char **numbers)
{
    if(!numbers || !(*numbers))
        return 0;
    int i;

    i = 0;
    
    while (numbers[i])
    {
        if (ft_isdigit_or_sign(numbers[i])  && (ft_atoi(numbers[i], numbers) >= INT_MIN 
            && ft_atoi(numbers[i], numbers) <= __INT_MAX__)) 
                i++;
        else
            return 0;
    }
    return 1;
}

int check_dups(char **numbers, int nb)
{
    int i;

    i = 0;
    while (numbers[i])
    {
        if(nb == ft_atoi(numbers[i], numbers))
            return 1;
        i++;
    }
    return 0;
}