#include "push_swap.h"

void free_numbers(char **numbers)
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
    if (!data ||!(*data))
    {
        return;
    }

    free_stack(&((*data)->stack_a));
    free_stack(&((*data)->stack_b));
    if((*data)->sorted)
        free((*data)->sorted);
    free(*data);
    
}

void	atoi_clean(char **numbers, t_data **data)
{
	free_numbers(numbers);
    // while ((*data)->moves)
    // {
    //     free((*data)->moves->move);
    //     (*data)->moves = (*data)->moves->next;
    // }
	free(*data);
	printf("Error: Invalid number\n");
    exit(1);
}