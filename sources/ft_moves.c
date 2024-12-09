/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:47:50 by palexand          #+#    #+#             */
/*   Updated: 2024/12/09 21:47:55 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	int		temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	else if (c == 's')
		ft_printf("ss\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, ' ');
}

void	ft_push(t_stack **source, t_stack **dest, char c)
{
	t_stack	*temp;

	if (!*source)
		return ;
	temp = *source;
	*source = (*source)->next;
	temp->next = *dest;
	*dest = temp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

// function that rotates the stack by shifting up all elements by 1;
// the first element becomes the last one.

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*temp;
	t_stack	*head;

	if (!*stack || !(*stack)->next || !stack)
		return ;
	head = *stack;
	temp = (*stack)->next;
	while (head->next)
		head = head->next;
	head->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	else if (c == 'r')
		ft_printf("rr\n");
}

void	ft_reverse_rotate(t_stack **stack, char c)
{
	t_stack	*temp;
	t_stack	*head;

	head = *stack;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	while (head->next)
		head = head->next;
	head->next = *stack;
	temp->next = NULL;
	*stack = head;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
	else if (c == 'r')
		ft_printf("rrr\n");
}
