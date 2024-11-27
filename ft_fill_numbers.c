#include "push_swap.h"

long	**ft_fill_numbers(char **argv)
{
	long	**numbers;
	int	i;
	int j;
	j = 1;
	i = 0;

	while (argv[j])
	{
		j++;
	}
	j = 1;
	while (argv[j])
	{
		numbers[i] = malloc(sizeof(long *) * ft_atol(argv[j]));
		*numbers[i] = ft_atol(argv[j]);
		j++;
		i++;
	}

	return ((long **)numbers);
}
