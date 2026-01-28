/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:29:05 by mkhashan          #+#    #+#             */
/*   Updated: 2026/01/28 19:29:05 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	idx_val(s_stack *stack_a, long idx)
{
	long	it;
	t_node	*temp;

	it = 0;
	temp = stack_a->head;
	while (it < idx)
	{
		temp = temp->next;
	}
	return (temp->val);
}


long	compute_disorder(s_stack *stack_a)
{
	double	mistakes;
	double	total;
	long	it1;
	long	it2;

	mistakes = 0;
	total = 0;
	it1 = 0;
	while (it1 < stack_a->size)
	{
		it2 = it1 + 1;
		while (it2 < stack_a->size)
		{
			if (idx_val(stack_a, it1) > idx_val(stack_a, it2))
				mistakes += 1;
			total += 1;
			it2++;
		}
		it1++;
	}
	return (mistakes /total);
}
