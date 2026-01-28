#include "push_swap.h"

s_stack *stack_create()
{
	s_stack *stack;

	stack = malloc(sizeof(s_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

void	add_node(s_stack *stack, long value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	if (stack->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		new_node->val = value;
		stack->head = new_node;
	}
	else
	{
		stack->head->prev->next = new_node;
		new_node->prev = stack->head->prev;
		new_node->next = stack->head;
		stack->head->prev = new_node;
	}
	stack->size++;
}

void	sx(s_stack *stack_x)
{
	long	temp;
	if (stack_x->size < 2)
		return ;
	temp = stack_x->head->val;
	stack_x->head->val = stack_x->head->next->val;
	stack_x->head->next->val = temp;
}

void	ss(s_stack *stack_a, s_stack *stack_b)
{
	sx(stack_a);
	sx(stack_b);
}