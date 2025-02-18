/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:26:39 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 08:52:12 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_numbers(char **numbers)
{
	int	i;

	i = 0;
	if (!numbers)
		return ;
	while (numbers[i])
	{
		free(numbers[i]);
		numbers[i] = NULL;
		i++;
	}
	free(numbers);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !(*stack))
		return ;
	current = (*stack);
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_data(t_data **data)
{
	if (!data || !(*data))
	{
		return ;
	}
	free_stack(&((*data)->stack_a));
	free_stack(&((*data)->stack_b));
	if ((*data)->sorted)
		free((*data)->sorted);
	free(*data);
}

void	atoi_clean(char **numbers, t_data **data)
{
	free_numbers(numbers);
	free(*data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
