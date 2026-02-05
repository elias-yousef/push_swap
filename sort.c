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

void	start_sort(t_stack *stack_a, t_config *conf)
{
	int		dis_ordered;
	t_stack	*stack_b;

	dis_ordered = compute_disorder(stack_a);
	stack_b = stack_create();
	dis_ordered = 0;
	if (conf->mod == 0)
		s_sort(stack_a, stack_b);
	else if (conf->mod == 1)
		m_sort(stack_a, stack_b);
	else if (conf->mod == 2)
		c_sort(stack_a, stack_b);
	else
	{
		if (dis_ordered < 0.2)
			s_sort(stack_a, &conf);
		else if (dis_ordered < 0.5)
			m_sort(stack_a, &conf);
		else
			c_sort(stack_a, &conf);
	}
	if (conf->bench)
		show_bench(stack_a, stack_b, conf, dis_ordered);
}
