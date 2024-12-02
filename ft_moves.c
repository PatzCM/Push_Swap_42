#include "push_swap.h"
// create a function that swaps the first two elements of a stack;
// do nothing if there is only one or no elements.
// not allowed to use -> prev
void	ft_swap(t_stack *stack, char c)
{
	t_stack	*temp;
	t_stack	*head;
	
	head = stack;
	temp = stack->next;

	if (temp && temp->next)
	{
		head->next = temp->next;
		temp->next = head;
		head = temp;
	}
	if (c == 'a')
	{
		ft_printf("sa\n");
	}
	else if (c == 'b')
	{
		ft_printf("sb\n");
	}
	else if (c == 's')
	{
		ft_printf("ss\n");
	}
}

void ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, ' ');
}

// function that pushes the first element of a stack to the other stack;
// do nothing if the stack is empty.
// not allowed to use -> prev

void ft_push(t_stack *stack_a, t_stack *stack_b, char c)
{
	t_stack	*temp;
	t_stack	*head_a;
	t_stack	*head_b;

	temp = stack_a->next;
	head_a = stack_a;
	head_b = stack_b;

	if (temp->next)
	{
		head_a->next = head_b;
		head_a = temp;
		stack_a = temp;
	}
	if (c == 'a')
	{
		ft_printf("pa\n");
	}
	else if (c == 'b')
	{
		ft_printf("pb\n");
	}
}

// function that rotates the stack by shifting up all elements by 1;
// the first element becomes the last one.
// not allowed to use -> prev

void ft_rotate(t_stack *stack, char c)
{
	t_stack	*temp;
	t_stack	*head;

	head = stack;
	temp = stack->next;

	if (temp->next)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = head;
		head->next = NULL;
	}
	if (c == 'a')
	{
		ft_printf("ra\n");
	}
	else if (c == 'b')
	{
		ft_printf("rb\n");
	}
	else if (c == 'r')
	{
		ft_printf("rr\n");
	}
}

void ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 'r');
	ft_rotate(stack_b, ' ');
}

// function that rotates the stack by shifting down all elements by 1; 
// the last element becomes the first one.
// not allowed to use -> prev

void ft_reverse_rotate(t_stack *stack, char c)
{
	t_stack	*temp;
	t_stack	*head;

	head = stack;
	temp = stack->next;

	if (temp->next)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = head;
		head->next = NULL;
	}
	if (c == 'a')
	{
		ft_printf("rra\n");
	}
	else if (c == 'b'){
		ft_printf("rrb\n");
	}
	else if (c == 'r'){
		ft_printf("rrr\n");
	}
}
void ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a, 'r');
	ft_reverse_rotate(stack_b, ' ');
}
