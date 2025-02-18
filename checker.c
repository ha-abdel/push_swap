/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:41:44 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 09:05:13 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	fill_moves(t_data **data, char **numbers)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_move(line))
		{
			free(line);
			line = NULL;
			clean_all(data, numbers);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		apply_moves(data, line);
		free(line);
		line = get_next_line(0);
	}
}

void	initilize_all(t_data **data, int count, char **numbers)
{
	(*data)->stack_a = NULL;
	(*data)->stack_b = NULL;
	(*data)->sorted = NULL;
	(*data)->moves = NULL;
	(*data)->total_size = 0;
	if (numbers)
		*numbers = NULL;
	if (count <= 10)
		(*data)->range = 5;
	else if (count <= 100)
		(*data)->range = 13;
	else
		(*data)->range = 30;
}

int	check_move(char *line)
{
	if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n") || !ft_strcmp(line,
			"ss\n") || !ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pb\n")
		|| !ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n")
		|| !ft_strcmp(line, "rr\n") || !ft_strcmp(line, "rra\n")
		|| !ft_strcmp(line, "rrb\n") || !ft_strcmp(line, "rrr\n"))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	**numbers;
	int		count;

	count = count_args(ac, av);
	data = malloc(sizeof(t_data));
	numbers = malloc((count + 1) * sizeof(char *));
	initilize_all(&data, count, numbers);
	fill_numbers(ac, av, numbers, &data);
	if (!check_numbers(numbers, &data))
		return (ft_putstr_fd("Error\n", 2), free_numbers(numbers),
			free(data), 1);
	fill_stack(&data->stack_a, numbers, &data->total_size, &data);
	fill_moves(&data, numbers);
	check_after(&data, numbers);
	clean_all(&data, numbers);
	return (0);
}

void	apply_moves(t_data **data, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_a(&(*data)->stack_a, data, 1);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(&(*data)->stack_b, data, 1);
	else if (!ft_strcmp(line, "ss\n"))
		ss(&(*data)->stack_a, &(*data)->stack_b, data);
	else if (!ft_strcmp(line, "pa\n"))
		push_a(&(*data)->stack_a, &(*data)->stack_b, data);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(&(*data)->stack_b, &(*data)->stack_a, data);
	else if (!ft_strcmp(line, "ra\n"))
		rotate_a(&(*data)->stack_a, data, 1);
	else if (!ft_strcmp(line, "rb\n"))
		rotate_b(&(*data)->stack_b, data, 1);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate_a(&(*data)->stack_a, data, 1);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate_b(&(*data)->stack_b, data, 1);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(&(*data)->stack_a, &(*data)->stack_b, data);
	else if (!ft_strcmp(line, "rr\n"))
		rr(&(*data)->stack_a, &(*data)->stack_b, data);
	else
		return ;
}
