/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:36:29 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/18 09:38:49 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	count_args(int ac, char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		count += ft_count_words(av[i], ' ');
		i++;
	}
	return (count);
}

void	fill_numbers(int ac, char **av, char **numbers, t_data **data)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		free_data(data);
		free_numbers(numbers);
		exit(1);
	}
	while (i < ac)
	{
		if (ft_is_empty(av[i]))
		{
			free_data(data);
			free_numbers(numbers);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		ft_split(av[i], ' ', numbers);
		i++;
	}
}

int	check_numbers(char **numbers, t_data **data)
{
	int	i;

	if (!numbers || !(*numbers))
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (ft_isdigit_or_sign(numbers[i]) && (ft_atoi(numbers[i], numbers,
					data) >= INT_MIN && ft_atoi(numbers[i], numbers,
					data) <= __INT_MAX__))
			i++;
		else
			return (0);
	}
	return (1);
}
