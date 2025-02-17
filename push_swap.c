#include "push_swap.h"

void clean_all(t_data **data, char **numbers)
{
    t_moves *next;
    while ((*data)->moves)
    {
        next = (*data)->moves->next;
        free((*data)->moves);
        (*data)->moves = next;
    }
    free_data(data);
    free_numbers(numbers);
}

void    initilize_all(t_data **data, int count, char **numbers)
{
    (*data)->stack_a = NULL;
    (*data)->stack_b = NULL;
    (*data)->sorted = NULL;
    (*data)->moves = NULL;
    (*data)->total_size = 0;
    if(numbers)
        *numbers = NULL;
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

    count = count_args(ac, av);
    data = malloc(sizeof(t_data));
    numbers = malloc((count + 1) * sizeof(char *));
    initilize_all(&data, count, numbers); 
    fill_numbers(ac, av, numbers, &data);
    if (!check_numbers(numbers, &data))
        return (printf("ERROR: Invalid number"), free_numbers(numbers), free(data), 1);
    fill_stack(&data->stack_a, numbers, &data->total_size, &data);
    sort_array(&data);
    push_swap(&data, count, numbers);
    print_moves(data->moves);
    // print_stack(data->stack_a);
    clean_all(&data, numbers);
    // free(data->moves);
    // free_data(&data);
    // free_numbers(numbers);
    return 0;
}



//-9615 18557 9566 11508 752


