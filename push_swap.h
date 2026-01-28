#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	long	val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	s_stack;

typedef struct s_bench
{
	int	status;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;
typedef struct s_config
{
	int		mod;
	t_bench	*bench;
}	t_config;

s_stack *stack_create();
void	add_node(s_stack *stack, long value);
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

#endif