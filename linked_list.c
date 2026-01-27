#include "push_swap.h"

t_node *node_create(long value)
{
    t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->val = value;
    node->next = NULL;
	node->prev = NULL;
    return (node);
}

s_stack *stack_create(long value)
{
    s_stack *stack;

	stack = (s_stack *)malloc(sizeof(s_stack));
    if (!stack)
        return (NULL);
    stack->head = node_create(value);
	stack->head->next = stack->head;
	stack->head->prev = stack->head;
	stack->size = 1;
    return (stack);
}

void	push(s_stack *stack, long value)
{
	t_node	*new_node;

	new_node = node_create(value);
	if (!new_node)
		return ;
	new_node->next = stack->head;
	stack->head->prev->next = new_node;
	new_node->prev = stack->head->prev;
	stack->head->prev = new_node;
	stack->size++;
}



