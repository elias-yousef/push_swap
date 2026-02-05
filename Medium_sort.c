/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utlis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:26:28 by mkhashan          #+#    #+#             */
/*   Updated: 2026/01/29 14:26:28 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_init_sort(int *arr, int size)
{
	int	it;
	int	temp;

	while (size)
	{
		it = 1;
		while (it < size)
		{
			if (arr[it] < arr[it - 1])
			{
				temp = arr[it - 1];
				arr[it - 1] = arr[it];
				arr[it] = temp;
			}
			it++;
		}
		size--;
	}
}

void	indexer(t_stack *stack_a)
{
	int		*arr_num;
	t_node	*temp;
	int		it;

	it = 0;
	temp = stack_a->head;
	arr_num = malloc(sizeof(int) * stack_a->size);
	while (it < stack_a->size)
	{
		arr_num[it] = temp->val;
		temp = temp->next;
		it++;
	}
	it = 0;
	s_init_sort(arr_num, stack_a->size);
	temp = stack_a->head;
	while (it < stack_a->size)
	{
		it = 0;
		while (temp->val != arr_num[it])
			it++;
		temp->val = it;
		temp = temp->next;
	}
}

void	f_p_s(t_stack *stack_a, t_stack *stack_b)
{
	int		it;
	int		it2;

	it2 = 1;
	while (stack_a != NULL)
	{
		it = 0;
		while (it < stack_a->size)
		{
			if (stack_a->head->val < (stack_a->size / 10) * it2)
				a_2s(px, stack_a, stack_b, 1);
			else
				a_1s(rx, stack_a, "ra", 1);
			it++;
		}
		it2++;
	}
}

void	m_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	temp;
	int		it;
	int		it2;

	it2 = 1;
	indexer(stack_a);
	f_p_s(stack_a, stack_b);
	while (stack_b->size)
	{
		if (d(stack_b, stack_b->size - 1) > 0)
			a_1s(rx, stack_b, "rb", d(stack_b, stack_b->size - 1));
		else if (d(stack_b, stack_b->size - 1) < 0)
			a_1s(rrx, stack_b, "rrb", -1 * d(stack_b, stack_b->size - 1));
		a_2s(px, stack_b, stack_a, 1);
	}
	clear_stack(stack_a);
	clear_stack(stack_b);
}
