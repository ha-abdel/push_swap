#include "push_swap.h"

// void push_swap(int *stack_a, int *stack_b)
// {
//     // Your implementation goes here
// }

void    print_stack(t_stack *stack_a)
{
    while (stack_a)
    {
        printf("%d\n", stack_a->number);
        stack_a = stack_a->next;
    }
    printf("==================================\n");
    // while (stack_b)
    // {
    //     printf("%d ", stack_b->number);
    //     stack_b = stack_b->next;
    // }
    // printf("\n");
    return;
}
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
        if (ft_isdigit1(numbers[i]) && (ft_atoi(numbers[i]) >= INT_MIN && ft_atoi(numbers[i]) <= __INT_MAX__))
                i++;
        else
            return 0;
    }
    return 1;
}

void free_all(char **numbers)
{
    int i = 0;

    if (!numbers) 
        return;
    
    while (numbers[i])
    {
        free(numbers[i]);
        numbers[i] = NULL;
        i++;
    }
    free(numbers);
}
int main(int ac, char **av)
{
    // t_stack *stack_a;
    // t_stack *stack_b;
    char **numbers;
    int count;

    count = 0;
    if (ac < 3)
        return (printf("ERROR: Invalid arguments"), 1);
    count = count_args(ac, av);
    numbers = malloc((count + 1) * sizeof(char *));
    fill_numbers(ac, av, numbers);
    if (!check_numbers(numbers))
        return (printf("ERROR: Invalid number"), free_all(numbers), 1);
    int i = 0;
    while (numbers[i])
    {
        printf("%s\n", numbers[i]);
        i++;
    }
    // free_all(numbers);
    
    // stack_a = malloc((ac * sizeof(t_stack)) + 2);
    // stack_b = malloc((ac * sizeof(t_stack)) + 2);
    // if(!stack_a || !stack_b)
    //     return (0);
    // stack_a = NULL;
    // stack_b = NULL;
    // int i = 1;
    // while (i < ac)
    // {
    //     append(&stack_a, ft_atoi(av[i]));
    //     i++;
    // }
    //append(&stack_b, 8);
    //print_stack(stack_a);
    // rotate_a(&stack_a);
    //push_a(&stack_b, &stack_a);
    // swap_a(&stack_a);
    // reverse_rotate_a(&stack_a);
    // print_stack(stack_b);
    return 0;
}