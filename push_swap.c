#include "push_swap.h"

void    initilize_all(t_data **data, int count)
{
    (*data)->stack_a = NULL;
    (*data)->stack_b = NULL;
    (*data)->total_size = 0;
    (*data)->mid = 0;
    if(count <= 10)
        (*data)->range = 5;
    else if (count <= 100)
        (*data)->range = 13;
    else
        (*data)->range = 30;
}


int main(int ac, char **av)
{
    t_data *data;
    char **numbers;
    int count;

    if (ac < 2)
        return (printf("ERROR: Invalid arguments"), 1);
    count = count_args(ac, av);
    data = malloc(sizeof(t_data));
    initilize_all(&data, count); 
    numbers = malloc((count + 1) * sizeof(char *));
    fill_numbers(ac, av, numbers, &data);
    if (!check_numbers(numbers, &data))
        return (printf("ERROR: Invalid number"), free_numbers(numbers), free(data), 1);
    fill_stack(&data->stack_a, numbers, &data->total_size, &data);
    sort_array(&data);
    // data->mid = get_mid(data, data->sorted);
    push_swap(&data, count);
    print_moves(data->moves);
    free_data(&data);
    free_numbers(numbers);
    free(data->moves);
    return 0;
}






