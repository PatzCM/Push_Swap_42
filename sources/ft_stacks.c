/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:18:46 by palexand          #+#    #+#             */
/*   Updated: 2024/12/09 21:18:46 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stack_init(char **numbers)
{
	t_stack	*head;
	t_stack	*new;
	t_stack	*current;
	int		i;

	i = -1;
	new = ft_calloc(sizeof(t_stack), 1);
	new->content = (ft_atol(numbers[++i]));
	new->index = -1;
	head = new;
	current = head;
	while (numbers[++i])
	{
		new = new->next;
		new = ft_calloc(sizeof(t_stack), 1);
		new->content = (ft_atol(numbers[i]));
		current->next = new;
		current = new;
		current->index = -1;
		current->next = NULL;
	}
	return (head);
}

void	ft_index(t_stack **a, int index, t_stack *head, t_stack *temp)
{
	int		max;
	int		lenght;

	lenght = len(a);
	while (index < lenght)
	{
		max = 2147483647;
		temp = head;
		while (temp)
		{
			if (temp->content < max && temp->index == -1)
				max = temp->content;
			temp = temp->next;
		}
		temp = head;
		while (temp)
		{
			if (temp->content == max)
				temp->index = index;
			temp = temp->next;
		}
		index++;
	}
}

t_stack	*get_last(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*smallest;

	if (!*stack || !stack)
		return (NULL);
	temp = *stack;
	smallest = temp;
	while (temp)
	{
		if (temp->content < smallest->content)
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

int	len(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
