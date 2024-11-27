#include "push_swap.h"

long	ft_atol(const char *str)
{
	int	i;
	long	nb;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] <= '\r' && str[i] >= '\t') || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
