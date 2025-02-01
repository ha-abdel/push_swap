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

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (ac < 2)
        return (printf("ERROR: Invalid arguments"), 1);
    stack_a = malloc((ac * sizeof(t_stack)) + 2);
    stack_b = malloc((ac * sizeof(t_stack)) + 2);
    if(!stack_a || !stack_b)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    int i = 1;
    while (i < ac)
    {
        append(&stack_a, ft_atoi(av[i]));
        i++;
    }
    print_stack(stack_a);
    // rotate_a(&stack_a);
    // swap_a(&stack_a);
    reverse_rotate_a(&stack_a);
    // print_stack(stack_b);
    print_stack(stack_a);
    return 0;
}