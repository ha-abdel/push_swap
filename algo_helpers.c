#include "push_swap.h"

void    repeat_n_rotate(t_data **data, t_stack **stack, int n)
{
    int i = 0;
    while (i < n)
    {
        rotate_a(stack, data);
        i++;
    }
}

void    repeat_n_rev_rotate(t_data **data, t_stack **stack, int n)
{
    int i = 0;
    while (i < n)
    {
        reverse_rotate_a(stack, data);
        i++;
    }
}

void    repeat_n_rotate_b(t_data **data, t_stack **stack, int n)
{
    int i = 0;
    while (i < n)
    {
        rotate_b(stack, data);
        i++;
    }
}

void    repeat_n_rev_rotate_b(t_data **data, t_stack **stack, int n)
{
    int i = 0;
    while (i < n)
    {
        reverse_rotate_b(stack, data);
        i++;
    }
}

// void    skip_out_of_range(t_data **data, int range)
// {
//     int index;
//     int mid_index;
//     t_stack *node;

//     node = (*data)->stack_a;
    
//     // index = get_node_index_by_value((*data)->stack_a->number);
//     while (node)
//     {
//         mid_index = (count_stack((*data)->stack_a) - 1) / 2;
//         if(node->index > range)
//         {
//             node = node->next;
//         }
//         else if(node->index <= range)
//         {
//             index = get_node_index_by_value(data, &((*data)->stack_a), node->number);
//             if(index <= mid_index)
//             {
//                 rotate_a(&((*data)->stack_a), data);
//                 return;
//             }
//                 // repeat_n_rotate(data, &((*data)->stack_a), index);
//             else
//             {
//                 reverse_rotate_a(&((*data)->stack_a), data);
//                 return;
//             }
//                 // repeat_n_rev_rotate(data, &((*data)->stack_a), (*data)->total_size - index);
//             return ;
            
//         }
//     }
// }

// void skip_out_of_range(t_data **data, int range)
// {
//     int index;
//     int mid_index;
//     t_stack *node;

//     node = (*data)->stack_a;

//     while (node)
//     {
//         mid_index = (count_stack((*data)->stack_a) - 1) / 2;
//         if (node->index > range)
//         {
//             node = node->next;
//         }
//         else if (node->index <= range)
//         {
//             index = get_node_index_by_value(data, &((*data)->stack_a), node->number);
//             if (index <= mid_index)
//             {
//                 // repeat_n_rotate(data, &((*data)->stack_a), index);
//                 rotate_a(&((*data)->stack_a), data);
//             }
//             else
//             {
//                reverse_rotate_a(&((*data)->stack_a), data);
//                 // repeat_n_rev_rotate(data, &((*data)->stack_a), count_stack((*data)->stack_a) - index);
//             }
//             // return;
//         }
//     }
// }


int get_max_value(t_data **data)
{
    t_stack *node;
    int max;

    node = (*data)->stack_b;
    max = node->number;
    while (node)
    {
        if(node->number > max)
            max = node->number;
        node = node->next;
    }
    return (max);
}

