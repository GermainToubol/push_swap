/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:23:42 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/20 18:00:04 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

static int	is_top_ordered(t_stack *stack, int grow)
{
	if (grow && stack->value < stack->next->value)
		return (1);
	if (!grow && stack->value > stack->next->value)
		return (1);
	return (0);
}

static int	inter_mid(t_stack *stack, int size)
{
	int	min;
	int	max;

	if (size == 0)
		return (0);
	min = stack->value;
	max = stack->value;
	while (stack != NULL)
	{
		if (max < stack->value)
			max = stack->value;
		else if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return ((max + min) / 2);
}


void	divide(t_stack **stack_a, t_stack **stack_b, int size, t_inst **instruct)
{
	int	pivot;
	int	size_a;
	int	size_b;
	int	i;
	int is_a;

	if (*stack_a == NULL)
		return ;
	is_a = !('a' - (*stack_a)->name);
	if (stack_n_sorted(*stack_a, size, is_a))
		return ;
	if (size == 2)
	{
		if (!is_top_ordered(*stack_a, is_a))
			stack_swap(stack_a, instruct);
		return ;
	}
	pivot = inter_mid(*stack_a, size);
	i = 0;
	size_a = 0;
	size_b = 0;
	while (i < size)
	{
		if ((is_a && ((*stack_a)->value < pivot))
			|| (!is_a && (*stack_a)->value > pivot))
		{
			stack_push(stack_b, stack_a, instruct);
			size_b++;
		}
		else
		{
			stack_rotate(stack_a, instruct);
			size_a++;
		}
		i++;
	}
	i = 0;
	while (i < size_a)
	{
		stack_reverse_rotate(stack_a, instruct);
		i++;
	}
	divide(stack_a, stack_b, size_a, instruct);
	merge(stack_a, stack_b, size_b, instruct);
}
