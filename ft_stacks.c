#include "push_swap.h"

t_stack	*ft_stack_init(char **numbers, int fill, int argc)
{
	t_stack	*head = NULL;
	t_stack	*new;
	t_stack *current;
	int	i;

	i = -1;
	if (fill == 0)
			head = malloc(sizeof(t_stack));
	if (fill == 1)
	{
		new = malloc(sizeof(t_stack));
		new->content = (ft_atol(numbers[++i]));
		new->index = -1;
		head = new;
		current = head;
		while (numbers[++i])
		{
			new = new->next;
			new = malloc(sizeof(t_stack));
			new->content = (ft_atol(numbers[i]));
			current->next = new;
			current = new;
			current->index = -1;
			current->next = NULL;
		}
	}
	return (head);
}

void	ft_index(t_stack **a)
{
	t_stack *temp;
	t_stack *head;
	int index;
	int max;
	int lenght;

	lenght = len(a);
	head = *a;
	index = 0;

	temp = head;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
	while (index < lenght)
	{
		max = 2147483647;
		temp = head;
		while (temp->next)
		{
			if (temp->content < max && temp->index == -1)
				max = temp->content;
			temp = temp->next;
		}
		temp = head;
		while (temp->next)
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

	temp = *stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

int len(t_stack **stack)
{
	int i;
	t_stack *temp;
	
	i = 0;
	temp = *stack;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
