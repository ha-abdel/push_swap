#include "push_swap.h"

// void push_rev_rotate_mid(t_data **data)
// {
//     while ((*data)->stack_a)
//     {
//         if ((*data)->stack_a->number == (*data)->mid)
//         {
//            push_b(&((*data)->stack_b), &((*data)->stack_a), data);
//            break ;
//         }
//         reverse_rotate_a(&((*data)->stack_a), data);
//     }
// }



void	push_all_to_stack_b(t_data **data)
{
	int	i;

	i = 0;
	while ((*data)->stack_a)
	{
		if ((*data)->stack_a->index <= i)
		{
			push_b(&((*data)->stack_b), &((*data)->stack_a), data);
			rotate_b(&((*data)->stack_b), data);
			i++;
		}
		else if ((*data)->stack_a->index <= (i + (*data)->range))
		{
			push_b(&((*data)->stack_b), &((*data)->stack_a), data);
			i++;
		}
		else if ((*data)->stack_a->index > (i + (*data)->range))
			skip_out_of_range(data, i + (*data)->range);
	}
}

// void push_all_to_stack_b(t_data **data)
// {
//     int i = 0;
//     int size;
//     int range = (*data)->range;

//     while ((*data)->stack_a)
//     {
//         size = count_stack((*data)->stack_a);
//         if ((*data)->stack_a->index <= i)
//         {
//             push_b(&((*data)->stack_b), &((*data)->stack_a), data);
//             rotate_b(&((*data)->stack_b), data);
//             i++;
//         }
//         else if ((*data)->stack_a->index <= (i + range))
//         {
//             push_b(&((*data)->stack_b), &((*data)->stack_a), data);
//             i++;
//         }
//         else
//         {
//             if (i < (size / 2) - 1)
//                 rotate_a(&((*data)->stack_a), data);
//             else
//                 reverse_rotate_a(&((*data)->stack_a), data);
//         }
//     }
// }
void	push_all_to_stack_a(t_data **data)
{
	t_stack	*node;
	int		mid_index;
	int		index;

	node = (*data)->stack_b;
	while (node)
	{
		mid_index = (count_stack((*data)->stack_b) - 1) / 2;
		if (get_max_value(data) == node->number)
		{
			index = get_node_index_by_value(data, &((*data)->stack_b),
					node->number);
			if (index <= mid_index)
				repeat_n_rotate_b(data, &((*data)->stack_b), index);
			else
				repeat_n_rev_rotate_b(data, &((*data)->stack_b),
					count_stack((*data)->stack_b) - index);
			push_a(&((*data)->stack_a), &((*data)->stack_b), data);
			node = (*data)->stack_b;
		}
		else
		{
			node = node->next;
		}
	}
}

// void push_rest(t_data **data)
// {
//     int i = 0;
//     while ((*data)->stack_a && i < (*data)->total_size)
//     {
//         if(is_it_top_five(data, (*data)->stack_a->number))
//             rotate_a(&((*data)->stack_a), data);
//         else if ((*data)->stack_a->number < (*data)->mid)
//         {
//             push_b(&((*data)->stack_b), &((*data)->stack_a), data);
//             rotate_b(&((*data)->stack_b), data);
//         }
//         else if ((*data)->stack_a->number > (*data)->mid)
//         {
//             push_b(&((*data)->stack_b), &((*data)->stack_a), data);
//         }
//         i++;
//     }
// }
// void push_rotate_mid(t_data **data)
// {
//     while ((*data)->stack_a)
//     {
//         if ((*data)->stack_a->number == (*data)->mid)
//         {
//            push_b(&((*data)->stack_b), &((*data)->stack_a), data);
//            break ;
//         }
//         rotate_a(&((*data)->stack_a), data);
//     }
// }

void	skip_out_of_range(t_data **data, int range)
{
	int index;
	int mid_index;
	t_stack *node;

	node = (*data)->stack_a;
	while (node)
	{
		mid_index = (count_stack((*data)->stack_a) - 1) / 2;
		if (node->index > range)
			node = node->next;
		else if (node->index <= range)
		{
			index = get_node_index_by_value(data, &((*data)->stack_a),
					node->number);
			if (index <= mid_index)
				repeat_n_rotate(data, &((*data)->stack_a), index);
			else
			{
				repeat_n_rev_rotate(data, &((*data)->stack_a),
				count_stack((*data)->stack_a) - index);
			}
			return ;
		}
	}
}
