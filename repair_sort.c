/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 06:32:31 by mkhashan          #+#    #+#             */
/*   Updated: 2026/02/06 06:32:31 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*temp;

	if (!a || !a->head)
		return (1);
	temp = a->head;
	while (temp->next)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	repair_sort(t_stack *a)
{
	if (is_sorted(a))
		return ;
	while (!is_sorted(a))
	{
		if (a->head->val > a->head->next->val)
			a_1s(sx, a, "sa", 1);
		a_1s(rx, a, "ra", 1);
	}
}
