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

t_stack *get_last(t_stack *stack)
{
	t_stack *temp;
	t_stack *smallest;
	temp = stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

void *sort_3(t_stack *a)
{
	int top;
	int middle;
	int bottom;

	top = a->content;
	middle = a->next->content;
	bottom = a->next->next->content;

	if (top > bottom && bottom > middle)
		ft_rotate(a, 'a');
	else if (top > middle && middle > bottom)
	{
	ft_swap(a, 'a');
	ft_reverse_rotate(a, 'a');
	}
	else if (middle > top && top > bottom)
		ft_reverse_rotate(a, 'a');
	else if (middle > bottom && bottom > top)
		ft_rotate(a, 'a');
	else if (bottom > top && top > middle)
		ft_swap(a, 'a');
}

void	*sort_4(t_stack *a, t_stack *b, int i)
{
	if (a->next->next->next->content == (get_last(a))->content)
	{
		while (a->content != (get_last(a))->content)
			ft_reverse_rotate(a, 'a');
	}
	else
	{
		while (a->content != (get_last(a))->content)
			ft_rotate(a, 'a');
	}
	if (!sorted(a))
	{
		ft_push(b, a, 'b');
		sort_3(a);
		ft_push(a, b, 'a');
	}
}

void *sort_5(t_stack *a, t_stack *b, int i)
{
	if (a->next->next->next->next->content == (get_last(a))->content
		|| a->next->next->next->content == (get_last(a))->content)
	{
		while (a->content != (get_last(a))->content)
			ft_reverse_rotate(a, 'a');
	}
	else
	{
		while (a->content != (get_last(a))->content)
			ft_rotate(a, 'a');
	}
	if (!sorted(a))
	{
		ft_push(b, a, 'b');
		sort_4(a, b, i);
		ft_push(a, b, 'a');
	}
}
