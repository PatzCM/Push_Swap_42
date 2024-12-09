/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:10:46 by palexand          #+#    #+#             */
/*   Updated: 2024/12/09 21:10:46 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int		i;

	i = -1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		numbers = number_division(&argc, argv);
	else
		numbers = fill_numbers(argv, argc);
	i = 0;
	if (numbers == NULL || ft_error_check(argc, numbers) == -1 || argc == 0)
		return (write(2, "Error\n", 6), ft_free_numbers(numbers), 0);
	stack_a = ft_stack_init(numbers);
	ft_index(&stack_a, 0, stack_a, stack_a);
	ft_size_choice(&stack_a, &stack_b);
	ft_free_numbers(numbers);
	ft_free_stack(&stack_a);
}

void	ft_size_choice(t_stack **a, t_stack **b)
{
	int	size;

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
