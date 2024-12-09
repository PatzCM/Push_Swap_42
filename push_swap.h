/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:11:31 by palexand          #+#    #+#             */
/*   Updated: 2024/12/09 21:11:31 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libs/Libft/libft.h"
# include "libs/Printf/ft_printf.h"

typedef struct s_stack
{
	long								content;
	struct s_stack						*next;
	int									index;
}	t_stack;

// Number functions

char	**number_division(int *argc, char **argv);
long	ft_atol(const char *str);
char	**fill_numbers(char **argv, int argc);
int		ft_error_check(int argc, char **argv);
int		ft_confirm_dups(char **argv);
int		ft_confirm_numbers(int argc, char **argv);

// Stack functions

t_stack	*ft_stack_init(char **numbers);

// Sorting functions

void	ft_size_choice(t_stack **a, t_stack **b);
void	ft_index(t_stack **a, int index, t_stack *head, t_stack *temp);
int		sorted(t_stack **stack);
t_stack	*get_last(t_stack **stack);
int		len(t_stack **stack);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	radix_sorting(t_stack	**a, t_stack	**b);

//Moves

void	ft_swap(t_stack **stack, char c);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack, char c);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **stack_a, t_stack **stack_b, char c);
void	ft_reverse_rotate(t_stack **stack, char c);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

//Free

void	ft_free_stack(t_stack **stack);
void	ft_free_numbers(char **numbers);

#endif
