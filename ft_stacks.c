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
