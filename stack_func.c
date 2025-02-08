#include "push_swap.h"

// void	swap_a(t_stack **head)
// {
// 	t_stack	*first;
// 	t_stack	*second;
// 	t_stack	*third;


// 	if (!head || !*head || !(*head)->next)
// 		return ;
	
// 	// first = (*head)->next;
// 	// second = (*head)->next->next;
// 	// second = *head;
// 	// (*head)->next = second;
// 	// (*head)->prev = first;
// 	// first->prev = NULL;
// 	// *head = first;

// 	//=====================
// 	first = *head;
// 	second = first->next;
// 	third = second->next;
// 	first->next = third;
// 	third->prev = first;
// 	first->prev = second;
// 	second->next = first;
// 	second->prev = NULL;
// 	(*head) = second;
// 	//===========================================


//     // t_stack *first;
//     // t_stack *second;

//     // if (!head || !*head || !(*head)->next)
//     //     return;

//     // // Let's denote:
//     // // A = *head, B = A->next, C = B->next
//     // first = *head;
//     // second = first->next;

//     // // Update the head to the second node.
//     // *head = second;
//     // second->prev = NULL;

//     // // Set first's new next to be C.
//     // first->next = second->next;
//     // if (second->next)
//     //     second->next->prev = first;

//     // // Place first after second.
//     // second->next = first;
//     // first->prev = second;

// 	// *head = second;
// }

void swap_a(t_stack **head)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    if (!head || !*head || !(*head)->next)
        return;

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
}

void	swap_b(t_stack **head)
{
	t_stack *first;
    t_stack *second;
    t_stack *third;

    if (!head || !*head || !(*head)->next)
        return;

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
}



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

// void	push_a(t_stack **head, t_stack **to_push)
// {
// 	t_stack	*head_a;
// 	t_stack	*head_b;
// 	t_stack	*first;
// 	t_stack	*second;

// 	if (!head || !(*head))
// 		return ;
// 	head_a = *head;
// 	head_b = *to_push;
// 	first = *head;
// 	append(to_push, first->number);
// 	second = first->next;
// 	(*head)->next = NULL;
// 	*head = second;
// 	if(second)
// 		(*head)->prev = NULL;
// }

void push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_b;
    t_stack *second_b;
    
    if (!stack_b || !*stack_b)
        return;
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
}

void push_b(t_stack **stack_b, t_stack **stack_a)
{
    t_stack *first_a;
    t_stack *second_a;
    
    if (!stack_a || !*stack_a)
        return;
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
