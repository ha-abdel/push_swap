/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:03:18 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/02/17 12:03:41 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	append_move(t_data **data, char *move)
{
	t_moves	*m;

	m = ft_new_move(move);
	lst_add_move_back(&(*data)->moves, m);
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

void	print_moves(t_moves *moves)
{
	while (moves)
	{
		printf("%s", moves->move);
		moves = moves->next;
	}
	return ;
}
