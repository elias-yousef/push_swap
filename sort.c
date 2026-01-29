/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:28:48 by mkhashan          #+#    #+#             */
/*   Updated: 2026/01/29 14:28:48 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(s_stack *stack_a, t_config *conf)
{
	int		dis_ordered;
	s_stack	*stack_b;

	stack_b = stack_create();
	dis_ordered = 0;
	if (conf->mod = 0)
		s_sort(stack_a, &conf);
	else if (conf->mod = 1)
		m_sort(stack_a, stack_b, &conf);
	else if (conf->mod = 2)
		c_sort(stack_a, &conf);
	else
	{
		dis_ordered = compute_disorder(stack_a);
		if (dis_ordered < 0.2)
			s_sort(stack_a, &conf);
		else if (dis_ordered < 0.5)
			m_sort(stack_a, &conf);
		else
			c_sort(stack_a, &conf);
	}
}