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

void	sort_three(t_data **data, t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number
		&& (*stack)->number > (*stack)->next->next->number)
	{
		if ((*stack)->next->number > (*stack)->next->next->number)
			(rotate_a(stack, data)), (swap_a(stack, data));
		else
			rotate_a(stack, data);
	}
	else if ((*stack)->next->number > (*stack)->number
		&& (*stack)->next->number > (*stack)->next->next->number)
	{
		if ((*stack)->number > (*stack)->next->next->number)
			(rotate_a(stack, data));
		else
			(rotate_a(stack, data)), (swap_a(stack, data));
	}
	else if ((*stack)->next->next->number > (*stack)->number
		&& (*stack)->next->next->number > (*stack)->next->number)
	{
		if ((*stack)->number > (*stack)->next->number)
			swap_a(stack, data);
	}
}

void	sort_four(t_data **data, t_stack **stack)
{
	int	x;

	push_b(&(*data)->stack_b, stack, data);
	sort_three(data, stack);
	init_vars(data, stack);
	x = (*data)->stack_b->number;
	if (x < (*data)->vars.a)
		push_a(stack, &(*data)->stack_b, data);
	else if (x > (*data)->vars.c)
	{
		(push_a(stack, &(*data)->stack_b, data)), (rotate_a(stack, data));
	}
	else if (x > (*data)->vars.a && x < (*data)->vars.b)
		(push_a(stack, &(*data)->stack_b, data)), (swap_a(stack, data));
	else
	{
		(rotate_a(stack, data)), (push_a(stack, &(*data)->stack_b, data));
		reverse_rotate_a(stack, data);
	}
}

void	sort_five(t_data **data, t_stack **stack)
{
	int x;

	push_b(&(*data)->stack_b, stack, data);
	sort_four(data, stack);
	init_vars(data, stack);
	x = (*data)->stack_b->number;
	if (x < (*data)->vars.a)
		push_a(stack, &(*data)->stack_b, data);
	else if (x > (*data)->vars.d)
		(push_a(stack, &(*data)->stack_b, data)), (rotate_a(stack, data));
	else if (x > (*data)->vars.a && x < (*data)->vars.b)
		(push_a(stack, &(*data)->stack_b, data)), (swap_a(stack, data));
	else if (x > (*data)->vars.b && x < (*data)->vars.c)
	{
		(rotate_a(stack, data)), (rotate_a(stack, data));
		push_a(stack, &(*data)->stack_b, data);
		(reverse_rotate_a(stack, data)), (reverse_rotate_a(stack, data));
	}
	else
	{
		(reverse_rotate_a(stack, data)), (push_a(stack, &(*data)->stack_b, data));
		(rotate_a(stack, data)), (rotate_a(stack, data));
	}
}
