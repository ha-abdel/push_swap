#include "push_swap.h"







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
    data->min = 0;
    // data->sorted = NULL;

    
    count = count_args(ac, av);
    numbers = malloc((count + 1) * sizeof(char *));
    fill_numbers(ac, av, numbers, &data);
    if (!check_numbers(numbers))
        return (printf("ERROR: Invalid number"), free_all(numbers), 1);
    

    fill_stack(&data->stack_a, numbers, &data->total_size, &data);
    sort_array(&data);
    data->mid = get_mid(data, data->sorted);
    data->min = data->sorted[0];
    push_all_to_stack_b(&data);

    print_stack(data->stack_b);
    print_stack(data->stack_a);

    // free_data(&data);
    // free_all(numbers);
    return 0;
}



// t_stack *push_swap(t_data **data)
// {
//     push_all_to_stack_b(data);
//     // get_target_from_b()
// }


// int get_target_from_b(t_stack current ,t_data *data)
// {
//     int target;
//     t_stack *src;

//     src = data->stack_b;
//     while (src)
//     {

//     }
// }