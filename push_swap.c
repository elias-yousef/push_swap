#include "push_swap.h"

int	ValidNum(char *str)
{
	int		it;
	long	num;

	it = 0;
	if (str[it] == '+' || str[it] == '-')
	{
		it++;
		return (0);
	}
	while (str[it])
	{
		if (str[it] <'0' || str[it] > '9')
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
		num = ft_atoi(str);
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
	if (lenth == 7 && ft_strncmp("bench", str, lenth) == 0)
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
int main(int argc, char **argv)
{
	int			it;
	char		*str;
	t_config	*conf;
	s_stack		*stack_a;

	stack_a = stack_create();
	it = 1;
	conf->mod = 3;
	while (it < argc)
	{
		str = argv[it];
		if (str[0] == '-' || str[1] == '-')
		{
			if (check_config(str) == -1)
				return (0);//print ERROR\N ON trderror and retrun
			else if (chink_config(str) == 4)
				conf->bench->status = 1;
			else
				conf->mod = chink_config(str);
		}
		else
		{
			if (can_2add_if(stack_a, str) == 0)
				return (0);//print ERROR\N ON trderror and retrun
		}
	}
}