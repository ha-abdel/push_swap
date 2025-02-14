#include "push_swap.h"

void    set_node_index(t_data **data, int value, int index)
{
    t_stack *node;

    
    node = (*data)->stack_a;
    while (node)
    {
        if (node->number == value)
        {
            node->index = index;
            break;
        }
        node = node->next;
    }
}
void assign_indexes(t_data **data)
{
    int i = 0;
    while ( i  < (*data)->total_size)
    {
        set_node_index(data, (*data)->sorted[i], i);
        i++;
    }
}

void    push_swap(t_data **data, int count)
{
    if(count == 3)
    {
        sort_three(data, &(*data)->stack_a);
        return;
    }
    else if(count == 4)
    {
        sort_four(data, &(*data)->stack_a);
        return;
    }
    else if(count == 5)
    {
        sort_five(data, &(*data)->stack_a);
        return;
    }
    assign_indexes(data);

    push_all_to_stack_b(data);
    push_all_to_stack_a(data);
    // print_stack((*data)->stack_a);
    // get_target_from_b()
}

int get_mid(t_data *data, int *sorted)
{
    int mid_index;
    int mid;

    mid_index = ((data->total_size) / 2);
    mid = sorted[mid_index];
    return (mid);
}