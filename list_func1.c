#include "push_swap.h"

t_moves *lst_last_move(t_moves **head)
{
    t_moves *current = *head;

    if (!current)
        return NULL;

    while (current->next)
        current = current->next;

    return current;
}
void    lst_add_move_back(t_moves **head, t_moves *new)
{
    t_moves *last;
    if(!head || !new)
        return;
    if(!*head)
    {
        *head = new;
        new->prev = NULL;
        new->next = NULL;
        return;
    }
    last = lst_last_move(head);
    last->next = new;
    new->prev = last;
    new->next = NULL;
}


void    lst_delete(t_stack **head, t_stack *node)
{
    if(!head ||!node)
        return;
    if(node->prev)
        node->prev->next = node->next;
    else
        *head = node->next;
    if(node->next)
        node->next->prev = node->prev;
    free(node);
}

int count_stack(t_stack *stack)
{
    int count;

    count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}