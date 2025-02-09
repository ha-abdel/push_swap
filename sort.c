#include "push_swap.h"

void sort_array(t_data **data)
{
    t_stack *stack;
    int i;

    (*data)->sorted = malloc(sizeof(int) * ((*data)->total_size));
    stack = (*data)->stack_a;
    if(!(*data)->sorted)
    {
        printf("Error: malloc failed\n");
        exit(1);
    }
    i = 0;
    while (stack)
    {
        (*data)->sorted[i] = stack->number;
        stack = stack->next;
        i++;
    }
    sort_helper(&((*data)->sorted), i);
    i = 0;
    while (i < 5)
    {
        (*data)->top_five[i] = (*data)->sorted[(*data)->total_size - i - 1];
        i++;
    }
}

void    sort_helper(int **arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = (i + 1);
        while (j < size)
        {
            if ((*arr)[i] > (*arr)[j])
            {
                tmp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
