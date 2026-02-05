/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:27:22 by mkhashan          #+#    #+#             */
/*   Updated: 2026/02/05 09:27:22 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_stack *a)
{
	int		numlessthan;
	int		listsize;
	t_node	*temp_x;
	t_node	*temp_y;

	if (!a || a->size < 2)
		return ;
	temp_x = a->head;
	while (temp_x->next != a->head)
	{
		listsize = a->size;
		numlessthan = 0;
		temp_y = a->head;
		while (listsize > 0)
		{
			if (temp_y->next->val < temp_x->val)
				numlessthan++;
			temp_y = temp_y->next;
			listsize--;
		}
		temp_x->val = numlessthan;
		temp_x = temp_x->next;
	}
}

void	c_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		j;

	assign_indexes(a);
	i = 0;
	max_bits = 0;
	while ((a->size - 1) >> max_bits != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = a->size;
		while (j > 0)
		{
			if ((a->head->val >> i) & 1)
				a_1s(rx, a, "ra", 1);
			else
				a_2s(px, a, b, -1);
			j--;
		}
		j = b->size;
		while (j > 0)
		{
			a_2s(px, b, a, 1);
			j--;
		}
		i++;
	}
}
