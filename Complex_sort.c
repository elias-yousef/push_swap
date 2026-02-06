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

void	map_val(t_stack *stack_a, int *arr)
{
	t_node	*temp;
	int		it1;
	int		it2;

	it1 = 0;
	it2 = 0;
	temp = stack_a->head;
	while (it1 < stack_a->size)
	{
		it2 = 0;
		while (temp->val != arr[it2])
			it2++;
		temp->val = it2;
		temp = temp->next;
		it1++;
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
	if (!arr_num)
		return ;
	while (it < stack_a->size)
	{
		arr_num[it] = temp->val;
		temp = temp->next;
		it++;
	}
	it = 0;
	s_init_sort(arr_num, stack_a->size);
	map_val(stack_a, arr_num);
	free(arr_num);
}

void	compare(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	j;

	j = stack_a->size;
	while (j > 0)
	{
		if ((stack_a->head->val >> i) & 1)
			a_1s(rx, stack_a, "ra", 1);
		else
			a_2s(px, stack_a, stack_b, -1);
		j--;
	}
}

void	c_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		j;

	indexer(a);
	i = 0;
	max_bits = 0;
	while ((a->size - 1) >> max_bits != 0)
		max_bits++;
	while (i < max_bits)
	{
		compare(a, b, i);
		j = b->size;
		while (j > 0)
		{
			a_2s(px, b, a, 1);
			j--;
		}
		i++;
	}
}
