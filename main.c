#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int	i;

	i = 0;
	
	if (argc == 2)
		numbers = number_division(&argc, argv);
		
	while (numbers[i] != NULL)
	{
		printf("%s\n", numbers[i]);
		i++;
	}
	if (ft_error_check(argc, numbers) == -1)
	{
		printf("Error\n");
		return (0);
	}
}
