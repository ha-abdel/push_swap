#include "push_swap.h"

t_moves	*ft_new_move(char *move)
{
	t_moves	*l;

	l = (t_moves *)malloc(sizeof(t_moves));
	if (!l)
		return (NULL);
	l->move = move;
	return (l);
}
void append_move(t_data **data, char *move)
{
    t_moves *m = ft_new_move(move);
    lst_add_move_back(&(*data)->moves, m);
}

void swap_a(t_stack **head , t_data **data)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    if (!head || !*head || !(*head)->next)
        return;

    // (void)data;
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
    // write(1, "sa\n", 3);
}

void	swap_b(t_stack **head , t_data **data)
{
	t_stack *first;
    t_stack *second;
    t_stack *third;

    if (!head || !*head || !(*head)->next)
        return;

    // (void)data;
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
    // write(1, "sb\n", 3);
}



void	rotate_a(t_stack **head , t_data **data)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	// (void)data;
    first = *head;
	last = lst_last(head);
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
    // write(1, "ra\n", 3);
    append_move(data, "ra\n");
}

void	rotate_b(t_stack **head , t_data **data)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	// (void)data;
    first = *head;
	last = lst_last(head);
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
    // write(1, "rb\n", 3);
    append_move(data, "rb\n");
}

void	reverse_rotate_a(t_stack **head , t_data **data)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	// (void)data;
    first = *head;
	last = lst_last(head);
	last->prev->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	*head = last;
    // write(1, "rra\n", 4);
    append_move(data, "rra\n");
}

void	reverse_rotate_b(t_stack **head , t_data **data)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	// (void)data;
    first = *head;
	last = lst_last(head);
	last->prev->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	*head = last;
    // write(1, "rrb\n", 4);
    append_move(data, "rrb\n");
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

void push_a(t_stack **stack_a, t_stack **stack_b , t_data **data)
{
    t_stack *first_b;
    t_stack *second_b;
    
    if (!stack_b || !*stack_b)
        return;
    // (void)data;
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
    // write(1, "pa\n", 3);
    append_move(data, "pa\n");
}

void push_b(t_stack **stack_b, t_stack **stack_a , t_data **data)
{
    t_stack *first_a;
    t_stack *second_a;
    
    if (!stack_a || !*stack_a)
        return;
    // (void)data;
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
    // write(1, "pb\n", 3);
    append_move(data, "pb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b , t_data **data)
{
	swap_a(stack_a, data);
	swap_b(stack_b, data);
    // write(1, "ss\n", 3);
    append_move(data, "ss\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b , t_data **data)
{
	rotate_a(stack_a, data);
	rotate_b(stack_b, data);
    // write(1, "rr\n", 3);
    append_move(data, "rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b , t_data **data)
{
	reverse_rotate_a(stack_a, data);
	reverse_rotate_b(stack_b, data);
    // write(1, "rrr\n", 4);
    append_move(data, "rrr\n");
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
    new->index = 0;
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


void    print_stack(t_stack *stack_a)
{
    while (stack_a)
    {
        printf("%d\n", stack_a->number);
        stack_a = stack_a->next;
    }
    printf("==================================\n");
    return;
}

void    print_stack_with_index(t_stack *stack_a)
{
    while (stack_a)
    {
        printf("%d    %d\n", stack_a->number, stack_a->index);
        stack_a = stack_a->next;
    }
    printf("==================================\n");
    return;
}
void    fill_stack(t_stack **stack, char **numbers, int *size, t_data **data)
{
    int i;

    i = 0;
    (*size) = 0;
    while (numbers[i])
    {
        if(check_duplicte(*stack, ft_atoi(numbers[i], numbers,data)))
        {
            free_numbers(numbers);
			free_data(data);
            printf("Error: Duplicates\n");
            exit(1);
        }
        append(stack, ft_atoi(numbers[i], numbers, data));
        i++;
        (*size)++;
    }

}

void    print_moves(t_moves *moves)
{
    while (moves)
    {
        printf("%s", moves->move);
        moves = moves->next;
    }
    // printf("==================================\n");
    return;
}