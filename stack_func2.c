/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:00:10 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 09:12:51 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b, t_data **data)
{
	reverse_rotate_a(stack_a, data, 0);
	reverse_rotate_b(stack_b, data, 0);
	append_move(data, "rrr\n");
}

void	fill_stack(t_stack **stack, char **numbers, int *size, t_data **data)
{
	int	i;

	i = 0;
	(*size) = 0;
	while (numbers[i])
	{
		if (check_duplicte(*stack, ft_atoi(numbers[i], numbers, data)))
		{
			free_numbers(numbers);
			free_data(data);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		append(stack, ft_atoi(numbers[i], numbers, data));
		i++;
		(*size)++;
	}
}

int	check_duplicte(t_stack *head, int value)
{
	while (head)
	{
		if (head->number == value)
			return (1);
		head = head->next;
	}
	return (0);
}
