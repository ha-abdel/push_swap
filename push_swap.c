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
void    fill_stack(t_stack **stack, char **numbers)
{
    int i;

    i = 0;
    while (numbers[i])
    {
        append(stack, ft_atoi(numbers[i]));
        i++;
    }

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
    t_stack *stack_a;
    t_stack *stack_b;
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
    // int i = 0;
    // while (numbers[i])
    // {
    //     printf("%s\n", numbers[i]);
    //     i++;
    // }
    // free_all(numbers);
    
    stack_a = malloc(count * sizeof(t_stack));
    stack_b = malloc(count * sizeof(t_stack));
    if(!stack_a || !stack_b)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    fill_stack(&stack_a, numbers);
    // stack_a = NULL;
    // stack_b = NULL;
    // int i = 1;
    // while (i < ac)
    // {
    //     append(&stack_a, ft_atoi(av[i]));
    //     i++;
    // }
    //append(&stack_b, 8);
    print_stack(stack_a);

    // printf("%ld\n", LONG_MAX);
    // rotate_a(&stack_a);
    //push_a(&stack_b, &stack_a);
    // swap_a(&stack_a);
    // reverse_rotate_a(&stack_a);
    // print_stack(stack_b);
    return 0;
}