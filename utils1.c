/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:02:09 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/17 16:59:26 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	get_node_index_by_value(t_data **data, t_stack **stack, int value)
{
	int		i;
	t_stack	*node;

	(void)data;
	node = (*stack);
	i = 0;
	while (node)
	{
		if (node->number == value)
			return (i);
		i++;
		node = node->next;
	}
	return (i);
}

void	clean_all(t_data **data, char **numbers)
{
	t_moves	*next;

	while ((*data)->moves)
	{
		next = (*data)->moves->next;
		free((*data)->moves);
		(*data)->moves = next;
	}
	free_data(data);
	free_numbers(numbers);
}

int	find_smaller_index(t_data **data, t_stack **stack)
{
	int		small;
	int		index;
	t_stack	*current;

	current = (*stack);
	small = (*stack)->number;
	while (current)
	{
		if (current->number < small)
			small = current->number;
		current = current->next;
	}
	index = get_node_index_by_value(data, stack, small);
	return (index);
}
