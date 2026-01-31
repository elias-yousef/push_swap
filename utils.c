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

void	a_1s(void (*f)(s_stack *), s_stack *stack_x, char *ops, int times)
{
	if (ft_strncmp("ra", ops, 2) == 0 || ft_strncmp("rb", ops, 2) == 0)
		stack_x->rx += times;
	else if (ft_strncmp("rr", ops, 2) == 0)
		stack_x->rr += times;
	else if (ft_strncmp("rra", ops, 3) == 0 || ft_strncmp("rrb", ops, 3) == 0)
		stack_x->rrx += times;
	else if (ft_strncmp("rrr", ops, 3) == 0)
		stack_x->rrr += times;
	else if (ft_strncmp("sa", ops, 2) == 0 || ft_strncmp("sb", ops, 2) == 0)
		stack_x->sx += times;
	else if (ft_strncmp("ss", ops, 2) == 0)
		stack_x->ss += times;
	while (times)
	{
		f(stack_x);
		//ft_printf("%s\n",ops);
		times--;
	}
}

void	a_2s(void (*f)(s_stack *,s_stack *), s_stack *stack_f, s_stack *stack_t, int times)
{
	stack_t->px += 1;
	while (times)
	{
		f(stack_f, stack_t);
		//ft_printf("%s\n",ops);
		times--;
	}
}

