/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:56:21 by mkhashan          #+#    #+#             */
/*   Updated: 2026/01/31 13:30:46 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ValidNum(char *str)
{
	int		it;
	long	num;

	it = 0;
	if (str[it] == '+' || str[it] == '-')
	{
		it++;
	}
	while (str[it])
	{
		if (str[it] < '0' || str[it] > '9')
			return (0);
		it++;
	}
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int	can_2add_if(s_stack *stack_a, char *str)
{
	int	num;
	t_node	*temp;
	int	it;

	it = 0;
	num = 0;
	if (ValidNum(str))
		num = (int)ft_atoi(str);
	else
		return(num);
	temp = stack_a->head;
	while (it < stack_a->size)
	{
		if (temp->val == num)
			return (0);
		it++;
		temp = temp->next;
	}
	add_node(stack_a, num);
	return (1);
}

int	check_config(char *str)
{
	int	lenth;

	lenth = len(str);
	if (lenth == 7 && ft_strncmp("--bench", str, lenth) == 0)
		retrun (4);
	else if (lenth == 8 && ft_strncmp("--simple", str, lenth) == 0)
		return (0);
	else if (lenth == 8 && ft_strncmp("--medium", str, lenth) == 0)
		return (1);
	else if (lenth == 9 && ft_strncmp("--complex", str, lenth) == 0)
		return (2);
	else if (lenth == 10 && ft_strncmp("--adaptive", str, lenth) == 0)
		return (3);
	else
		return (-1);
}

s_stack	*Parser(int argc, char **argv, t_config *conf , s_stack *stack_a)
{
	int		it;
	char	*str;

	it = 1;
	while (it < argc)
	{
		str = argv[it];
		if (str[0] == '-' || str[1] == '-')
		{
			if (check_config(str) == -1)
				return (NULL);
			else if (chink_config(str) == 4)
				conf->bench = 1;
			else
				conf->mod = chink_config(str);
		}
		else
		{
			if (can_2add_if(stack_a, str) == 0)
				return (NULL);
		}
		it++;
	}
	return (stack_a);
}

int main(int argc, char **argv)
{
	int			it;
	char		*str;
	t_config	conf;
	s_stack		*stack_a;

	conf.mod = 3;
	stack_a = stack_create();
	if (Parser(argc, argv, &conf, stack_a) == NULL)
	{
		//print ERROR\N ON stderror
		clear_stack(stack_a);
		return (1);
	}
	start_sort(stack_a, &conf);
}