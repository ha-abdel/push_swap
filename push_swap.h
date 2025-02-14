#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "limits.h"





typedef struct s_moves
{
    char *move;
    struct s_moves *next;
    struct s_moves *prev;
} t_moves;

typedef struct s_stack
{
    int number;
    struct s_stack *next;
    struct s_stack *prev;
    // int cost;
    // int target;
    int index;
} t_stack;

typedef struct s_vars
{
    int a;
    int b;
    int c;
    int d;
    int e;
} t_vars;

typedef struct s_data
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_moves *moves;
    int *sorted;
    t_vars vars;
    int total_size;
    int mid;
    int range;
} t_data;



t_stack	*ft_lstnew(int nb);

t_stack *lst_last(t_stack **head);

void    lst_add_back(t_stack **head, t_stack *new);

void    lst_add__move_back(t_stack **head, t_moves *new);

void lst_add_front(t_stack **head, t_stack *new);

void    lst_clear(t_stack **head);

void    lst_delete(t_stack **head, t_stack *node);

void    swap_a(t_stack **head, t_data **data);

void    swap_b(t_stack **head, t_data **data);

void    rotate_a(t_stack **head, t_data **data);

void    rotate_b(t_stack **head, t_data **data);

void	reverse_rotate_a(t_stack **head, t_data **data);
void    append(t_stack **head, int nb);

void push_a(t_stack **stack_a, t_stack **stack_b, t_data **data);

void push_b(t_stack **stack_b, t_stack **stack_a, t_data **data);

int check_duplicte(t_stack *head, int value);

long	ft_atoi(char *str, char **numbers, t_data **data);

size_t	ft_count_words(char *s, char c);

int check_args(char *str);


int count_args(int ac, char **av);
int	ft_isdigit(int c);

int	ft_isdigit_or_sign(char *s);

int	ft_is_empty(char *s);

void free_numbers(char **numbers);

void free_stack(t_stack **stack);

void free_data(t_data **data);

void    ft_split(char *s, char c, char **arr);

void fill_numbers(int ac, char **av, char **numbers, t_data **data);

int check_numbers(char **numbers, t_data **data);

int check_dups(char **numbers, int nb);


void    push_swap(t_data **data, int count);

void sort_array(t_data **data);

void    sort_helper(int **arr, int size);





/* FUNCTIONS */
void check_before(t_data **data);
void check_after(t_data **data);
void	fill_moves(t_data **data, char **numbers);
void	apply_moves(t_data **data);
int ft_strcmp(const char *s1, const char *s2);
void	rrr(t_stack **stack_a, t_stack **stack_b , t_data **data);
void	rr(t_stack **stack_a, t_stack **stack_b , t_data **data);
void	ss(t_stack **stack_a, t_stack **stack_b , t_data **data);
void append_move(t_data **data, char *move);
void    print_moves(t_moves *moves);
void    initilize_all(t_data **data, int count);
void	reverse_rotate_b(t_stack **head , t_data **data);
void    repeat_n_rotate_b(t_data **data, t_stack **stack, int n);
void    repeat_n_rev_rotate_b(t_data **data, t_stack **stack, int n);
void	atoi_clean(char **numbers, t_data **data);
int count_stack(t_stack *stack);
void    print_stack_with_index(t_stack *stack_a);
void push_all_to_stack_a(t_data **data);
int get_max_value(t_data **data);
void    repeat_n_rev_rotate(t_data **data, t_stack **stack, int n);
void    repeat_n_rotate(t_data **data, t_stack **stack, int n);
void    skip_out_of_range(t_data **data, int range);
void    lst_add_move_back(t_moves **head, t_moves *new);
t_moves *lst_last_move(t_moves **head);
void	sort_five(t_data **data, t_stack **stack);
void	sort_four(t_data **data, t_stack **stack);
void	sort_three(t_data **data, t_stack **stack);
// int is_it_top_five(t_data **data, int value);
int get_node_index_by_value(t_data **data, t_stack **stack, int value);
void    print_stack(t_stack *stack_a);
void    fill_stack(t_stack **stack, char **numbers, int *size, t_data **data);
int get_mid(t_data *data, int *sorted);
void push_rotate_mid(t_data **data);

void push_rev_rotate_mid(t_data **data);
// void push_rest(t_data **data);
void push_all_to_stack_b(t_data **data);

#endif