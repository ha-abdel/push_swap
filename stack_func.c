#include "push_swap.h"

void	swap_a(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!head || !*head)
		return ;
	first = (*head)->next;
	second = (*head)->next->next;
	first->next = *head;
	(*head)->next = second;
	(*head)->prev = first;
	first->prev = NULL;
	*head = first;
}

void	swap_b(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!head || !*head)
		return ;
	first = (*head)->next;
	second = (*head)->next->next;
	first->next = *head;
	(*head)->next = second;
	(*head)->prev = first;
	first->prev = NULL;
	*head = first;
}

void	rotate_a(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = lst_last(head);
	(*head)->next->prev = NULL;
	(*head) = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rotate_b(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = lst_last(head);
	(*head)->next->prev = NULL;
	(*head) = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	push_a(t_stack **head, t_stack **to_push)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*first;
	t_stack	*second;

	if (!head || !to_push || !(*to_push))
		return ;
	head_a = *head;
	head_b = *to_push;
	first = *head;
	append(head, first->number);
	second = first->next;
    *head = second;
    (*head)->prev = NULL;
    first->next = NULL;
}

void	append(t_stack **head, int nb)
{
	t_stack	*new;

	if (!head)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->number = nb;
	new->prev = NULL;
	if (!(*head))
	{
		new->next = NULL;
		*head = new;
		return ;
	}
	new->next = *head;
	(*head)->prev = new;
	*head = new;
}

int	check_duplicte(t_stack *head, int value)
{
	if (!head || !value)
		return (0);
	while (head)
	{
		if (head->number == value)
			return (1);
		head = head->next;
	}
	return (0);
}
