#include "push_swap.h"

void	sort_three(t_data **data, t_stack **stack)
{
	int a = (*stack)->number;
	int b = (*stack)->next->number;
	int c = (*stack)->next->next->number;

	if (a > b && a > c)
	{
		if (b > c)
			(rotate_a(stack, data)), (swap_a(stack, data));
		else
			rotate_a(stack, data);
	}
	else if (b > a && b > c)
	{
		if (a > c)
			(reverse_rotate_a(stack, data)), (swap_a(stack, data));
		else
			reverse_rotate_a(stack, data);
	}
	else if (c > a && c > b)
	{
		if (a > b)
			swap_a(stack, data);
	}
}



void	sort_four(t_data **data, t_stack **stack)
{
	int a = (*stack)->number;
	int b = (*stack)->next->number;
	int c = (*stack)->next->next->number;
    int d = (*stack)->next->next->next->number;

	push_b((*data)->stack_b, stack, data);
	sort_three(data, stack);
	if(a > d)
		push_a(stack, (*data)->stack_b, data);
	if(a < d && b > d)
	    (push_a(stack, (*data)->stack_b, data)), (swap_a(stack, data));
	else if(b < d && c > d)
	{
		(rotate_a(stack, data)), (rotate_a(stack, data));
		push_a(stack, (*data)->stack_b, data);
        (reverse_rotate_a(stack, data)), (reverse_rotate_a(stack, data));
	}
	    
	else if(c < d)
	{
		reverse_rotate_a(stack, data);
		push_a(stack, (*data)->stack_b, data);
		rotate_a(stack, data);
		rotate_a(stack, data);
	}
}

void	sort_five(t_data **data, t_stack **stack)
{
	int a = (*stack)->number;
	int b = (*stack)->next->number;
	int c = (*stack)->next->next->number;
    int d = (*stack)->next->next->next->number;
	int e = (*stack)->next->next->next->next->number;

	push_b((*data)->stack_b, stack, data);
	sort_four(data, stack);
	if(a > e)
	    push_a(stack, (*data)->stack_b, data);
	else if(a < e && b > e)
	    (push_a(stack, (*data)->stack_b, data)), (swap_a(stack, data));
	else if(c < d)
	{
		reverse_rotate_a(stack, data);
		push_a(stack, (*data)->stack_b, data);
		rotate_a(stack, data);
		rotate_a(stack, data);
	}
}
