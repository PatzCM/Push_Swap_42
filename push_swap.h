#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Libft/libft.h"
#include "Printf/ft_printf.h"

typedef struct s_stack
{
	long	content;
	struct s_stack	*next;
}	t_stack;

char	**number_division(int *argc, char **argv);
long	ft_atol(const char *str);
long	**ft_fill_numbers(char **argv);
int	ft_error_check(int argc, char **argv);

#endif
