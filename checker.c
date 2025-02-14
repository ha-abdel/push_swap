#include "get_next_line.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	char	**numbers;
	int		count;
	char	*line;

	if (ac < 2)
		return (printf("ERROR: Invalid arguments"), 1);
	count = count_args(ac, av);
	data = malloc(sizeof(t_data));
	initilize_all(&data, count);
	numbers = malloc((count + 1) * sizeof(char *));
	fill_numbers(ac, av, numbers, &data);
	if (!check_numbers(numbers, &data))
		return (printf("ERROR: Invalid number"), free_numbers(numbers),
			free(data), 1);
	fill_stack(&data->stack_a, numbers, &data->total_size, &data);
	fill_moves(&data, numbers);
	apply_moves(&data);
    check_after(&data);
	free_data(&data);
	free_numbers(numbers);
	return (0);
}

void	fill_moves(t_data **data, char **numbers)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_move(line))
			return (printf("ERROR: Invalid move"), free_numbers(numbers),
				free(data), free(line), 1);
		append_move(data, line);
		free(line);
		line = get_next_line(0);
	}
}

void	apply_moves(t_data **data)
{
	while ((*data)->moves)
	{
		if (!ft_strcmp((*data)->moves->move, "sa\n"))
			swap_a(&(*data)->stack_a, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "sb\n"))
			swap_b(&(*data)->stack_b, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "ss\n"))
			ss(&(*data)->stack_a, &(*data)->stack_b, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "pa\n"))
			push_a(&(*data)->stack_a, &(*data)->stack_b, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "pb\n"))
			push_b(&(*data)->stack_b, &(*data)->stack_a, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "ra\n"))
			rotate_a(&(*data)->stack_a, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "rb\n"))
			rotate_b(&(*data)->stack_b, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "rra\n"))
			reverse_rotate_a(&(*data)->stack_a, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "rrb\n"))
			reverse_rotate_b(&(*data)->stack_b, &(*data));
		else if (!ft_strcmp((*data)->moves->move, "rrr\n"))
			rrr(&(*data)->stack_a, &(*data)->stack_b, &(*data));
	}
}


