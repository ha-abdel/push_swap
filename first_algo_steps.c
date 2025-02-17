/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:27:20 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/17 12:37:29 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_stack_b(t_data **data)
{
	int	nb_pushed;

	nb_pushed = 0;
	while ((*data)->stack_a)
	{
		if ((*data)->stack_a->index <= nb_pushed)
		{
			push_b(&((*data)->stack_b), &((*data)->stack_a), data);
			rotate_b(&((*data)->stack_b), data);
			nb_pushed++;
		}
		else if ((*data)->stack_a->index <= (nb_pushed + (*data)->range))
		{
			push_b(&((*data)->stack_b), &((*data)->stack_a), data);
			nb_pushed++;
		}
		else if ((*data)->stack_a->index > (nb_pushed + (*data)->range))
			skip_out_of_range(data, nb_pushed + (*data)->range);
	}
}

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

void	skip_out_of_range(t_data **data, int range)
{
	int		index;
	int		mid_index;
	t_stack	*node;

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
