#include "push_swap.h"

int is_it_top_five(t_data **data, int value)
{
    int i = 0;
    while (i < 5)
    {
        if(value == (*data)->top_five[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int get_node_index_by_value(t_data **data, int value)
{
    int i;
    t_stack *node;

    node = (*data)->stack_a;
    i = 0;
    while (node)
    {
        if(node->number == value)
            return i;
        i++;
        node = node->next;
    }
    return (i);

}


