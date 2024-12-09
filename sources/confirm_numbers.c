/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:54:42 by palexand          #+#    #+#             */
/*   Updated: 2024/11/27 18:54:42 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_confirm_dups(char **argv);
int	ft_confirm_numbers(int argc, char **argv);

char	**number_division(int *argc, char **argv)
{
	char	**split_numbers;
	int		len;

	if (argv[1] == NULL || argv[1][0] == '\0')
		return (NULL);
	split_numbers = ft_split(argv[1], ' ');
	len = 0;
	while (split_numbers[len])
		len++;
	if (len == 0)
	{
		free(split_numbers);
		return (NULL);
	}
	*argc = len;
	split_numbers[len] = NULL;
	return (split_numbers);
}

int	ft_error_check(int argc, char **argv)
{
	if (ft_confirm_dups(argv) == -1)
		return (-1);
	if (ft_confirm_numbers(argc, argv) == -1)
		return (-1);
	return (0);
}

int	ft_confirm_dups(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]) && i != j)
				return (-1);
			j++;
		}
		if ((ft_atol(argv[i]) > INT_MAX) || (ft_atol(argv[i]) < INT_MIN))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_confirm_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	(void) argc;
	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if ((argv[i][j] == '-' || argv[i][j] == '+') && j != 0)
					return (-1);
				else if (argv[i][j] != '-' && argv[i][j] != '+')
					return (-1);
				else if (argv[i][j + 1] == '\0')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**fill_numbers(char **argv, int argc)
{
	char	**numbers;
	int		i;

	i = -1;
	numbers = ft_calloc(sizeof(char *), argc);
	if (numbers == NULL)
		return (0);
	argv++;
	while (++i < (argc - 1))
		numbers[i] = ft_strdup(argv[i]);
	return (numbers);
}
