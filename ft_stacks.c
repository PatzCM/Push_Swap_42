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
		head = new;
		current = head;
		while (numbers[++i])
		{
			new = new->next;
			new = malloc(sizeof(t_stack));
			new->content = (ft_atol(numbers[i]));
			current->next = new;
			current = new;
			current->next = NULL;
		}
	}
	return (head);
}

void	ft_index(t_stack *a)
{
	t_stack *temp;
	t_stack *head;
	int index;
	int max;
	int lenght;

	lenght = len(a);
	head = a;
	index = 0;

	while (index < lenght)
	{
		max = 2147483647;
		temp = head;
		while (!temp->next)
		{
			if (temp->content < max)
				max = temp->content;
			temp = temp->next;
		}
		temp = head;
		while (!temp->next)
		{
			if (temp->content == max)
				temp->index = index;
			temp = temp->next;
		}
		index++;
	}
}
