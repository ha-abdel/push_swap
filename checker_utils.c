#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->number > stack->next->number)
            return 0;
        if(stack->next == NULL)
            break;
        stack = stack->next;
    }
    return 1;
}

void check_after(t_data **data, char **numbers)
{
    if (is_sorted((*data)->stack_a) && !(*data)->stack_b)
    {
        printf("OK\n");
        return;
        // exit(0);
    }
    else
    {
        printf("KO\n");
        clean_all(data, numbers);
        exit(1);
    }
}

void check_before(t_data **data, char **numbers)
{
    if (is_sorted((*data)->stack_a))
    {
        // printf("OK\n");
        // free_data(data);
        // free_numbers(numbers);
        clean_all(data, numbers);
        // return;
        exit(0);
    }
}