/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:59:37 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 09:13:04 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_stack **head, t_data **data, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = lst_last(head);
	last->prev->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	*head = last;
	if (print)
		append_move(data, "rrb\n");
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_data **data)
{
	t_stack	*first_b;
	t_stack	*second_b;

	if (!stack_b || !*stack_b)
		return ;
	first_b = *stack_b;
	second_b = first_b->next;
	*stack_b = second_b;
	if (second_b)
		second_b->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = first_b;
	first_b->next = *stack_a;
	first_b->prev = NULL;
	*stack_a = first_b;
	append_move(data, "pa\n");
}

void	push_b(t_stack **stack_b, t_stack **stack_a, t_data **data)
{
	t_stack	*first_a;
	t_stack	*second_a;

	if (!stack_a || !*stack_a)
		return ;
	first_a = *stack_a;
	second_a = first_a->next;
	*stack_a = second_a;
	if (second_a)
		second_a->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = first_a;
	first_a->next = *stack_b;
	first_a->prev = NULL;
	*stack_b = first_a;
	append_move(data, "pb\n");
}

void	reverse_rotate_a(t_stack **head, t_data **data, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = lst_last(head);
	last->prev->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	*head = last;
	if (print)
		append_move(data, "rra\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_data **data)
{
	swap_a(stack_a, data, 0);
	swap_b(stack_b, data, 0);
	append_move(data, "ss\n");
}
