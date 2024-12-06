#include "push_swap.h"

void ft_free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

void ft_free_numbers(char **numbers)
{
  int	i;

	i = 0;	
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}

}
