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

#include "push_swap.h"

static int	ft_confirm_dups(int argc, char **argv);
static int	ft_confirm_numbers(int argc, char **argv);

char	**number_division(int *argc, char **argv)
{
	char	**split_numbers;
	int		len;

	split_numbers = ft_split(argv[1], ' ');
	len = 0;
	while (split_numbers[len])
		len++;
	*argc = len;
	split_numbers[len] = NULL;
	return (split_numbers);
}

int	ft_error_check(int argc, char **argv)
{

	if (ft_confirm_dups(argc, argv) == -1)
		return (-1);
	if (ft_confirm_numbers(argc, argv) == -1)
		return (-1);
	return (0);
}

static int	ft_confirm_dups(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if ((ft_atol(argv[i]) > INT_MAX) || (ft_atol(argv[j]) > INT_MAX))
				return (-1);
			if (ft_atol(argv[i]) == ft_atol(argv[j]) && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_confirm_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1) 
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				if (argv[i][j] != '-' && j != 0)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
