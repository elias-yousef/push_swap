#include "push_swap.h"

void	px(s_stack *from, s_stack *to)
{
	t_node	*temp;

	if (from->size < 1)
		return;
	/*cut the node form the "from stack"*/
	temp = from->head;
	from->head->prev->next = from->head->next;
	from->head->next->prev = from->head->prev;
	from->head = from->head->next;
	/* add the node to the "to stack"*/
	temp->next = to->head;
	temp->prev = to->head->prev;
	to->head->prev->next = temp;
	to->head->prev = temp;
}

void	rx(s_stack *stack_x)
{
	if (stack_x < 1)
		return;
	stack_x->head = stack_x->head->next;
}

void	rr(s_stack *s1, s_stack *s2)
{
	rx(s1);
	rx(s2);
}

void	rrx(s_stack *stack_x)
{
	if (stack_x < 1)
		return;
	stack_x->head = stack_x->head->prev;
}

void	rrrr(s_stack *s1, s_stack *s2)
{
	rrx(s1);
	rrx(s2);
}