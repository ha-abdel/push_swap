/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:43:36 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/17 11:59:18 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **head, t_data **data)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	third = second->next;
	*head = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
	{
		third->prev = first;
	}
	(*head) = second;
	append_move(data, "sa\n");
}

void	swap_b(t_stack **head, t_data **data)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	third = second->next;
	*head = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
	{
		third->prev = first;
	}
	(*head) = second;
	append_move(data, "sb\n");
}

void	rotate_a(t_stack **head, t_data **data)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = lst_last(head);
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	append_move(data, "ra\n");
}

void	rotate_b(t_stack **head, t_data **data)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = lst_last(head);
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	append_move(data, "rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_data **data)
{
	rotate_a(stack_a, data);
	rotate_b(stack_b, data);
	append_move(data, "rr\n");
}
