#include "push_swap.h"

void	swap_a(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = (*head)->next;
	second = (*head)->next->next;
	second = *head;
	(*head)->next = second;
	(*head)->prev = first;
	first->prev = NULL;
	*head = first;
}

void	swap_b(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = (*head)->next;
	second = (*head)->next->next;
	second = *head;
	(*head)->next = second;
	(*head)->prev = first;
	first->prev = NULL;
	*head = first;
}

//
//1
//2 first
//3 second
//4
//5

void	rotate_a(t_stack **head)
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
}

void	rotate_b(t_stack **head)
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
}

void	reverse_rotate_a(t_stack **head)
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
}

void	reverse_rotate_b(t_stack **head)
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
}

void	push_a(t_stack **head, t_stack **to_push)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*first;
	t_stack	*second;

	if (!head || !(*head))
		return ;
	head_a = *head;
	head_b = *to_push;
	first = *head;
	append(to_push, first->number);
	second = first->next;
	(*head)->next = NULL;
	*head = second;
	if(second)
		(*head)->prev = NULL;
}

void	push_b(t_stack **head, t_stack **to_push)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*first;
	t_stack	*second;

	if (!head || !(*head))
		return ;
	head_a = *head;
	head_b = *to_push;
	first = *head;
	append(to_push, first->number);
	second = first->next;
	(*head)->next = NULL;
	*head = second;
	if(second)
		(*head)->prev = NULL;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
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
	lst_add_back(head, new);

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
