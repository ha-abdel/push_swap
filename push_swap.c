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
void    fill_stack(t_stack **stack, char **numbers, int *size)
{
    int i;

    i = 0;
    (*size) = 0;
    while (numbers[i])
    {
        if(check_duplicte(*stack, ft_atoi(numbers[i], numbers)))
        {
            free_all(numbers);
            free_stack(stack);
            printf("Error: Duplicates\n");
            exit(1);
        }
        append(stack, ft_atoi(numbers[i], numbers));
        i++;
        (*size)++;
    }

}

int get_mid(t_data *data, int *sorted)
{
    int mid_index;
    int mid;

    if(data->total_size % 2 == 0)
    {
        mid_index = (data->total_size / 2) - 1;
    }
    else
        mid_index = data->total_size / 2;
    mid = sorted[mid_index];
    return (mid);
}

int main(int ac, char **av)
{
    // t_stack *stack_a;
    // t_stack *stack_b;
    t_data *data;
    char **numbers;
    int count;
    // int *sorted;


    if (ac < 2)
        return (printf("ERROR: Invalid arguments"), 1);
    data = malloc(sizeof(t_data));
    count = 0;
    data->stack_a = NULL;
    data->stack_b = NULL;
    data->total_size = 0;
    data->sorted = NULL;

    
    count = count_args(ac, av);
    numbers = malloc((count + 1) * sizeof(char *));
    fill_numbers(ac, av, numbers);
    if (!check_numbers(numbers))
        return (printf("ERROR: Invalid number"), free_all(numbers), 1);
    

    fill_stack(&data->stack_a, numbers, &data->total_size);
    sort_array(&data);
    printf("%d", get_mid(data, data->sorted));
    // print_stack(data->stack_a);
    // push_swap(&stack_a, &stack_b);
    // print_stack(data->stack_a);
    // free_stack(&(data->stack_a));
    // free_stack(&(data->stack_b));
    free_data(&data);
    free_all(numbers);
    return 0;
}
void sort_array(t_data **data)
{
    // int *arr;
    int i;

    (*data)->sorted = malloc(sizeof(int) * ((*data)->total_size));
    if(!(*data)->sorted)
    {
        printf("Error: malloc failed\n");
        exit(1);
    }
    i = 0;
    while ((*data)->stack_a)
    {
        (*data)->sorted[i] = (*data)->stack_a->number;
        (*data)->stack_a = (*data)->stack_a->next;
        i++;
    }
    sort_helper(&((*data)->sorted), i);
    // return arr;

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

// t_stack *push_swap(t_stack **stack_a, t_stack **stack_b)
// {
    
// }