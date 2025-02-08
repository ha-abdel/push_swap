#include "push_swap.h"

void free_all(char **numbers)
{
    int i = 0;

    if (!numbers || !*numbers) 
        return;
    
    while (numbers[i])
    {
        free(numbers[i]);
        numbers[i] = NULL;
        i++;
    }
    free(numbers);
}

void free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *next;

    if (!stack || !(*stack))
        return;

    current = (*stack);
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

void free_data(t_data **data)
{
    free_stack(&((*data)->stack_a));
    free_stack(&((*data)->stack_b));
    free((*data)->sorted);
    free(*data);
    
}