#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "limits.h"


typedef struct s_stack
{
    int number;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

t_stack	*ft_lstnew(int nb);

t_stack *lst_last(t_stack **head);

void    lst_add_back(t_stack **head, t_stack *new);

void lst_add_front(t_stack **head, t_stack *new);

void    lst_clear(t_stack **head);

void    lst_delete(t_stack **head, t_stack *node);

void    swap_a(t_stack **head);

void    swap_b(t_stack **head);

void    rotate_a(t_stack **head);

void    rotate_b(t_stack **head);

void	reverse_rotate_a(t_stack **head);
void    append(t_stack **head, int nb);

void	push_a(t_stack **head, t_stack **to_push);
int check_duplicte(t_stack *head, int value);

long	ft_atoi(char *str);

size_t	ft_count_words(char *s, char c);

int	ft_isdigit(int c);

int	ft_isdigit1(char *s);

int	ft_is_empty(char *s);

void free_all(char **numbers);

void    ft_split(char *s, char c, char **arr);
#endif