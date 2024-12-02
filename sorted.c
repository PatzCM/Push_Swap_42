#include "push_swap.h"

int	sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int len(t_stack *stack)
{
	int i;
	t_stack *temp;
	
	i = 0;
	temp = stack;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
