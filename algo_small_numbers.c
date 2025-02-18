/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:20:20 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 09:08:00 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_vars(t_data **data, t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	(*data)->vars.a = (*stack)->number;
	if ((*stack)->next)
		(*data)->vars.b = (*stack)->next->number;
	else
		return ;
	if ((*stack)->next->next)
		(*data)->vars.c = (*stack)->next->next->number;
	else
		return ;
	if ((*stack)->next->next->next)
		(*data)->vars.d = (*stack)->next->next->next->number;
	else
		return ;
	if ((*stack)->next->next->next->next)
		(*data)->vars.e = (*stack)->next->next->next->next->number;
	else
		return ;
}

void	sort_two(t_data **data, t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
	{
		(swap_a(stack, data, 1));
	}
	else
		return ;
}

void	sort_three(t_data **data, t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number
		&& (*stack)->number > (*stack)->next->next->number)
	{
		if ((*stack)->next->number > (*stack)->next->next->number)
			(rotate_a(stack, data, 1)), (swap_a(stack, data, 1));
		else
			rotate_a(stack, data, 1);
	}
	else if ((*stack)->next->number > (*stack)->number
		&& (*stack)->next->number > (*stack)->next->next->number)
	{
		if ((*stack)->number > (*stack)->next->next->number)
			(rotate_a(stack, data, 1)), (rotate_a(stack, data, 1));
		else
			(reverse_rotate_a(stack, data, 1)), (swap_a(stack, data, 1));
	}
	else if ((*stack)->next->next->number > (*stack)->number
		&& (*stack)->next->next->number > (*stack)->next->number)
	{
		if ((*stack)->number > (*stack)->next->number)
			swap_a(stack, data, 1);
	}
}

void	sort_four(t_data **data, t_stack **stack)
{
	int	index;

	index = find_smaller_index(data, stack);
	if (index == 0)
		push_b(&(*data)->stack_b, stack, data);
	else if (index == 1)
		(rotate_a(stack, data, 1)), (push_b(&(*data)->stack_b, stack, data));
	else if (index == 2)
	{
		(rotate_a(stack, data, 1)), (rotate_a(stack, data, 1));
		push_b(&(*data)->stack_b, stack, data);
	}
	else if (index == 3)
	{
		(reverse_rotate_a(stack, data, 1));
		push_b(&(*data)->stack_b, stack, data);
	}
	sort_three(data, stack);
	push_a(stack, &(*data)->stack_b, data);
}

void	sort_five(t_data **data, t_stack **stack)
{
	int	index;

	index = find_smaller_index(data, stack);
	if (index == 0)
		push_b(&(*data)->stack_b, stack, data);
	else if (index == 1)
		(rotate_a(stack, data, 1)), (push_b(&(*data)->stack_b, stack, data));
	else if (index == 2)
	{
		(rotate_a(stack, data, 1)), (rotate_a(stack, data, 1));
		push_b(&(*data)->stack_b, stack, data);
	}
	else if (index == 3)
	{
		(reverse_rotate_a(stack, data, 1)), (reverse_rotate_a(stack, data, 1));
		push_b(&(*data)->stack_b, stack, data);
	}
	else if (index == 4)
	{
		(reverse_rotate_a(stack, data, 1)), (push_b(&(*data)->stack_b, stack,
				data));
	}
	sort_four(data, stack);
	push_a(stack, &(*data)->stack_b, data);
}
