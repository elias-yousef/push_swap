/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:25:11 by mkhashan          #+#    #+#             */
/*   Updated: 2026/02/05 09:25:11 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *a)
{
	t_node	*temp;
	int		i;
	long	min;
	int		index;

	i = 1;
	index = 0;
	temp = a->head;
	min = temp->val;
	while (i < a->size - 1)
	{
		temp = temp->next;
		if (min > temp->val)
		{
			min = temp->val;
			index = i;
		}
		i++;
	}
	return (index);
}

void	bring_to_top(t_stack *a, int index)
{
	if (index <= a->size / 2)
	{
		while (index > 0)
		{
			rx(a);
			index--;
		}
	}
	else
	{
		while (index < a->size)
		{
			rrx(a);
			index++;
		}
	}
}

void	s_sort(t_stack *a, t_stack *b)
{
	int	index;

	while (a->size > 0)
	{
		index = get_min_index(a);
		bring_to_top(a, index);
		px(a, b);
	}
	while (b->size > 0)
		px(b, a);
}
