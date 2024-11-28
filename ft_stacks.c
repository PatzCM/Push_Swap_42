#include "push_swap.h"

t_stack	*ft_stack_init(char **numbers, int fill)
{
	t_stack	*temp;
	int	i;

	i = 0;
	if (fill == 0)
	{
		temp = malloc(sizeof(t_stack));
		temp->content = 0;
		temp->next = NULL;
	}
	if (fill == 1)
	{
		while (numbers[i])
		{
			temp = malloc(sizeof(t_stack) * i);
			temp->content = (ft_atol(numbers[i]));
			temp->next = temp;
			i++;
		}
	}
	return (temp);
}	
