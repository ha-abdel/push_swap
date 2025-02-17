/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:33:31 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/17 11:33:50 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int nb)
{
	t_stack	*l;

	l = (t_stack *)malloc(sizeof(t_stack));
	if (!l)
		return (NULL);
	l->number = nb;
	l->next = NULL;
	l->prev = NULL;
	return (l);
}

t_stack	*lst_last(t_stack **head)
{
	t_stack	*current;

	current = *head;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

void	lst_add_back(t_stack **head, t_stack *new)
{
	t_stack	*last;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	last = lst_last(head);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}

void	lst_add_front(t_stack **head, t_stack *new)
{
	t_stack	*current;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	current = *head;
	current->prev = new;
	new->next = current;
}

void	lst_clear(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
