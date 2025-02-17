/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:23:59 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/17 11:24:06 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	return (1);
}

void	check_after(t_data **data, char **numbers)
{
	if (is_sorted((*data)->stack_a) && !(*data)->stack_b)
	{
		ft_putstr_fd("OK\n", 1);
		return ;
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		clean_all(data, numbers);
		exit(1);
	}
}

void	check_before(t_data **data, char **numbers)
{
	if (is_sorted((*data)->stack_a))
	{
		clean_all(data, numbers);
		exit(0);
	}
}
