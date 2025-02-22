/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:38:06 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 09:43:44 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (ft_putstr_fd("Error", 2), free_numbers(numbers),
			free(data), 1);
	fill_stack(&data->stack_a, numbers, &data->total_size, &data);
	sort_array(&data);
	check_before(&data, numbers);
	push_swap(&data, count, numbers);
	print_moves(data->moves);
	clean_all(&data, numbers);
	return (0);
}
