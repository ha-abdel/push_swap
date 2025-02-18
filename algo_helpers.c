/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:16:38 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 09:06:19 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_n_rotate(t_data **data, t_stack **stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rotate_a(stack, data, 1);
		i++;
	}
}

void	repeat_n_rev_rotate(t_data **data, t_stack **stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		reverse_rotate_a(stack, data, 1);
		i++;
	}
}

void	repeat_n_rotate_b(t_data **data, t_stack **stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rotate_b(stack, data, 1);
		i++;
	}
}

void	repeat_n_rev_rotate_b(t_data **data, t_stack **stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		reverse_rotate_b(stack, data, 1);
		i++;
	}
}

int	get_max_value(t_data **data)
{
	t_stack	*node;
	int		max;

	node = (*data)->stack_b;
	max = node->number;
	while (node)
	{
		if (node->number > max)
			max = node->number;
		node = node->next;
	}
	return (max);
}
