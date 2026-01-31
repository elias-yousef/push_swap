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
		while (it > size)
		{
			if (arr[it] < arr[it-1])
			{
				temp = arr[it -1];
				arr[it - 1] = arr[it];
				arr[it] = temp;
			}
			it++;
		}
		size--;
	}
}

void	indexer(s_stack *stack_a)
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
	s_init_sort(arr_num, stack_a->size);
	it = 0;
	while (it < stack_a->size)
	{
		temp = stack_a->head;
		while (temp->val != arr_num[it])
			temp = temp->next;
		temp->val = it;
		it++;
	}
}


void	m_sort(s_stack *stack_a, s_stack *stack_b)
{
	t_node	temp;
	int		it;
	int		it2;

	it2 = 1;
	indexer(stack_a);
	while (stack_a != NULL)
	{
		it = 0;
		while (it < stack_a->size)
		{
			if (stack_a->head->val < (stack_a->size/10)*it2)
				a_2s(px, stack_a, stack_b, 1);
			else
				a_1s(rx, stack_a, "ra", 1);
			it++;
		}
		it2++;
	}
	while (stack_b->size)
	{
		if (dis_of_head(stack_b, stack_b->size - 1) > 0)
			a_1s(rx, stack_b, "rb", dis_of_head(stack_b, stack_b->size - 1));
		else if (dis_of_head(stack_b, stack_b->size - 1) < 0)
			a_1s(rrx, stack_b, "rrb", -1 * dis_of_head(stack_b, stack_b->size - 1));
		a_2s(px, stack_b, stack_a, 1);
	}
}