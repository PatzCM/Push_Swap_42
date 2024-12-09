/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:23 by palexand          #+#    #+#             */
/*   Updated: 2024/12/06 16:18:23 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_3(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->content;
	middle = (*a)->next->content;
	bottom = (*a)->next->next->content;
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
	{
		ft_reverse_rotate(a, 'a');
		ft_swap(a, 'a');
	}
	else if (bottom > top && top > middle)
		ft_swap(a, 'a');
}

void	sort_4(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->next->content == (get_last(a))->content)
	{
		while ((*a)->content != (get_last(a))->content)
			ft_reverse_rotate((a), 'a');
	}
	else
	{
		while ((*a)->content != (get_last(a))->content)
			ft_rotate(a, 'a');
	}
	if (!sorted(a))
	{
		ft_push(a, b, 'a');
		sort_3(a);
		ft_push(b, a, 'b');
	}
}

void	sort_5(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->next->next->content == (get_last(a))->content
		|| (*a)->next->next->next->content == (get_last(a))->content)
	{
		while ((*a)->content != (get_last(a))->content)
			ft_reverse_rotate((a), 'a');
	}
	else
	{
		while ((*a)->content != (get_last(a))->content)
			ft_rotate(a, 'a');
	}
	if (!sorted(a))
	{
		ft_push(b, a, 'b');
		sort_4(a, b);
		ft_push(a, b, 'a');
	}
}

void	radix_sorting(t_stack	**a, t_stack	**b)
{
	int	lenght;
	int	bit;

	bit = 0;
	while (!sorted(a) )
	{
		lenght = len(a);
		while (lenght--)
		{
			if ((*a)->index & 1 << bit)
				ft_rotate(a, 'a');
			else
				ft_push(a, b, 'b');
		}
		while (*b)
			ft_push(b, a, 'a');
		bit++;
	}
}
