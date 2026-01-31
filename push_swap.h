/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:56:28 by mkhashan          #+#    #+#             */
/*   Updated: 2026/01/31 14:03:49 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int	val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	int		sx;
	int		ss;
	int		px;
	int		rx;
	int		rr;
	int		rrx;
	int		rrr;
}	s_stack;

typedef struct s_config
{
	int	mod;
	int	bench;
}	t_config;

s_stack *stack_create();
void	add_node(s_stack *stack, int value);
void	sx(s_stack *stack_x);
void	ss(s_stack *stack_a, s_stack *stack_b);

void	px(s_stack *from, s_stack *to);
void	rx(s_stack *stack_x);
void	rr(s_stack *s1, s_stack *s2);
void	rrx(s_stack *stack_x);
void	rrrr(s_stack *s1, s_stack *s2);

int	ft_atoi(const char *str);
int	len(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	clear_stack(s_stack *stack_x);
double	compute_disorder(s_stack *stack_a);
int	idx_val(s_stack *stack_a, int idx);
int	dis_of_head(s_stack *stack_x, int val);
void	a_1s(void (*f)(s_stack *), s_stack *stack_x, char *ops, int times);
void	a_2s(void (*f)(s_stack *,s_stack *), s_stack *stack_f, s_stack *stack_t, int times);
void	m_sort(s_stack *stack_a, s_stack *stack_b);

#endif