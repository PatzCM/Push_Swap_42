#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int	i;

	i = 0;	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		numbers = number_division(&argc, argv);
	else
	{
		numbers = ft_calloc(sizeof(char *), argc);
		if (numbers == NULL)
			return (0);
		argv++;
		while (i < (argc - 1))
		{
			numbers[i] = ft_strdup(argv[i]);
			i++;
		}

	}
	i = 0;
	if (ft_error_check(argc, numbers) == -1)
		return (0);
	stack_a = ft_stack_init(numbers, 1);
	ft_index(&stack_a);
	ft_size_choice(&stack_a, &stack_b);
	/*while (stack_a)*/
	/*{*/
	/*	printf("content: %ld  ", stack_a->content);*/
	/*	printf("index: %d\n", stack_a->index);*/
	/*	stack_a = stack_a->next;*/
	/*}*/
	ft_free_numbers(numbers);
	ft_free_stack(&stack_a);
}

void	ft_size_choice(t_stack **a, t_stack **b)
{
	int size;

	size = len(a);
	if (size == 2 && !sorted(a))
		ft_swap(a, 'a');
	else if (size == 3 && !sorted(a))
		sort_3(a);
	else if (size == 4 && !sorted(a))
			sort_4(a, b);
	else if (size == 5 && !sorted(a))
			sort_5(a, b);
	else
		radix_sorting(a, b);
}
