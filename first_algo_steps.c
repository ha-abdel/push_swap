#include "push_swap.h"

void push_rev_rotate_mid(t_data **data)
{
    while ((*data)->stack_a)
    {
        if ((*data)->stack_a->number == (*data)->mid)
        {
           push_b(&((*data)->stack_b), &((*data)->stack_a), data);
           break;
        }
        reverse_rotate_a(&((*data)->stack_a), data);
    }
}

void push_all_to_stack_b(t_data **data)
{
    int i = get_node_index_by_value(data, (*data)->mid);
    if(i < (((*data)->total_size) / 2))
        push_rotate_mid(data);
    else
        push_rev_rotate_mid(data);
    push_rest(data);

}

int get_mid(t_data *data, int *sorted)
{
    int mid_index;
    int mid;

    mid_index = ((data->total_size) / 2);
    mid = sorted[mid_index];
    return (mid);
}

void push_rest(t_data **data)
{
    int i = 0;
    while ((*data)->stack_a && i < (*data)->total_size)
    {
        if(is_it_top_five(data, (*data)->stack_a->number))
            rotate_a(&((*data)->stack_a), data);
        else if ((*data)->stack_a->number < (*data)->mid)
        {
            push_b(&((*data)->stack_b), &((*data)->stack_a), data);
            rotate_b(&((*data)->stack_b), data);
        }
        else if ((*data)->stack_a->number > (*data)->mid)
        {
            push_b(&((*data)->stack_b), &((*data)->stack_a), data);
        }
        i++;
    }
}
void push_rotate_mid(t_data **data)
{
    while ((*data)->stack_a)
    {
        if ((*data)->stack_a->number == (*data)->mid)
        {
           push_b(&((*data)->stack_b), &((*data)->stack_a), data);
           break;
        }
        rotate_a(&((*data)->stack_a), data);
    }
}