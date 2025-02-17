/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:38:24 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/17 11:38:52 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(t_data **data)
{
	t_stack	*stack;
	int		i;
	t_stack	*head;

	head = (*data)->stack_a;
	(*data)->sorted = malloc(sizeof(int) * ((*data)->total_size));
	stack = (*data)->stack_a;
	if (!(*data)->sorted)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		exit(1);
	}
	i = 0;
	while (stack)
	{
		(*data)->sorted[i] = stack->number;
		stack = stack->next;
		i++;
	}
	(*data)->stack_a = head;
	sort_helper(&((*data)->sorted), i);
}

void	sort_helper(int **arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = (i + 1);
		while (j < size)
		{
			if ((*arr)[i] > (*arr)[j])
			{
				tmp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
