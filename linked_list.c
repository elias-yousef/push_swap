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

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
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
		new_node->val = value;
	}
	stack->size++;
}

void	sa(s_stack *stack_a)
{
	long	temp;
	if (stack_a->size < 2)
		return ;
	temp = stack_a->head->val;
	stack_a->head->val = stack_a->head->next->val;
	stack_a->head->next->val = temp;
}

void	sb(s_stack *stack_b)
{
	long	temp;
	if (stack_b->size < 2)
		return ;
	temp = stack_b->head->val;
	stack_b->head->val = stack_b->head->next->val;
	stack_b->head->next->val = temp;
}

void	ss(s_stack *stack_a, s_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(s_stack *stack_a)
{
	while (stack_a->head->next != stack_a->head)
	{
		stack_a->head 
	}
}

