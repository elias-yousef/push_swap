/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:43:30 by mkhashan          #+#    #+#             */
/*   Updated: 2026/01/29 15:43:30 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dis_of_head(s_stack *stack_x, int val)
{
	t_node	*temp;
	int		it;
	int	f_d;
	int	b_d;

	it = 0;
	f_d = 0;
	b_d = 0;
	temp = stack_x->head;
	while (temp->val != val)
	{
		temp = temp->next;
		f_d += 1;
	}
	temp = stack_x->head;
	while (temp->val != val)
	{
		temp = temp->prev;
		b_d -= 1;
	}
	if (-1 * b_d > f_d)
		return (b_d);
	else
		return (f_d);
}

void	a_1s(void (*f)(s_stack *),int times, s_stack *stack_x, t_config *conf, char *ops)
{
	if (ft_strncmp("ra", ops, 2) == 0)
		conf->bench.ra += times;
	else if (ft_strncmp("rb", ops, 2) == 0)
		conf->bench.rb += times;
	else if (ft_strncmp("rr", ops, 2) == 0)
		conf->bench.rr += times;
	else if (ft_strncmp("rra", ops, 3) == 0)
		conf->bench.rra += times;
	else if (ft_strncmp("rrb", ops, 3) == 0)
		conf->bench.rrb += times;
	else if (ft_strncmp("rrr", ops, 3) == 0)
		conf->bench.rrr += times;
	else if (ft_strncmp("sa", ops, 2) == 0)
		conf->bench.sa += times;
	else if (ft_strncmp("sb", ops, 2) == 0)
		conf->bench.rb += times;
	else if (ft_strncmp("ss", ops, 2) == 0)
		conf->bench.ss += times;
	while (times != 0)
	{
		f(stack_x);
		//ft_printf("%s\n",ops);
		times--;
	}
}

void	a_2s(void (*f)(s_stack *,s_stack *),int times, s_stack *stack_f, s_stack *stack_t, t_config *conf, char *ops)
{
	if (ft_strncmp("pa", ops, 2) == 0)
		conf->bench.pa += times;
	else if (ft_strncmp("pb", ops, 2) == 0)
		conf->bench.pb += times;
	while (times != 0)
	{
		f(stack_f, stack_t);
		//ft_printf("%s\n",ops);
		times--;
	}
}