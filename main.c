#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int	i;

i = 0;	
	
	if (argc == 2)
		numbers = number_division(&argc, argv);
	else
	{
		numbers = malloc(sizeof(char *) * argc);
		if (numbers == NULL)
			return (0);
		argv++;
		while (i < argc)
		{
			numbers[i] = ft_strdup(argv[i + 1]);
			i++;
		}

	}
	i = 0;
	while (numbers[i] != NULL)
	{
		ft_printf("%s\n", numbers[i]);
		i++;
	}
	ft_printf("No error\n");
	if (ft_error_check(argc, numbers) == -1)
	{
		printf("Error\n");
		return (0);
	}
	stack_a = ft_stack_init(numbers, 1);
	stack_b = ft_stack_init(numbers, 0);
	

}
