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
    int cost;
} t_stack;

typedef struct s_data
{
    t_stack *stack_a;
    t_stack *stack_b;
    int *sorted;
    int total_size;
    int mid;
} t_data;

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

void push_a(t_stack **stack_a, t_stack **stack_b);

void push_b(t_stack **stack_b, t_stack **stack_a);

int check_duplicte(t_stack *head, int value);

long	ft_atoi(char *str, char **numbers);

size_t	ft_count_words(char *s, char c);

int check_args(char *str);


int count_args(int ac, char **av);
int	ft_isdigit(int c);

int	ft_isdigit_or_sign(char *s);

int	ft_is_empty(char *s);

void free_all(char **numbers);

void free_stack(t_stack **stack);

void free_data(t_data **data);

void    ft_split(char *s, char c, char **arr);

void fill_numbers(int ac, char **av, char **numbers);

int check_numbers(char **numbers);

int check_dups(char **numbers, int nb);


t_stack *push_swap(t_stack **stack_a, t_stack **stack_b);

void sort_array(t_data **data);

void    sort_helper(int **arr, int size);



/* FUNCTIONS */

#endif